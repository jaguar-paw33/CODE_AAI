// Keep in mind here we are considering only the subarray partition and not the subset partition


#include<bits/stdc++.h>
using namespace std;

int split_point(vector<int> & nums) {
	int lsum = 0;
	int rsum = 0;
	int i, j;

	for (i = 0, j = nums.size() - 1; i <= j;) {
		if (lsum < rsum) {
			lsum += nums[i++];
		} else {
			rsum += nums[j--];
		}
	}

	if (lsum == rsum)
		return j;

	return -1;
}

int main() {
	int n;
	cin >> n;

	vector<int> nums;
	int v;

	while (n--) {
		cin >> v;
		nums.push_back(v);
	}

	cout << split_point(nums) << endl;

	return 0;
}
