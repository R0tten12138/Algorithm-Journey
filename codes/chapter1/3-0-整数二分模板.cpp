// 区间[l, r]被划分成[l, mid - 1], [mid, r]时使用
int bsearch_1(int l, int r) {
	while (l < r) {
		int mid = l + r + 1 >> 1;  // 等价于(l + r + 1) / 2
		if (check(mid)) l = mid;	// 向上取整
		else r = mid - 1;
	}
	return l;
}

// 区间[l, r]被划分成[l, mid], [mid + 1, r]时使用
int bsearch_2(int l, int r) {
	while (l < r) {
		int mid = l + r >> 1;  	   // 等价于(l + r) / 2
		if (check(mid)) r = mid;    // 向下取整
		else l = mid + 1;
	}
	return l;
}




