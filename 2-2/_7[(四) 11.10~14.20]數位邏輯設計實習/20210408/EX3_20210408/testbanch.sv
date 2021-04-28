/**Settings
1. Aldec Riviera Pro 2020.04
2. Open EPWave after run if not
*/
`timescale 1ns/1ns

module mux2_1_test();
  
  reg A, B, S;
  
  wire Y;
  
  mux2_1 uut(.A(A), .B(B), .S(S), .Y(Y));
  
  initial
    begin
      A=1'b0;
      B=1'b0;
      S=1'b0;
      #80; // 等待時間
      A=1'b0;
      B=1'b0;
      S=1'b0;
      #80; // 等待時間
      A=1'b1;
      B=1'b0;
      S=1'b0;
      #80; // 等待時間
      A=1'b1;
      B=1'b0;
      S=1'b1;
      #80; // 等待時間
      A=1'b1;
      B=1'b0;
      S=1'b1;
      #80; // 等待時間
      A=1'b1;
      B=1'b0;
      S=1'b1;
      #80; // 等待時間
      A=1'b0;
      B=1'b0;
      S=1'b1;
      #80; // 等待時間
      A=1'b0;
      B=1'b0;
      S=1'b1;
      #80; // 等待時間
      A=1'b0;
      B=1'b1;
      S=1'b1;
      #80; // 等待時間
      A=1'b0;
      B=1'b1;
      S=1'b1;
      #80; // 等待時間
      A=1'b0;
      B=1'b1;
      S=1'b1;
    end
  
  initial
  begin
    $display("dump.cvd");
    #800;
    $finish();
  end
  
  initial
  begin
    $dumpfile("dump.vcd");
    $dumpvars(0);
  end
endmodule