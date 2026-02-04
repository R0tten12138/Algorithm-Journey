#include <stdio.h>
const int N = 1e5 + 10;
int A[N], B[N];
int n, m, x;
/*
将a放到A开头， b放到B结尾，
这样A[a] + B[b]的增大只能由a控制
减小只能由b控制，这样就可以单调讨论了
*/
int main() {
    scanf("%d%d%d", &n, &m, &x);
    for(int i = 0; i < n; i++) scanf("%d", &A[i]);
    for(int i = 0; i < m; i++) scanf("%d", &B[i]);
    
    int a = 0, b = m - 1;
    while(a < n) {
        if(A[a] + B[b] < x) a ++;
        else if(A[a] + B[b] > x) b --;
        else break;
    }
    printf("%d %d\n", a, b);
    
    return 0;
}


