#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;



ll n, m, k, s, e, c;
vector<vector<pii>> v(1001);

priority_queue<ll> distDp[1001];

void solve() {
	cin >> n >> m >> k;
	
	for(int i = 0; i < m; i++) {
		cin >> s >> e >> c;
		v[s].push_back(make_pair(c, e));
	}
	auto cmp = [](pii left, pii right) {
		return left.first > right.first;
	};
	priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);
	pq.push(make_pair(0, 1));
	distDp[1].push(0);
	
	while(!pq.empty()) {
		pii curr = pq.top();
		pq.pop();
		ll currNode = curr.second;
		ll currCost = curr.first;
		
		for(pii nextState: v[currNode]) {
			ll nCost = nextState.first;
			ll nextNode = nextState.second;
			ll nextCost = currCost + nCost;
			if(distDp[nextNode].size() < k) {
				distDp[nextNode].push(nextCost);
				pq.push(make_pair(nextCost, nextNode));
			} else if (nextCost < distDp[nextNode].top()) {
				distDp[nextNode].pop();
				distDp[nextNode].push(nextCost);
				pq.push(make_pair(nextCost, nextNode));
			}
		}
	}
	
	for(int i = 1; i <= n; i++) {

		if(distDp[i].size() < k) {
			cout << -1 << "\n";
			continue;
		}
		cout << distDp[i].top() << "\n";

	}
}

int main() {
	// your code goes here
	solve();
	return 0;
}
