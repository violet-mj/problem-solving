
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

#define mp make_pair 
#define pb push_back 
#define f first 
#define s second

void solve(int tn) {
	int n, m;
	cin >> n >> m;
	int curr = 1;
	int i = 0;

	while(i < n) {
		if(!(m & curr)) {
			cout << "#" << tn << " " << "OFF" << "\n";
			return;
		}
		i++;
		curr <<= 1;
	}

	cout << "#" << tn << " " << "ON" << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++) solve(i);
}
