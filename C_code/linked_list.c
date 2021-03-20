#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LL LL; // 把型別"struct LL" 定義成 LL, 所以在這個程式裡宣告型別LL, 都等於是宣告struct LL

struct LL {
    int data;
    LL *nxt;
};

int main(){
    LL *head = NULL;
    LL *back = NULL;
    char ts[105];
    while (scanf("%s",ts)) {
        if (strcmp(ts,"INSERT") == 0) {
            int val;
            scanf("%d",&val);
            if (head == NULL) { // 如果完全沒有節點的話 我們就開新的記憶體給他
                head = (LL*)malloc(sizeof(LL));
                head->data = val;
                head->nxt = NULL;
                back = head;
            }
            else { // 我們把新的東西接在後面
                LL *cur = (LL*)malloc(sizeof(LL));
                cur->data = val; // 改值
                back->nxt = cur; // 把剛剛的back的下一個設為這個新的
                cur->nxt = NULL; // 把這個的下一個設為NULL
                back = cur; // 把這個變成新的back
            }
        }
        if (strcmp(ts,"POP") == 0){
            printf("val = %d\n",head->data);
            head = head->nxt;
        }
    }
}



