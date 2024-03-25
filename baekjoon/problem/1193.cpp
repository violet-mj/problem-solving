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

	int cnt, ccnt;

	for(int i = 1; i <= n; i++) {
		if(i * (i + 1) / 2 >= n) {
			cnt = i - 1;	
			ccnt = n - (i * (i - 1) / 2);
			break;
		}
	}

	int hope = cnt + 2;

	cout << (hope % 2 == 0 ? to_string(hope - ccnt) + "/" + to_string(ccnt) : to_string(ccnt) + "/" + to_string(hope-ccnt)) << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
