#include <stdio.h>
#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int q[N];
int n;

void qsort(int *q, int l, int r) {
	if (l >= r)
		return ;

	int x = q[(l + r) / 2];
	int i = l - 1, j = r + 1;   // 先放在边界的两侧
	while (i < j) {
		do
			i ++;
		while (q[i] < x); // do while,无论什么情况，都要让两个指针先移动
		do
			j --;
		while (q[j] > x); // 这样可以避免卡死
		if (i < j)
			swap(q[i], q[j]);  // 只有没相遇的时候才需要交换
	}
	qsort(q, l, j);
	qsort(q, j + 1, r);  // 这里注意，以j为划分后的边界指针
	// 如果是用i的话，就应该是 i - 1， i为分界
	// 同时x的选定也要调整，可以是(l + r + 1) / 2,向上取整，一定不能取到l为边界，会死循环
	// 1 2的例子，1为分界，结束后i不会移动，停在0，之后 [i, r]还是[0, 1]，就死循环了

	//同理，选用j为分界的时候， j, j + 1，x就不能取到q[r]
	// 1 2   2为分界，结束后j不移动，[l, j]还是[0, 1]，死循环了
	// 同一个区间被无限递归
	return ;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &q[i]);
	qsort(q, 0, n - 1);
	for (int i = 0; i < n; i++)
		printf("%d ", q[i]);
	return 0;
}