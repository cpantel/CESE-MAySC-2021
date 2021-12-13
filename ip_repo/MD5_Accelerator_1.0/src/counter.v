module counter(
   input CLK,
   input reset,
   input enable,
   input step,
   output [30:0] counter_out,   // 28
   output reg running,
   output reg done
);

reg [31:0] count;                   // 29
assign counter_out = count[30:0];   // 28
initial count   = 0;
initial running = 0;
initial done    = 0;

always @(posedge CLK) 
begin
  if (reset) 
  begin
    count   <= 0;
    running <= 0;
    done    <= 0;
  end 
  else if (count == 31'hffffffff)    // 29'h1fffffff
  begin
    running <= 0;
    done    <= 1;
  end
  else if (enable) 
  begin
    count   <= count + 1;
    running <= 1;
    done    <= 0;
  end
  else if (step) 
  begin
    count   <= count + 1;
    running <= 0;
    done    <= 0;
  end
end
endmodule
