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

int n, m;
vector<int> words;

void solve() {	
	cin >> n >> m;
	words.resize(n, 0)	;

	for(int i =0; i < n; i++) {
		cin >> words[i];
	}

	lint l = 0;
	lint r = 1LL << 60;

	auto check = [&](lint v) {
		lint curr = 0;	
		lint width = 1;

		for(int i = 0; i < words.size(); i++) {
			if(words[i] > v) return false;
			if(curr + words[i] <= v)	 {
				curr += words[i] + 1;	
			} else {
				width++;
				curr = words[i] + 1;
			}
		}
		if(width > m) {
			return false;	
		} else {
			return true;	
		}
	};

	while(l + 1 < r) {
		lint mid = (l + r) >> 1;	
		if(check(mid))	{
			r = mid;	
		} else {
			l = mid;	
		}
	}
	cout << r << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
