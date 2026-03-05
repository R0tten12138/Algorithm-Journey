#include <stdio.h>

// 当我们要快速判断两个字符串是否相等的时候，就可以用这种做法
// 当我们将字符串哈希处理之后，就可以O1的时间判断是否相等了

typedef unsigned long long ULL;
//  用unsigned long long的溢出代替模2^64

const int N = 1e5 + 10;
const int P = 131;

int n, m;
char str[N];
ULL h[N], p[N];
// h[N] 用来存字符串前缀的哈希值, p[N]用来存储p的次方，这样就不用重复计算了

ULL getNum(int l, int r) {
    // 这里需要用到p的k次，因此我们要提前处理出来
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    scanf("%d%d%s", &n, &m, str + 1); // 字符串的编号从1开始
    
    p[0] = 1; // p的0次方为1
    for(int i = 1; i <= n; i++) { // 处理p和h
        p[i] = p[i - 1] * P; 
        h[i] = h[i - 1] * P + str[i]; // 这里字母直接映射为ASCII码
    }
    
    for(int i = 0; i < m; i++) {
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if(getNum(l1, r1) == getNum(l2, r2)) printf("Yes\n");
        else printf("No\n");
    }
    
    
    return 0;
}


