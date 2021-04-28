		ORG	0000H			;
START:	
		MOV	R1, #02H		;
		MOV	R2, #07H		;
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
		AJMP	START			;

DELAY:	MOV	R6, #250		;
DL1:		MOV	R7, #200		;
DL2:		DJNZ	R7, DL2		;
		DJNZ	R6, DL1		;
		RET				;

		END				;

