#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
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

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"

int n, k, m;

void solve() {
	cin >> n >> k >> m;
	deque<int> q;	

	for(int i = 1; i <= n; i++) {
		q.push_back(i);
	}

	vector<int> res;

	for(int i = 0; i < n; i++) {
		int loc = i / m;
		if(loc % 2 == 0)	{
			for(int j = 0; j < k - 1; j++) {
				int qf = q.front();			
				q.pop_front();
				q.push_back(qf);
			}
			res.pb(q.front());
			q.pop_front();
		} else {
			for(int j = 0; j < k - 1; j++) {
				int qb = q.back();			
				q.pop_back();
				q.push_front(qb);
			}
			res.pb(q.back());
			q.pop_back();
		}
		debug(res);
		debug(q);
	}


	for(int i = 0; i < n; i++) {
		cout << res[i] << "\n";
	}

}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
