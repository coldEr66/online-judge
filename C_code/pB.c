#include <stdio.h>
#include <string.h>


char item[15][15], ans[15][15];
int prior[15], c[15];
int id[15], ok[15];
int A,n;
void SORT() {
    for (int i=0;i<n;++i) {
        for (int j=i;j<n;++j) {
            if (prior[id[j]] > prior[id[i]]) {
                int tmp = id[i];
                id[i] = id[j];
                id[j] = tmp;
            }
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&A,&n);
        for (int i=0;i<n;++i) {
            scanf("%d %d %s",&prior[i],&c[i],item[i]);
            id[i] = i;
            ok[i] = 0;
        }
        SORT();
        int tA = A, idx = 0;
        for (int i=0;i<n;++i) {
            int cur = id[i];
            if (tA > c[cur]) {
                ok[cur] = 1;
                tA -= c[cur];
                strcpy(ans[idx++],item[cur]);
            }
        }
        printf("%d",A - tA);
        for (int i=0;i<idx;++i) {
            for (int j=i;j<idx;++j) {
                if (strcmp(ans[i],ans[j]) > 0) {
                    char tmp[15];
                    strcpy(tmp,ans[i]);
                    strcpy(ans[i],ans[j]);
                    strcpy(ans[j],tmp);
                }
            }
        }
        for (int i=0;i<idx;++i) {
            printf(" %s",ans[i]);
        }
        printf("\n");
    }
}
