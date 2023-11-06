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

const int MAX = 300000;
const int ROOT = 1;

struct Trie {
	int nxt[MAX+1][2];
	bool isEnd[MAX+1];
	int nextN;

	Trie(): nextN(1) {
		fill(&nxt[0][0], &nxt[MAX][2], 0);
		fill(isEnd, &isEnd[MAX+1], false);
	}

	void insert(int target) {
		int curr = ROOT;
		while(target > 0)	{
			debug(curr, target);
			int num = target & 1;	
			target >>= 1;
			if(!nxt[curr][num]) {
				nxt[curr][num] = ++nextN;
			}
			curr = nxt[curr][num];
		}
		isEnd[curr] = true;
	}

	int dp(int currNode, int currDepth, bool isZero) {
		if(currNode == 0) return 0;
		int curr = currDepth == -1 || isZero ? 0 : 1 << currDepth;
		return curr | (dp(nxt[currNode][0], currDepth + 1, true) | dp(nxt[currNode][1], currDepth + 1, false));
	}
};

void solve() {
	int n;
	cin >> n;
	Trie trie;		
	for(int i = 0; i < n; i++)	 {
		int tmp;
		cin >> tmp;
		trie.insert(tmp);
	}
	debug(2);
	cout << trie.dp(ROOT, -1, true) << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
