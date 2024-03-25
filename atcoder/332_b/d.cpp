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
	int n, m;		
	cin >> n >> m;
	
	vector<vector<int>> g1(n, vector<int>(m));
	vector<vector<int>> g2(n, vector<int>(m));

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> g1[i][j];
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> g2[i][j];
		}
	}

	vector<int> x(n);
	for(int i = 0; i < n; i++) {
		x[i] = i;
	}
	vector<int> y(m);
	for(int i = 0; i < m; i++) {
		y[i] = i;
	}

	int gcnt = 1 << 30;
	int count = 0;

	do {
		if(count > 20000) break;
		do {
			if(count > 20000) break;
			count++;
			bool flag = true;
			for(int i = 0; i < n && flag; i++) {
				for(int j = 0; j < m && flag; j++) {
					if(g1[x[i]][y[j]] == g2[i][j]) {
						continue;	
					} else {
						flag = false;
					}
				}
			}
			if(!flag) continue;

			int cnt = 0;

			for(int i = n -1; i >= 0; i--) {
				for(int j = 0; j < i; j++) {
					if(x[j] > x[j+1])	 {
						swap(x[j], x[j+1]);
						cnt++;
					}
				}
			}
			for(int i = m - 1; i >= 0; i--) {
				for(int j = 0; j < i; j++) {
					if(y[j] > y[j+1])	 {
						swap(y[j], y[j+1]);
						cnt++;
					}
				}
			}
			gcnt = min(cnt, gcnt);
		} while(next_permutation(all(y)));
	} while(next_permutation(all(x)));

	if(gcnt == 1 << 30) {
		cout << -1 << "\n";
	} else {
		cout << gcnt << "\n";
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
