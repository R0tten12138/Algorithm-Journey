#include <stdio.h>
#include <string.h>

typedef long long LL;
const int N = 1e5 + 10;
int n;
int stk[N], tt = -1;

void push(int x) { // ≤Â»Î
    stk[++ tt] = x;
    return ;
}

void pop() { // µØ≥ˆ
    tt --;
    return ;
}

int empty() { // ≈–ø’
    return tt == -1;
}

int query() { // ≤È—Ø’ª∂•
    return stk[tt];
}

int main() {
    scanf("%d", &n);
    char in[10];
    int x;
    for(int i = 0; i < n; i++) {
        scanf("%s", in);
        if(strcmp(in, "push") == 0) {
            scanf("%d", &x);
            push(x);
        } else if(strcmp(in, "pop") == 0) {
            pop();
        } else if(strcmp(in, "empty") == 0) {
            if(empty()) printf("YES\n");
            else printf("NO\n");
        } else {
            printf("%d\n", query());
        }
        
        
    }
    return 0;
}

