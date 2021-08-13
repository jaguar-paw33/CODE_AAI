/*

Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backward) for which the stock price was less than or equal to today's price.

For example, if the price of a stock over the next 7 days were [100,80,60,70,60,75,85], then the stock spans would be [1,1,1,2,1,4,6].
Implement the StockSpanner class:

StockSpanner() Initializes the object of the class.
int next(int price) Returns the span of the stock's price given that today's price is price.


Example 1:

Input
["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
[[], [100], [80], [60], [70], [60], [75], [85]]
Output
[null, 1, 1, 1, 2, 1, 4, 6]

Explanation
StockSpanner stockSpanner = new StockSpanner();
stockSpanner.next(100); // return 1
stockSpanner.next(80);  // return 1
stockSpanner.next(60);  // return 1
stockSpanner.next(70);  // return 2
stockSpanner.next(60);  // return 1
stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
stockSpanner.next(85);  // return 6


Constraints:

1 <= price <= 105
At most 104 calls will be made to next.


Level: Medium

Problem Practice Link: https://leetcode.com/problems/online-stock-span/

Code:  With using stack: https://ideone.com/VRpA9H

Python Code:  With using stack: https://onlinegdb.com/SyRsrJgnS

Code: Without using stack: https://ideone.com/qS39cu

Python Code: Without using stack: https://onlinegdb.com/H1xt9JghH

*/

#include<bits/stdc++.h>
using namespace std;

class StockSpanner {
	int * arr;
	int next_idx;
	int * span;
	stack<int> s;

public:
	StockSpanner() {
		arr = new int [10001];
		span = new int[10001];
		next_idx = 0;
	}

	int next(int price) {

		span[next_idx] = 1;

		if (!next_idx) {
			s.push(next_idx);
		} else {
			if (price >= arr[next_idx - 1]) {
				while (s.size() && price >= arr[s.top()]) {
					span[next_idx] += span[s.top()];
					s.pop();
				}
			}
			s.push(next_idx);
		}

		arr[next_idx++] = price;
		return span[next_idx - 1];
	}
};

int main() {
	StockSpanner * stockSpanner = new StockSpanner();
	cout << stockSpanner->next(100) << endl; // return 1
	cout << stockSpanner->next(80) << endl; // return 1
	cout << stockSpanner->next(60) << endl; // return 1
	cout << stockSpanner->next(70) << endl; // return 2
	cout << stockSpanner->next(60) << endl; // return 1
	cout << stockSpanner->next(75) << endl; // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
	cout << stockSpanner->next(85) << endl; // return 6
}
