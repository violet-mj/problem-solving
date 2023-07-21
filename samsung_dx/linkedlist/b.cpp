#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

#define mp make_pair 
#define pb push_back 
#define f first 
#define s second


#ifdef DEBUG
#define debug 1
#else
#define debug 0
#endif



void solve(int tn) {
	int n, m, L, tmp, i;	
	char cmd;
	deque<int> arr;
	cin >> n >> m >> L;
		
	for(i = 0; i < n; i++ ) {
		cin >> tmp;
		arr.pb(tmp);
	}

	for(i = 0; i < m; i++) {
		cin >> cmd;			
		int x, y;
		int z;
		switch(cmd) {
			case 'I': {
				cin >> x >> y;		
				arr.insert(next(arr.begin(), x), y);
				break;
			}
			case 'D': {
				cin >> z;
				arr.erase(next(arr.begin(), z));
				break;
			}
			case 'C': {
				cin >> x >> y;					
				arr.erase(next(arr.begin(), x));
				arr.insert(next(arr.begin(), x), y);
				break;
			}
		}
	  if(debug) {
	  	cout << "check " << i << ": ";
	  	for(auto data: arr) {
	  		cout <<	data << " ";
	  	}
	  	cout << "\n";
	  }
	}



	if(L > arr.size() - 1 ) {
		cout << "#" << tn << " " << -1 << "\n";
	} else {
		cout << "#" << tn << " " << arr[L] << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++) solve(i);
}
