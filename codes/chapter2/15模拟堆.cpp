#include <stdio.h>
#include <string.h>


const int N = 1e5 + 10;
int n;
int h[N], ph[N], hp[N];
// ph[i] 第i次插入的数在堆中的下标
// hp[i] 堆中下标为i的数是第几次插入的
// h[0] 存储堆的大小

void heap_swap(int a, int b) { 
    // 注意，这里传入的是堆中的下标
    int tmp;
    tmp = ph[hp[a]]; ph[hp[a]] = ph[hp[b]]; ph[hp[b]] = tmp;
    tmp = hp[a]; hp[a] = hp[b]; hp[b] = tmp;
    tmp = h[a]; h[a] = h[b]; h[b] = tmp;
    return ;
}

void down(int x) { // 下调操作
    int t = x;
    if(x * 2 <= h[0] && h[x * 2] < h[t]) t = x * 2;
    if(x * 2 + 1 <= h[0] && h[x * 2 + 1] < h[t]) t = x * 2 + 1;
    if(t != x) {
        heap_swap(x, t);
        down(t);
    }
    return ;
}

void up(int x) { // 上调操作
    while(x / 2 >= 1 && h[x / 2] > h[x]) {
        heap_swap(x, x / 2);
        x /= 2;
    }
    return ;
}

void insert(int x, int k) { // 插入
    h[++ h[0]] = x;
    ph[k] = h[0];
    hp[h[0]] = k; // 把数放到堆尾，并更新相应的数据
    
    up(h[0]); // 上调
    return ;
}

int printfM() { // 返回最小值
    return h[1];
}

void delM() { // 删除最小值
    heap_swap(1, h[0]);
    h[0] --; // 末尾数据覆盖堆顶
    
    down(1); // 下调
    return ;
}

void del(int k) { // 删除第k次插入的数
    int pos = ph[k];
    // 这里要注意，我们swap完之后 ph[k] = h[0]
    // 我们必须记录删除前第k次插入的数在堆中的位置！！！！！！！！！！！！
    heap_swap(h[0], ph[k]); // 末尾数据和要删除的数据交换
    h[0] --;
    down(pos); up(pos);
    return ;
}

void change(int k, int x) { // 更改第k次插入的数据的值
    h[ph[k]] = x;
    down(ph[k]); up(ph[k]);
    return ;
}




int main() {
    scanf("%d", &n);
    char choose[5]; int x, y;
    int k = 0;
    for(int i = 0; i < n; i++) {
        scanf("%s", choose);
        
        if(strcmp(choose, "I") == 0) {
            scanf("%d", &x); 
            insert(x, ++ k);
        } else if(strcmp(choose, "PM") == 0) {
            printf("%d\n", printfM());
        } else if(strcmp(choose, "DM") == 0) {
            delM();
        } else if(strcmp(choose, "D") == 0) {
            scanf("%d", &x);
            del(x);
        } else {
            scanf("%d%d", &x, &y);
            change(x, y);
        }
    }
    
    
    return 0;
}