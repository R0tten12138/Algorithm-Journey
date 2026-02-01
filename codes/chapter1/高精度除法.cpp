#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> div(vector<int> &A, int b, int *r) {
    vector<int> C;
    *r = 0;
    // 这里注意， 除法是从最高位开始算的
    for(int i = A.size() - 1; i >= 0; i--) {
        *r = *r * 10 + A[i];
        C.push_back(*r / b);
        *r %= b;
    }  // 这里得到的C的最高位是在小地址，因此要翻转过来
    reverse(C.begin(), C.end());
    // 处理前导0
    while(C.size() > 1 && C.back() == 0) C.pop_back(); 
    return C;
}

int main() {
    vector<int> A, C;
    int b; 
    string A_c;
    cin >> A_c; cin >> b;
    for(int i = A_c.size() - 1; i >= 0; i--) A.push_back(A_c[i] - '0');
    int r;
    C = div(A, b, &r);
    for(int i = C.size() - 1; i >= 0; i--) cout << C[i];
    cout << endl;
    cout << r;
    return 0;
}



#include <stdio.h>
#include <string.h>

const int N = 1e6 + 10;
char A[N], C[N];
int b, r;  // r 为余数，这里偷个懒写成全局

void reverse(char *tmp) {
    int len = strlen(tmp);
    int i = 0, j = len - 1;
    while(i < j) {  // 这里不能用 != 哦 会交错过去
        char t = tmp[i]; tmp[i] = tmp[j]; tmp[j] = t;
        i ++; j --;
    }
    return ;
}

void mul(char *A, int b) {
    int a = strlen(A);
    r = 0;
    for(int i = a - 1; i >= 0; i--) {
        r = r * 10 + A[i] - '0';
        C[i] = r / b + '0';  // 这种方法C不用翻转
        r %= b;
    }
    // 截断 这里除法位数不会增加，所以直接用a喽！
    C[a] = '\0';
    for(int i = a - 1; i > 0; i--) {
        if(C[i] == '0') C[i] = '\0';
        else break;
    }
    return ;
}

int main() {
    scanf("%s", A); scanf("%d", &b);
    reverse(A);
    mul(A, b);
    for(int i = strlen(C) - 1; i >= 0; i--) printf("%c", C[i]);
    printf("\n%d", r);
    return 0;
}