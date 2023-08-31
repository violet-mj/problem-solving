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

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define all(v) (v).begin(),(v).end()

// 정수가 int형의 범위를 넘어가는지
// integer overflow 확인
// 정방향이 아닌 역방향도 생각해보기
void solve() {
	int n, k;
	cin >> n >> k;		
	vector<int> da(n+1, n + 1);
	vector<int> dk(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> da[i];
		dk[i] = da[i];
	}

	sort(all(dk));
	for(int i = 0; i < n; i++) {
		if(dk[i] != i) {
			da[n] = i;	
			break;
		}
	}

	if(da[n] == n + 1) {
		da[n] = n;	
	}

	debug(da);

	int check = k % (n + 1);

	if(check == 0) {
		for(int i = 0; i < n; i++)	 {
			cout << da[i] << " \n"[i == n -1];
		}
		return;
	}

	for(int i = n - check + 1; i <= n; i++) {
		cout << da[i] << " ";	
	}
	for(int i = 0; i < n - check; i++) {
		cout << da[i] << " ";
	}
	cout << "\n";
}



int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
