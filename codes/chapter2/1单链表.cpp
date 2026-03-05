#include <stdio.h>

const int N = 1e5 + 10;
int n;
int head, e[N], ne[N], idx;
// head头指针，idx最后一个元素的下标 + 10
// e存储val，ne存储next指针
void init() {  // 初始化
    head = -1;
    idx = 0;
    return ;
}

void add_to_head(int x) {  // 头插
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx ++;
    return ;
}

void add(int k, int x) {  // 中间插入
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx ++;
    return ;
}

void del(int k) {  // 删除 注意，第一个节点删除后head也会变化，需要特判
    if(k == -1) head = ne[head];
    else ne[k] = ne[ne[k]];
    return ;
}

int main() {
    init();
    scanf("%d", &n);
    char c;
    int x, k;
    for(int i = 0; i < n; i++) {
        scanf(" %c", &c); // 这里需要加个空格跳过换行符等内容！！
        if(c == 'H') {  // %c不会自动跳过换行符！！！
            scanf("%d", &x);
            add_to_head(x);
        }
        else if(c == 'D') {
            scanf("%d", &k);
            del(k - 1); // 这里我们k从0开始，所以要 - 1
        }
        else {
            scanf("%d%d", &k, &x);
            add(k - 1, x);
        }
    }
    
    for(int i = head; i != -1; i = ne[i]) printf("%d ", e[i]);
    return 0;
}