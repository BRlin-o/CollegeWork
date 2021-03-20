/********* 3_18A.c***指標應用範例*********
*動作：由RAM位址0x10以後填入計數值
*******************************************/
main() 
{
    unsigned char  i=1;     //定義計數變數
    unsigned char  *point;  //定義指標變數
    point=0x10; //設定RAM開始位址
 loop:
    *point++=i; //填入計數值到RAM內，RAM位址遞加
    i++;        //計數值遞加 
   goto loop;
}