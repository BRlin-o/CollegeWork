## Chapter-3

#### 程式ch3_1.c 改
```C
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#define N 100

int stack[N];
int top = -1;

void push(int d){
    if(top == N-1){
        printf("stack is overflow!");
        exit(1);
    }
    stack[++top] = d;
}

int pop(){
    if(top == -1){
        printf("stack is empty!");
        exit(1);
    }
    return stack[top--];
}

void list(){
    int index = -1;
    while((++index) <= top && index < N)printf("%d ", stack[index]);
    printf("\n");
}

void _top(){
    if(top > -1){
        printf("%d\n", stack[top]);
    }
}

int main(){
    int d, loop=1;
    char input[5];

    printf("***Stack Array***\n");
    printf("u can input command in following: list, top, push, pop, +, -, exit\n");

    do{
        printf("==>");
        scanf("%s", &input);
        if(strcmp(input, "list")==0){
            list();
        }else if(strcmp(input, "top")==0){
            _top();
        }else if(strcmp(input, "push")==0){
            printf("please input the number: ");
            scanf("%d", &d);
            push(d);
        }else if(strcmp(input, "pop")==0){
            if(top == -1){
                printf("stack is empty!");
                continue;
            }
            printf("%d\n", pop());
        }else if(strcmp(input, "+")==0){
            if(top < 1){
                printf("Error: data Insufficient, can't do '+'.\n");
                continue;
            }
            push(pop() + pop());
        }else if(strcmp(input, "-")==0){
            if(top < 1){
                printf("Error: data Insufficient, can't do '-'.\n");
                continue;
            }
            push(pop() - pop());
        }else if(strcmp(input, "exit")==0){
            loop = 0;
        }else{
            printf("input error!!!\n");
        }
    }while(loop);
    printf("B B!\n");
    return 0;
}
```

### 後序式的優點
- 運算式中不必使用誇號
- 運算符沒有優先權，一切按照運算符排序計算