#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
using namespace std;

int n;
const int MOD = 1000000007;
map<char, int> alpha = {
    {'A', 3},
    {'B', 2},
    {'C', 1},
    {'D', 0}
};

void solve(int tn) {
    string line;    
    cin >> line;
    int size = line.size();

    int dp[size][16];

    fill(&dp[0][0], &dp[size-1][16], 0);
    int currKeyHave = 3;
    int k = alpha.at(line[0]);

    for(int i = 1; i <= 15; i++) {
        if((i & (1 << currKeyHave)) && (i & (1 << k))) {
            dp[0][i] = 1;
        }
    }
    int visited[16];
    for(int i = 0; i < size - 1; i++) {
        int currRes = alpha.at(line[i + 1]);
        for(int j = 1; j <= 15; j++) {
            if(!dp[i][j]) continue;
            fill(&visited[0], &visited[16], 0);
            for(int z = 0; z < 4; z++) {
                if(!(j & (1 << z))) continue;
                for(int h = 1; h <= 15; h++) {
                    if((h & (1 << currRes)) && (h & (1 << z)) && !visited[h]) {
                        dp[i+1][h] = (dp[i+1][h] + dp[i][j]) % MOD;
                        visited[h] = 1;
                    }
                }
            }
        }
    }
    int result = 0;
    for(int i = 1; i <= 15; i++) {
        result = (result + dp[size-1][i]) % MOD;
    }

    cout << "#" << tn << " " << result << "\n";
    

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        solve(i + 1);
    }
}
