;
; 配合"8個LED(共陰)實習板"
;     P0所接的8個LED(初始狀態:最左2個亮；其餘6個LED熄著),並進行右旋的變化
;

		ORG	0000H			;
START:	
		MOV	R1, #07H		;
		MOV	A, #00000001B	;
LEFT:		MOV	P0, A			;
		ACALL	DELAY			;
		RL	A			;
		DJNZ	R1, LEFT		;
		MOV	R1, #07H		;
		MOV	A, #10000000B	;
RIGHT:	MOV	P0, A			;
		ACALL	DELAY			;
		RR 	A			;
		DJNZ	R1, RIGHT		;
		AJMP	START			;

DELAY:	MOV	R6, #250		;
DL1:		MOV	R7, #200		;
DL2:		DJNZ	R7, DL2		;
		DJNZ	R6, DL1		;
		RET				;

		END				;
