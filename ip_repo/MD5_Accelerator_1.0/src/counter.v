module counter # (
    parameter integer STEP = 1
)(
   input CLK,
   input reset,
   input enable,
   output [31:0] counter_out,
   output reg running,
   output reg done
);

reg [32:0] count;
assign counter_out = count[31:0];

always @(posedge CLK) 
begin
  if (reset) 
  begin
    count   <= 0;
    running <= 0;
    done    <= 0;
  end 
  else if (count > 32'h0ffffffff)
  begin
    running <= 0;
    done    <= 1;
  end
  else if (enable) 
  begin
    count   <= count + STEP;
    running <= 1;
    done    <= 0;
  end
end
endmodule
