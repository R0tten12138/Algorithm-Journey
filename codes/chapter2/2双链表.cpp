#include <stdio.h>
#include <string.h>

const int N = 1e5 + 10;
int n;
int e[N], L[N], R[N], idx;
// e存储val，L存储左指针，R存储右指针，idx表示当前位置

// 初始化
void init() {
    // 0 表示左端点，1表示右端点
    // 0点右侧是1点， 1点左侧是0点
    R[0] = 1; L[1] = 0;
    idx = 2; // 0 1已经使用过了
    // 此时R[0]表示最左端的结点
    // L[1]表示最右端的结点
    
} 

//  插入
void add_to_right(int k, int x) {
    e[idx] = x;
    R[idx] = R[k]; L[idx] = k; // 新结点调整指向
    L[R[k]] = idx; // k右结点的左连到新节点
    R[k] = idx; // k结点右连到新节点, 这两步不能颠倒
    idx ++;
    return ;
}

void add_to_left(int k, int x) {
    e[idx] = x;
    R[idx] = k; L[idx] = L[k];
    R[L[k]] = idx; // k结点的左节点的右侧连到新节点
    L[k] = idx; // k结点左侧连接到新结点 
    idx ++;
    return ;
}

void add_L(int x) {
    e[idx] = x;
    R[idx] = R[0];
    L[idx] = 0; // 先把新结点的线接好
    L[R[0]] = idx; // 原最左端结点的左侧连到新结点
    R[0] = idx; // 更新虚拟右结点
    idx ++;
    return ; 
}

void add_R(int x) {
    e[idx] = x;
    L[idx] = L[1];
    R[idx] = 1;
    R[L[1]] = idx; // 原最右侧结点的有段连接到新结点
    L[1] = idx; // 更新虚拟左节点
    idx ++;
    return ;
}


void del(int k) {
    R[L[k]] = R[k]; // 左边结点的右侧连接到待删除的k的右侧
    L[R[k]] = L[k]; // 右边结点的左侧连接到待删除的k的左侧
    return ;
}

int main() {
    init();
    scanf("%d", &n);
    int k, x;
    char in[10];
    for(int i = 0; i < n; i++) {
        scanf("%s", in);
        if(strcmp(in, "R") == 0) {
            // 字符串的比较要用strcmo，不能直接 == ！
            scanf("%d", &x);
            add_R(x);
        } else if(strcmp(in, "L") == 0) {
            scanf("%d", &x);
            add_L(x);
        } else if(strcmp(in, "IR") == 0) {
            scanf("%d%d", &k, &x);
            add_to_right(k + 1, x);
        // 这里要注意，之前我们自己定义了一个head，我们的idx从0开始
        // 所以我们使用k的时候是 - 1
        // 但是现在我们已经占用了0 1，idx从2开始，而我们题目中的k是
        // 从1开始的，因此我们要 + 1而不是 - 1 ！
        } else if(strcmp(in, "IL") == 0) {
            scanf("%d%d", &k, &x);
            add_to_left(k + 1, x);
        } else {
            scanf("%d", &k);
            del(k + 1);
        }
    }
    // 这里i不能从0开始，0是虚拟左结点，R[0]才是左侧第一个有意义的结点
    for(int i = R[0]; i != 1; i = R[i]) printf("%d ", e[i]);
    return 0;
}

