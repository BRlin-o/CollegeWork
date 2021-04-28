/**Settings
1. Aldec Riviera Pro 2020.04
2. Open EPWave after run if not
*/
`timescale 1ns/1ns

module full_adder_test();
  
  reg A, B, Ci;
  
  wire Co, S;
  
  full_adder uut(.A(A), .B(B), .Ci(Ci), .Co(Co), .S(S));
  
  initial
    begin
      A=1'b0;
      B=1'b0;
      Ci=1'b0;
      #100; // 等待時間
      A=1'b0;
      B=1'b0;
      Ci=1'b1;
      #100; // 等待時間
      A=1'b0;
      B=1'b1;
      Ci=1'b0;
      #100; // 等待時間
      A=1'b0;
      B=1'b1;
      Ci=1'b1;
      #100; // 等待時間
      A=1'b1;
      B=1'b0;
      Ci=1'b0;
      #100; // 等待時間
      A=1'b1;
      B=1'b0;
      Ci=1'b1;
      #100; // 等待時間
      A=1'b1;
      B=1'b1;
      Ci=1'b0;
      #100; // 等待時間
      A=1'b1;
      B=1'b1;
      Ci=1'b1;
    end
  
  initial
  begin
    $display("dump.cvd");
    #1000;
    $finish();
  end
  
  initial
  begin
    $dumpfile("dump.vcd");
    $dumpvars(0);
  end
endmodule