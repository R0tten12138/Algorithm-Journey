#include <stdio.h>
const int N = 1e6 + 10;
int n;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int x, sum = 0;
        scanf("%d", &x);
        while(x) {
            if(x & 1) sum += 1;
            x = x >> 1;
        }
        printf("%d ", sum);
    }
    
    return 0;
}


// 优化
#include <stdio.h>
const int N = 1e6 + 10;
int n;

int lowbit(int x) {
    return x & (-x);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, sum = 0;
        scanf("%d", &x);
        while (x) {
            // 当x > 0 时，每一次减去x的最低位1
            // 这样减的次数就是x二进制表示中1的个数
            x -= lowbit(x);
            sum++;
        }
        printf("%d ", sum);
    }

    return 0;
}