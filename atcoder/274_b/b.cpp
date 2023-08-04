
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

int a, b;
string tmp;
vector<string> graph;

void solve() {
	cin >> a >> b;	
	
	for(int i = 0; i < a; i++) {
		cin >> tmp;
		graph.push_back(tmp);
	}

	int count;
	for(int i = 0; i < b; i++) {
		count = 0;	
		for(int j = 0; j < a; j++){
			if(graph[j][i] == '#') {
				count++;
			}
		}
		cout << count << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}
