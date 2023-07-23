#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

#define mp make_pair 
#define pb push_back 
#define f first 
#define s second

#ifdef DEBUG
#define debug 1
#else
#define debug 0
#endif

int n, tmp;
const int possible[12] = {202021, 20202021, 202002021, 202012021, 202022021, 202032021, 202042021, 202052021, 202062021, 202072021, 202082021, 202092021};


void solve() {
	cin >> n;
	vector<int> v;
	for(int i = 0; i < n; i++) {
		cin >> tmp;		
		v.pb(tmp);
	}

	sort(v.begin(), v.end());

	long result = 0;

	for(int i = 0; i < n; i++) {
		int curr = v[i];
		for(auto search: possible) {
			auto l = lower_bound(v.begin() + i + 1, v.end(), search - curr);
			auto r = upper_bound(v.begin() + i + 1, v.end(), search - curr);
			if(debug) cout << "i : " << i <<  "l : " << l - v.begin() << "r : " << r - v.begin() << " search : " << search <<  " r - l : " << r - l << "\n";
			result += (r-l);
		}		
	}

	if(debug) cout << "result: ";
	cout << result << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;

	for(int i = 0; i < t; i++) solve();
}
