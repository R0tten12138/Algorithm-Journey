#include <stdio.h>

const int N = 1e6 + 10;
int a[N], b[N];
int n, m;

void insert(int l, int r, int c) {  // 插入
    b[l] += c; b[r + 1] -= c;
    return ;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    // 这里a[0] == 0，所以不用再特殊处理b1
    // for(int i = 1; i <= n; i++) b[i] = a[i] - a[i - 1];
    
    // 这里实际使用的求取b的方法是：
    // 把a数组视为由一个全为0的数组插入成的数组
    // 第i次在[i, i] 插入a[i]
    // 这样就统一操作了
    for(int i = 1; i <= n; i++) insert(i, i, a[i]);
    
    for(int i = 0; i < m; i++) {
        int l, r, c;
        scanf("%d %d %d", &l, &r, &c);
        insert(l, r, c);
    }
    
    // 还原a，a为现在b的前缀和数组
    for(int i = 1; i <= n; i++) a[i] = a[i - 1] + b[i];
    for(int i = 1; i <= n; i++) printf("%d ", a[i]);
    
    return 0;
}

