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
	lint A, B, P;
	cin >> A >> B >> P;

	vector<lint> ai(A+1, 0);
	vector<lint> bi(B+1, 0);
	vector<lint> prefixA(A+1, 0);
	vector<lint> prefixB(B+1, 0);

	for(int i = 1; i <= A; i++) {
		cin >> ai[i];
	}
	for(int i = 1; i <= B; i++) {
		cin >> bi[i];
	}

	sort(all(ai));
	sort(all(bi));

	for(int i = 1; i <= A; i++) {
		prefixA[i] = prefixA[i-1] + ai[i];
	}
	for(int i = 1; i <= B; i++) {
		prefixB[i] = prefixB[i-1] + bi[i];
	}

	auto binarySearch = [&](lint currNum) {
		lint l = 0;		
		lint r = B+1;
		lint diff = P - currNum;
		debug(diff);
		while(l + 1 < r) {
			lint mid = (l + r) >> 1;
			debug(mid);
			if(bi[mid] > diff) {
				r = mid;	
			}	else {
				l = mid;	
			}
		}

		return l;
	};

	lint res = 0LL;
	for(int i = 1; i <= A; i++) {
		lint idx = binarySearch(ai[i]);
		// debug(prefixB[idx], ai[i] * idx, P * (B - idx));
		res += prefixB[idx];
		res += ai[i] * idx;
		res += P * (B - idx);
	}

	cout << res << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
