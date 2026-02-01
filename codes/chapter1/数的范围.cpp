#include <stdio.h>

const int N = 1e6 + 10;
int q[N];
int n, k;
// 如果数组中不存在x，那么返回的l就是第一个大于x的下标
int b_search_left(int x, int l, int r) {
    while(l < r) {
        int mid = l + r >> 1;
        if(q[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}
// 如果数组中不存在x，那么返回的l就是最后一个小于x的下标
int b_search_right(int x, int l, int r) {
    while(l < r) {
        int mid = l + r + 1 >> 1;
        if(q[mid] <= x) l = mid;
        else r = mid - 1;
    }
    return l; 
}
/*
x起始位置：满足之后的元素 >= x  左边界：第一个位置，使得该位置及其后面的元素都 ≥ x
x结束位置：满足之前的元素 <= x  右边界：最后一个位置，使得该位置及其前面的元素都 ≤ x
*/

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) scanf("%d", &q[i]);
    for(int i = 0; i < k; i++) {
        int x; scanf("%d", &x);
        int l = b_search_left(x, 0, n - 1), r = b_search_right(x, 0 , n - 1);
        //if(q[l] != x) printf("-1 -1\n");
        printf("%d %d\n", l, r);
    }
}
