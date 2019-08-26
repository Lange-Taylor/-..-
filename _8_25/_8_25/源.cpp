#if 0

//两个有序数组拼接

void merge(vector<int>& nums1, vector<int>& nums2, int m, int n)
{
	int i = 0, j = 0;
	while (i < m && j < n)
	{
		if (nums1[i] <= nums2[j])
			++i;
		else
		{
			m += 1;
			for (int a = m; a > i + 1; --a)
				nums1[a - 1] = nums1[a - 2];
			nums1[i] = nums2[j];
			++j;
		}
	}
	while (j < n)
		nums1[i++] = nums2[j++];
}




#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> nums1 = { 1,2,3,0,0,0 };
	vector<int> nums2 = { 2,5,6 };
	int m = 3, n = 3;
	int p = m-- + n-- - 1;
	while (m >= 0 && n >= 0) {
		nums1[p--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
	}

	while (n >= 0) {
		nums1[p--] = nums2[n--];

	}
	for (auto e : nums1)
		cout << e << ' ';
	cout << endl;
	return 0;
}
#endif



#if 0

//删除数组中重复元素并返回剩余个数

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 2)
			return nums.size();
		int j = 0;
		for (int i = 1; i < nums.size(); ++i)
			if (nums[j] != nums[i])
				nums[++j] = nums[i];
		return ++j;
	}
};

#endif