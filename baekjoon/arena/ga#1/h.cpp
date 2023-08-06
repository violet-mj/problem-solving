
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


long long n, m, q, cmd, a, b;



void solve() {
	cin >> n >> m >> q;	
	long long  matrix[n+1][m+1];
	long long row[n+1];
	long long column[m+1];
	fill(&matrix[0][0], &matrix[n][m+1], 0);
	fill(row, &row[n+1], 0);
	fill(column, &column[m+1], 0);

	for(long long i = 0; i < q; ++i ) {
		cin >> cmd >> a >> b;	

		if(cmd == 1) {
			row[a] += (long long)b;
		} else {
			column[a] += (long long)b;
		}
	}

	for(long long i = 1; i <= n; i++) {
		for(long long j = 1; j <= m; j++)	 {
			cout << row[i] + column[j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}
