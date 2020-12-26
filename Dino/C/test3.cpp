#include <iostream>
#include <string.h>

using namespace std;

char  *str;
int DEBUG = 1;
string lastChar = "";

string run(int index){
    if(str[index] == '\0' || str[index] == '!' || str[index] == '?' || str[index] == '.'){
        lastChar = str[index];
        return "";
    }
    string sstr = run(index+1);
    if(str[index] == ' '){
        cout<<sstr<<" ";
        return "";
    }else{
        return str[index] + sstr;
    }
}

int main(){
    str =  "you can cage a swallow can't you?";
    cout<<run(0)<<lastChar;

    return 0;
}
