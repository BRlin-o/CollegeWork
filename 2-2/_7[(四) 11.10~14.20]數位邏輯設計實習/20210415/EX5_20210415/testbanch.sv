/**Settings
1. Aldec Riviera Pro 2020.04
2. Open EPWave after run if not
*/
`timescale 1ns/1ns

module mux2_1_test();
  
  reg [4:0] P, Q;
  
  wire [6:0] R;
  wire [5:0] T, W;
  wire [4:0] U, V, X;
  wire [3:0] S;
  wire Y, Z;
  
  choice uut(P, Q, R, S, T, U, V, W, X, Y, Z);
  
  initial
    begin
      P=5'b00001;
      Q=5'b00001;
      #100; // 等待時間
      P=5'b00011;
      Q=5'b00101;
      #100; // 等待時間
      P=5'b01101;
      Q=5'b01001;
      #100; // 等待時間
      P=5'b01101;
      Q=5'b10001;
      #100; // 等待時間
      P=5'b11111;
      Q=5'b00111;
      #100; // 等待時間
      P=5'b10011;
      Q=5'b00001;
      #100; // 等待時間
      P=5'b11011;
      Q=5'b00101;
      #100; // 等待時間
      P=5'b11111;
      Q=5'b11111;
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