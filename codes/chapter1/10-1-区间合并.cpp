#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> PII;
const int N = 1e6 + 10;
int n;
vector<PII> segs;

void merge(vector<PII> & segs) {
    vector<PII> res; // 合并后结果
    sort(segs.begin(), segs.end(), [](PII &a, PII &b){return a.first < b.first;});
    int st = -2e9, ed = -2e9;
    
    for(int i = 0 ; i < segs.size(); i++) {
        //  这里不用单独判断st和segs[i],排序后一定满足 <= 关系的
        // 1 内部
        if( ed >= segs[i].second) continue;
        // 2 有交集但不在内部
        else if( ed < segs[i].second && ed >= segs[i].first) ed = segs[i].second;
        // 3 完全在外部
        else {
            if(st != -2e9) res.push_back({st, ed}); // 不能是初始的区间
            st = segs[i].first; ed = segs[i].second;
        }
    }
    
    if(st != -2e9) res.push_back({st, ed});
    // 最后的区间也要加入，但是为了防止segs为空，所以还要再判断一下
    segs = res;
    return ;
}

int main() {
    cin >> n; 
    for(int i  = 0; i < n; i ++) {
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }
    
    merge(segs);
    cout << segs.size() << endl;
    return 0;
}




#include <stdio.h>

const int N = 1e6 + 10;
typedef struct PII {
    int l, r;
} PII;

PII SEGS[N]; int segs = 0; // 存储区间
PII RES[N]; int res = 0;
int n;

PII tmp_p; //临时变量，方便使用

void qsort(PII *q, int l, int r) {
    if(l >= r) return ;
    int i = l - 1, j = r + 1;
    int x = q[l + r >> 1].l;
    while(i < j) {
        do i ++; while(q[i].l < x);
        do j --; while(q[j].l > x);
        if(i < j) {
            PII tmp = q[i]; q[i] = q[j]; q[j] = tmp;
        }
    } 
    qsort(q, l, j); qsort(q, j + 1, r);
    return ;
}

void merge(PII *SEGS, int segs) {
    qsort(SEGS, 0, segs - 1); // 排序
    int st = -2e9, ed = -2e9; //  初始边界
    for(int i = 0; i < segs; i++) {
        int l = SEGS[i].l, r = SEGS[i].r;
        if(ed >= r) continue; // 情况1 i区间在当前区间内不
        else if(ed < r && ed >= l) ed = r; // 情况2 i区间和当前区间有重叠
        else { // 情况3 i区间和当前区间无重叠，当前区间可以收进RES中了
            if(st != -2e9) {// 最开始的区间是我们自己设置的，不要加进去
                tmp_p.l = st; tmp_p.r = ed;
                RES[res ++] = tmp_p;
            }
            st = l; ed = r; // 更新维护的区间
        }
    }
    if(st != -2e9) { // 最后一个区间，因为无后续区间，要手动判断
        tmp_p.l = st; tmp_p.r = ed; // 并且要防止SEGS为空而误加入我们虚拟出来的起始区间
        RES[res ++] = tmp_p;
    }
    return ;
}


int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) {
        int l, r;
        scanf("%d %d", &l, &r);
        tmp_p.l = l; tmp_p.r = r;
        SEGS[segs ++] = tmp_p;
    }
    merge(SEGS, segs);
    printf("%d", res);
    
    
    return 0;
}