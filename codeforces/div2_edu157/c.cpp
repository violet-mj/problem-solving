#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>

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

void solve() {
	int n;		
	cin >> n;
	vector<string> v(n);
	vector<vector<int>> pre(n);
	vector<vector<int>> strSum(6);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
		int cnt = 0;
		pre[i].pb(0);
		for(int j = 0; j < v[i].size(); j++) {
			cnt += v[i][j] - '0';
			pre[i].pb(pre[i][pre[i].size() - 1] + v[i][j] - '0');
		}
		strSum[v[i].size()].pb(cnt);
	}

	for(int i = 1; i < 6; i++) {
		sort(all(strSum[i]));
	}

	int res= 0;

	for(int i = 0; i < n; i++) {
		int currSize = v[i].size();	
		int init = currSize % 2 == 0 ? 2 : 1;
		for(int j = init; j < currSize; j+=2) {
			int diffSize = (currSize - j) >> 1;
			int minSize, maxSize;
			int diffValue = pre[i][currSize] - 2 * (pre[i][diffSize]);
			int f1 = lower_bound(all(strSum[j]), diffValue) - strSum[j].begin();
			int s1 = upper_bound(all(strSum[j]), diffValue) - strSum[j].begin();
			res += (s1 - f1);
			debug(v[i], currSize, j,res , f1, s1, diffValue);
		}
	}

	for(int i = 0; i < n; i++) {
		int currSize = v[i].size();	
		int init = currSize % 2 == 0 ? 2 : 1;
		for(int j = init; j <= currSize; j+=2) {
			int diffSize = (j - currSize) >> 1;
			int minSize, maxSize;
			int diffValue = pre[i][currSize] - 2 * (pre[i][currSize - diffSize]);
			int f1 = lower_bound(all(strSum[j]), -diffValue) - strSum[j].begin();
			int s1 = upper_bound(all(strSum[j]), -diffValue) - strSum[j].begin();
			res += s1 - f1;
			debug(v[i], currSize, j,res, f1, s1, diffValue);
		}
	}
	

	for(int i = 1; i < 6; i++) {
		debug(strSum[i])	;
	}
	for(int i = 0; i < n; i++) {
		debug(pre[i])	;
	}

	cout << res << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	solve();
}
