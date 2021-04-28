;
; 配合"8個LED(共陰)實習板"
;     P0所接的8個LED(初始狀態:最左2個亮；其餘6個LED熄著),並進行右旋的變化
;

	MOV	A,#11000000B
START:
	MOV	P0,A

	ACALL	DELAY100MS
	RR	A
	SJMP	START

	include delay.inc

	END
