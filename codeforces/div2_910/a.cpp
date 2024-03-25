
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
	int n, k;
	string s;
	cin >> n >> k >> s;
	int cnt = count(all(s), 'B');

	if(cnt == k) {
		cout << 0 << "\n";
		return;
	}

	int bcnt = 0;

	for(int i = n - 1; i >= 0; i--) {
		if(bcnt == k) {
			cout << 1 << "\n";
			cout << i + 1 << " A\n";	
			return;
		}

		if(bcnt + i + 1 == k) {
			cout << 1 << "\n";
			cout << i + 1 << " B\n";
			return;
		}

		bcnt += (s[i] == 'B' ? 1 : 0);
	}

}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
