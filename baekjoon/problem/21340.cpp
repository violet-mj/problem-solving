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
#define all(v) (v).begin(),(v).end()

void solve() {
	int n;			
	lint dist1, dist2;
	cin >> n;

	auto cal = [&](int p, int q) {
		cout << 0 << " " << p << endl;
		cin >> dist1;

		cout << 0 << " " << q << endl;
		cin >> dist2;

		if(dist1 <= dist2) {
			return true;
		} else {
			return false;
		}
	};

	auto calx = [&](int p, int q) {
		cout << p << " " << 0 << endl;
		cin >> dist1;

		cout << q << " " << 0 << endl;
		cin >> dist2;

		if(dist1 <= dist2) {
			return true;
		} else {
			return false;
		}
	};
	auto calc = [&](int v) {
		cout << 0 << " " << v << endl;
		cin >> dist1;
		return dist1;
	};
	auto calcx = [&](int v) {
		cout << v << " " << 0 << endl;
		cin >> dist1;
		return dist1;
	};

	for(int i = 0; i < n; i++) {
		// find y	

		int l = 0;
		int r = 1e6; 

		while(r - l >= 3) {
			int p = (l * 2 + r)	/ 3;
			int q = (l + 2 * r) / 3;

			if(cal(p, q)) {
				r = q;	
			} else {
				l = p;	
			}
		}
		lint min_ = 1LL << 60;
		int idx = -1;
		bool flag = false;
		for(int i = l; i <= r; i++) {
			lint resultv = calc(i);
			if(resultv == 0) {
				flag = true;
				break;
				if(resultv < min_) {
					idx = i;	
					min_ = min(min_, resultv);
				}
			}
		}

		if(flag) continue;

		l = 0;
		r = 1e6;

		while(r - l >= 3) {
			int p = (l * 2 + r) / 3;			
			int q = (l + 2 * r) / 3;

			if(calx(p, q)) {
				r = q;	
			} else {
				l = p;	
			}
		}

		lint minx = 1LL << 60;
		int idxx = -1;
		flag = false;

		for(int i = l; i <= r; i++) {
			lint resultv = calcx(i);
			if(resultv == 0) {
				flag = true;
				break;
			}
			if(resultv < minx){ 
				idxx = i;	
				minx = resultv; 
			}
		}

		if(!flag) {
			cout << idxx << " " << idx << endl;	
			cin >> dist1;
		}
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
