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
	string s; cin >> s;
	int sn = (int)sqrt(n) + 1;
	vector<int> prime;

	for(int i = 1; i <= sn; i++) {
		if(n % i == 0) {
			prime.pb(i);
			if(n / i != i) {
				prime.pb(n / i);
			}
		}
	}

	int min_ = 1 << 30;

	for(int p: prime) {

		int error1 = 0;

		for(int i = 0; i < n; i+=p) {
			for(int j = 0; j < p; j++) {
				if(s[j] != s[i + j]) {
					error1++;	
				}
			}
		}

		int error2 = 0;

		for(int i = 0; i < n; i+=p) {
			for(int j = 0; j < p; j++) {
				if(p + j >= n) break;
				if(s[p + j] != s[i + j]) {
					error2++;	
				}
			}
		}

		if(error1 <= 1 || error2 <= 1) {
			min_ = min(min_, p);
		}
	}

	cout << min_ << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
