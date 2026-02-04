#include <stdio.h>
#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int q[N], tmp[N];
int n;

void merge_sort(int *q, int l, int r) {
	if (l >= r)
		return ;
	int mid = l + (r - l) / 2;
	merge_sort(q, l, mid);
	merge_sort(q, mid + 1, r);
	int k = 0, i = l, j = mid + 1;  // k为tmp数组待存放元素的位置，i j为两个有序数组的遍历指针
	while (i <= mid && j <= r) {
		if (q[i] <= q[j])
			tmp[k ++] = q[i ++];
		else
			tmp[k ++] = q[j ++];
	}
	while (i <= mid)
		tmp[k ++] = q[i ++];  // 将没有遍历完的那个数组的剩余内容放到tmp中
	while (j <= r)
		tmp[k ++] = q[j ++];
	for (int i = l, j = 0; i <= r; i++, j++)
		q[i] = tmp[j];  // 数据写回，注意这里q的i是从l开始到r，而不是0开始
	return ;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &q[i]);
	merge_sort(q, 0, n - 1);
	for (int i = 0; i < n; i++)
		printf("%d ", q[i]);
	return 0;
}

