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
int n;			
int skill[21][21];
vector<int> currState;
int sum_ = 0;
int c = 0;
int sN;
int res = 1 << 30;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define all(v) (v).begin(),(v).end()

set<int> ss;

void backtracking(int currValue) {
	int currComb = 0;	
	int currSize = currState.size() - 1;
	int currStateValue = currState[currSize];
	for(int i = currSize; i >= 0; i--) {
		int iValue = currState[i];
		currComb += skill[currStateValue][iValue];
		currComb += skill[iValue][currStateValue];
	}
	if(currState.size() == sN) {
		int s = 0;
		for(auto z = ss.begin(); z != ss.end(); z++) {
			for(auto j = z; j != ss.end(); j++)	{
				int zz = *z;	
				int jj = *j;
				s += skill[zz][jj];
				s += skill[jj][zz];
			}
		}
		// debug(currState, ss, c, s - c, s);
		c += currComb;
		res = min(res, abs(s - c));
		c -= currComb;
		return;
	}
	for(int i = currValue + 1; i <= n; i++) {
		c += currComb;	
		ss.erase(i);
		currState.pb(i);
		backtracking(i);
		c -= currComb;
		ss.insert(i);
		currState.pop_back();
	}
}

void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++)	 {
			cin >> skill[i][j];
		}
	}

	for(int i = 1; i <= n; i++) {
		ss.insert(i);
	}
	 
	debug(sum_);
	sN = n / 2;

	for(int i = 1; i <= n; i++) {
		currState.pb(i);
		ss.erase(i);
		backtracking(i);
		currState.pop_back();
		ss.insert(i);
	}

	cout << res << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
