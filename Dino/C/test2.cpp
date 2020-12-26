#include <stdio.h>
#include <string.h>

int spaceNum(char *str){
    int index = 1;
    for(int i=0;str[i]!='\0';++i)index += str[i] == ' ';
    return index;

}

void lastIndex(char *dest, char *str, char *sym){
    int i=0;
    for(;str[i]!='\0' && str[i]!='.' && str[i]!='!' && str[i]!='?';++i);
    //printf("%c", str[i]);
    sym[0] = str[i];
    strncpy(dest, str, i);
    printf("dest = %s : %d\nstr = %s : %d\n", dest, strlen(dest), str, strlen(str));
}

int main()
{
  char O_str[999] = "you can cage a swallow can't your?";
  char str[999], sym[1];
  lastIndex(str, O_str, sym);


  char *delim = " ";
  int size = spaceNum(str), index = 0;
  char *arr[size];
  printf("O_str\t- %s : %d\nstr\t- %s : %d\n\tsize: %d\n", O_str, strlen(O_str), str, strlen(str), size);
  //return 0;


  char * pch;
  pch = strtok(str,delim);
  while (pch != NULL)
  {
    arr[index++] = pch;
    printf ("%s\n",pch);
    pch = strtok (NULL, delim);
  }
  for(int i=size-1;i>=0;--i){
    printf ("%s",arr[i]);
    if(i>0)printf(" ");
    else printf("%c", sym[0]);
  }
  return 0;
}
