#include <stdio.h>

const int N = 1010;
int n, m, q;
int a[N][N], b[N][N];

void insert(int x1, int y1, int x2, int y2, int c) {
    b[x1][y1] += c; // 插入操作
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y1] -= c;
    b[x2 + 1][y2 + 1] += c;
    return ;
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for(int i = 1; i <= n; i++) { 
        for(int j = 1; j <= m; j ++) {
            // 这里切记都是从1开始！！！
            scanf("%d", &a[i][j]);
            insert(i, j, i, j, a[i][j]);
            // 将a初始状态视为全为0；
            // 扫描完就插入，简化操作
            // 不用再考虑b的构造了
        }
    }
    
    // 处理题目要求的插入
    for(int i = 0; i < q; i++) {
        int x1, y1, x2, y2, c;
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
        insert(x1, y1, x2, y2, c);
    }
    
    // 还原a, 并输出
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            // 牢记， 当b是a的差分数组时，a就是b的前缀和数组
            a[i][j] = b[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    
    
    return 0;
}

