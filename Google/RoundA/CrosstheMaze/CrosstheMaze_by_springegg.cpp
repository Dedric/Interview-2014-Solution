#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<map>
#include<cstring>
#include<vector>
#include<set>
#define maxn 201000
#define maxl 1000000000
#define mod 1000003
using namespace std;

typedef unsigned long long ull;

const int dx[]={0,-1,0,1};
const int dy[]={1,0,-1,0};
const char ds[]={"ENWS"};
char g[110][110],ans[11000];

bool checkleft(int x,int y,int d){
	d=(d+1)%4;
	x+=dx[d];y+=dy[d];
	return g[x][y]=='#';
}

bool checkst(int x,int y,int d){
	x+=dx[d];y+=dy[d];
	return g[x][y]=='#';
}

void solve(){
	int n,i,j,sx,sy,tx,ty,d;
	scanf("%d",&n);
	for(i=0;i<=n+1;++i)
		for(j=0;j<=n+1;++j)g[i][j]='#';
	for(i=1;i<=n;++i){
		scanf("%s",g[i]+1);
		g[i][n+1]='#';
	}
	scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
	if(sx==1 && sy==1){
		d=0;
	}else if(sx==1 && sy==n){
		d=3;
	}else if(sx==n && sy==n){
		d=2;
	}else {
		d=1;
	}
	if(sx==tx && sy==ty){
		printf("%d\n",0);
		printf("\n");
	}
	for(i=1;i<=10000;++i){
		if(!checkleft(sx,sy,d)){
			d=(d+1)%4;
			sx+=dx[d];sy+=dy[d];
			ans[i]=ds[d];
		}else {
			for(j=0;j<=3;++j){
				if(!checkst(sx,sy,d))break;
				d=(d+3)%4;
			}
			if(checkst(sx,sy,d))break;
			sx+=dx[d];sy+=dy[d];
			ans[i]=ds[d];
		}
		if(sx==tx && sy==ty){
			printf("%d\n",i);
			for(j=1;j<=i;++j)printf("%c",ans[j]);
			printf("\n");
			return;
		}
	}
	printf("Edison ran out of energy.\n");
}

int main(){
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;++i){
		printf("Case #%d: ",i);
		solve();
	}
}