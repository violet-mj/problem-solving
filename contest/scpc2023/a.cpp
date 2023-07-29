
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

int t, n, a, b;

void solve(int tn) {
	cout << "Case #" << tn << "\n";
	cin >> n >> a >> b;	

	int mi = min(a, b);
	int ma = max(a, b);

	int loop = n / mi;

	for(int i = loop; i >= 0; i--) {
		int maValue	= n - i * mi;

		if(maValue < 0) break;

		if(maValue % ma == 0) {
			cout << i + maValue / ma << "\n";
			return;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for(int i = 1; i <= t; i++) solve(i);
}
