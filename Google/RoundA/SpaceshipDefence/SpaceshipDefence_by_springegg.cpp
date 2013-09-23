#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<map>
#include<cstring>
#include<vector>
#include<set>
#define maxn 2010
#define maxm 80100
#define maxl 1000000000
#define mod 1000003
using namespace std;

typedef unsigned long long ull;

map<string,int> mm;
int tot;
vector<pair<int,int> > v[maxn];
int d[maxn];

int find(const string &s){
	if(mm.count(s))return mm[s];
	mm[s]=++tot;
	v[tot].clear();
	return tot;
}

int dui[maxn];
bool visit[maxn];

int getDis(int x,int y){
	int head=0,tail=1,i,j,tmp;
	for(i=1;i<=tot;++i){
		d[i]=maxl;
		visit[i]=false;
	}
	d[x]=0;
	visit[x]=true;
	dui[1]=x;
	while(head!=tail){
		if(++head==maxn)head-=maxn;
		x=dui[head];
		for(i=0;i<v[x].size();++i){
			j=v[x][i].first;
			tmp=d[x]+v[x][i].second;
			if(tmp<d[j]){
				d[j]=tmp;
				if(!visit[j]){
					visit[j]=true;
					if(++tail==maxn)tail-=maxn;
					dui[tail]=j;
				}
			}
		}
		visit[x]=false;
	}
	if(d[y]<maxl)return d[y];else return -1;
}

string a[maxm];

void solve(){
	int n,i,m,x,y,z,q;
	cin>>n;
	mm.clear();
	tot=0;
	getline(cin,a[0]);
	for(i=1;i<=n;++i){
		getline(cin,a[i]);
	}
	cin>>m;
	for(i=1;i<=m;++i){
		cin>>x>>y>>z;
		x=find(a[x]);y=find(a[y]);
		v[x].push_back(make_pair(y,z));
	}
	cin>>q;
	for(i=1;i<=q;++i){
		cin>>x>>y;
		x=find(a[x]);y=find(a[y]);
		cout<<getDis(x,y)<<endl;
	}
}


int main(){
	ios::sync_with_stdio(false);
	int t,i;
	cin>>t;
	for(i=1;i<=t;++i){
		cout<<"Case #"<<i<<":"<<endl;
		solve();
	}
}