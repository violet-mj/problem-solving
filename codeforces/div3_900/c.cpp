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
	lint n, k, x;		
	cin >> n >> k >> x;
	lint minValue = n - k;
	lint checkMax = n * (n + 1) / 2 - minValue * (minValue + 1) / 2;
	lint checkMin = k * (k + 1) / 2;

	if(x <= checkMax && x >= checkMin) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}


}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
