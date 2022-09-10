// # include <bits/stdc++.h>
# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <algorithm>
# include <vector>
# include <queue>
# include <set>
# include <cstring>
# include <cstdio>
# include <string>
using namespace std;

vector<int> v, v2;

void maxHeapAdjust(vector<int>& v, int start, int end) {
    int left = 2 * start + 1;  // 第一步：求出左右子节点的下标
    int right = left + 1;  // = 2 * start + 2;
    int maxIndex = start;  // 第二步：求出v[start]、v[left]、v[right]三者中的最大值
    if (left <= end && v[left] > v[maxIndex]) maxIndex = left;
    if (right <= end && v[right] > v[maxIndex]) maxIndex = right;
    if (maxIndex != start) {  // 第三步：若根节点不是最大，则交换父子节点，并递归调整下一层
        swap(v[maxIndex], v[start]);
        maxHeapAdjust(v, maxIndex, end);
    }
}

void heapSort(vector<int>& v) {
    // 初始化建堆：从最后一个非叶子节点开始，从右到左从上到下调整二叉树成大顶堆
    for (int i = v.size() / 2 - 1; i >= 0; i--) {
        maxHeapAdjust(v, i, v.size() - 1);
    }
    // 堆排序：交换首尾元素后，调整根节点，使前面的无序树成为大顶堆
    for (int i = v.size() - 1; i >= 1; i--) {
        swap(v[0], v[i]);
        maxHeapAdjust(v, 0, i - 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    v.resize(n);
    v2.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &v2[i]);
    }
    int cnt1 = 1, cnt2 = n - 1;
    while (cnt1 < n && v2[cnt1] >= v2[cnt1 - 1]) cnt1++;
    int index = cnt1;
    while (cnt1 < n && v2[cnt1] == v[cnt1]) cnt1++;
    if (cnt1 == n) {
        printf("Insertion Sort\n");
        sort(v2.begin(), v2.begin() + index + 1);
    }
    else {
        printf("Heap Sort\n");
        while (cnt2 >= 0 && v2[cnt2] >= v2[0]) cnt2--;
        swap(v2[0], v2[cnt2]);
        maxHeapAdjust(v2, 0, cnt2 - 1);
    }
    printf("%d", v2[0]);
    for (int i = 1; i < n; i++)
        printf(" %d", v2[i]);
    return 0;
}
