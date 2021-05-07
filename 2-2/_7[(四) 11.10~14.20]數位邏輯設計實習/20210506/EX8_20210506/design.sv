// Code your design here
module test(I, O1, O2);
  input 	[2:0] I;
  output 	[2:0] O1, O2;
  reg		[2:0] O2;
  
  assign O1[0] = ~I[0];
  assign O1[1] = ~(I[1] ^ I[0]);
  assign O1[2] = I[2]&(~I[1])&(~I[0]) | (~I[2])&I[0] | (~I[2])&I[1];
  
  always@(I)
    case(I)
      3'b000 : O2 = 3'b011;
      3'b001 : O2 = 3'b100;
      3'b010 : O2 = 3'b101;
      3'b011 : O2 = 3'b110;
      3'b100 : O2 = 3'b111;
      3'b101 : O2 = 3'b000;
      3'b110 : O2 = 3'b001;
      3'b111 : O2 = 3'b010;
    endcase
endmodule