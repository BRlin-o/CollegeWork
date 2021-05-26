        ORG     0000H
START:  MOV     DPTR, #TABLE

        MOV     R3, #10
LOOP:   MOV     R2, #100
SCAN:   ACALL   SCAN1
        DJNZ    R2, SCAN
        INC     DPTR
        INC     DPTR
        INC     DPTR
        INC     DPTR
        INC     DPTR
        DJNZ    R3, LOOP
        AJMP    START


SCAN1:  MOV     R1, #00H
        MOV     R5, #1111110B
        MOV     R4, #05

LOOP1:  MOV     A, R1
        MOVC    A, @A+DPTR

        MOV     P0, A
        MOV     P1, R5

        MOV     R6, #5
DL1:    MOV     R7, #200
DL2:    DJNZ    R7, DL2
        DJNZ    R6, DL1

        ORL     P1, #11111111B

        MOV     A, R5
        RL      A
        MOV     R5, A
        INC     R1
        DJNZ    R4, LOOP1
        RET

TABLE:  DB      00111110B
        DB      01010001B
        DB      01001001B
        DB      01000101B
        DB      00111110B
; 0
        DB      00000000B
        DB      01000010B
        DB      01111111B
        DB      01000000B
        DB      00000000B
;1
        DB      01000010B
        DB      01100001B
        DB      01010001B
        DB      01001001B
        DB      01000110B
;2
        DB      00100001B
        DB      01000001B
        DB      01001001B
        DB      01001101B
        DB      00110011B
;3
        DB      00011000B
        DB      00010100B
        DB      00010010B
        DB      01111111B
        DB      00010000B
;4
        DB      00100111B
        DB      01000101B
        DB      01000101B
        DB      01000101B
        DB      00111001B
;5
        DB      00111100B
        DB      01001010B
        DB      01001001B
        DB      01001001B
        DB      00110000B
;6
        DB      00000001B
        DB      00000001B
        DB      01111001B
        DB      00000101B
        DB      00000011B
;7
        DB      00110110B
        DB      01001001B
        DB      01001001B
        DB      01001001B
        DB      00110110B
;8
        DB      00000110B
        DB      01001001B
        DB      01001001B
        DB      00101001B
        DB      00011110B
;9

        END



        