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

int n;
char c[110][110];

void input(){
	RI(n);
	REP(i,n) scanf("%s",c[i]);
}

int dx[]={1,0,-1,0,1,-1};
int dy[]={0,1,0,-1,-1,1};

int vis[110][110];

bool out(int i,int j){
	return i<0 || i>=n || j<0 || j>=n;
}

bool go(int i,int j,char t){
	vis[i][j]=1;
	if(j==n-1)return true;
	REP(d,6){
		int ni=i+dx[d], nj=j+dy[d];
		if(out(ni,nj) || vis[ni][nj] || c[ni][nj]!=t)continue;
		if(go(ni,nj,t))return true;
	}
	return false;
}

bool win(char t){
	memset(vis,0,sizeof(vis));
	REP(i,n){
		if(c[i][0]==t && vis[i][0]==0 && go(i,0,t)) return true;
	}
	return false;
}

void solve(){
	int rn=0, bn=0;
	REP(i,n) REP(j,n){
		if(c[i][j]=='R') rn++;
		if(c[i][j]=='B') bn++;
	}
	if(abs(rn-bn)>1){
		puts("Impossible");
		return;
	}
	if(win('B')){
		int w=0;
		REP(i,n)REP(j,n){
			if(c[i][j]!='B')continue;
			c[i][j]='.';
			if(!win('B')){w=1;break;}
			c[i][j]='B';
		}
		if(rn>bn || w==0) puts("Impossible");
		else puts("Blue wins");
		return;
	}
	REP(i,n){
		for(int j=i+1;j<n;j++) swap(c[i][j],c[j][i]);
	}
	if(win('R')){
		int w=0;
		REP(i,n)REP(j,n){
			if(c[i][j]!='R')continue;
			c[i][j]='.';
			if(!win('R')){w=1;break;}
			c[i][j]='R';
		}
		if(bn>rn || w==0) puts("Impossible");
		else puts("Red wins");
		return;
	}	
	puts("Nobody wins");
	
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



