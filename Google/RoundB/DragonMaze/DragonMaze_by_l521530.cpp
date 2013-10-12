// TwT514 {{{
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define SZ(x) ((int)(x).size())
#define FOR(i,c) for (__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define REP1(i,a,b) for (int i=(int)(a); i<=(int)(b); i++)
#define ALL(x) (x).begin(),(x).end()
#define MS0(x,n) memset((x),0,(n)*sizeof(*x))
#define MS1(x,n) memset((x),-1,(n)*sizeof(*x))
#define MP make_pair
#define PB push_back
#define RI(a) scanf("%d",&(a))
#define RII(a,b) scanf("%d%d",&(a),&(b))
#define RIII(a,b,c) scanf("%d%d%d",&(a),&(b),&(c))
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
// }}}
#define INF 100100
int n,m;
int ex,ey,gx,gy,mp[110][110];

void input(){
	RII(n,m);
	RII(ex,ey);
	RII(gx,gy);
	REP(i,n)REP(j,m)RI(mp[i][j]);
}

int dis[110][110], c[110][110];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

bool out(int x,int y){
	return x<0 || x>=n || y<0 || y>=m;
}

void solve(){
	REP(i,n)REP(j,m) dis[i][j]=INF;
	memset(c,0,sizeof(c));
	dis[ex][ey]=0;
	c[ex][ey]=mp[ex][ey];
	queue<PII> q;
	q.push(MP(ex,ey));

	while(!q.empty()){
		PII p = q.front(); q.pop();
		int x = p.first, y = p.second, ds = dis[x][y];
		REP(d,4){
			int nx = x+dx[d], ny = y+dy[d];
			if(out(nx,ny) || mp[nx][ny]==-1 || dis[nx][ny]<=ds) continue;

			c[nx][ny]=max(c[nx][ny], c[x][y]+mp[nx][ny]);
			if(dis[nx][ny]==INF){
				dis[nx][ny]=ds+1;
				q.push(MP(nx,ny));	
			}
		}		
	}
	if(dis[gx][gy]==INF)puts("Mission Impossible.");
	else printf("%d\n",c[gx][gy]);
}

int main() {
	int zn;
	RI(zn);
	REP(zi,zn){
		input();
		printf("Case #%d: ",zi+1);
		solve();
	}
	
	return 0;
}


