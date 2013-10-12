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
int rx[1010][2],ry[1010][2];
int m;
PII pp[1001001];
PII xd[1001001];
PII yd[1001001];
void input(){
	RI(n);
	m=0;
	REP(i,n){
		RII(rx[i][0],ry[i][0]);
		RII(rx[i][1],ry[i][1]);
		REP1(x,rx[i][0],rx[i][1]){
			REP1(y,ry[i][0],ry[i][1]){
				pp[m]=MP(x,y);
				xd[m]=MP(x,m);	
				yd[m]=MP(y,m);
				m++;
			}
		}	
	}
}
LL dis[1001001];

void go(PII r[]){
	sort(r,r+m);
	LL d=0;
	REP(i,m) d+=abs(r[i].first-r[0].first);
	dis[r[0].second]+=d;
	for(int i=1;i<m;i++){
		d-=1LL*(m-i-i)*(r[i].first-r[i-1].first);
		dis[r[i].second]+=d;
	}
}

LL bd;
int bx,by;

void solve(){
	memset(dis,0,sizeof(dis));
	go(xd);
	go(yd);
	bd = 1e18;
	REP(i,m){
		if(dis[i]<bd || 
		  (dis[i]==bd && pp[i].first<bx) ||
		  (dis[i]==bd && pp[i].first==bx && pp[i].second<by)){
			bd=dis[i];
			bx=pp[i].first;
			by=pp[i].second;
		}
	}
	printf("%d %d ",bx,by);
	cout << bd << endl;
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


