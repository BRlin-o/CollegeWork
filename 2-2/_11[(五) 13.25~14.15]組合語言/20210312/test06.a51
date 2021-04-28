		ORG	0000H			;
START:	
		MOV	R1, #03H		;
		MOV	R2, #07H		;
		MOV	A, #10000000B	;
LOOP1:	MOV	P0, #11110000B	;
		ACALL DELAY			;
		MOV	P0, #00001111B	;
		ACALL	DELAY			;
		DJNZ	R1, LOOP1		;
		MOV	R1, #03H		;
		MOV	A, #10000000B	;
RIGHT:	MOV	P0, A			;
		ACALL	DELAY			;
		RR 	A			;
		DJNZ	R2, RIGHT		;
		MOV	R2, #07H		;
		MOV	A, #00000001B	;
LEFT:		MOV	P0, A			;
		ACALL	DELAY			;
		RL	A			;
		DJNZ	R2, LEFT		;
LOOP3:	MOV	P0, #01010101B	;
		ACALL DELAY			;
		MOV	P0, #10101010B	;
		ACALL	DELAY			;
		DJNZ	R1, LOOP3		;
		AJMP	START			;

DELAY:	MOV	R6, #250		;
DL1:		MOV	R7, #1000		;
DL2:		DJNZ	R7, DL2		;
		DJNZ	R6, DL1		;
		RET				;

		END				;

