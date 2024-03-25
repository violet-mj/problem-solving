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
	cin >> n;

	vector<int> values(n);
	vector<int> fail(n, 0);
	for(int i = 0; i < n; i++) cin >> values[i];

	reverse(all(values));
	debug(values);

	for(int i = 1, j =0; i < n; i++) {
		while(j > 0 && values[i] != values[j])	j = fail[j - 1];
		if(values[i] == values[j]) fail[i] = ++j;
	}

	debug(fail);
	int cnt = 1e9;
	int k = 0;
	int p = 0;
	for(int i = 0; i < n; i++) {
		int ck = n - 1 - i;
		int cp = i + 1 - fail[i];
		int ccnt = ck + cp;

		if(ccnt == cnt) {
			if(cp < p) {
				p = cp;				
				k = ck;
			}
		} else if(ccnt < cnt) {
				p = cp;		
				k = ck;
				cnt = ccnt;
		}
	}

	cout << k << " " << p << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
