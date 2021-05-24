/*

You want to buy a ticket for a well-known concert which is happening in your city. But the number of tickets available is limited. Hence the sponsors of the concert decided to sell tickets to customers based on some priority.

A queue is maintained for buying the tickets and every person is attached with a priority (an integer, 1 being the lowest priority).

The tickets are sold in the following manner -

1. The first person (pi) in the queue requests for the ticket.
2. If there is another person present in the queue who has higher priority than pi, then ask pi to move at end of the queue without giving him the ticket.
3. Otherwise, give him the ticket (and don't make him stand in queue again).

Giving a ticket to a person takes exactly 1 minute and it takes no time for removing and adding a person to the queue. And you can assume that no new person joins the queue.
Given a list of priorities of N persons standing in the queue and the index of your priority (indexing starts from 0). Find and return the time it will take until you get the ticket.

Input Format:
The first line of input contains an integer, that denotes the value of total number of people standing in queue or the size of the array of priorities. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array of priorities.
The following contains an integer, that denotes the value of index of your priority. Let us denote it with symbol k.

Output Format :
The first and only line of output contains the time required for you to get the ticket.

Constraints:
Time Limit: 1 sec

Sample Input 1 :
3
3 9 4
2
Sample Output 1 :
2

Sample Output 1 Explanation :
Person with priority 3 comes out. But there is a person with higher priority than him. So he goes and then stands in the queue at the end. Queue's status :  {9, 4, 3}. Time : 0 secs.
Next, the person with priority 9 comes out. And there is no person with higher priority than him. So he'll get the ticket. Queue's status :  {4, 3}. Time : 1 secs.
Next, the person with priority 4 comes out (which is you). And there is no person with higher priority than you. So you'll get the ticket. Time : 2 secs.

Sample Input 2 :
5
2 3 2 2 4
3
Sample Output 2 :
4

*/

#include<bits/stdc++.h>
using namespace std;

int time_to_buy(int * arr, int n, int p) {
	priority_queue<int> pq;
	queue<int> pos;

	for (int i = 0; i < n; i++) {
		pq.push(arr[i]);
		pos.push(i);
	}

	int t = 0;

	while (!pos.empty()) {
		if (arr[pos.front()] == pq.top()) {
			t++;
			if (pos.front() == p)
				break;
			pos.pop();
			pq.pop();
		} else {
			pos.push(pos.front());
			pos.pop();
		}
	}

	return t;
}

int main() {
	int n;
	cin >> n;
	int * arr = new int [n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int p;
	cin >> p;
	cout << time_to_buy(arr, n, p) << endl;
	delete [] arr;
	return 0;
}