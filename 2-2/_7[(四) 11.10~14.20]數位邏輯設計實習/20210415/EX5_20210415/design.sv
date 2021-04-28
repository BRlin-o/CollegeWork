// Code your design here
module choice(P, Q, R, S, T, U, V, W, X, Y, Z);
  input [4:0] P, Q;
  output [6:0] R;
  output [5:0] T, W;
  output [4:0] U, V, X;
  output [3:0] S;
  output Y, Z;
  assign R = P * 3;
  assign S = Q >> 1;
  assign T = 4'b0110 + P;
  assign U = P ^ Q;
  assign V = P >> 2;
  assign W = {P[2:0], Q[4:2]};
  assign X = (P > 10 ? P : Q);
  assign Y = (Q >= 10 && Q <= 20 ? 1 : 0);
  assign Z = (^P==1 ? 1 : 0);
endmodule