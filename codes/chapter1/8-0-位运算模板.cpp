#include <stdio.h>

void show_binary(int x) {
	while(x) {
        // x & 1相当于取出n二进制最低位
        //注意！这里的二进制是倒着输出的
        // (100)2 -> 001
        printf("%d", x & 1);
    	x = x >> 1;
    }
    printf("\n");
    return ;
}

int main() {
    int n; scanf("%d", &n);
	show_binary(n);
	show_binary(n & (- n));
	show_binary(n & (~n + 1));
    reutn 0;	
}



