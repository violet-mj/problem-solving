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

int gcd(int a, int b) {
	while(b != 0) {
		a = a % b;
		swap(a, b);
	}
	return a;
}

void solve() {
	int n, m;		
	cin >> n >> m;
	vector<pair<int, int>> values;

	values.push_back(mp(0, 1));
	for(int i = 1; i <= n; i++)  {
		for(int j = 1; j <= i; j++)	 {
			if( gcd(i, j) == 1 && i * 2 < j) {
				values.push_back(mp(j, i));
			}
		}
	}

	sort(values.begin(), values.end(), [](pii p1, pii p2) {
		return p1.first * p2.second < p1.second * p2.first;	
	});
	int vs = values.size();

	for(int i = 0; i < values.size(); i++) {
		cout << values[i].first << " " << values[i].second << "\n";
	}

	if(m-1 > vs - 1) {
		cout << values[vs-1-(m-1)].first << " " << values[vs-1-(m-1)].second << "\n";
	} else {
		cout << values[m-1].first << " " << values[m-1].second << "\n";
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
