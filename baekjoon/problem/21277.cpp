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

const int INF = 1e9;

vector<vector<char>> rotate90(vector<vector<char>>& map_) {
	int n = map_.size();	
	int m = map_[0].size();
	vector<vector<char>> tmp(m, vector<char>(n, '0'));

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++){
			tmp[j][n - i - 1]	= map_[i][j];
		}
	}

	return tmp;
}

void solve() {			
	int n1, m1, n2, m2;
	cin >> n1 >> m1;
	vector<vector<char>> square1(n1, vector<char>(m1, '0'));
	int maxX = 0;
	int maxY = 0;
	for(int i = 0; i < n1; i++) {
		for(int j = 0; j < m1; j++)	 {
			cin >> square1[i][j];
			if(square1[i][j] == '1') {
				maxX = max(maxX, i);
				maxY = max(maxY, j);
			}
		}
	}
	cin >> n2 >> m2;
	vector<vector<char>> square2(n2, vector<char>(m2, '0'));
	for(int i = 0; i < n2; i++) {
		for(int j = 0; j < m2; j++)	 {
			cin >> square2[i][j];
		}
	}

	int max2 = max(n2, m2);
	debug(maxX, maxY, max2);
	int n3 = n1 + 2 * max2;
	int m3 = m1 + 2 * max2;
	vector<vector<char>> squareMap(n3, vector<char>(m3, '0'));


	for(int i = max2; i < max2 + n1; i++) {
		for(int j = max2; j < max2 + m1; j++)	 {
			squareMap[i][j] = square1[i-max2][j-max2];
		}
	}

	debug(squareMap);
	vector<vector<char>> square2s[4];
	square2s[0] = square2;
	square2s[1] = rotate90(square2s[0]);
	square2s[2] = rotate90(square2s[1]);
	square2s[3] = rotate90(square2s[2]);

	debug(square2s[0]);
	debug(square2s[1]);
	debug(square2s[2]);
	debug(square2s[3]);
	int res = INF;

	for(int i = 0; i < n3; i++) {
		for(int j = 0; j < m3; j++)	 {
			for(int z = 0; z < 4; z++)	 {
				int minw = max2;		
				int minh = max2; 
				int maxw = max2 + maxY;
				int maxh = max2 + maxX;

				vector<vector<char>> currSquare2 = square2s[z];
				int cn = currSquare2.size();
				int cm = currSquare2[0].size();
				bool flag = true;
				for(int xx = 0; xx < cn && flag; xx++) {
					for(int yy = 0; yy < cm && flag; yy++)	{
							if(i == 3 && j == 2) {
								debug(i, j, minw, minh, maxw, maxh);
							}
							if(i+xx < 0 || i+xx >= n3 || j+yy < 0 || j+yy >= m3) {
								flag=false;	
								break;
							}
							if(squareMap[i+xx][j+yy] == currSquare2[xx][yy]) {
								if(currSquare2[xx][yy] == '1') {
									flag=false;
									break;	
								}
							} else {
								if(i == 3 && j == 2) {
								debug(i, j, minw, minh, maxw, maxh, i + xx, j + yy);
								debug(squareMap[i+xx][j+yy], currSquare2[xx][yy]);
								}
								minh = min(minh, i+xx);
								maxh = max(maxh, i+xx);
								minw = min(minw, j+yy);
								maxw = max(maxw, j+yy);
							}
					}
				}
				if(flag) {
					int aaa = (maxh - minh + 1) * (maxw - minw + 1);
					res = min(res, aaa);
					debug(i, j, maxh, minh, maxw, minw, z, aaa);
				}
			}
		}
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
