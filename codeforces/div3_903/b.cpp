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
		
	int a,b,c;
	cin >> a >> b >> c;

	vector<int> value = {a, b, c};

	int min_ = min({a, b, c});
	int max_ = max({a, b, c});
	int cnt = 0;

	for(auto i: value) {
		if(i % min_ != 0) {
			cout << "NO\n";
			return;
		} else {
			cnt += i / min_ - 1;
		}
	}
	
	if(cnt > 3) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}
	
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
