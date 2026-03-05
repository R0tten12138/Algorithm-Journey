#include <stdio.h>
#include <math.h>

const int N = 5e4 + 10;
int n, k;
int res = 0;
int P[N], cnt[N]; // 记录父节点和到祖宗结点的距离
/*
cnt [x] % 3 的结果	x 和根节点的关系
0	x 与根节点同类
1	x 吃根节点
2	根节点吃 x
*/
// (cnt[x] - cnt[y]) % 3 == 0 x y同类
// (cnt[x) - cnt[y] - 1) % 3 == 0 x吃y
// 思路：我们把能确定关系的结点放到同一个集合里面


int  find(int x) {
    // 函数定义：返回x的祖宗结点，并路径压缩
    // 压缩完之后，P[x]就是当前集合的root
    // 所以cnt[x] = cnt[x] + cnt[P[x]
    // 逻辑上x到根节点的距离应该是 x到原父结点距离 + 原父结点到根结点距离
    if(P[x] != x) {
        // 第一步：先递归找到P[x]的根节点t，同时完成P[x]的路径压缩和cnt[P[x]]的更新
        int t = find(P[x]);
        // 第二步：此时P[x]已经指向根节点t，cnt[P[x]]是「P[x]到根节点t的最终距离」
        // 所以cnt[x] = x到原父节点P[x]的距离 + 原父节点P[x]到根节点t的距离
        cnt[x] += cnt[P[x]];
        // 第三步：把x的父节点直接指向根节点t，完成x的路径压缩
        P[x] = t;
    }
    return P[x];    
}

/*
当x和y关系未确定时，我们把x集合连接到y集合上
逻辑上来讲，当连接完成之后， x到根节点的距离就是 x到xx + xx到yy，即 cnt[x] + cnt[xx];
场景 1（a=1，x 和 y 同类）：要求(cnt[x] + cnt[xx]) %3 = cnt[y] %3 → 解得cnt[xx] = cnt[y] - cnt[x]；
场景 2（a=2，x 吃 y）：要求(cnt[x] + cnt[xx]) %3 = (cnt[y]+1) %3 → 解得cnt[xx] = cnt[y]+1 - cnt[x]；

*/

int main() {
    scanf("%d%d", &n, &k);
    
    for(int i = 1; i <= n; i++) {
        P[i] = i; cnt[i] = 0;
    } // 编号从1开始的
    
    int a, x, y;
    for(int i = 0; i < k; i++) {
        scanf("%d%d%d", &a, &x, &y);
        if(x > n || y > n) {
            res ++;
            continue;
        } 
        
        int xx = find(x), yy = find(y);
        if(a == 1) {
            if(xx != yy) { // x 和 y的关系还未确定，在a = 1时，说明是同类
                P[xx] = yy;
                cnt[xx] = cnt[y] - cnt[x]; // 如果cnt[xx]因为累计太多爆了
                // 可以把每个cnt都约束在0 1 2三个数
                // cnt[xx] = ((cnt[y] - cnt[x]) % 3 + 3) % 3; 
            } else { // x y关系已经确定，现在就判断是否是同类
                if((cnt[x] - cnt[y]) % 3 != 0) res ++;
            }
        } else {
            if(xx != yy) { // x 和 y的关系还未确定，在a = 2时，说明是x吃y
                P[xx] = yy;
                cnt[xx] = cnt[y] + 1 - cnt[x];
                // cnt[xx] = ((cnt[y] + 1 - cnt[x]) % 3 + 3) % 3;
            } else {
                if((cnt[x] - cnt[y] - 1) % 3 != 0) res ++;
            }
        }
    }
    printf("%d\n", res);
    
    return 0;
}