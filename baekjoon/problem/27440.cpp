#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

#ifndef ONLINE_JUDGE
#include "/Users/mj/.vim/template/debug.cpp"
#else
#define debug(x...)
#endif

typedef long long lint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
typedef vector<int> vi;
typedef vector<lint> vl;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define all(v) (v).begin(),(v).end()

struct Default {
	int value = 1 << 30;
};

map<int, Default> dp;
lint n;

void solve() { 
	cin >> n;
	queue<vector<lint>> q;
	q.push({n, 0});

	while(!q.empty()) {
		vector<lint> curr = q.front();
		lint currNum = curr[0];
		lint currCount = curr[1];
		if(currNum == 1) {
			cout << currCount << "\n"	;
			return;
		}
		q.pop();
		if(dp[currNum].value <= currCount) continue;
		dp[currNum].value = currCount;
		if(currNum % 3 == 0) q.push({currNum / 3, currCount+1});
		if(currNum % 2 == 0) q.push({currNum / 2, currCount+1});
		q.push({currNum-1, currCount+1});
	}
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
