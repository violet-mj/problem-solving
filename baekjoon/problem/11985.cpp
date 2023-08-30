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

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define all(v) (v).begin(),(v).end()

const lint INF = 1LL << 60;

// 정수가 int형의 범위를 넘어가는지
// integer overflow 확인
// 정방향이 아닌 역방향도 생각해보기
void solve() {
	int n, m;
	lint k;				
	cin >> n >> m >> k;
	vector<lint> orange(n + 1, 0);
	vector<lint> dp(n + 1, INF);
	dp[0] = 0;

	debug(dp);

	for(int i = 1; i <= n; i++) {
		cin >> orange[i];
	}

	for(int i = 1; i <= n; i++) {

		lint min_ = orange[i];
		lint max_ = orange[i];
		for(int j = 0; j < m; j++)	{
			if(i - j - 1 < 0) break;
			if(orange[i-j] < min_) min_ = orange[i-j];
			if(orange[i-j] > max_) max_ = orange[i-j];
			dp[i] = min(dp[i], dp[i-j-1] + k + (j+1) * (max_ - min_))	;
		}
		debug(dp)	;
	}
	cout << dp[n] << "\n";
}


int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
