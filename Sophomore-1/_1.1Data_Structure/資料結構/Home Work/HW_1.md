## 資料結構作業二

#### 一維陣列A有n筆資料
> 取得陣列A中元素索引i的資料時，其時間複雜度是?請說明
> `
> O(1)，因為知道其所引，所以可以直接依索引取值
> `
> 取得陣列A中元素資料為7999時，其時間複雜度是?請說明
> `
> O(n)，因為在最多的情況下，需要對所有資料(n筆)做驗證，才得以得出答案
> `
---
## 資料結構作業三

#### 單向鏈接串列複雜度分析(假設串列長度為 n)，先寫虛擬碼，在分析
```c++
struct node{ //單向串列結構
  int data;
  struct node *next;
}
```
> 1. 刪除資料內容為5的節點的時間複雜度是?
> > O(n)
> ```c++
> node* REMOVE_DATA_5(node* list){
>   node *p, *start;
>   p = start = list;
>   while(list != NULL){
>       if(list->data == 5){
>           p->next = list->next;
>           list = list->next;
>           continue;
>       }
>       p = list;
>       list = list->next;
>   }
>   if(start->data == 5){
>       start = start->next;
>   }
>   return start;
> }
> ```
> ---
> 2. 刪除串列第m筆資料的時間複雜度為
> > O(m);
> ```c++
> node* REMOVE_M(node* list, int m){
>   node *start;
>   start = list;
>   while(--m > 1){
>       list = list->next;
>   }
>   list->next = list->next->next;
>   return start;
> }
> ```
> ---
> 3. 已知節點p，刪除節點p下一節點的時間複雜度是?
> > O(1)
> ```c++
> void REMOVE_NEXT(node* p){
>   free(p->next);
> }
> ```