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


typedef long long ll;
typedef pair<ll, ll> pll;
ll t, n, k, tmp;

void solve(ll tn) {
	cin >> n;	
	ll candidates[n];
	priority_queue<pll, vector<pll>, greater<pll>> pq;

	for(ll i = 0; i < n; i++) {
		cin >> tmp;	
		candidates[i] = tmp;
	}


	cin >> k;

	pq.push(mp(0, k));
	while(pq.top().second != 0) {
		pll curr = pq.top();
		ll currCnt = curr.first;
		ll currX = curr.second;
		pq.pop();

		pq.push(mp(currCnt + currX, 0));

		for(int i = 0; i < n; i++) {
			pq.push(mp(currCnt + (currX % candidates[i]), currX / candidates[i]));
		}
	}

	ll ans = pq.top().first;

	cout << "#" << tn << " " << ans << "\n";

}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for(ll i = 0; i < t; i++) solve(i+1);
}
