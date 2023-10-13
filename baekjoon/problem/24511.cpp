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
	vector<int> isQueue(n);
	vector<int> values(n);
	deque<int> dq;
	
	for(int i = 0; i < n; i++) cin >> isQueue[i];
	for(int i = 0; i < n; i++) cin >> values[i];
	
	for(int i = 0; i < n; i++) {
		if(!isQueue[i])	 {
			dq.push_back(values[i]);
		}
	}

	int cnt, x;
	cin >> cnt;

	for(int i = 0; i < cnt; i++) {
		cin >> x;
		dq.push_front(x);
		cout << dq.back() << " \n"[i == cnt - 1];
		dq.pop_back();
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
