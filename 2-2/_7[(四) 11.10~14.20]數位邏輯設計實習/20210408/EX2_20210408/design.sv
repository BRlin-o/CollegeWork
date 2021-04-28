// Code your design here
module full_adder(A, B, Ci, Co, S);
  input A, B, Ci;
  output Co, S;
  and(AB, A, B);
  and(BCi, B, Ci);
  and(ACi, A, Ci);
  or(Co, AB, BCi, ACi);
  xor(S, A, B, Ci);
endmodule