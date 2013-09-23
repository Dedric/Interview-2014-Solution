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

bool cmp(const int &x,const int &y){
	return x>y;
}

void solve(){
	int n,i,x;
	scanf("%d",&n);
	vector<int> ans(n),even,even2,odd,odd2;
	for(i=0;i<n;++i){
		scanf("%d",&x);
		if(x%2==0){
			even.push_back(x);
			even2.push_back(i);
		}else {
			odd.push_back(x);
			odd2.push_back(i);
		}
	}
	sort(odd.begin(),odd.end());
	sort(even.begin(),even.end(),cmp);
	for(i=0;i<odd.size();++i){
		ans[odd2[i]]=odd[i];
	}
	for(i=0;i<even.size();++i){
		ans[even2[i]]=even[i];
	}
	for(i=0;i<ans.size();++i)printf(" %d",ans[i]);
	printf("\n");
}
int main(){
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;++i){
		printf("Case #%d:",i);
		solve();
	}
	return 0;
}