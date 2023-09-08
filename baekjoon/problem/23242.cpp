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

ld B, N;
const ld INF = (ld)10000000000000;

void solve() {
	cin >> B >> N;	
	vector<ld> values(N + 1, 0);
	vector<ld> prefixSum(N + 1, 0);
	vector<ld> prefixSquareSum(N + 1, 0);

	auto calculateError = [&](int i1, int i2) {
		ld partSum = prefixSum[i2] - prefixSum[i1 - 1];
		ld partSquareSum = prefixSquareSum[i2] - prefixSquareSum[i1 - 1];
		ld partLen = i2 - i1 + 1;
		ld average = partSum / partLen; 
		return partSquareSum - 2 * average * partSum + partLen * average * average;
	};

	for(int i = 1; i <= N; i++) {
		cin >> values[i];
		prefixSum[i] = prefixSum[i - 1] + values[i];
		prefixSquareSum[i] = prefixSquareSum[i - 1] + values[i] * values[i];
	}

	debug(prefixSum);
	debug(prefixSquareSum);

	vector<vector<ld>> dp(B + 1, vector<ld>(N + 1, INF));
	dp[0][0] = (ld)0;

	for(int i = 1; i <= N; i++) {
		for(int j = 0; j < i; j++) {
			ld partError = calculateError(j + 1, i);
			for(int z = 1; z <= B; z++)	 {
				dp[z][i] = min(dp[z][i], dp[z-1][j] + partError);
			}
		}
	}

	ld res = INF;

	for(int i = 1; i <= B; i++) {
		res = min(res, dp[i][N]);
	}

	cout << res << "\n";
}

int main() {
	cin.tie(0);
	cout.unsetf(ios::fixed);
	cout.precision(30);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
