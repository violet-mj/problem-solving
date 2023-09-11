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

lint n;
const lint MOD = 1000000000LL;

void solve() {
	cin >> n;
	lint dp[n+1][10][1 << 10];
	fill(&dp[0][0][0], &dp[n][9][1 << 10], 0LL);
	for(lint i = 1; i < 10; i++) {
		dp[1][i][1 << i]	= 1LL;
	}

	lint fullBit = (1 << 10) - 1;

	for(int i = 1; i < n; i++) {
		for(int j = 0; j < 10; j++) {
			for(int z = 0; z < 1 << 10; z++) {
				if(!(z & (1 << j))) continue;
				if(j + 1 < 10) {
					dp[i+1][j+1][z | (1 << (j + 1))] += dp[i][j][z];
					dp[i+1][j+1][z | (1 << (j + 1))] %= MOD; 
				}

				if(j - 1 >= 0) {
					dp[i+1][j-1][z | (1 << (j - 1))] += dp[i][j][z];
					dp[i+1][j-1][z | (1 << (j - 1))] %= MOD; 
				}
			}
		}
	}

	lint res = 0;
	for(int i = 0; i < 10; i++) {
		res += dp[n][i][fullBit];
		res %= MOD;
	}

	cout << res << "\n";

}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	solve();
}
