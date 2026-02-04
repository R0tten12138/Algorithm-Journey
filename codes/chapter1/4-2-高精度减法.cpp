#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int N = 1e6 + 10;

// 判断 A >= B
int cmp(vector<int> &A, vector<int> &B) {
    if(A.size() != B.size()) return A.size() > B.size();
    for(int i = A.size() - 1; i >= 0; i--){
        if(A[i] != B[i]) return A[i] > B[i];
    }
    return 1; // A == B
}

// C = A - B
vector<int> sub(vector<int> &A, vector<int> &B) {
    vector<int> C;
    int t = 0;  // 借位
    for(int i = 0; i < A.size(); i++) {
        t += A[i];
        if(i < B.size()) t -= B[i];
        if(t >= 0) { C.push_back(t); t = 0; }
        else { C.push_back(t + 10); t = -1; }
        // 这里也可以是直接 (t + 10) % 10
        // 但是这样写仍需要判断t正负性，因为要判断是否借位
    }
    // 去除前导0
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main() {
    string a, b;
    vector<int> A, B, C;
    cin >> a >> b;
    // 逆序把a b存到数组里面去
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
    // 逆序输出
    if(cmp(A, B)) {
        C = sub(A, B);
    } else {
         C = sub(B, A);
        cout << "-";
    }
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

int cmp(char *A, char *B) {
    int a = strlen(A), b = strlen(B);
    if(a != b) return a > b;
    for(int i = a - 1;i >= 0; i--) {
        if(A[i] != B[i]) return A[i] > B[i];
    }
    return 1;
}
// C = A - B
void sub(char *A, char *B) {
    int a = strlen(A), b = strlen(B), t = 0, c = 0;
    for(; c < a; c++) {
        t += A[c] - '0';
        if(c < b) t -= B[c] - '0';
        if(t >= 0) { C[c] = t + '0'; t = 0; }
        else { C[c] = t + 10 + '0'; t = -1; }
    }
    C[c] = '\0';  // 预截断
    for(int i = c - 1; i > 0; i--) {
        // 处理前导0，截断
        if(C[i] == '0') C[i] = '\0';
        else break;
    }
    return ;
}

int main() {
    scanf("%s", A); scanf("%s", B);
    reverse(A); reverse(B); // 翻转
    if(cmp(A, B)) {
        sub(A, B);
    } else{
        sub(B, A); printf("-");
    }
    for(int i = strlen(C) - 1; i>= 0; i--) printf("%c", C[i]);
}