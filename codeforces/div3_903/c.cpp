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

	vector<vector<char>> graph(n, vector<char>(n));
	vector<vector<int>> visited(n, vector<int>(n, 0));

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}

	auto rotate90 = [&](pii coord) {
		return mp(coord.s, n - 1 - coord.f);
	};

	auto check = [&](int x, int y) {
		pii curr = mp(x, y);
		pii curr90 = rotate90(curr);
		pii curr180 = rotate90(curr90);
		pii curr270 = rotate90(curr180);

		vector<int> k;

		k.pb(graph[curr.f][curr.s] - 'a');
		k.pb(graph[curr90.f][curr90.s] - 'a');
		k.pb(graph[curr180.f][curr180.s] - 'a');
		k.pb(graph[curr270.f][curr270.s] - 'a');
		int res = 1e9;
		for(int i = 0; i < 26; i++) {
			int value = 0;
			bool flag = true;
			for(int j = 0; j < 4; j++)	 {
				if(i < k[j]) {
					flag = false;
				} else {
					value += i - k[j];	
				}	
			}
			if(flag) res = min(res ,value);
		}
		
		visited[curr.f][curr.s] = 1;
		visited[curr90.f][curr90.s] = 1;
		visited[curr180.f][curr180.s] = 1;
		visited[curr270.f][curr270.s] = 1;
		return res;
	};

	int cnt = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)	 {
			if(!visited[i][j])	 {
				cnt += check(i, j);
			}
		}
	}
	cout << cnt	<< "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) solve();
}
