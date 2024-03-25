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
	int n, t, p;		
	cin >> n;
	vector<int> ts(6);
	for(int i = 0; i < 6; i++) cin >> ts[i];
	cin >> t >> p;
	int sum_ = 0;
	for(int i = 0; i < 6; i++) {
		sum_ += (ts[i] + t - 1) / t; 	
	}

	cout << sum_ << "\n";
	cout << n / p << " " << n % p << "\n";

}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
