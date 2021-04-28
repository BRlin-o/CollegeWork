;
; 配合"8個LED(共陰)實習板"
;     P0所接的8個LED(初始狀態:最左2個亮；其餘6個LED熄著),並進行右旋的變化
;
START:	
	MOV	P0, #0FEH		;
	ORG	0000H			;
LOOP:	MOV	P0, #00000000B	;
	MOV	A,P0			;
	RL	A			;
	MOV	P0,A			;

	ACALL	DELAY			;
	MOV	P0, #11111111B	;
	ACALL	DELAY			;
	AJMP	LOOP			;


DELAY:	MOV	R6, #250	;
DL1:		MOV	R7, #200	;
DL2:		DJNZ	R7, DL2	;
		DJNZ	R6, DL1	;
		RET			;

		END			;
