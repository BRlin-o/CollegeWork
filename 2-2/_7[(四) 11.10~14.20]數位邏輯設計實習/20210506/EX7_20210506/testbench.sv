// Code your testbench here
// or browse Examples
`timescale 1ns/1ns

module testbanch();
  reg [1:0] I;
  wire [3:0] O1, O2, O3;
  
  test uut(.I(I), .O1(O1), .O2(O2), .O3(O3));
  
  initial
    begin
      I = 2'b00;
      #100
      I = 2'b01;
      #100
      I = 2'b10;
      #100
      I = 2'b11;
    end
  
  initial
    begin
      $display("testBanch");
      #400;
      $finish();
    end
  
  initial
    begin
      $dumpfile("dump.vcd");
      $dumpvars(0);
    end
endmodule