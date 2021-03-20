#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *p[10005];
int main(){
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;++i) {
        int k;
        scanf("%d",&k);
        p[i] = (int*)malloc(sizeof(int) * (k+1));
        for (int j=0;j<k;++j) {
            int cur;
            scanf("%d",&p[i][j]);
        }
    }
    int q;
    scanf("%d",&q);
    while (q--) {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d\n",p[a][b]);
    }
}
