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
	int n;			
	cin >> n;

	if(n % 3 == 0) {
		if(n - 12 >= 0) {
			cout << "Yes\n";	
			cout << 1 << " " << 4 << " " << n - 5 << "\n";
			return;
		}
		cout << "No\n";
		return;
	} else if(n % 3 == 1) {
		if(n - 7 >= 0)	 {
			cout << "Yes\n";
			cout << 1 << " " << 2 << " " << n - 3 << "\n";
			return;
		}
		cout << "No\n";
		return;
	} else {
		if(n - 8 >= 0)	 {
			cout << "Yes\n";
			cout << 1 << " " << 2 << " " << n - 3 << "\n";
			return;
		}
		cout << "No\n";
		return;
	}
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
