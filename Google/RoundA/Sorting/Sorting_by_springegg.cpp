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

void solve(){
	int xz;
	ull n,x,y;
	cin>>xz;
	if(xz==1){
		cin>>n;
		vector<int> v;
		while(n>1){
			v.push_back(n%2);
			n/=2;
		}
		reverse(v.begin(),v.end());
		ull p=1,q=1;
		for(int i=0;i<v.size();++i)if(v[i]==0){
			q+=p;
		}else {
			p+=q;
		}
		cout<<p<<" "<<q<<endl;
	}else {
		cin>>x>>y;
		ull now=1,ans=0;
		while(x!=1 || y!=1){
			if(x>y){
				ans+=now;
				x-=y;
			}else {
				y-=x;
			}
			now<<=1;
		}
		ans+=now;
		cout<<ans<<endl;
	}
}

int main(){
	ios::sync_with_stdio(false);
	int t,i;
	cin>>t;
	for(i=1;i<=t;++i){
		cout<<"Case #"<<i<<": ";
		solve();
	}
}