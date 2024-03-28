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
	string s;	cin >> s;
	int sn = s.size();
	int cnt[2] = {0, 0};
	int oneLoc = -1;

	for(int i = 0; i < sn; i++) {
		cnt[s[i] - '0']++;
		if(s[i] - '0' == 1) oneLoc = i;
	}

	debug(cnt[0], cnt[1]);

	if(cnt[0] > cnt[1]) {
		for(int i = 0; i < sn; i++) {
			cout << "1";
		}
	} else if(cnt[1] > cnt[0]) {
		for(int i = 0; i < sn; i++) {
			cout << "0";
		}
	} else {
		int init = s[0] - '0';
		cout << (init ^ 1);
		for(int i = 1; i < sn; i++) {
			if(init == 0) {
				cout << "0";
			} else {
				cout << "1";
			}
		}
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
