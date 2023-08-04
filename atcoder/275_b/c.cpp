#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

#ifdef DEBUG
#define debug 1
#else
#define debug 0
#endif

#define mp make_pair 
#define pb push_back 
#define f first 
#define s second

vector<string> v;
string tmp;

void solve() {

	for(int i = 0; i < 9; i++) {
		cin >> tmp;
		v.pb(tmp);
	}

	int result = 0;

	for(int i = 0; i <= 8; i++) {
		for(int j = 0; j <= 8; j++)	 {
			for(int x = 0; x < 9; x++) {
				for(int y = 1; y < 9; y++) {
					int x1 = i + x;	
					int y1 = j + y;
					int x2 = x1 + y;
					int y2 = y1 - x;
					int x3 = x2 - x;
					int y3 = y2 - y;
					if (x1 < 0 || x1 >= 9 || x2 < 0 || x2 >= 9 || x3 < 0 || x >= 9) continue;
					if (y1 < 0 || y1 >= 9 || y2 < 0 || y2 >= 9 || y3 < 0 || y >= 9) continue;
					if(v[i][j] != '#' || v[x1][y1] != '#' || v[x2][y2] != '#' || v[x3][y3] != '#') continue;
					//cout << "x : " << i << " y : " << j << "\n";
					result++;
				}
			}
		}
	}
	cout << result << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}
