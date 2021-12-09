`timescale 1ns/100ps

module tb_driver();
   reg  CLK;
   reg  reset_button;
   reg  enable_switch;
   reg  [127:0] target_selected;
   wire [31:0] target;
   wire status_paused;
   wire status_running;
   wire status_warming;
   wire status_found;
   wire status_done;
   wire enabled;

always 
  #5 CLK = ~CLK;
  
  
  
initial begin

//  target_selected = 128'hf1d3ff8443297732862df21dc4e57262; // 00000000
//  target_selected = 128'ha4300bfbc02f3d4a1e47d4caf91fd29e; // 00000010
//  target_selected = 128'h2ab4b906fabd1c154d3d8fd77942028e; // 00000100
//  target_selected = 128'h33eba1e7a037d9c4bb54e60d39d0c869; // 00000200
//  target_selected = 128'h7f78dc6c2d96c9312550124899899b94; // 00001000

//  setup
  CLK  = 1'b0;
  reset_button  = 1'b0;
  enable_switch = 1'b0;
  # 20 reset_button = 1'b1;
  
  target_selected = 128'h33eba1e7a037d9c4bb54e60d39d0c869; // 00000200
  # 20 enable_switch = 1'b1;
  # 700;
  # 20 enable_switch = 1'b0;
  
  
  target_selected = 128'h2ab4b906fabd1c154d3d8fd77942028e; // 00000100  
  # 20 enable_switch = 1'b1;  
  # 600;
  # 20 enable_switch = 1'b0;

  target_selected = 128'ha4300bfbc02f3d4a1e47d4caf91fd29e; // 00000010  
  # 20 enable_switch = 1'b1;  
  # 400;
  # 20 enable_switch = 1'b0;


  $finish;
end

driver u_driver(
  .CLK            (CLK),       
  .CPU_RESETN     (reset_button),      
  .enable_switch  (enable_switch),      
  .target_selected  (target_selected),
  .target         (target),
  .status_paused  (status_paused),
  .status_running (status_running),
  .status_warming (status_warming),
  .status_found   (status_found),
  .status_done    (status_done),
  .enabled        (enabled)     
  );

endmodule