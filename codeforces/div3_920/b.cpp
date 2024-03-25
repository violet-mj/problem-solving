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
	int n;
	string s1, s2;
	cin >> n >> s1 >> s2;
	int cnt = 0;
	int c1 = 0;
	int c2 = 0;
	for(int i = 0; i < n; i++) {
		if(s1[i] == '0' && s2[i] == '1')	 {
			cnt++;	
		}

		if(s1[i] == '1') c1++;
		if(s2[i] == '1') c2++;
	}

	debug(c1, c2, cnt);

	cout << max(0, c1 - c2) + cnt << "\n";

}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) 
	solve();
}
