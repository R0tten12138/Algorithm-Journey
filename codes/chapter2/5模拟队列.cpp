#include <stdio.h>
#include <string.h>

const int N = 1e5 + 10;
int n;
int q[N], hh = 0, tt = -1;

void push(int x) { // 入队操作
    q[++ tt] = x; 
    return ;
}

void pop() { // 出队操作
    hh ++;
    return ;
}

int empty() { // 判空
    return hh > tt;
}

int query() { // 查询队头元素
    return q[hh];
}

int main() {
    scanf("%d", &n);
    char in[10]; int x;
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

