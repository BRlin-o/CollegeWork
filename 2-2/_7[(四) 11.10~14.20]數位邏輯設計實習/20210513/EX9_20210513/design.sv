// Code your design here
module alu4(S, A, B, Alu);
  input 	[3:0] S;
  input 	[4:0] A, B;
  output	[4:0] Alu;
  reg		[4:0] Alu;

  always@(S or A or B)
    case(S)
      0	: Alu = A>B ? 5'b11111 : 5'b00000;
      1	: Alu = A > B ? A : B;
      5	: Alu = {B[2:0], B[3]};
      7	: Alu = A>>1;
      12: Alu = ~(A^B);
      13: Alu = ~(A & B);
      default: Alu = 6;
    endcase
endmodule