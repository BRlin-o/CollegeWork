// Code your testbench here
// or browse Examples
`timescale 1ns/1ns

module testbanch();
  reg Clk, D;
  wire [3:0] Q1, Q2;
  
  test uut(.Clk(Clk), .D(D), .Q1(Q1), .Q2(Q2));
  
  initial
    begin
      Clk = 1'b0;
      D   = 1'b0;
      #100
      Clk = 1'b1;
      D	  = 1'b1;
      #100
      Clk = 1'b0;
      D	  = 1'b1;
      #100
      Clk = 1'b1;
      D	  = 1'b0;
      #100
      Clk = 1'b0;
      D	  = 1'b0;
      #100
      Clk = 1'b1;
      D	  = 1'b1;
      #100
      Clk = 1'b0;
      D	  = 1'b1;
      #100
      Clk = 1'b1;
      D	  = 1'b0;
      #100
      Clk = 1'b0;
      D	  = 1'b0;
      #100
      Clk = 1'b1;
      D	  = 1'b1;
      #100
      Clk = 1'b0;
      D	  = 1'b1;
      #100
      Clk = 1'b1;
      D	  = 1'b1;
      #100
      Clk = 1'b0;
      D	  = 1'b1;
      #100
      Clk = 1'b1;
      D	  = 1'b0;
      #100
      Clk = 1'b0;
      D	  = 1'b0;
      #100
      Clk = 1'b1;
      D	  = 1'b0;
      #100
      Clk = 1'b0;
      D	  = 1'b0;
      #100
      Clk = 1'b1;
      D	  = 1'b1;
      #100
      Clk = 1'b0;
      D	  = 1'b1;
      #100
      Clk = 1'b1;
      D	  = 1'b1;
      #100
      Clk = 1'b0;
      D	  = 1'b1;
      #100
      Clk = 1'b1;
      D	  = 1'b1;
    end
  
  initial
    begin
      $display("testBanch");
      #2200;
      $finish();
    end
  
  initial
    begin
      $dumpfile("dump.vcd");
      $dumpvars(0);
    end
endmodule