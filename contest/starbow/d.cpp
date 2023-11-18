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

const vector<string> stari = {
	"  *  ",
	"  *  ",
	"*****",
	" *** ",
	" * * ",
};

vector<vector<char>> board;

void recur(int currX, int currY, int currSize, bool isStar) {
	if(currSize == 1) {
		for(int i = 0; i < 5; i++) {
			for(int j = 0; j < 5; j++) {
				board[currX + i][currY + j] = isStar ? stari[i][j] : ' ';
			}
		}
		return;
	}

	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			recur(currX + i * currSize, currY + j * currSize, currSize / 5, isStar & (stari[i][j] == '*'));
		}
	}

}

void solve() {
	int n;
	cin >> n;
	int pows = (int)pow(5, n);

	if(n == 0) {
		cout << "*\n";
		return;
	} else if(n == 1) {
		for(int i = 0; i < 5; i++)	 {
			for(int j = 0; j < 5; j++)	 {
				cout << stari[i][j];	
			}
			cout << "\n";
		}
		return;
	}
	board.assign(pows, vector<char>(pows));
	pows /= 5;
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
				recur(i * pows, j * pows, pows / 5, (stari[i][j] == '*'));
		}
	}

	for(int i = 0; i < board.size(); i++) {
		for(int j = 0; j < board.size(); j++)	 {
			cout << board[i][j];
		}
		cout << "\n";
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
