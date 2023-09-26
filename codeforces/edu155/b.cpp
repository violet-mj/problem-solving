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
	int n;		
	cin >> n;

	vector<lint> a(n);
	vector<lint> b(n);

	lint aSum = 0;
	lint bSum = 0;

	for(int i = 0; i < n; i++) {
		cin >> a[i];
		aSum += a[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> b[i];
		bSum += b[i];
	}

	cout << min(*min_element(all(a)) * n + bSum, *min_element(all(b)) * n + aSum) << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
