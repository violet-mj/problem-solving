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
	int n, m, x;
	cin >> n >> m;	
	vector<int> v(n);
	set<int> s;
	for(int i = 0; i < n; i++) cin >> v[i];
	for(int i = 0; i < m; i++) {
		cin >> x;
		s.insert(x);
	}

	int cnt = 0;
	for(int i = 0; i < m; i++) {
		if(s.find(v[i]) == s.end())	{
			cnt++;	
		}
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
