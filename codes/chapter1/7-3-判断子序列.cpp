#include <stdio.h>
const int N = 1e5 + 10;
int A[N], B[N];
int n, m;
/*
a b指向A B
b负责遍历
a移动逻辑：B[b] == A[a];
*/

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &A[i]);
    for(int i = 0; i < m; i++) scanf("%d", &B[i]);
    
    int a = 0, b = 0;
    while(b < m && a < n) { // b走完或a走完，结束循环
        if(A[a] == B[b]) a ++;
        b ++;
    }
    if(a == n) printf("Yes");
    else printf("No");
    
    return 0;
}


