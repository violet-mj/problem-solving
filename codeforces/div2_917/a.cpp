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
	vector<int> value(n);
	int minus = 0;
	int zero = 0;
	for(int i = 0; i < n; i++) {
		cin >> value[i];
		if(value[i] < 0) minus++;
		if(value[i] == 0) zero++;
	}

	if(zero > 0) {
		cout << 0 << "\n";
		return;
	}

	if(minus == 0 || minus % 2 == 0) {
		cout << 1 << "\n";
		cout << 1 << " " << 0 << "\n";
	} else if(minus % 2 == 1)  {
		cout << 0 << "\n";
	}
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
