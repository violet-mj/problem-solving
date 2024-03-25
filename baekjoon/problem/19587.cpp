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

const vector<vector<lint>> matrix = {
	{2, 1, 0},
	{0, 2, 1},
	{0, 1, 0}
};

const vector<vector<lint>> iMatrix = {
	{1, 0, 0},
	{0, 1, 0},
	{0, 0, 1}
};

const lint MOD = 1000000007LL;

vector<vector<lint>> matMul(vector<vector<lint>> cmat1, vector<vector<lint>> cmat2)  {

	vector<vector<lint>> tmpMat(3, vector<lint>(3, 0));

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			for(int z = 0; z < 3; z++) {
				tmpMat[i][j] += cmat1[i][z] * cmat2[z][j];
				tmpMat[i][j] %= MOD;
			}
		}
	}

	return tmpMat;
}

vector<vector<lint>> mul(lint n) {
	if(n == 0) return	iMatrix; 
	if(n == 1) return matrix;
	vector<vector<lint>> mid = mul(n / 2);
	if(n % 2 == 1) {
		return matMul(matMul(mid, mid), matrix);
	} else {
		return matMul(mid, mid);
	}
}


void solve() {
	map<lint, lint>	m;
	lint n; cin >> n;
	m[1] = 3;
	m[2] = 7;
	m[3] = 17;

	if(n <= 3) {
		cout << m[n] << "\n";
		return;	
	}

	debug(n - 3LL);
	vector<vector<lint>> result = mul(n - 3LL);

	lint res = 0LL;

	for(int i = 0; i < 3; i++)	 {
		res += result[0][i]	* m[3 - i];
		res %= MOD;
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
