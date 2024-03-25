#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>

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

lint gcd(lint a, lint b) {
	while(b != 0) {
		a %= b;	
		swap(a, b);
	}
	return a;
}

void solve() {
	int n; cin >> n;
	vector<int> values(n);
	map<int, queue<int>> m;
	map<int, int> idx;
	int cnt = 0;
	vector<int> rres(n, -1);
	for(int i = 0; i < n; i++) {
		cin >> values[i];
		int tmp = values[i];
		if(tmp == 1) {
			rres[cnt++] = 1;
			continue;
		}
		for(int j = 2; j <= (int)sqrt(values[i]); j++) {
			if(tmp % j == 0) {
				m[j].push(i);
				while(tmp % j == 0) tmp /= j;
			}
		}

		if(tmp != 1) {
			m[tmp].push(i);
		}
	}
	vector<int> res;
	set<int> check;

	while(res.size() != n - cnt) {
		int curridx = -1;
		int min_ = 1 << 30;
		for(auto i = m.begin(); i != m.end(); i++){
			while(!i->s.empty()) {
				if(check.find(i->s.front()) != check.end()) {
					i->s.pop();	
				} else {
					break;	
				}
			}
			if(i->s.empty()) continue;
			if(min_ > values[i->s.front()]){
				curridx = i->f;	
				min_ = min(min_, values[i->s.front()]);
			}
		}

		res.pb(values[m[curridx].front()]);
		check.insert(m[curridx].front());
		m[curridx].pop();
	}
	int nxt = 0;

	for(int i = cnt; i < n; i++) {
		rres[i] = res[i - cnt];
	}

	for(int i = 0; i < n; i++) {
		cout << rres[i] << " ";	
	}
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
