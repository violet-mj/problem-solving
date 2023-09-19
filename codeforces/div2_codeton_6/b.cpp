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
void solve() {
	cin >> n >> m;
	vector<int> ai(n);
	vector<int> bi(m);

	int bSum = 0;
	int aSum = 0;
	for(int i = 0; i < n; i++) {
		cin >> ai[i];
		aSum ^= ai[i];
	}
	for(int i = 0; i < m; i++) {
		cin >> bi[i];
		bSum |= bi[i];
	}
	

	if(n % 2 == 1) {
		cout << aSum << " " << (aSum | bSum) << "\n";
	} else {
		cout << (aSum & ~bSum) << " " << aSum << "\n";
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
