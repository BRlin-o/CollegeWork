		ORG	000H			;
START:	MOV	R0, #OK-TABLE+1	;
		MOV	DPTR, #TABLE	;
		MOV	R1, #00H		;
		MOV	R2, #02H		;
		MOV	R3, #00H		;
LOOP:		MOV 	A, R1			;
		MOVC	A, @A+DPTR		;
		MOV	P0, A			;
		ACALL	DELAY2		;
		INC	R1			;
		ACALL DELAY2		;
		INC	R1			;
		
		DJNZ	R0, LOOP		;
		AJMP	START			;

DELAY:	MOV	R5, #10		;
DL1:		MOV	R6, #250		;
DL2:		MOV	R7, #200		;
DL3:		DJNZ	R7, DL3		;
		DJNZ	R6, DL2		;
		DJNZ	R5, DL1		;
		RET				;

DELAY2:	MOV	R4, R2		;
DL4:		ACALL	DELAY			;
		DJNZ	R4, DL4		;
		RET				;

TABLE:	DB	10000001B		;
		DB	10000010B		;
		DB	00100100B		;
OK:		DB	01000100B		;