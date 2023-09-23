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

map<int, pair<int,int>> numberMap = {
	{0, mp(1, 2)},
	{1, mp(0, 2)},
	{2, mp(0, 1)},
};


void solve(int seq) {
	char namsu;		
	char board[3][3];

	for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) cin >> board[i][j];
	cin >> namsu;

	auto printArray = [&](int seq, int x, int y) {
				cout << "Case " << seq << ":\n";
				board[x][y] = namsu;
				for(int i = 0; i < 3; i++) {
					for(int j = 0; j < 3; j++){
							cout << board[i][j];
					}
					cout << "\n";
				}
				return true;
	};

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++){
			if(board[i][j] == '-' && board[i][numberMap[j].f] == namsu && board[i][numberMap[j].s] == namsu)	{
				printArray(seq, i, j);
				return;
			}
		}
		for(int j = 0; j < 3; j++){
			if(board[j][i] == '-' && board[numberMap[j].f][i] == namsu && board[numberMap[j].s][i] == namsu)	{
				printArray(seq, j, i);
				return;
			}
		}
	}
	
	for(int i = 0; i < 3; i++) {
		if(board[i][i] == '-' && board[numberMap[i].f][numberMap[i].f] == namsu && board[numberMap[i].s][numberMap[i].s] == namsu) {
				printArray(seq, i, i);
				return;
		}
	}
	for(int i = 0; i < 3; i++) {
		if(board[i][2 - i] == '-' && board[numberMap[i].f][2-numberMap[i].f] == namsu && board[numberMap[i].s][2-numberMap[i].s] == namsu) {
				printArray(seq, i, 2-i);
				return;
		}
	}
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)  solve(i+1);
}
