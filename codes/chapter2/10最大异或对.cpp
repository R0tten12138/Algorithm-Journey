#include <stdio.h>
#include <math.h>


/*
思路：将待存储的数以二进制形式从高位到低位存储
统一存储31位（高位不足的补0）
全部数据存储结束后，再遍历每个数
异或： 0 1 - > 1  else -> 0
从高位开始的原因：高位的影响最大
0-x-1位即使全部为异或1，值仍小于x异或为1的结果

我们从高位开始，对于当前数，如果存储的所有数据中这一位
有和当前位不一样的，那么就走这条道
SON[p][1 - u] != 0,这一位满足异或为1，记录到tmp中
否则，就走 SON[p][u]，这一位异或为0，tmp不更新
（因为我们是录入了完整的31位，所以对于任一结点，子结点要么有要么有1要么有0
一定是可以继续往下走的
）

维护一个全局MAX，时刻更新
*/
const int N = 1e5 * 32 + 10;
int n;
int SON[N][2];
int idx;
int MAX = 0;
int nums[100010];

void insert(int x) {
    int bin_num[31];
    for(int i = 30 ; i >= 0; i--) {
        bin_num[i] = (x >> (30 - i)) & 1; 
    } // 从高到低存储31位二进制表达
    // 这里用 (x >> (30 - i)) & 1，不用修改x的值就能获取每一位
    
    int p = 0; // 存入到trie树中
    for(int i = 0; i < 31; i++) { // 从高位开始存
        if(SON[p][bin_num[i]] == 0) SON[p][bin_num[i]] = ++ idx;
        p = SON[p][bin_num[i]];    
    }
}

int getRes(int cnt){
    // 这里不使用pow来获取2的k次
    // 因为pow是浮点数运算，效率很低很低
    int res = 1;
    for(int i = 0; i < cnt; i++){
        res *= 2;
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        insert(nums[i]); // 读入数据，存入trie树
    }
    
    for(int i = 0; i < n; i++) {
        int tmp = 0; // 临时tmp
        
        int bin_num[31];
        for(int j = 30; j >= 0; j --) {
            bin_num[j] = (nums[i] >> (30 - j)) & 1;
        } // 获取当前这个数的31位
        
        // 从最高位开始，当前位为u，不断尝试走1-u这条路
        int p = 0;
        for(int j = 0 ; j < 31; j++) {
            int u = bin_num[j];
            if(SON[p][1 - u] != 0) {
                tmp += getRes(30 - j);
                p = SON[p][1 - u];
            } else {
                p = SON[p][u];
            }
        }
        if(tmp > MAX) MAX = tmp; // 维护MAX
    }
    printf("%d", MAX);
    
    
    return 0;
}