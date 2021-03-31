/*********** 3_18.c***指標應用範例*********
*動作：由RAM位址0x10以後填入資料0xFF
*******************************************/
main() 
{
    unsigned char *point; //定義指標變數
    point=0x10;     //設定RAM開始位址
 loop:
    *point++=0xFF; //填入資料到RAM內，RAM位址遞加
     goto loop;
}