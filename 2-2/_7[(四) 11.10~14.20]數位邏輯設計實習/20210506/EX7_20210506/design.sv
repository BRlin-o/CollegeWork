// Code your design here
module test(I, O1, O2, O3);
  input 	[1:0] I;
  output 	[3:0] O1, O2, O3;
  reg		[3:0] O1, O2, O3;
  
  and(O1[0], I[0], 1);
  and(O1[1], 0, 0);
  and(O1[2], I[1], !I[0]);
  and(O1[3], I[1], I[0]);

  always@(I)
    if(I == 2'b00) O2 = 4'b0000;
  	else if(I == 2'b01) O2 = 4'b0001;
  	else if(I == 2'b10) O2 = 4'b0100;
  	else if(I == 2'b11) O2 = 4'b1001;
  
  always@(I)
    case(I)
      2'b00 : O3 = 4'b0000;
      2'b01 : O3 = 4'b0001;
      2'b10 : O3 = 4'b0100;
      2'b11 : O3 = 4'b1001;
    endcase
endmodule