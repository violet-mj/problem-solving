
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

int n, x, y, tmp;
vector<int> v;

const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,1,0,-1};

bool backtracking(int nx, int ny, int prevDir, int count) {

	if(debug) cout << "nx : " << nx << " ny : " << ny << " count : " << count << " currDir : "  << prevDir <<"\n";

	if(count == n) {
		return nx == x && ny == y ? true : false;
	}

	int d1 = (prevDir - 1 + 4) % 4;
	int d2 = (prevDir + 1) % 4;
	return backtracking(ny+dy[d1]*v[count], nx+dx[d1] *v[count], d1, count + 1) || backtracking(ny+dy[d2]*v[count], nx+dx[d2] * v[count], d2, count + 1);
}

void solve() {
	cin >> n >> x >> y;	
	for(int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	bool res = backtracking(0, v[0], 1, 1);

	string result = res ? "Yes": "No";

	cout << result << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}
