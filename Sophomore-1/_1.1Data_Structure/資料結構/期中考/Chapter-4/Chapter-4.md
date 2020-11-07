## Chapter-4
ch4_1_改.cpp
```c
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#define N 100

int queue[N];
int front = N-1, rear = N-1;
bool tag = 0;

bool isEmpty(){
    return front == rear;
}

bool isfull(){
    return tag==0 ? false : (rear+1)%N==front;
}

void add(int d){
    tag = 1;
    if(isfull() == false){
        printf("qeueu is full!");
        exit(1);
    }
    queue[rear=(rear+1)%N] = d;
}

int pop(){
    tag = 0;
    if(isfull() == false){
        printf("queue is empty!");
        exit(1);
    }
    return queue[front=(front+1)%N];
}

void list(){
    int index = front;
    while(index < rear ? true : (index != rear)&&(index < rear+N))printf("%d ", queue[index=(index+1)%N]);
    //while(index < rear || ((index+1)%N)<((rear+1)%N))printf("%d ", queue[index=(index+1)%N]);
    printf("\n");
}

void _head(){
    if(isEmpty() == false){
        printf("%d\n", queue[(front+1)%N]);
    }
}

void _tail(){
    if(isEmpty() == false){
        printf("%d\n", queue[rear]);
    }
}

int main(){
    int d, loop=1;
    char input[5];

    printf("***Circular Queue Array***\n");
    printf("u can input command in following: list, head, tail, add, pop, +, -, exit\n");

    do{
        printf("==>");
        scanf("%s", &input);
        if(strcmp(input, "list")==0){
            list();
        }else if(strcmp(input, "head")==0){
            _head();
        }else if(strcmp(input, "tail")==0){
            _tail();
        }else if(strcmp(input, "add")==0){
            printf("please input the number: ");
            scanf("%d", &d);
            add(d);
        }else if(strcmp(input, "pop")==0){
            if(isEmpty()){
                printf("stack is empty!");
                continue;
            }
            printf("%d\n", pop());
        }else if(strcmp(input, "+")==0){
            if((rear > front ? rear-front : rear+N-front) < 2){
                printf("Error: data Insufficient, can't do '+'.\n");
                continue;
            }
            add(pop() + pop());
        }else if(strcmp(input, "-")==0){
            if((rear > front ? rear-front : rear+N-front) < 2){
                printf("Error: data Insufficient, can't do '-'.\n");
                continue;
            }
            add(pop() - pop());
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
### 本章練習
1. (1) 何謂佇列？ 先進先出的列隊
(2)何謂環狀佇列？ 一個佇列的頭與尾相接所形成的環



### 陣列製作佇列要點
- 必須將佇列視為環狀佇列
- 新資料由環狀佇列尾端加入
- 刪除資料是取出環狀佇列前端元素
- 定義變數front表示前端元素的前一個位置，而rear則表示目前尾端元素的位置
- 環狀佇列是否為空(front == rear)
- 環狀佇列是否已滿((front+1)%N == rear)