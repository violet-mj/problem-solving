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
	int n, q; string s;
	cin >> n >> s >> q;
	vector<vector<int>> check(26);
	vector<int> alpha(26);
	for(int i = 0; i < 26; i++) {
		alpha[i] = i;
	}

	for(int i = 0; i < q; i++) {
		char fc, sc;		
		cin >> fc >> sc;
		for(int i = 0; i < 26; i++) {
			if(alpha[i] == fc - 'a')	 {
				alpha[i] = sc - 'a';
			}
		}
	}

	for(int i = 0; i < n; i++) {
		cout << ((char)(alpha[s[i] - 'a'] + 'a'));
	}
	cout << "\n";

}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
