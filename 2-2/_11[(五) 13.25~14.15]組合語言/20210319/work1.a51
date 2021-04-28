		ORG	000H			;
START:	MOV	R0, #OK-TABLE+1	;
		MOV	DPTR, #TABLE	;
		MOV	R1, #00H		;
LOOP:		MOV 	A, R1			;
		MOVC	A, @A+DPTR		;
		MOV	P0, A			;
		ACALL	DELAY			;
		INC	R1			;
		
		DJNZ	R0, LOOP		;
		AJMP	START			;

DELAY:	MOV	R5, #2		;
DL1:		MOV	R6, #250		;
DL2: 		MOV	R7, #200		;
DL3:		DJNZ	R7, DL3		;
		DJNZ	R6, DL2		;
		DJNZ	R5, DL1		;
		RET				;

TABLE:	DB	01111110B		
		DB	00111100B		
		DB	00011000B		
		DB	00000000B		
		DB	00011000B		
		DB	00111100B		
		DB	01111110B		;
		DB	01111110B		
		DB	00111100B		
		DB	00011000B		
		DB	00000000B		
		DB	00011000B		
		DB	00111100B		
		DB	01111110B
		DB	11111111B		;
		DB	00000000B
		DB	11111111B
		DB	00000000B
OK:		DB	11111111B		;
		END