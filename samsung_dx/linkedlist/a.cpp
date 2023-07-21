
#include <vector>
#include <algorithm>
#include <queue>
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
deque<int> q1;
deque<int> q2;

void solve(int tn) {
	int n, command, tmp;
	int curr = 1;
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> tmp;
		q2.pb(tmp);
	}

	cin >> command;

	for(int i = 0; i < command; i++) {
		char cmd;	
		int x, y, qn, tmpn, xloc;
		cin >> cmd;
		switch(cmd) {
			case 'A': {
				if(debug) cout << "A segfault?" << "\n";
				cin >> qn;
				for(int i = 0; i < qn; i++) {
					cin >> tmpn;	
					q2.pb(tmpn);
				}
				break;
			}
			case 'D': {
				if(debug) cout << "D segfault?" << "\n";
				int x, y;
				int value;
				cin >> x >> y;
				int moved = x - curr;
				if(moved < 0) {
					for(int i = 0; i < -moved; i++)	{
						value = q1.back();
						q1.pop_back();
						q2.push_front(value);
					}
				} else {
					for(int i = 0; i < moved; i++)	{
						value = q2.front();
						q2.pop_front();
						q1.push_back(value);
					}
				}

				for(int i = 0; i < y; i++) {
					q2.pop_front();	
				}
				curr = x;
				break;
			}
			case 'I': {
				if(debug) cout << "I segfault?" << "\n";
				cin >> xloc >> qn;
				int moved = xloc - curr;
				if(moved < 0) {
					for(int i = 0; i < moved; i++)	{
						int value = q1.back();
						q1.pop_back();
						q2.push_front(value);
					}
				} else {
					for(int i = 0; i < -moved; i++)	{
						int value = q2.front();
						q2.pop_front();
						q1.push_back(value);
					}
				}
				for(int i = 0; i < qn; i++) {
					int tmpi;
					cin >> tmpi;
					q2.push_front(tmpi);
				}
				curr = xloc;
				break;
			}
		}
	}
	cout << "#" << tn << " ";
	while(!q2.empty()) {
		int v = q2.front();
		q2.pop_front();
		q1.push_back(v);
	}
	for(int i = 0; i < 10; i++) {
		int p;	
		p = q1.front();
		q1.pop_front();
		cout << p << " ";
	}
	cout << "\n";
	q1.clear();
	q2.clear();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for(int i = 1; i <= 1; i++) solve(i);
}
