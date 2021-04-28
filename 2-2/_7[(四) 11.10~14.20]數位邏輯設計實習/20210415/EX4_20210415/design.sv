// Code your design here
module choice(A, B, C, ,X, Y, Z);
  input [3:0] A, B, C;
  output [3:0] X, Y, Z;
  assign X = (A > B ? (A > C ? A : (B > C ? B : C)) : (B > C ? B : (A > C ? A : C)));
  assign Y = (A < B ? (A < C ? A : (B < C ? B : C)) : (B < C ? B : (A < C ? A : C)));
  assign Z = (A > B ? (A < C ? A : (B > C ? B : C)) : (B < C ? B : (A > C ? A : C)));
  
endmodule