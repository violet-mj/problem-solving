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

void solve() {
	int n, x;
	cin >> n >> x;
	int sum_ = 0;
	vector<int> values(n-1);
	for(int i = 0; i < n-1; i++) {
		cin >> values[i];
		sum_ += values[i];
	}
	sort(all(values));
	sum_ -= values[0];
	sum_ -= values[n-2];
	debug(values);
	debug(sum_);
	
	for(int i = 0; i <= 100; i++)	{
		if(i < values[0])	{
			sum_ += values[0];
			if(sum_ >= x) {
				cout << i << "\n"	;
				return;
			}
			sum_ -= values[0];
		} else if(i > values[n-2]) {
			sum_ += values[n-2];
			if(sum_ >= x) {
				cout << i << "\n";
				return;
			}
			sum_ -= values[n-2];
		} else {
			sum_ += i;
			if(sum_ >= x) {
				cout << i << "\n";
				return;
			}
			sum_ -= i;
		}
	}

	cout << -1 << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
