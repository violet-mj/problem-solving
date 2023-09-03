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
	int n, q, a, b, x;		
	cin >> n >> q;
	vector<int> color(q + 1, 0);
	vector<vector<int>> start(n+1);
	vector<vector<int>> end(n+1);
	vector<int> qVisit(n + 1, 0);
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 1; i <= q; i++) {
		cin	>> a >> b >> x;
		color[i] = x;
		start[a].pb(i);
		end[b].pb(i);
	}

	for(int i = 1; i <= n; i++) {
		for(auto j: start[i])	{
			pq.push(j);
		}
		// debug(i, qVisit);
		while(!pq.empty()) {
			if(qVisit[pq.top()]) {
				pq.pop();	
			} else {
				break;	
			}
		}

		// debug(i, pq.top());

		if(pq.empty()) {
			cout << 0 << " ";
		} else {
			cout << color[pq.top()] << " ";
		}

		for(auto j: end[i]) {
			qVisit[j] = 1;	
		}
	}

	cout << "\n";
	return;
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
