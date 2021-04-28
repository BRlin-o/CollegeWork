/**Settings
1. Aldec Riviera Pro 2020.04
2. Open EPWave after run if not
*/
`timescale 1ns/1ns

module mux2_1_test();
  
  reg [3:0] A, B, C;
  
  wire [3:0] X, Y, Z;
  
  choice uut(.A(A), .B(B), .C(C), .X(X), .Y(Y), .Z(Z));
  
  initial
    begin
      A=4'b0000;
      B=4'b0010;
      C=4'b0100;
      #100; // 等待時間
      A=4'b0000;
      B=4'b0100;
      C=4'b0010;
      #100; // 等待時間
      A=4'b1000;
      B=4'b0010;
      C=4'b0100;
      #100; // 等待時間
      A=4'b0010;
      B=4'b0011;
      C=4'b0001;
      #100; // 等待時間
      A=4'b1000;
      B=4'b1010;
      C=4'b1100;
      #100; // 等待時間
    end
  
  initial
  begin
    $display("dump.cvd");
    #500;
    $finish();
  end
  
  initial
  begin
    $dumpfile("dump.vcd");
    $dumpvars(0);
  end
endmodule