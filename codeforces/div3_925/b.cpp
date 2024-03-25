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
	vector<int> ws(n);
	lint sum_ = 0LL;

	for(int i = 0; i < n; i++) {
		cin >> ws[i];
		sum_ += ws[i];
	}

	lint avg = sum_ / n; 
	lint remain = 0LL;

	for(int i = 0; i < n; i++) {
		if(ws[i] >= avg)	 {
			remain += (ws[i] - avg);
		} else {
			if(avg - ws[i] > remain) {
				cout << "NO\n";
				return;
			} else {
				remain -= (avg - ws[i]);
			}
		}
	}

	cout << "YES\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) 
	solve();
}
