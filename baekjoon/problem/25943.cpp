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

int n;
const vector<int> weight = {1, 2, 5, 10, 20, 50, 100};
// 정수가 int형의 범위를 넘어가는지
// integer overflow 확인
// 정방향이 아닌 역방향도 생각해보기
void solve() {
	cin >> n;
	vector<int> v(n);

	for(int i = 0; i < n; i++) cin >> v[i];

	int left = v[0];
	int right = v[1];

	for(int i = 2; i < n; i++) {
		if(left <= right) {
			left += v[i];
		}	else {
			right += v[i];
		}
	}

	int diff = abs(left - right);
	int cnt = 0;
	debug(diff);

	while(diff > 0) {
		debug(diff);
		int k = upper_bound(all(weight), diff) - weight.begin();
		debug(weight[k-1]);
		diff -= weight[k-1];
		cnt++;
	}

	cout << cnt << "\n";
} 

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
