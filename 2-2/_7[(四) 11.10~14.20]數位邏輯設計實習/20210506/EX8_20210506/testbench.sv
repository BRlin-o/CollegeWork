// Code your testbench here
// or browse Examples
`timescale 1ns/1ns

module testbanch();
  reg [2:0] I;
  wire [2:0] O1, O2;
  
  test uut(.I(I), .O1(O1), .O2(O2));
  
  initial
    begin
      I = 3'b000;
      #100
      I = 3'b001;
      #100
      I = 3'b010;
      #100
      I = 3'b011;
      #100
      I = 3'b100;
      #100
      I = 3'b101;
      #100
      I = 3'b110;
      #100
      I = 3'b111;
    end
  
  initial
    begin
      $display("testBanch");
      #800;
      $finish();
    end
  
  initial
    begin
      $dumpfile("dump.vcd");
      $dumpvars(0);
    end
endmodule