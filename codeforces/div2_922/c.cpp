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
	lint a, b, r; cin >> a >> b >> r;		

	lint diff = a - b;
	debug(diff);

	lint cnt1 = 0LL;
	lint res = 1LL << 60;
	if(diff >  0) {
		for(int i = 0; i <= 60; i++)  {
			if((a & (1LL << i)) != 0 && (b & (1LL << i)) == 0 && r >= cnt1 + (1LL << i) && (abs(diff) & (1LL << (1LL + i))) != 0){
				cnt1 += (1LL << i);
			}
		}
	} else if (diff > 0) {
		for(int i = 0; i <= 60; i++)  {
			if((b & (1LL << i)) != 0 && (a & (1LL << i)) == 0 && r >= cnt1 + (1LL << i) && (abs(diff) & (1LL << (1LL + i))) != 0){
				cnt1 += (1LL << i);
			}
		}
	}

	lint origin = abs((a ^ cnt1) - (b ^ cnt1));

	if(diff >  0) {
		for(int i = 60; i >= 0; i--)  {
			if((a & (1LL << i)) != 0 && (b & (1LL << i)) == 0 && r >= cnt1 + (1LL << i)){
				cnt1 += (1LL << i);
				lint curr = a - b - 2 * (a & cnt1 - b & cnt1);
				res = min(res, abs(curr));
				if(curr < 0) {
					cnt1 -= (1LL << i);	
				}
			}
		}
	} else if (diff > 0) {
		for(int i = 60; i >= 0; i--)  {
			if((b & (1LL << i)) != 0 && (a & (1LL << i)) == 0 && r >= cnt1 + (1LL << i)) {
				cnt1 += (1LL << i);
				lint curr = a - b - 2 * (a & cnt1 - b & cnt1);
				res = min(res, abs(curr));
				if(curr > 0) {
					cnt1 -= (1LL << i);
				}
			}
		}
	}
	
		debug(r - cnt1, res);
		lint rr = abs((a ^ cnt1) - (b ^ cnt1));
		cout << min(rr, origin) << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
