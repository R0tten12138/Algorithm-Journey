#include <stdio.h>
#include <math.h>
using namespace std;

const double MIN = 1e-8;  // 这里切记是double
// 如果题目要求保留k位小数，这里就写成-(k + 2 )保证精度
int main() {
    double n; scanf("%lf", &n);
    double l = 0, r= (n >= 1) ? n : 1;
    // 如果n < 1,例如0.01，那结果理应是0.1
    // 但是如果直接采用n作为边界，就一定取不到0.1
    while(r - l > MIN) {
        double mid = (l + r) / 2;
        if(mid * mid >= n) r = mid;
        else l = mid;
    }
    printf("%.6lf", l);
    return 0;
}

