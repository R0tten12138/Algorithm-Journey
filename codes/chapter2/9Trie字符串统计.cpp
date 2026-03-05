#include <stdio.h>

const int N =1e5 + 10;
// 注意，这里N的大小应该是所有字符串的总长度
// 单条字符串最大长度*总操作次数
int n;
int SON[N][26], cnt[N];
int idx;
// 我们的0号位既作为root也作为NULL
//因此有效值是从1开始的，应该是 ++ idx
void insert(char *exp) {
    int p = 0;
    for(int i = 0; exp[i]; i++) {
        int num = exp[i] - 'a';
        if(SON[p][num] == 0) SON[p][num] = ++ idx;
        // 这里注意，只有当前路径不存在的时候我们才需要创建新的
        p = SON[p][num];
    }
    cnt[p] ++;
    return ;
}

int find(char *exp) {
    int p = 0;
    for(int i = 0; exp[i]; i++) {
        int num = exp[i] - 'a';
        if(SON[p][num] == 0) return 0;
        // 不存在的时候直接return 而不是 break！
        p = SON[p][num];
    }
    return cnt[p];
}

int main() {
    scanf("%d", &n);
    char exp[100000 + 10], choose[5];
    for(int i = 0 ; i < n; i++) {
        scanf("%s", choose);
        scanf("%s", exp);
        
        if(choose[0] == 'I') insert(exp);
        else printf("%d\n", find(exp));
    }
    
    return 0;
}

