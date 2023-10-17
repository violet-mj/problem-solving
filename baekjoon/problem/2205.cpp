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


int log2(int n) {
	int cnt = 0;
	while(n % 2 == 0) {
		cnt++;
		n/=2;
	}
	return cnt;
}

void solve() {
	int n;
	cin >> n;
	vector<int> visited(10001, 0);

	for(int i = 1; i <= n; i++) {
		int square = 1 << (log2(i) + 1);
		while(visited[square - i] || square - i <= 0) {
			square <<= 1;	
		}
		visited[square - i] = 1;
		// debug(i, square - i, square);
		cout << square - i << "\n";
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
