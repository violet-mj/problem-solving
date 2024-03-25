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

void solve() {
	string s;			
	cin >> s;
	int n = s.size();
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

	for(int i = 0; i <= n; i++) {
		for(int j = 1; j <= n; j++)	{
			if(j + i > n) continue;
			if(s[j - 1] == s[j + i - 1])  {
				if(j + 1 > j + i - 1)	{
					dp[j][j + i] = 1;	
				} else {
					if(dp[j+1][j + i - 1] == 1) {
						dp[j][j + i] = 1;
					}
				}
			}
		}
	}

	int cnt = 0;

	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++)	{
			if(dp[i][j]) cnt++;	
		}
	}

	cout << (cnt % 10007) << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
