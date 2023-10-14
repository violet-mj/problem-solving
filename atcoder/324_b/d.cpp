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
	string s;
	cin >> n >> s;

	int ss = s.size();
	sort(all(s));
	reverse(all(s));

	vector<int> values(10, 0);

	for(int i = 0; i < n; i++) {
		values[s[i] - '0']++;
	}

	int cnt = 0;

	lint target = stoll(s);

	if (target == 0LL) {
		cout << 1 << "\n";
		return;
	}

	for(lint i = 1; i * i <= target; i++)  {
		lint square = i * i;	
		vector<int> k(10, 0);
		int nt = 0;
		while(square != 0) {
			k[square % 10]++;
			square /= 10;
			nt++;
		}

		k[0] += ss - nt;

		bool flag = true;
		for(int i =0; i < 10; i++) {
			if(values[i] != k[i])	 {
				flag = false;
				break;
			}
		}

		if(flag) {
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
