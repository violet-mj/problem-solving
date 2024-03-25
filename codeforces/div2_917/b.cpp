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
	int n; 		
	string s;
	cin >> n >> s;

	set<char> check;

	if(n == 1) {
		cout << 1 << "\n";
		return;
	}

	check.insert(s[0]);
	check.insert(s[1]);
	int cnt = 1;
	for(int i = 2; i < n; i++) {
		cnt += check.size();		
		check.insert(s[i]);
	}
	cnt += check.size();
	
	cout << cnt << "\n";

}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
