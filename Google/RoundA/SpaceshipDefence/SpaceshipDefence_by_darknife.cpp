#include<cstdio>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cassert>
#include<ctime>
#include<queue>
using namespace std;

#define REP(i,n) for(int i = 0; i < (int)n; i++)
#define FOR(i,n,m) for(int i = (int)n; i <= (int)m; i++)
#define FOD(i,n,m) for(int i = (int)n; i >= (int)m; i--)
#define EACH(i,v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)

typedef long long i64;
typedef pair<int, int> PI;

#define sz(v) ((i64)(v).size())
#define all(v) (v).begin(),(v).end()
#define bit(n) (1LL<<(i64)(n))

#define PB push_back
#define MP make_pair
#define X first
#define Y second
template<class T> void fmax(T &a, const T &b) { if (a < b) a = b; }
template<class T> void fmin(T &a, const T &b) { if (a > b) a = b; }
template<class T> T sqr(const T &a) { return a * a; }

const int N = 3005;
int G[N][N], id[800000];
int n, m, cnt;
map<string, int> ID;

int getID(const string &s) {
	if (!ID.count(s)) {
		ID[s] = cnt++;
	}
	return ID[s];
}
const int INF = 1e9;
int main() {
	int Te;
	scanf("%d", &Te);
	for (int Ti = 1; Ti <= Te; Ti++) {
		scanf("%d", &n);
		cnt = 0;
		ID.clear();

		FOR(i, 1, n) {
			string s;
			cin >> s;
			id[i] = getID(s);
		}
		REP(i, cnt) REP(j, cnt) G[i][j] = (i == j ? 0 : INF);
		scanf("%d", &m);
		REP(i, m) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			x = id[x];
			y = id[y];
			G[x][y] = min(G[x][y], z);
		}
//return 0;
		REP(k, cnt) REP(i, cnt) REP(j, cnt)
			G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
		REP(i, cnt) REP(j, cnt)
		if (G[i][j] >= INF) G[i][j] = -1;
		int q;
		scanf("%d", &q);
		printf("Case #%d:\n", Ti);
		while (q--) {
			int i, j;
			scanf("%d%d", &i, &j);
			i = id[i]; j = id[j];
			printf("%d\n", G[i][j]);
		}
	}
}