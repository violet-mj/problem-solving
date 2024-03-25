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
const	int trix[6] = {0, 1, 1, 1, 0, 0};
const	int triy[6] = {0, 0, -1, 1, 1, -1};
const	int trirx[6] = {0, 0, 0, 1, 1, 1};
const	int triry[6] = {-1, 0, 1, 0, -1, 1};


void solve() {
	int n; cin >> n;
	vector<string> graph(n);
	for(int i = 0; i < n; i++) cin >> graph[i];

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)	 {
			bool flag1 = true;
			bool flag2 = true;
			for(int z = 0; z < 6; z++) {
				int nx = i + trix[z];
				int ny = j + triy[z];
				if(nx < 0 || nx >= n || ny < 0 || ny >= n) {
					flag1 = false;	
					break;
				}

				if(z < 4) {
					if(graph[nx][ny] == '0') {
						flag1	 = false;
						break;
					}
				} else {
					if(graph[nx][ny] == '1') {
						flag1	 = false;
						break;
					}
				}
			}
			

			for(int z = 0; z < 6; z++) {
				int nx = i + trirx[z];
				int ny = j + triry[z];
				if(nx < 0 || nx >= n || ny < 0 || ny >= n) {
					flag2 = false;	
					break;
				}

				if(z < 4) {
					if(graph[nx][ny] == '0') {
						flag2	 = false;
						break;
					}
				} else {
					if(graph[nx][ny] == '1') {
						flag2	 = false;
						break;
					}
				}
			}

			if(flag1 || flag2) {
				cout << "TRIANGLE\n";
				return;
			}
		}
	}
	cout << "SQUARE\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
