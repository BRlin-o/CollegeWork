#include <stdio.h>
#include <string.h>

char  *str;
int DEBUG = 1;

char* run(int index){
    if(str[index] == '\0'){
        return "";
    }
    char *sstr = run(index+1);
    if(str[index] == ' '){
        //if(DEBUG){
        //    printf("%s", sstr);
        //}
        int i=0;
        while(sstr[i] != '\0'){
            printf("%c", sstr[i++]);
        }
        //printf("%s", sstr);
        return " ";
    }else{
        if(DEBUG){
            printf("%s", str[index] + sstr);
        }
        return str[index] + sstr;
    }
}

int main(){
    str =  "hello world";
    run(0);
    return 0;
}
