#include <stdio.h>

const int N = 1010;
int a[N][N], s[N][N];
int n, m, q;


int main() {
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 1; i <= n; i++) { // 注意，(1, 1)开始！
        for(int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
    }
    // 处理前缀和
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++){
            s[i][j] = a[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    //输出
    for(int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1]);
    }
}

