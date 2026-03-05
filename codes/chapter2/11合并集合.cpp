#include <stdio.h>
#include <string.h>

const int N = 1e5 + 10;
int n, m;
int P[N]; // parent数组，标记每个数所在集合

int find(int x) {
    // 函数定义：找到x的祖宗结点并进行路径压缩
    if(P[x] != x) P[x] = find(P[x]);
    return P[x];
    //如果x父节点不是root，那么利用函数定义，将父节点
    // 替换为root，并返回父节点
}

void merge(int x, int y) {
    int a = find(x), b = find(y);
    if(a != b) P[a] = b; 
    return ;
}


int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0 ; i < n; i++) P[i] = i;
    // 初始化这一步不能忘，最开始每个元素都是一个单独的集合
    char choose[5];
    int x, y; 
    for(int i = 0; i < m; i ++) {
        scanf("%s", choose);
        // 这里虽然是单个字符，但是我们还是选择读字符串，
        // scanf读字符的时候会读空格和换行符，读字符串会跳过，省事且不容易出错
        if(strcmp(choose, "M") == 0) {
            scanf("%d%d", &x, &y);
            merge(x, y);
        } else {
            scanf("%d%d", &x, &y);
            if(find(x) == find(y)) printf("Yes\n");
            else printf("No\n");
        }
    }
    
    return 0;
}



