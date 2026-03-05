#include <stdio.h>
typedef long long LL;
const int N = 1e5 + 10;
int n;
int stk[N], tt = -1;
int arr[N];

void push(int x) { // 插入
    stk[++ tt] = x;
    return ;
}

void pop() { // 弹出
    tt --;
    return ;
}

int empty() { // 判空
    return tt == -1;
}

int query() { // 查询栈顶
    return stk[tt];
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) scanf("%d", &arr[i]);
    for(int i = 0; i < n; i++) {
        // while(!empty() && arr[query()] >= arr[i]) pop();
        // 如果是输出下标，那我们栈中就存下标，元素直接到arr中取
        // 如果栈中存数，我们还得再额外存这个数对应的下标，浪费空间
        while(!empty() && query() >= arr[i]) pop();
        // 始终保证栈中元素从栈底到栈顶是单调递增的
        if(empty()) printf("-1 ");
        else printf("%d ", query());
        push(arr[i]);
    }
    
    return 0;
}

