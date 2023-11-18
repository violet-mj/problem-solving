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
	vector<int> values(m);
	vector<int> check(n, 0);
	for(int i = 0; i < m; i++) cin >> values[i];
	int winner = -1;
	int number = 0;

	for(int i = 0; i < m; i++) {
		if(i == 0)	 {
			cout << values[i]	<< "\n";
			winner = values[i];
			number = 1;
			check[winner]++;
			continue;
		} else {
			if(check[values[i]] + 1 < number) {
				check[values[i]]++;
			} else if(check[values[i]] + 1 == number) {
				if(values[i] < winner)	 {
					winner = values[i];
				}
				check[values[i]]++;
			} else {
				winner = values[i];
				check[values[i]]++;
				number = check[values[i]];
			}
		}

		cout << winner << "\n";
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
