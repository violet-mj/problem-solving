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
	int n, r;		
	cin >> n >> r;

	vector<pii> babpool(n);

	for(int i = 0; i < n; i++) {
		cin >> babpool[i].f >> babpool[i].s;	
	}

	auto check = [&](int cx, int cy) {
		int cnt = 0;
		for(int i = 0; i < n; i++) {
			int diffx = babpool[i].f - cx;
			int diffy = babpool[i].s - cy;
			
			if(diffx * diffx + diffy * diffy <= r * r) {
				cnt++;	
			}
		}

		return cnt;
	};

	int maxCount = 0;
	int maxx = -1;
	int maxy = -1;

	for(int x = -100; x <= 100; x++) {
		for(int y = -100; y <= 100; y++) {
			int count = check(x, y);

			if(count >= maxCount) {
				maxCount = count;		
				maxx = x;
				maxy = y;
			}
		}
	}

	cout << maxx << " " << maxy << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
