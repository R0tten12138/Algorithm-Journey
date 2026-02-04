#include <stdio.h>

const int N = 1e6 + 10;
int q[N], tmp[N];
int n;
typedef long long LL;

LL func(int *q, int l, int r) {
	// 函数定义：降序排序数组q[l, r]，并返回其中的逆序数对数
	if (l >= r)
		return 0;
	LL res = 0;
	int mid = l + (r - l) / 2;
	res += func(q, l, mid);
	res += func(q, mid + 1, r); // 递归处理左右两部分
	int i = l, j = mid + 1, k = 0;
	while (i <= mid && j <= r) {
		if (q[i] > q[j]) { // 这里要注意了，我们只在 > 的时候放i而不是 >=
			if (q[i] > q[j])
				res += r - j + 1;  //如果是 >=，在这res不便，那j后面的就都没统计
			tmp[k ++] = q[i ++];  // 比如 2  2 1  2 = 2，但是右边的1就没算成逆序对纳入res！
		} else
			tmp[k ++] = q[j ++];
	}
	while (i <= mid)
		tmp[k ++] = q[i ++];
	while (j <= r)
		tmp[k ++] = q[j ++];

	for (int i = l, j = 0; i <= r; i++, j++)
		q[i] = tmp[j];
	return res;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &q[i]);
	printf("%lld", func(q, 0, n - 1));
	return 0;
}

