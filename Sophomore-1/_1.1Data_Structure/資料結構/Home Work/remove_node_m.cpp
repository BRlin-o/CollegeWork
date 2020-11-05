#include<bits/stdc++.h>

using namespace std;

struct node{ //單向串列結構
  int data;
  struct node *next;
};

void printList(node* list){
    while(list != NULL){
        cout<<list->data<<" ";
        list = list->next;
    }
}

node* newNode(int data){
    node *nd;
    nd = (node *)malloc(sizeof(node));
    nd->data = data;
    nd->next = NULL;
    return nd;
}

node* REMOVE_DATA_5(node* list){
  node *p, *start;
  p = start = list;
  while(list != NULL){
      if(list->data == 5){
          p->next = list->next;
          list = list->next;
          continue;
      }
      p = list;
      list = list->next;
  }
  if(start->data == 5){
      start = start->next;
  }
  return start;
}

node* REMOVE_M(node* list, int m){
   node *start;
   start = list;
   while(--m > 1){
       list = list->next;
   }
   list->next = list->next->next;
   return start;
}

int main(){
    node *list, *p;
    list = newNode(5);      //1
    p = list;
    p->next = newNode(5);   //2
    p = p->next;
    p->next = newNode(7);   //3
    p = p->next;
    p->next = newNode(10);  //4
    p = p->next;
    p->next = newNode(6);   //5
    p = p->next;
    printList(list);
    cout<<'\n';
    //list = REMOVE_M(list, 3);
    list = REMOVE_DATA_5(list);
    printList(list);
}
