
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

int n, tmp;
vector<int> v;

int tree[1000000];

int binarySearch(int value) {
	int l = 0;
	int r = 20;
	int mid;

	while(l + 1 < r) {
		mid = (l + r) >> 1;	
		
		if(value >= (1 << mid)) {
			l = mid;	
		} else {
			r = mid;		
		}
	}
	return l;
}

void solve() {
	cin >> n;		
	tree[1] = 0;
	for(int i = 1; i <= n; i++) {
		cin >> tmp;
		tree[i*2+1] = tree[tmp] + 1;
		tree[i*2] = tree[tmp] + 1;
	}

	for(int i = 1; i <= 2 * n + 1;i++) {
		cout << tree[i]	 << "\n";
	}
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}
