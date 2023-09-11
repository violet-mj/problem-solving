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
typedef pair<lint, lint> pii;
typedef vector<int> vi;
typedef vector<lint> vl;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define all(v) (v).begin(),(v).end()

lint n, k, a, b, xx, yy;

void solve() {
	cin >> n >> k >> a >> b;
	vector<pii> graph(n + 1);


	for(int i = 1; i <= n; i++) {
		cin >> xx >> yy;
		graph[i] = mp(xx, yy);
	}

	if(a <= k && b <= k) {
		cout << 0 << "\n";
		return;
	}
	lint aTob = (lint)abs(graph[a].f - graph[b].f) + (lint)abs(graph[a].s - graph[b].s);
	if(k <= 1) {
		cout << 	(lint)abs(graph[a].f - graph[b].f) + (lint)abs(graph[a].s - graph[b].s) << "\n";
		return;
	}

	if(a > k && b <= k) {
			lint min_ = aTob;
			pii aCoord = graph[a];
			for(lint i = 1; i <= k; i++)	 {
				if(i == b) continue;
				pii currCoord = graph[i];
				lint dist = abs(aCoord.f - currCoord.f) + abs(aCoord.s - currCoord.s);
				if(dist < min_) {
					min_ = dist;	
				}
			}
			cout << min_ << "\n";
			return;
	} else if (a <= k && b > k) {
			lint min_ = aTob;
			pii aCoord = graph[b];
			for(lint i = 1; i <= k; i++)	 {
				if(i == a) continue;
				pii currCoord = graph[i];
				lint dist = abs(aCoord.f - currCoord.f) + abs(aCoord.s - currCoord.s);
				if(dist < min_) {
					min_ = dist;	
				}
			}
			cout << min_ << "\n";
			return;
	} else {
		pii aCoord = graph[a];		
		pii bCoord = graph[b];
		lint currK = 0LL;
		lint minDist = aTob;
		for(lint i = 1; i <= k; i++) {
			pii currCoord = graph[i];
			lint dist = abs(aCoord.f - currCoord.f) + abs(aCoord.s - currCoord.s);
			if(dist < minDist) {
				currK = i;
				minDist = dist;
			}
		}
		lint minB = aTob; 
		for(int i = 1; i <= k; i++) {
			if(i == currK) continue;	
			pii currCoord = graph[i];
			lint dist = abs(bCoord.f - currCoord.f) + abs(bCoord.s - currCoord.s);
			minB = min(minB, dist);
		}

		lint currKDist = (lint)abs(bCoord.f - graph[currK].f) + (lint)abs(bCoord.s - graph[currK].s);
		lint lastDance = aTob;
		for(int i = 1; i <= k; i++) {
			if(i == currK) continue;	
			pii currCoord = graph[i];
			lint dist = (lint)abs(aCoord.f - currCoord.f) + (lint)abs(aCoord.s - currCoord.s);
			lastDance = min(lastDance, dist);
		}
		lint kkk = min(currKDist + lastDance, minDist + minB);
		cout << min(aTob, kkk) << "\n";
	}

	
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
