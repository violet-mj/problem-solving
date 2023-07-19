#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>

using namespace std;

#define mp make_pair 
#define pb push_back 
#define f first 
#define s second

const int MOD = 1234567;

void solve() {
	int n;
	cin >> n;


	vector<vector<int>> numbers = {
		
			{7},
			{2, 4},
		  {1, 3, 5},
		   {2, 6},
		   {1, 5, 7},
		   {2, 4, 6, 8},
		   {3, 5, 9},
		   {0, 4, 8},
		   {5, 7, 9},
		   {6, 8}
		
	};

	int dp[10][n];

	fill(&dp[0][0], &dp[9][n], 0);

	for(int i = 0; i < 10; i++) {
		dp[i][0] = 1;
  }

	for(int i = 0; i < n - 1; i++) {
		for(int j = 0; j <= 9; j++) {
			vector<int> number = numbers[j];
			for(auto z: number) {
				dp[z][i+1] = (dp[z][i+1] + dp[j][i]) % MOD;
			}
		}	
	}

	int result = 0;
	for(int i = 0; i < 10; i++) {
		result = (result + dp[i][n-1])	% MOD;
	}
	
	cout << result << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;

	while(t--) solve();
}
