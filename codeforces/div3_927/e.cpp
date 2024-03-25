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
	int nn; cin >> nn;		
	string news; cin >> news;
	vector<char> s;

	int z;
	for(z = 0; z < nn; z++) {
		if(news[z] == '0')	continue;
		else break;
	}

	debug(z);

	for(int i = z; i < nn; i++) {
		s.pb(news[i]);
	}

	int n = s.size();

	vector<int> preSum(n + 1, 0);
	for(int i = 1; i <= n; i++) {
		preSum[i] = preSum[i - 1]	+ (s[i-1] - '0');
	}
	reverse(all(preSum));
	debug(preSum);
	vector<int> res;

	int cnt = 0;

	for(int i = 1; i <= n; i++) {
		cnt += (-preSum[n]	+ preSum[i - 1]);
		res.pb(cnt % 10);
		debug(cnt ,cnt % 10);
		cnt /= 10;
	}

	while(cnt > 0) {
		res.pb(cnt	% 10);
		cnt /= 10;
	}
	reverse(all(res));
	for(int i = 0; i < res.size(); i++) {
		cout << res[i];
	}
	cout << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
