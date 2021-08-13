/*

We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.



Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
Example 4:

Input: asteroids = [-2,-1,1,2]
Output: [-2,-1,1,2]
Explanation: The -2 and -1 are moving left, while the 1 and 2 are moving right. Asteroids moving the same direction never meet, so no asteroids will meet each other.


Constraints:

2 <= asteroids.length <= 10^4
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0

Level: Medium

Problem Practice link: https://leetcode.com/problems/asteroid-collision/

Companies Asked in: Amazon, Google, Paypal

Similar Questions:

Can Place Flowers: https://leetcode.com/problems/can-place-flowers/

*/




#include<bits/stdc++.h>
using namespace std;

// Time Complexity - O(n) and Space Complexity - O(n)
vector<int> asteroidCollision1(vector<int>& asteroids) {
	vector<int> ans;
	stack<int> s;

	for (int i = 0; i < asteroids.size();) {

		if (s.size() && asteroids[i] < 0 && s.top() > 0) {

			if (abs(s.top()) < abs(asteroids[i])) {
				s.pop();
			} else if (abs(s.top()) == abs(asteroids[i])) {
				s.pop();
				i++;
			} else {
				i++;
			}

		} else {

			s.push(asteroids[i++]);

		}

	}

	while (!s.empty()) {

		ans.push_back(s.top());
		s.pop();

	}

	reverse(ans.begin(), ans.end());

	return ans;
}


// Time Complexity - O(n) and Space Complexity - O(1)
vector<int> asteroidCollision2(vector<int>& asteroids) {
	vector<int> ans;

	for (int i = 0; i < asteroids.size();) {

		if (ans.size() && asteroids[i] < 0 && ans[ans.size() - 1] > 0) {

			if (abs(ans[ans.size() - 1]) < abs(asteroids[i])) {
				ans.pop_back();
			} else if (abs(ans[ans.size() - 1]) == abs(asteroids[i])) {
				ans.pop_back();
				i++;
			} else {
				i++;
			}

		} else {

			ans.push_back(asteroids[i++]);

		}
	}

	return ans;
}

int main() {
	int n;
	cin >> n;

	vector<int> asteroids;
	int v;

	while (n--) {
		cin >> v;
		asteroids.push_back(v);
	}

	vector<int> ans1 = asteroidCollision1(asteroids);

	for (int i = 0; i < ans1.size(); i++) {
		cout << ans1[i] << " ";
	}

	cout << endl;

	vector<int> ans2 = asteroidCollision2(asteroids);

	for (int i = 0; i < ans2.size(); i++) {
		cout << ans2[i] << " ";
	}

	return 0;
}


