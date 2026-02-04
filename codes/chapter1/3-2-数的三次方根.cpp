#include <stdio.h>
#include <cmath>
using namespace std;

const double MIN = 1e-8;

int main() {
    double n; scanf("%lf", &n);
    double l = 0, r= 10000.0; 
    // 这里直接选取题目边界，不用n，多不了几次判断
    while(r - l > MIN) {
        double mid = (l + r) / 2;
        if(mid * mid * mid > abs(n)) r = mid;
        else l = mid;
    }
    if(n < 0) l *= -1;
    printf("%lf", l);
    return 0;
}



