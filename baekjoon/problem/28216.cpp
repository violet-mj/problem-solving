#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <tuple>
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
#define mt make_tuple
#define f first
#define s second
#define endl "\n"
#define all(v) (v).begin(),(v).end()

int n, q, direction, toward;

struct tiii {
	int xi;
	int yi;
	int ci;
	tiii(int xxi,int yyi,int cci): xi(xxi), yi(yyi), ci(cci) {}
};

vector<tiii> items;
vector<vector<int>> xCoord(200001,vector<int>(1, 0));
vector<vector<int>> yCoord(200001,vector<int>(1, 0));
vector<vector<lint>> xPre(200001,vector<lint>(1, 0));
vector<vector<lint>> yPre(200001,vector<lint>(1, 0));

void solve() {
	cin >> n >> q;	
	int t1,t2,t3;	
	for(int i = 0; i < n; i++) {
		cin >> t1 >> t2 >> t3;
		items.pb(tiii(t1, t2, t3));
	}
	sort(all(items), [](tiii tiii1, tiii tiii2) {
				if(tiii1.yi == tiii2.yi) {
					return tiii1.xi < tiii2.xi;	
				}	
				return tiii1.yi < tiii2.yi;
			});

	for(int i = 0; i < items.size(); i++) {
		tiii item = items[i];
		int xi = item.xi;
		int yi = item.yi;
		int ci = item.ci;
		int xSize = xPre[xi].size();
		int ySize = yPre[yi].size();
		xCoord[xi].pb(yi);
		yCoord[yi].pb(xi);
		xPre[xi].pb(xPre[xi][xSize-1] + ci);
		yPre[yi].pb(yPre[yi][ySize-1] + ci);
	}

	debug(xPre[1], xPre[3], xPre[5]);
	debug(yPre[5], yPre[8]);

	pii curr = mp(1, 1);
	lint res = 0;
	for(int i = 0; i < q; i++) {
		cin >> direction >> toward;	
		int prevC, nextC;
		int xx = curr.f;
		int yy = curr.s;
		debug(curr);
		if(direction == 0) {
			prevC = xx + 1;
			nextC = xx + toward;
			int f = lower_bound(all(yCoord[yy]), prevC) - yCoord[yy].begin() - 1;
			int s = upper_bound(all(yCoord[yy]), nextC) - yCoord[yy].begin() - 1;
			debug(f, s);
			debug(yPre[yy], yCoord[yy]);
			debug(yPre[yy][s], yPre[yy][f]);
			res += yPre[yy][s] - yPre[yy][f];
			curr.f = nextC;
		} else if (direction == 2) {
			prevC = xx - toward;
			nextC = xx - 1;
			int f = lower_bound(all(yCoord[yy]), prevC) - yCoord[yy].begin() - 1;
			int s = upper_bound(all(yCoord[yy]), nextC) - yCoord[yy].begin() - 1;
			debug(f, s);
			debug(yPre[yy], yCoord[yy]);
			debug(yPre[yy][s], yPre[yy][f]);
			res += yPre[yy][s] - yPre[yy][f];
			curr.f = prevC;
		} else if(direction == 1) {
			prevC = yy + 1;	
			nextC = yy + toward;
			int f = lower_bound(all(xCoord[xx]), prevC) - xCoord[xx].begin() - 1;
			int s = upper_bound(all(xCoord[xx]), nextC) - xCoord[xx].begin() - 1;
			debug(f, s);
			debug(xPre[xx], xCoord[xx]);
			debug(xPre[xx][s], xPre[xx][f]);
			res += (xPre[xx][s] - xPre[xx][f]);
			curr.s = nextC;
		} else {
			prevC = yy - toward;	
			nextC = yy - 1;
			int f = lower_bound(all(xCoord[xx]), prevC) - xCoord[xx].begin() - 1;
			int s = upper_bound(all(xCoord[xx]), nextC) - xCoord[xx].begin() - 1;
			debug(f, s);
			debug(xPre[xx], xCoord[xx]);
			debug(xPre[xx][s], xPre[xx][f]);
			res += xPre[xx][s] - xPre[xx][f];
			curr.s = prevC;
		}
		debug(prevC, nextC);
		debug(res);
		debug();
	}
	cout << res << "\n";
}

int main() {
	cin.tie(0);
  ios::sync_with_stdio(0);
	int t;
	// cin >> t;
	// for(int i = 0; i < t; i++) 
	solve();
}
