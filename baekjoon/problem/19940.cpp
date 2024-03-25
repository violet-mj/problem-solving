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

int go[5] = {60, 10, -10, 1, -1};
int n;	
const int INF = 1 << 30;

struct Custom {
	vector<int> value = vector<int>(5, INF);
};

struct Node {
	int num;
	vector<int> state;

	Node(int n, vector<int> s): num(n), state(s) {}
};

struct cmp {
	bool operator () (Node n1, Node n2){
		return abs(n1.num - n) > abs(n2.num - n);	
	}
};

void solve() {
	cin >> n;
	map<int, Custom> visited;
	
	priority_queue<Node, vector<Node>, cmp> q;
	q.push(Node(0, {0,0,0,0,0}));
	visited[0].value = {0,0,0,0,0};

	while(!q.empty()) {
		Node curr = q.top();
		q.pop();

		int currNum = curr.num;
		vector<int> currState = curr.state;

		// debug(currNum, currState);

		if(currNum == n) {
			for(int i = 0; i < 5; i++)	 {
				cout << currState[i] << " \n"[i == 4];
			}
			return;
		}

		if(currState > visited[currNum].value) continue;

		for(int i = 0; i < 5; i++) {
			vector<int> copyState = currState;
			copyState[i]++;
			if(copyState < visited[currNum + go[i]].value) {
				q.push(Node(currNum + go[i], copyState));
				visited[currNum + go[i]].value = copyState;
			}
		}
	}
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
  cin >> t;
	for(int i = 0; i < t; i++) solve();
}
