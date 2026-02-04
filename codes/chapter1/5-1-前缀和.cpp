#include <stdio.h>

const int N = 1e6 + 10;
int a[N], s[N];
int n, m;

int main() {
    scanf("%d %d", &n, &m);
    // 这里注意，从1开始！
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    // 计算前缀和数组
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    // 输出
    for(int i = 0; i < m; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]);
    }
    
    return 0;
}

