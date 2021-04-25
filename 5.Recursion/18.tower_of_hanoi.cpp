#include<iostream>
#include<string>
using namespace std;

void toh(int n, string src, string aux, string dest) {
	if (n <= 0)
		return;
	toh(n - 1, src, dest, aux);
	cout << src << " to " << dest << endl;
	toh(n - 1, aux, src, dest);
}

int main() {
	string src = "source", aux = "auxillary", dest = "destination";
	int n;
	cin >> n;
	toh(n, src, aux, dest);
	return 0;
}