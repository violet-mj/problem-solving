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

typedef vector<int> vi;
typedef long long ll;

int dep[100002];
bool visited[100002];
int sparse[20][100002];
int par[100002];

void print(std::vector<int> const &input)
{
    for (int i = 0; i < input.size(); i++) {
        cout << input.at(i) << ' ';
    }
}

int calDist(int prev, int next) {

	if (dep[prev] < dep[next]) {
		swap(prev, next);
	}

	int depDiff = dep[prev] - dep[next];

	int c = prev;
	
	for(int i = 19; i >= 0; --i) {
		if((depDiff >> i)	& 1) {
			c = sparse[i][c];
		}
	}

	if (next == c) {
		return depDiff;	
	}

	int prevc = c;
	int nextc = next;

	for(int i = 19; i >= 0; --i) {
		if(sparse[i][prevc] != sparse[i][nextc])	{
			prevc = sparse[i][prevc];
			nextc = sparse[i][nextc];
		}
	}
	prevc = sparse[0][prevc];
	// cout << "prev : " << prev << " next : " << next <<  "dep[prevc] : " << prevc << "\n" ;
	return dep[prev] + dep[next] - 2 * dep[prevc];
}

void bfs(vector<vi>& tree, int curr, int depth) {
	queue<pair<int, int>> q;
	visited[1] = true;
	q.push(make_pair(1, 0));
	fill(&visited[0], &visited[100002], false);

	while(!q.empty()) {
		pair<int, int> currPair= q.front();
		int currNode = currPair.first;
		int depth = currPair.second;
		q.pop();

		dep[currNode] = depth;

		for(auto nextNode: tree[currNode]) {
			if(visited[nextNode])	continue;
			//cout << "nextNode : " << nextNode << "\n";
			visited[nextNode] = true;	
			q.push(make_pair(nextNode, depth + 1));
		}
	}
}

void solve(int tn) {
	int n, tmp;
	queue<int> q;
	cin >> n;
	vector<vi> tree(n + 1);

	fill(&sparse[0][0], &sparse[19][100002], -1);
	fill(dep, &dep[100002], 0);
	fill(par, &par[100002], 0);

	for(int i = 2; i < n + 1; i++) {
		cin >> tmp;
		par[i] = tmp;
		sparse[0][i] = tmp;
		tree[tmp].push_back(i);
	}

	bfs(tree, 1, 0);

	for(int i = 1; i < 20; i++) {
		for(int j = 1; j < n + 1; j++) {
			int t__ = sparse[i-1][j];
			if(t__ == -1) continue;
			int t_ = sparse[i-1][sparse[i-1][j]];
			if(t_ != -1) {
				sparse[i][j] = t_;
			}
		}	
	}

	ll res = 0;
	visited[1] = true;
	q.push(1);
	fill(&visited[0], &visited[n+1], false);
	int prevNode = 1;

  // cout << "\n----------\n";
  // for(int i = 1; i <= n; i++) {
  	// cout << "index " << i << " ";
  	// print(tree[i]);
  	// cout << "\n";
  // }
  // cout << "\n----------\n";


	while(!q.empty()) {
		int currNode = q.front();
		q.pop();

		int ppp = calDist(prevNode, currNode);
		res += ppp;


		prevNode = currNode;	
		// cout << "\n----------\n";
		// cout << "indexc " << currNode << " : "; 
		// print(tree[currNode]);
		// cout << "\n----------\n";
		for(auto nextNode: tree[currNode]) {
			if(visited[nextNode])	continue;
			//cout << "nextNode : " << nextNode << "\n";
			visited[nextNode] = true;	
			q.push(nextNode);
			
		}

		// cout << "isQueue empty? : " << q.empty() << "\n";
		
	}

	cout << '#' << tn << " " << res << "\n";
	
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;

	for(int i = 1; i <= t; i++) solve(i);
}
