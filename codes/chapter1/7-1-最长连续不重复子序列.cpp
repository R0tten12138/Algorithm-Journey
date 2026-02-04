#include <stdio.h>
const int N = 1e5 + 10;
int A[N], NUM[N];
int n;

/*
用NUM维护A中窗口[j, i]间每个数出现的次数
i负责遍历，每一次都把当前走到的数存到NUM中
j移动逻辑：当这一论循环的i使NUM中A[i]出现的次数 > 1时
    说明又重复了，那j就不断往前走，直到从后面走到这个
    重复的数，消除重复，j往前走，对应的数的NUM就要 --
*/

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n ; i++) scanf("%d", &A[i]);
    
    int max = 0;
    for(int i = 0, j = 0; i < n; i++) {
        // j移动逻辑
        NUM[ A[i] ] += 1;
        while(NUM[ A[i] ] > 1) NUM[ A[j ++] ] -= 1;
        // 具体题目逻辑
        if(i - j + 1 > max) max = i - j + 1;
    }
    printf("%d", max);
    return 0;
}

