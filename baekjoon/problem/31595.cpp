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
	int n; cin >> n;	
	lint ans = 0LL;
	vector<int> cnt(n);
	vector<lint> val(n);
	for(int i = 0; i < n; i++) cin >> cnt[i];
	int clz = 0;
	for(int i = 0; i < n - 1; i++)  {
		int dcnt = abs(cnt[i + 1] - cnt[i] - 1);
		clz = max(clz, dcnt + 1);
		val[i] = (1LL << dcnt) - 1;
		if(val[i] - i >= 0) ans |= (val[i] - i);
	}

	debug(val);

	int oneCnt = __builtin_popcountll(ans);
	int diff = cnt[0] - oneCnt;

	for(int i = 0; i < diff; i++) {
		ans |= 1LL << clz++;	
	}

	lint res = ans;

	for(int i = 0; i < n; i++) {
		if(cnt[i] != __builtin_popcountll(ans++))	 {
			cout << -1 << "\n";
			return;
		}
	}

	cout << res << "\n";

}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
