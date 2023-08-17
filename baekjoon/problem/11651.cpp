#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int n, cx, cy;
using pii = pair<int, int>;
typedef long long lint;

int main() {
	cin >> n;	

	vector<pii> coords;

	for(int i = 0; i < n; i++) {
		cin >> cx >> cy;	
		coords.push_back(make_pair(cx, cy));
	}

	sort(coords.begin(), coords.end(), [](pii f, pii s) {
				if(f.second == s.second) {
					return f.first< s.first;	
				}		

				return f.second < s.second;
			});
	
	for(auto [xx, yy]: coords) {
		cout << xx << " " << yy << "\n";
	}
}
