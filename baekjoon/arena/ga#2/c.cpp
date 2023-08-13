#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

#ifdef DEBUG
#define debug 1
#else
#define debug 0
#endif

#define mp make_pair 
#define pb push_back 
#define f first 
#define s second

typedef long long lint;
int n;

void solve() {
	cin >> n;
	lint A[n];

	for(int i = 0 ; i < n; i++) cin >> A[i];
	
	priority_queue<lint> maxQ;
	priority_queue<lint, vector<lint>, greater<lint>> minQ;

	for(int i = 0; i < n; i++) {
		maxQ.push(A[i]);
		minQ.push(A[i]);
	}

	int cnt = 0;


	lint iMaxValue = maxQ.top() * 2; 
	lint iDiff = maxQ.top() - minQ.top();
	lint res = (lint)1000000000000000000;

	while(true) {
		lint minValue = minQ.top();
		lint maxValue = maxQ.top();
		lint diff = maxValue - minValue;

		if(maxValue == iMaxValue) break;

		res = min(diff, res);

		minQ.pop();

		minQ.push(minValue * 2);
		maxQ.push(minValue * 2);

		//cout << "minValue : " << minValue << " maxValue : " << maxValue << " diff : " << diff << "\n";
	}

	cout << res << "\n";

}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}
