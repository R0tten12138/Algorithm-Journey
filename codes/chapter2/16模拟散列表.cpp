// 拉链法
#include <stdio.h>
#include <string.h>

const int N = 1e5 + 3; // 最好直接取成质数
int n;
int h[N], e[N], ne[N], idx;
// h[i] 存储哈希值为i的对应链表的头节点
// e[i] 存储每个点的实际值（插入查找的x的实际值）
// ne[i] 存储每个结点的下一个结点
// idx 用来给每个结点分配唯一的下标
// 注意，这里h中不存值，只存头指针

void insert(int x) {
    int hs = (x % N + N) % N; // 获取哈希值
    e[idx] = x; ne[idx] = h[hs]; h[hs] = idx;
    // 存结点的实际值、头插法插入到h[hs]对应的链表中
    idx ++;
    return ;
}

int find(int x) {
    int hs = (x % N + N) % N;
    // 遍历当前哈希值对应的链表
    for(int i = h[hs]; i != -1; i = ne[i]) {
        if(e[i] == x) return 1;
    }
    return 0;
}


int main() {
    scanf("%d", &n);
    // 初始化，一开始所有哈希值链表头指针都指向空（-1）
    memset(h, - 1, sizeof(h));
    
    char choose[5]; int x;
    for(int i = 0; i < n; i ++) {
        scanf("%s", choose);
        if(choose[0] == 'I') {
            scanf("%d", &x);
            insert(x);
        } else {
            scanf("%d", &x);
            if(find(x)) printf("Yes\n");
            else printf("No\n");
        }
    }
    
    return 0;
}




// 开放寻址法
#include <stdio.h>
#include <string.h>

const int N = 2e5 + 3, null = 0x3f3f3f3f;
int n;
int h[N];

void insert(int x) {
    int hs = (x % N + N) % N;
    while(h[hs] != null) {
        hs += 1;
        if(hs == N) hs = 0;
    };
    // 也可写成 hs = (hs + 1) % N,但是影响效率
    // 这里 % N，当hs达到模长时会自动回0
    h[hs] = x;
    return ;
}

int find(int x) {
    int hs = (x % N + N) % N;
    while(1) {
    // 因为N开的是二倍的数据量，所以这个循环一定会停下来的
    // 一定会存在空位
        if(h[hs] == null) return 0;
        if(h[hs] == x) return 1;
        hs += 1;
        if(hs == N) hs = 0;
    }
    return 0;
}



int main() {
    scanf("%d", &n);
    // 初始化，一开始所有哈希值对应的数都设置为null
    // 0x3f3f3f3f超出题目中的数据范围，所以可被视为null
    memset(h, 0x3f, sizeof(h));
    
    char choose[5]; int x;
    for(int i = 0; i < n; i ++) {
        scanf("%s", choose);
        if(choose[0] == 'I') {
            scanf("%d", &x);
            insert(x);
        } else {
            scanf("%d", &x);
            if(find(x)) printf("Yes\n");
            else printf("No\n");
        }
    }
    
    return 0;
}