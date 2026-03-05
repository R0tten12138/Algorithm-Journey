#include <stdio.h>

const int N = 1e5 + 10;
char exp[N];

int stk1[N], tt1 = -1; // 存储数字
char stk2[N]; int tt2 = -1; // 存储运算符

// 运算符优先级：
// ( : 0,  + - : 1,  * / : 2
// 每个运算符入栈二，要把优先级大于等于自己的运算符先弹出去计算

void cal(char c) { // 运算
    // 注意，我们先取出来的是num2，再是num1，计算num1 c num2
    int a = stk1[tt1 --], b = stk1[tt1 --];
    if(c == '+') stk1[++ tt1] = b + a;
    else if(c == '-') stk1[++ tt1] = b - a;
    else if(c == '*') stk1[++ tt1] = b * a;
    else stk1[++ tt1] = b / a;
}

int main() {
    scanf("%s", exp);
    
    int tmp = 0; // 存储数字
    char c;
    for(int i = 0; exp[i]; i++) {
        if(exp[i] >= '0' && exp[i] <= '9') tmp = tmp * 10 + exp[i] - '0'; // 数字情况
        else { // 运算符情况
            if(tmp) { // 之前的部分是有效数字，加入栈1中
                stk1[++ tt1] = tmp;
                tmp = 0; // 清空数字
            }
            
            if(exp[i] == '(') stk2[++ tt2] = exp[i]; // 左括号直接入栈
            else if(exp[i] == ')'){
                while(stk2[tt2] != '('){
                    c = stk2[tt2 --];
                    cal(c);
                } // 计算栈2中第一个左括号之前的所有运算符
                tt2 --; // 弹出左括号
            }  // 运算符括号，运算符弹至出现右括号
            else if(exp[i] == '*' || exp[i] == '/') {
                while(tt2 >= 0 && (stk2[tt2] == '*' || stk2[tt2] == '/')) {
                    c = stk2[tt2 --];
                    cal(c);
                }
                stk2[++ tt2] = exp[i];
            } // * / 把优先级大于等于自己的弹出去（* /）计算
            else {
                while(tt2 >= 0 && stk2[tt2] != '(') {
                    c = stk2[tt2 --];
                    cal(c);
                }
                stk2[++ tt2] = exp[i];
            }// + - 把优先级大于等于自己的弹出去（+* / + -）计算
        }
    }
    if(tmp) stk1[++ tt1] = tmp; // 因为我们是用运算符号截断数字，所以最后还要再判断一下
    while(tt2 >= 0) cal(stk2[tt2 --]); // 弹出栈中剩余的运算符
    printf("%d", stk1[tt1]); // 最后栈1中只会有一个结果，就是运算答案
    
    
    return 0;
}