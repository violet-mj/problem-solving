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
	int h, w, xa, ya, xb, yb;		
	cin >> h >> w >> xa >> ya >> xb >> yb;

	int isWinH = 0;
	int isWinW = 0;

	if(xa >= xb) {
		cout << "Draw\n";
		return;
	}

	int diffx = abs(xa - xb);

	if(diffx % 2 == 1) {
		isWinH = 1;
	}

	if(ya == yb) {
		if(isWinH) {
			cout << "Alice\n";
		} else {
			cout << "Bob\n";
		}
		return;
	}

	if(isWinH) {
		if(ya <= yb) {
			if(w - ya + w - yb <= diffx)	{
				isWinW = 1;	
			}
		} else {
			if(ya + yb <= diffx) {
				isWinW = 1;	
			}
		}
	} else {
		if(ya <= yb)	 {
			if(w - yb + w - ya <= diffx)	 {
				isWinW = 1;	
			} 
		} else {
			if(ya + yb <= diffx)	 {
				isWinW = 1;	
			}
		}
	}

	debug(isWinH, isWinW);

	if(isWinW == 0) {
		cout << "Draw\n";
	} else {
		if(isWinH)	 {
			cout << "Alice\n";
		} else {
			cout << "Bob\n";
		}
	}
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) 
	solve();
}
