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
	vector<int> pre(31, 1 << 30);
	pre[0] = 0;
	int check[5] = {1, 3, 6, 10, 15};

	for(int i = 1; i <= 30; i++) {
		for(int j = 0; j < 5; j++) {
			if(i - check[j] < 0) continue;
			pre[i] = min(pre[i], pre[i - check[j]] + 1);
		}
	}

	if(n <= 15) {
		cout << pre[n] << "\n";
	} else {
		cout << n / 15 - 1 + (pre[n % 15 + 15]) << "\n";
	}

}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
