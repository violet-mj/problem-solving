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

int makeBinDecimal(int check) {
	int k = 0;
	int ten = 1;
	
	for(int i = 0; i < 5; i++) {
		if((check & (1 << i)) > 0) {
			k += ten;
		}
		ten *= 10;
	}

	return k;
}

void solve() {
	int n; cin >> n;		
	int cn = n;

	int flag = 1;

	while(cn != 0) {
		if(cn % 10 > 1) {
			flag = 0;
			break;
		}
		cn /= 10;
	}

	if(flag) {
		 cout << "YES\n"	;
		 return;
	}

	while(n % 100000 == 0) {
		n /= 100000;
	}

	for(int i = 2; i < (1 << 5); i++) {
		int dec = makeBinDecimal(i);
		while(n % dec == 0) {
			n /= dec;
		}
	}

	cout << (n == 1 ? "YES\n": "NO\n");
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
