for(i = 0, j = 0; i < n; i ++) {
	while(j < i && check(i, j)) j ++;
	
	// 具体逻辑
}

#include <stdio.h>
#include <string.h>
const int N = 1e5 + 10;
char a[N];
int main() {
    fgets(a, N, stdin);
    // 读取逻辑：从指定输入流（默认 stdin 即键盘）读取，
    //最多读取 n-1 个字符（n 是数组长度），遇到「换行符 \n」或
    //「文件结束 EOF」就停止；
    //换行符处理：会把换行符 \n 一起读入字符串末尾
    //（比如输入 hello\n，字符串里会是 hello\n\0）；
    a[strcspn(a, "\n")] = '\0'; // 去掉读入的换行符
    int len = strlen(a);
    for(int i = 0; a[i]; i++) {
        int j = i;
        // j没走到终点且j所在不是空格
        while(a[j] && a[j] != ' ') j ++;
        
        // 具体逻辑
        for(int k = i; k < j; k++) printf("%c", a[k]);
        printf("\n");
        i = j;  // i此时指向空格， i ++后指向下一个单词的头
    }
}

