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
	char graph[2*n][2*n];
	int flag = 1;
	char cc[2] = {'.', '#'};

	for(int i = 0; i < 2 * n; i += 2) {
		flag = (i / 2 + 1) % 2;
		for(int j = 0; j < 2 * n; j += 2)	 {
			for(int x = 0; x < 2; x++) {
				for(int y = 0; y < 2; y++) {
					graph[i+x][j+y]	= cc[flag];
				}
			}
			flag ^= 1;
		}
	}

	for(int i = 0; i < 2 * n; i++) {
		for(int j = 0; j < 2 * n; j++) {
			cout << graph[i][j];
		}
		cout << "\n";
	}
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
