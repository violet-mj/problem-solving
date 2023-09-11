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

int n, m;
void solve() {
	cin >> n >> m;	

	vector<vector<int>> graph(n, vector<int>(m, 0));

	if(m == 1) {
		cout << 0 << "\n"	;
		for(int i = 0; i < n; i++) {
			cout << 0 << "\n";
		}
		return;
	}

	if(n < m) {
		cout << n + 1 << "\n";
	} else {
		cout << m << "\n"	;
	}

	if(m == 2) {
		for(int i = 0; i < n; i++)	 {
			cout << 0 << " " << 1 << "\n";
		}
		return;
	}

	if(m == 3) {
		int n2 = n / 2;		
		int nSub = n - n2;

		for(int i = 0; i < n2; i++)  {
			cout << 0 << " " << 2 <<  " " << 1 << "\n";
		}

		for(int i = 0; i < nSub; i++) {
			cout << 1 << " " << 0 <<  " " << 2 << "\n";
		}
		return;
	}

	for(int j = 0; j < m; j++) {
		for(int i = 0; i < n; i++)	 {
			graph[i][j] = m - 1 - j;	
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < m; j++)	{
			graph[i][j] = j - i - 1;	
		}
	}

	if(m % 2 == 1) {
	  for(int i = m/2; i < n; i++) {
		  graph[i][m/2]	^= graph[i][0];
		  graph[i][0] ^= graph[i][m/2];
		  graph[i][m/2] ^= graph[i][0];
	  }
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)	 {
			cout << graph[i][j] << " ";	
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
