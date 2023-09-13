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
	vector<int> values(n, 0);
	vector<pii> pValue(n);
	for(int i =0 ; i < n; i++) {
		cin >> values[i];
		pValue[i] = mp(values[i], i);
	}	

	sort(all(pValue));
	reverse(all(pValue));
	vector<int> res(n);

	for(int i = 0; i < n; i++) {
		res[pValue[i].s] = i+1;
	}

	for(int i =0 ; i < n; i++) {
		cout << res[i] << " \n"[i == n - 1];
	}
}


int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
