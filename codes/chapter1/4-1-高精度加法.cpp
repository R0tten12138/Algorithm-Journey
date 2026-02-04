#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int N = 1e6 + 10;

// C = A + B
vector<int> add(vector<int> &A, vector<int> &B) {
    vector<int> C;
    int t = 0;  // 进位
    for(int i = 0; i < A.size() || i < B.size(); i++) {
        if(i < A.size()) t += A[i];
        if(i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if(t) C.push_back(1);  // 结束后再判断要不要进位
    return C;
}

int main() {
    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    // 逆序把a b存到数组里面去
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
    // 逆序输出
    vector<int> C = add(A, B);
    for(int i = C.size() - 1; i >= 0; i--) cout << C[i];
    return 0;
}

// c风格
#include <stdio.h>
#include <string.h>

const int N = 1e6 + 10;
char A[N], B[N], C[N];

void reverse(char *tmp) {
    int len = strlen(tmp);
    int i = 0, j = len - 1;
    while(i < j) {  // 这里不能用 != 哦 会交错过去
        char t = tmp[i]; tmp[i] = tmp[j]; tmp[j] = t;
        i ++; j --;
    }
    return ;
}

// C = A + B
void add(char *A, char *B) {
    int a = strlen(A), b = strlen(B), c = 0, t = 0;
    for(; c < a || c < b; c++) {
        if(c < a) t += A[c] - '0';
        if(c < b) t += B[c] - '0';
        C[c] = t % 10 + '0';
        t /= 10;
    }
    if(t) C[c ++] = '1';
    C[c] = '\0';  // 补充\0，这样才能用strlen
    return ;
}

int main() {
    scanf("%s", A); scanf("%s", B);
    reverse(A); reverse(B); // 翻转
    add(A, B);
    for(int i = strlen(C) - 1; i>= 0; i--) printf("%c", C[i]);
    
}
