#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> mul(vector<int> &A, int b) {
    vector<int> C;
    int t = 0;
    for(int i = 0; i < A.size(); i++) {
        t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    // 这里因为t可能不止一位，所以要一个个取出来放到C
    while(t) { C.push_back(t % 10); t /= 10; }
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
    C = mul(A, b);
    for(int i = C.size() - 1; i >= 0; i--) cout << C[i];
    return 0;
}





#include <stdio.h>
#include <string.h>

const int N = 1e6 + 15; // b <= 1e5,所以C最多多5位
char A[N], C[N];
int b;

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
    int t = 0, c= 0;
    for(; c < a || t; c++) {
        // 这里优化了t的处理，当A的每一位处理完后，只处理t
        if(c < a) t += (A[c] - '0') * b;
        C[c] = t % 10 + '0';
        t /= 10;
    }
    // 截断
    C[c] = '\0';
    for(int i = c - 1; i > 0; i--) {
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
    return 0;
}

