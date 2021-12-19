module driver #
	(
		// Users to add parameters here
        parameter integer PIPELINES = 1
    ) (
  input          CLK,
  input          CPU_RESETN,
  input          enable_switch,
  input  [127:0] target_selected,  
  output [31:0]  target,
  output         status_paused,
  output reg     status_running,
  output reg     status_warming,
  output reg     status_found,
  output reg     status_done,
  output [4:0]   pipelines,
  output [(PIPELINES - 1):0] each_found,
  output [3:0]   version,
  output         enabled  
);
localparam hdl_version          = 4'b0001;
localparam state_start          = 4'b0001;
localparam state_warm_up        = 4'b0010;
localparam state_running        = 4'b0100;
localparam state_done           = 4'b1000;

wire                      counter_done;
wire [31:0]               counter_out;
wire [31:0]               counter_full;
wire                      found;
wire                      warming_up_done;
wire                      reset;
reg                       reset_counter;
reg  [3:0]                state;

assign target        = counter_out; 
assign enabled       = enable_switch;
assign found         = |each_found;
assign reset         = !CPU_RESETN;
assign status_paused = !status_running;
assign pipelines     = PIPELINES;
assign version       = hdl_version;


always @(posedge CLK) begin
  if (reset) begin
     state           <= state_start;
     status_running  <= 1'b0; 
     status_warming  <= 1'b0;
     status_found    <= 1'b0;
     status_done     <= 1'b0;
     reset_counter   <= 1'b1;
  end else begin
     case (state)
        state_start : begin
           if (enable_switch) begin
              state           <= state_warm_up;
              status_running  <= 1'b1; 
              status_warming  <= 1'b1;
              status_found    <= 1'b0;
              status_done     <= 1'b0;
              reset_counter   <= 1'b0;
           end else begin
              state           <= state_start;
              status_running  <= 1'b0; 
              status_warming  <= 1'b0;
              status_found    <= 1'b0;
              status_done     <= 1'b0;
              reset_counter   <= 1'b1;
           end                   
        end
        
        state_warm_up : begin
           if (warming_up_done) begin
              state           <= state_running;
              status_running  <= 1'b1; 
              status_warming  <= 1'b0;
              status_found    <= 1'b0;
              status_done     <= 1'b0;
              reset_counter   <= 1'b0;              
           end else begin
              state           <= state_warm_up;
              status_running  <= 1'b1; 
              status_warming  <= 1'b1;
              status_found    <= 1'b0;
              status_done     <= 1'b0;
              reset_counter   <= 1'b0; 
           end    
        end
        
        state_running : begin
           if (found) begin
              state           <= state_done;
              status_running  <= 1'b0; 
              status_warming  <= 1'b0;
              status_found    <= 1'b1;
              status_done     <= 1'b1;
              reset_counter   <= 1'b0;
           end else if (counter_done) begin
              state           <= state_done;
              status_running  <= 1'b0; 
              status_warming  <= 1'b0;
              status_found    <= 1'b0;
              status_done     <= 1'b1;
              reset_counter   <= 1'b0;              
           end else begin
              state           <= state_running;
              status_running  <= 1'b1; 
              status_warming  <= 1'b0;
              status_found    <= 1'b0;
              status_done     <= 1'b0;
              reset_counter   <= 1'b0;
           end
        end
        
        state_done : begin
           if (!enable_switch) begin
              state           <= state_start;
              status_running  <= 1'b0; 
              status_warming  <= 1'b0;
              status_found    <= status_found;
              status_done     <= 1'b1;
              reset_counter   <= 1'b1;                            
           end else begin
              state           <= state_done;      
              status_running  <= 1'b0; 
              status_warming  <= 1'b0;
              status_found    <= status_found;
              status_done     <= 1'b1;
              reset_counter   <= 1'b0;
           end
        end
        
     endcase
  end							
end							

warmup_counter u_warm_upcounter(
   .CLK(CLK),
   .reset(reset | reset_counter),
   .enable(status_warming),
   .done(warming_up_done)
);

counter #( .STEP(PIPELINES) ) counter (.CLK(CLK),
  .reset(reset | reset_counter),
  .enable(!status_paused),
  .counter_out(counter_out),
  .done(counter_done)
);

genvar idx;

generate
  for (idx = 0; idx < PIPELINES; idx = idx + 1) begin
    pipeline pipeline(.CLK(CLK),
      .counter_in( counter_out | idx ),
      .target_hash(target_selected),
      .reset(reset | reset_counter),
      .found(each_found[idx])
    );
  end
endgenerate

endmodule