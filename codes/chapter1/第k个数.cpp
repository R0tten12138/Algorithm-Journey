#include <stdio.h>
#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int q[N];
int n;

void qsort(int *q, int l, int r) {
	if (l >= r)
		return ;
	int x = q[l + (r - l) / 2];
	int i = l - 1, j = r + 1;
	while (i < j) {
		do
			i ++;
		while (q[i] < x);
		do
			j --;
		while (q[j] > x);
		if (i < j)
			swap(q[i], q[j]);
	}
	qsort(q, l, j);
	qsort(q, j + 1, r);
	return ;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &q[i]);
	qsort(q, 0, n - 1);
	printf("%d", q[k - 1]);
	return 0;
}
