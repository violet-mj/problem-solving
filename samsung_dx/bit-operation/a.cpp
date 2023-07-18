
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

#define mp make_pair 
#define pb push_back 
#define f first 
#define s second

int n;

void solve(int testNumber) {
	cin >> n;	
	int mul = 1;
	int curr = 0;
	while(1) {
		int currValue = n * mul;			
		while(currValue != 0) {
			int v = currValue % 10;	
			curr |= (1 << v);
			currValue /= 10;
		}
		
		if(curr == 1023) break;

		mul++;
	}
	cout << "#" << testNumber << " " << mul * n << "\n"; 
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++) solve(i);
}
