// Code your design here
module mux2_1(A, B, S, Y);
  input A, B, S;
  output Y;
  assign Y = (A & ~S) | (B & S);
endmodule