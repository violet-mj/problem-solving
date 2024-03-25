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
		int moo = 0;
		int cnt = 0;
		int win = 0;
		int lose = 0;
		for(int i = 0; i < 6; i++) {
			int a, b, c; cin >> a >> b >> c;	
			if(a + b + c != 5) {
				cout << "0 ";
				return;
			}
			moo = max(moo, b * 2);
			win += a;
			lose += c;
			cnt += b;
		}

		if(win + cnt/2 != 15 || lose + cnt/2 != 15 || cnt < moo || cnt % 2 == 1) {
			cout << "0 ";
			return;
		}
		cout << "1 ";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t = 4;
	for(int i = 0; i < t; i++) 
	solve();
}
