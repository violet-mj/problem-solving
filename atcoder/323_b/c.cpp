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
	int n, m;		
	cin >> n >> m;
	vector<int> score(m, 0);
	vector<pii> score_(m);
	for(int i = 0; i < m; i++ ) {
		cin >> score[i];
		score_[i] = mp(i, score[i]);
	}

	sort(all(score_), [](pii p1, pii p2) {
				return p1.s > p2.s;	
	});

	vector<vector<char>> board(n, vector<char>(m, '-'));
	vector<int> playerScore(n, 0);
	for(int i = 0; i < n; i++) {
		playerScore[i]+=(i+1);
		for(int j = 0; j < m; j++)	 {
			cin >> board[i][j];
			if(board[i][j] == 'o') {
				playerScore[i]+=score[j];
			}
		}
	}

	for(int i = 0; i < n; i++) {
		int max_ = 0;
		for(int j = 0; j < n; j++)		 {
			if(i == j) continue;	
			max_ = max(max_, playerScore[j]);
		}
		debug(max_);
		int curr = playerScore[i];
		int res = 0;
		bool flag = true;
		for(int z = 0; z < m; z++) {
			if(curr >= max_) {
				cout << res << "\n";
				flag = false;
				break;
			}
			if(board[i][score_[z].f] == 'o') continue;
			curr += score_[z].s;
			res++;
		}

		if(flag) cout << res << "\n";
	}
	debug(playerScore);
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
