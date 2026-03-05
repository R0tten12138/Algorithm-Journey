#include <stdio.h>

const int N = 1e6 + 10;
int n, k;
int arr[N]; // 存储读入的数据
int q1[N], hh1 = 0, tt1 = -1; // 队列内单调递增（这里存的是下标）
int q2[N], hh2 = 0, tt2 = -1; // 单调递减
int MIN[N], MAX[N], idx = 0;

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i ++) scanf("%d", &arr[i]);
    int i = 0, j = 0;
    
    while(j < n) {
        // 首先扩大窗口，处理队列内单调性
        // 这里是从队尾弹出，
        // 满足q1内单调增，这样队头是MIN
        // q2单调减，队头是MAX
        // 这里从队尾弹出而不是队头，只有这样才能保证单调性！
        while(hh1 <= tt1 && arr[q1[tt1]] >= arr[j]) tt1 --;
        while(hh2 <= tt2 && arr[q2[tt2]] <= arr[j]) tt2 --;
        q1[++ tt1] = j; q2[++ tt2] = j;
        j ++;        
        
        // 因为j ++，所以这里是j - i而不是j - i + 1
        // 这里的j是下次要放入的元素
        // j 0 -> n - 1
        if(j - i == k) {
            // 这里表明窗口已经长k，要缩小窗口，下一次窗口才能再次到k
            MIN[idx] = arr[q1[hh1]];
            MAX[idx ++] = arr[q2[hh2]];
            if(q1[hh1] == i) hh1 ++; // 如果缩小的正好是队头，就要弹出
            if(q2[hh2] == i) hh2 ++;
            i ++;
        }
    }
    
    for(int i = 0; i < idx; i++) printf("%d ", MIN[i]); printf("\n");
    for(int i = 0; i < idx; i++) printf("%d ", MAX[i]);
    
    return 0;
}



#include <stdio.h>

const int N = 1e6 + 10;
int n, k;
int arr[N]; // 存储读入的数据
int q1[N], hh1 = 0, tt1 = -1; // 队列内单调递增（这里存的是下标）
int q2[N], hh2 = 0, tt2 = -1; // 单调递减
int MIN[N], MAX[N], idx = 0;

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i ++) scanf("%d", &arr[i]);
    int i = 0, j = -1;
    
    while(j < n - 1) {
        // 首先扩大窗口，处理队列内单调性
        // 这里是从队尾弹出，
        // 满足q1内单调增，这样队头是MIN
        // q2单调减，队头是MAX
        // 这里从队尾弹出而不是队头，只有这样才能保证单调性！
        j ++;
        while(hh1 <= tt1 && arr[q1[tt1]] >= arr[j]) tt1 --;
        while(hh2 <= tt2 && arr[q2[tt2]] <= arr[j]) tt2 --;
        q1[++ tt1] = j; q2[++ tt2] = j;
        
        // 这里的j是这次放入的元素
        // j从-1 -> n - 2
        if(j - i + 1 == k) {
            // 这里表明窗口已经长k，要缩小窗口，下一次窗口才能再次到k
            MIN[idx] = arr[q1[hh1]];
            MAX[idx ++] = arr[q2[hh2]];
            if(q1[hh1] == i) hh1 ++; // 如果缩小的正好是队头，就要弹出
            if(q2[hh2] == i) hh2 ++;
            i ++;
        }
    }
    
    for(int i = 0; i < idx; i++) printf("%d ", MIN[i]); printf("\n");
    for(int i = 0; i < idx; i++) printf("%d ", MAX[i]);
    
    return 0;
}