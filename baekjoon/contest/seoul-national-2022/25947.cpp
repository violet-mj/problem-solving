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
	lint n, b, a;			
	cin >> n >> b >> a;
	vector<lint> items(n);
	for(int i = 0; i < n; i++) cin >> items[i];
	sort(all(items));
	debug(items);

	int l = 0;
	int r = n + 1;

	lint currPrice = 0LL;
	int discount = 0LL;
	int itemCount = 0LL;

	for(int i = 0; i < n; i++) {
		debug(currPrice, itemCount, discount);
		if(currPrice > b) {
			cout << itemCount - 1 << "\n"	;
			return;
		}
		if(discount < a) {
			currPrice += items[i] / 2;	
			discount++;
		} else {
			currPrice += items[i] / 2;	
			currPrice += items[i-a] / 2;
		}
		itemCount++;
	}
	
	if(currPrice > b) {
		cout << itemCount - 1 << "\n";
	} else {
		cout << itemCount << "\n"	;
	}

}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}