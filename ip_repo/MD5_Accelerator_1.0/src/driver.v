module driver(
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
  output         enabled
);

parameter state_start          = 4'b0001;
parameter state_warm_up        = 4'b0010;
parameter state_running        = 4'b0100;
parameter state_done           = 4'b1000;

wire        counter_done;
wire [30:0] counter_out;
wire        found, found0, found1; //, found2, found3;
wire        warming_up_done;
wire        reset;
reg         reset_counter;
reg  [7:0]  state;

assign target        = {counter_out,1'b0}; //3'b000
assign enabled       = enable_switch;
assign found         = (found0 | found1);// | found2 | found3);
assign reset         = !CPU_RESETN;
assign status_paused = !status_running;

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

counter counter(.CLK(CLK),
  .reset(reset | reset_counter),
  .step(0),
  .enable(!status_paused),
  .counter_out(counter_out),
  .done(counter_done)
);

pipeline pipeline0(.CLK(CLK),
  .counter_in({counter_out,1'b0}),
  .target_hash(target_selected),
  .reset(reset),
  .found(found0)
);

pipeline pipeline1(.CLK(CLK),
  .counter_in({counter_out,1'b1}),
  .target_hash(target_selected),
  .reset(reset),
  .found(found1)
);
/*
pipeline pipeline2(.CLK(CLK),
  .counter_in({counter_out,3'b010}),
  .target_hash(target_selected),
  .reset(reset),
  .found(found2)
);

pipeline pipeline3(.CLK(CLK),
  .counter_in({counter_out,3'b011}),
  .target_hash(target_selected),
  .reset(reset),
  .found(found3)
);
*/
endmodule