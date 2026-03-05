#include <stdio.h>

const int N = 1e5 + 10;
int n, m;
int hp[N]; // hp 0存储的是堆的大小

void down(int x) {
    int t = x;
    if(x * 2 <= hp[0] && hp[x * 2] < hp[t]) t = x * 2;
    if(x * 2 + 1 <= hp[0] && hp[x * 2 + 1] < hp[t]) t = x * 2 + 1;
    // 这里一定要注意， < hp[0]而不是n！我们的堆的大小是在变化的！！
    if(t != x) {
        int tmp = hp[x]; hp[x] = hp[t]; hp[t] = tmp;
        down(t);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &hp[i]);
    hp[0] = n;
    // 线性建堆
    for(int i = n / 2; i >= 1; i --) down(i);
    
    for(int i = 0; i < m; i++) {
        printf("%d ", hp[1]);
        hp[1] = hp[hp[0] --]; down(1);
    }
    return 0;
}


