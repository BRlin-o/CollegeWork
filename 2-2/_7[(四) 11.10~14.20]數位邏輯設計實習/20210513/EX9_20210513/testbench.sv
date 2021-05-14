// Code your testbench here
// or browse Examples
`timescale 1ns/1ns

module testbanch();
  reg [3:0] S;
  reg [4:0] A, B;
  wire [4:0] Alu;
  
  alu4 uut(.S(S), .A(A), .B(B), .Alu(Alu));
  
  initial
    begin
      S = 4'b1101;
      A = 5'b10100;
      B = 5'b00101;      
      #100
      S = 4'b1100;
      #100
      S = 4'b0111;
      #100
      S = 4'b0101;
      #100
      S = 4'b0001;
      #100
      S = 4'b0000;
      #100
      S = 4'b1111;
    end
  
  initial
    begin
      $display("testBanch");
      #700;
      $finish();
    end
  
  initial
    begin
      $dumpfile("dump.vcd");
      $dumpvars(0);
    end
endmodule