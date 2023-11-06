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
typedef vector<int> vi;
typedef vector<lint> vl;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define all(v) (v).begin(),(v).end()

void solve() {
	int n;		
	cin >> n;
	vector<int> v(n);
	vector<int> vo(n);

	for(int i = 0; i < n; i++) cin >> v[i];
	for(int i = 0; i < n; i++) cin >> vo[i];

	priority_queue<int> pq;
	priority_queue<int> pq1;

	for(int i = 0; i < n; i++) {
		if(vo[i] < v[n-1])	 {
			pq.push(vo[i]);
		}
		pq1.push(vo[i]);
	}

	sort(all(v));
	sort(all(vo));

	int res = 0;
	for(int i = n - 1; i >= 0; i--) {
		if(pq.size() == 0) {
			res -= 50;
			continue;
		}
		if(pq.top() < v[i])	 {
			res += 100;	
		} else if (pq.top() == v[i]) {
			res += 20;	
		} else {
			res -= 50;	
		}
		pq.pop();
	}

	int res1= 0;
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(pq1.size() == 0) {
			break;
		}
		debug(pq1.top());
		if(pq1.top() < v[i])	 {
			res1 += 100;	
		} else if (pq1.top() == v[i]) {
			res1 += 20;	
		} else {
			res1 -= 50;	
		}
		pq1.pop();
		cnt++;
	}

	for(int i = cnt; i < n; i++) {
		if(v[i] > vo[i-cnt])	 {
			res1 += 100;	
		} else if(v[i] == vo[i-cnt]) {
			res1 += 20;	
		} else {
			res1 -= 50;	
		}
	}

	cout << max(res,res1) << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
