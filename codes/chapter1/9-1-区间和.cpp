#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
A存储离散化后插入的结果,PRE为A前缀和
一共需要离散化n + 2m个坐标
离散前的坐标存在alls中，共n + 2m个
通过find把这所有坐标映射到1 - n + 2m + 1
在add的之后根据离散化后的坐标在A中插入
*/

typedef pair<int, int> PII;
// 每个存进来的数都包括 插入位置 插入数据，所以用pair存

const int N = 1e5 * 3 + 10;
// 这里开3倍，是因为插入、查询的坐标都要存

int n, m;
int A[N], PRE[N];
// A存储离散化后的结果，PRE为A前缀和

vector<int> alls; // 存储要离散化的数(这里指插入的坐标)
vector<PII> add, query;  //   插入操作 读取操作

int find(int x) {  // 求取x离散化后的值
    int l = 0, r = alls.size() - 1;
    while(l < r) {
        int mid = l + r >> 1;
        if(alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l + 1;
    // l + 1表明是从1开始映射的
}

int main() {
    cin >> n  >> m;
    for(int i = 0; i < n; i++) {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        alls.push_back(x);
    }
    
    for(int i = 0; i < m; i ++) {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        alls.push_back(l); alls.push_back(r);
    }
    // 现在所有待离散化的下标都存在了alls中
    // 去重
    sort(alls.begin(), alls.end());  // 去重前要排序
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    
    for(int i = 0; i < add.size(); i ++) { // 处理插入
        int x = find(add[i].first);
        A[x] += add[i].second;
    }
    
    // 预处理前缀和
    for(int i = 1; i <= alls.size(); i ++) PRE[i] = PRE[i - 1] + A[i];
    
    for(int i = 0; i < query.size(); i++) { // 处理查询
        int l = find(query[i].first), r = find(query[i].second);
        cout << PRE[r] - PRE[l  -1] << endl;
    }
    return 0;
}


#include <stdio.h>
const int  N = 1e5 + 10;

typedef struct PII {
    int num1, num2;
} PII;
int n, m;
int INDEX[N * 3], index = 0; // 存储所有要离散化的下标
PII ADD[N]; int add = 0; // 存储要插入的值
PII LR[N]; int lr = 0; // 存储查询的左右坐标
int A[N * 3], a = 0; // 存储离散化后插入的结果
int PRE[N * 3], pre = 0; // 存储A的前缀和

PII tmp_p; // 用作临时变量

/*
这一题的本质上就是对一共n + 2m个坐标进行去重后排序
排成从1到p，对应A中的下标，
使用二分index就是为了快速确认下标x到底排第几
A中共p个位置，查询坐标映射出来的对应的A为0，插入的话有 += c
原坐标x1  x2映射为（其实就是n + 2m个坐标中大小排第几）l, r
那x1到x2中插入的所有数的和就是 A[l, r]的和
*/

int find(int x) { 
	// >= x左边界
    // f(x) = x在A中对应的下标
    int l = 0, r = index - 1;
    while(l < r) {
        int mid = l + r >> 1;
        if(INDEX[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l + 1; // 从1开始映射
}

void qsort(int *q, int l, int r) {
    // 数组升序排序
    if(l >= r) return ; 
    int x = q[l + r >> 1];
    int i = l - 1, j = r + 1;
    while(i < j) {
        do i ++; while(q[i] < x);
        do j --; while(q[j] > x);
        if(i < j) {
            int tmp = q[i]; q[i] = q[j]; q[j] = tmp;
        }
    }
    qsort(q, l, j); qsort(q, j + 1, r);
    return ;
}

void getUnique(int *q, int *len) {
    // 双指针去重
    // 思路：已经保证q是升序的前提下，i扫描，j记录
    // 这里j是不重复部分的结尾，不是待插入位置！
    // [0, j]表示不重复元素
    // 当 len <= 1,不用去重，直接返回
    // 第一个元素肯定是保留的，所以i从1开始扫描
    // 所以[0, j]肯定不空
    // i一定是走在j前面的，当q[i] > q[j]，说明i对应
    // 元素不在[0, j]的不重复元素中，插入
    //  如果相等，那就说明重复了，不插入
    if(*len <= 1) return ;
    int i = 1, j = 0;
    while(i < *len) {
        if(q[i] > q[j]) q[++ j] = q[i];
        i ++;
    }
    *len = j + 1; // 不重复区域长度是j + 1
    return ;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) { // 记录插入操作
        int x, c; scanf("%d %d", &x, &c);
        INDEX[index ++] = x;
        tmp_p.num1 = x; tmp_p.num2 = c;
        ADD[add ++] = tmp_p;
    }
    
    for(int i = 0; i < m; i++) { // 记录查询操作
        int l, r; scanf("%d %d", &l, &r);
        INDEX[index ++] = l, INDEX[index ++] = r;
        tmp_p.num1 = l; tmp_p.num2 = r;
        LR[lr ++] = tmp_p;
    }
    
    // 对坐标进行离散化，并完成插入 
    qsort(INDEX, 0, index - 1);
    getUnique(INDEX, &index);
    
    // 插入
    for(int i = 0; i < add; i++) {
        int x = ADD[i].num1, c = ADD[i].num2;
        A[find(x)] += c;
        // 注意！！！！！！！！！！！！！！！
        // 这里是+=，一个坐标上可能会重复加
    }
    // 处理前缀和
    for(int i = 1; i <= index; i++) {
        PRE[i] = PRE[i - 1] + A[i];
    }
    // 查询
    for(int i = 0; i < lr; i++) {
        int l = LR[i].num1, r = LR[i].num2;
        printf("%d\n", PRE[find(r)] - PRE[find(l) - 1]);
    }
    return 0;
}