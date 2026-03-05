#include <stdio.h>
#include <string.h>

const int N = 1e5 + 10;
int n, m;
int P[N], cnt[N]; // 记录祖宗节点和所在集合点的数量

int find(int x) {
    if(P[x] != x) P[x] = find(P[x]);
    return P[x];
}

void merge(int x, int y) {
    int a = find(x), b = find(y);
    if(a != b) {
        P[a] = b;
        cnt[b] += cnt[a];
        // a b不在一个集合的时候才更改cnt
    }
    return ;
}


int main() {
    scanf("%d%d", &n, &m);
    // 初始化
    for(int i = 0; i < n; i++) {
        P[i] = i;
        cnt[i] = 1;
    }
        
    char choose[5];
    int x, y;
    
    for(int i = 0; i < m; i++) {
        scanf("%s", choose);
        if(strcmp(choose, "C") == 0) {
            scanf("%d%d", &x, &y);
            merge(x, y);
        } else if(strcmp(choose, "Q1") == 0) {
            scanf("%d%d", &x, &y);
            if(find(x) == find(y)) printf("Yes\n");
            else printf("No\n");
        } else {
            scanf("%d", &x);
            printf("%d\n", cnt[find(x)]);
        }
    }
    
    
    return 0;
}

