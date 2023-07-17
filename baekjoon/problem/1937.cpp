
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

#define mp make_pair 
#define pb push_back 
#define f first 
#define s second
#define pii pair<int,int>

typedef struct ii{
	int x;
	int y;
	int value;
} info;

bool operator < (info a, info b) {
	return a.value < b.value;
}

int dx[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int graph[500][500];
int dp[500][500];
int n;
vector<info> k;


int dfs(int currX, int currY) {
	if(dp[currX][currY] != -1) return dp[currX][currY];
	int max_ = 1;
	for(int i = 0; i < 4; i++) {
		int nx = currX + dx[i];
		int ny = currY + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (graph[nx][ny] <= graph[currX][currY]) continue;
		max_ = max(max_, dfs(nx, ny) + 1);
	}
	dp[currX][currY] = max_;
	return max_;
}

void solve() {
	cin >> n;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j ++ ){ 
			dp[i][j] = -1;	
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}		
	}

	int max_ = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			max_ = max(dfs(i, j), max_);
		}
	}

	cout << max_ << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
