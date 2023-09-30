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

const lint INF = 1LL << 60;

void solve() {
	int n, k, p;
	cin >> n >> k >> p;
	lint dp[n+1][p+1][p+1][p+1][p+1][p+1];
	int costs[n+1][6];
	fill(&dp[0][0][0][0][0][0], &dp[n][p][p][p][p][p+1], INF);
	fill(&costs[0][0], &costs[n][6], 0);
	dp[0][0][0][0][0][0] = 0;
	int tmp;
	for(int i = 1; i <= n; i++) {
		for(int j = 0;  j < k + 1; j++){
			cin >> tmp;
			costs[i][j] = tmp;
		}
	}
	int check[5] = {0, 0, 0, 0, 0};

	for(int i = 0; i < k; i++) {
		check[i] = p;	
	}
	
	for(int i = 0; i < n; i++) {
		for(int p1 = 0; p1 <= check[0]; p1++) {
			for(int p2 = 0; p2 <= check[1]; p2++) {
				for(int p3 = 0; p3 <= check[2]; p3++) {
					for(int p4 = 0; p4 <= check[3]; p4++) {
						for(int p5 = 0; p5 <= check[4]; p5++) {
							int newP1 = min(p, p1 + costs[i+1][1]);
							int newP2 = min(p, p2 + costs[i+1][2]);
							int newP3 = min(p, p3 + costs[i+1][3]);
							int newP4 = min(p, p4 + costs[i+1][4]);
							int newP5 = min(p, p5 + costs[i+1][5]);
							dp[i+1][newP1][newP2][newP3][newP4][newP5] = min(dp[i+1][newP1][newP2][newP3][newP4][newP5], dp[i][p1][p2][p3][p4][p5] + costs[i+1][0]);
							dp[i+1][p1][p2][p3][p4][p5] = min(dp[i+1][p1][p2][p3][p4][p5], dp[i][p1][p2][p3][p4][p5]);
							if(i == 2 ) {
								debug(i, p1,p2,p3,p4,p5, dp[i][p1][p2][p3][p4][p5]);
								debug(i,newP1, newP2, newP3, newP4, newP5,dp[i+1][newP1][newP2][newP3][newP4][newP5]);
								debug(costs[i+1][4]);
							}
						}
					}
				}
			}
		}
	}

	lint res = INF;

	for(int i = 0; i <= n; i++) {
		res = min(dp[i][check[0]][check[1]][check[2]][check[3]][check[4]], res);
	}
	cout << (res == INF ? -1: res) << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
