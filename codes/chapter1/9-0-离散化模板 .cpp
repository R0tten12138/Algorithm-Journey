vector<int> alls; // 存储所有待离散化的值
sort(alls.begin(), all.end()); // 排序
all.erase(unique(all.begin(), all.end()), alls.end()); // 去重
// unique函数必须在有序的情况下才能用
// 它会把数组中的重复的元素放到数组的末尾，然后
// 返回这些重复元素的开头位置
//  |不重复元素|  (unique返回的位置)|重复元素|

// 二分求出x对应的离散化的值
int find(itn x) {
    // 找到第一个 >= x 的值
    int l = 0, r = all.size() - 1;
    while(l < r) {
        int mid = l + r >> 1;
        if(all[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l + 1;
    // 这里返回l就是离散到0, 1, 2...
    // + 1就是离散到 1, 2, 3...
}

