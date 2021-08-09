/*

Given array of size n consiting of element from 1 to n-2. Find the two repeating numbers.

*/

#include<bits/stdc++.h>
using namespace std;

/*

Mathematically, we can solve this problem by computing x+y = sum of all number in array - sum of all unique numbers
and x*y = product of all numbers in array / product of all unique numbers

Now, we can write x-y = sqrt((x+y)^2 - 4xy)

Once, we have x-y and x+y. We can compute the value of x and y which are the repeating numbers.

*/

// int first_set_bit_index(int n) {
// 	int first_set_bit_num = n & (~(n - 1));
// 	return log2(first_set_bit_num);
// }

// int is_ith_bit_set(int n, int i) {
// 	return n & (1 << i);
// }

// Rather than finding the index and then checking the number we can directly send the number
int first_set_bit_number(int n) {
	return n & (~(n - 1));
}


vector<int> find_two_repeating(vector<int> & nums) {
	int repeating_xor = 0;
	for (int i = 0; i < nums.size(); i++) {
		repeating_xor ^= nums[i];
	}

	for (int i = 1; i <= nums.size() - 2; i++) {
		repeating_xor ^= i;
	}

	int set_bit_number = first_set_bit_number(repeating_xor);

	int first = 0;

	for (int i = 0; i <= nums.size(); i++) {
		if (set_bit_number & nums[i])
			first ^= nums[i];
	}

	for (int i = 1; i <= nums.size() - 2; i++) {
		if (set_bit_number & i)
			first ^= i;
	}

	vector<int> ans;
	ans.push_back(first);
	ans.push_back(repeating_xor ^ first);
	return ans;
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

	vector<int> ans = find_two_repeating(nums);

	cout << ans[0] << " " << ans[1] << endl;

	return 0;
}