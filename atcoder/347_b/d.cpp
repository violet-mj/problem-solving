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
	lint a, b, c; cin >> a >> b >> c;		
	int reverse = 0;
	if(a > b) {
		swap(a, b);
		reverse = 1;
	}

	int cp = __builtin_popcountll(c);
	int diff = b - a;
	debug(a, b, diff, cp);
	cp -= diff;
	int ag = 0;
	int bg = diff;
	debug("diff", ag, bg, cp);



	if(cp < 0 || cp % 2 == 1 || 2 * a < cp) {
		cout << -1 << "\n";
		return;
	}


	ag += cp / 2;
	bg += cp / 2;

	debug("cp divide", ag, bg, cp);

	a -= ag;

	int last = 0;

	lint resA = 0LL;
	lint resB = 0LL;

	for(int i = 0; i < 60; i++) {
		if((c & (1LL << i)) > 0)	 {
			if(bg > 0)	 {
				resB |= (1LL << i);
				last = i;
				bg--;
			} else if(ag > 0) {
				resA |= (1LL << i);
				last = i;
				ag--;
			} else {
				break;	
			}
		} else {
			if(a <= 0) continue;
			a--;
			resA |= (1LL << (i));
			resB |= (1LL << (i));
		}
	}
	

	debug(ag, bg, last, a);
	debug(resA, resB);

	for(int i = 0; i < a; i++) {
		if(last + 1 + i >= 60)	 {
			cout << -1 << "\n";
			return;
		}
		resA |= (1LL << (last + 1 + i));
		resB |= (1LL << (last + 1 + i));
		debug(1LL << (last + 1 + i));
	}

	if(reverse) swap(resA, resB);

	cout << resA << " " << resB << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
