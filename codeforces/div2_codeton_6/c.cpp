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

const int INF = 1e9;

void solve() {
	int n, k;
	cin >> n >> k;

	vector<pii> ai;
	int res[k+1];
	int visitValue[k+1];
	int visitIndex[n+1];
	priority_queue<int> maxQ;
	priority_queue<int, vector<int>, greater<int>> minQ;

	fill(res, &res[k+1], INF);
	fill(visitValue, &visitValue[k+1], 0);
	fill(visitIndex, &visitIndex[n+1], 0);

	int tmp;
	ai.pb(mp(0, 0));
	for(int i = 1; i <= n; i++) {
		cin >> tmp;
		ai.pb(mp(tmp, i));
		minQ.push(i);
		maxQ.push(i);
	}

	sort(all(ai), [&](pii p1, pii p2) {
		if(p1.f == p2.f) {
			return p1.s < p2.s;
		}			
		return p1.f < p2.f;
	});

	for(int i = 1; i <= n; i++) {
		int currIndex = ai[i].s;	
		int currValue = ai[i].f;
		int minv = INF , maxv = INF;


		if(visitValue[currValue]) {
			visitIndex[currIndex] |= 1;
			continue;	
		}
		
		while(!minQ.empty()) {
			int small = minQ.top();	

			if(visitIndex[small]) {
				minQ.pop();	
				continue;
			} else {
				minv = small;	
				break;
			}
		}

		while(!maxQ.empty()) {
			int big = maxQ.top();	

			if(visitIndex[big]) {
				maxQ.pop();	
				continue;
			} else {
				maxv = big;	
				break;
			}
		}

		if(minv != INF && maxv != INF) {
			res[currValue] = (abs(maxv - minv) + 1) * 2;	
		} else {
			continue;	
		}
		
		visitValue[currValue] |= 1;
		visitIndex[currIndex] |= 1;;

	}


	for(int i = 1; i <= k; i++) {
		cout << (res[i] == INF ? 0 : res[i]) << " ";	
	}
	cout << "\n";
		
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) 
	solve();
}
