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
	lint n, t; cin >> n >> t;				
	vector<lint> A;
	vector<lint> B;
	map<lint, lint> m;
	vector<lint> players(n + 1, 0);
	m[0] = n;
	for(int i = 0; i < t; i++) {
		lint ai, bi; cin >> ai >> bi;	
		A.pb(ai); B.pb(bi);
		lint prev = players[ai];
		lint next = prev + bi;
		m[prev] -= 1;
		if(m[prev] <= 0) {
			m.erase(prev);
		}
		m[next]+=1;
		players[ai] = next;
		cout << m.size() << "\n";
	}
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
