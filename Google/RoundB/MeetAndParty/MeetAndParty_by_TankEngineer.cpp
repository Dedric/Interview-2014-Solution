#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		vector<pair<int, int> > v;
		vector<int> x, y;
		vector<long long> sumx, sumy;
		for (int i = 0; i < n; ++i) {
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			for (int tx = x1; tx <= x2; ++tx) {
				for (int ty = y1; ty <= y2; ++ty) {
					v.push_back(make_pair(tx, ty));
					x.push_back(tx);
					y.push_back(ty);
				}
			}
		}
		n = v.size();
		sort(v.begin(), v.end());
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		sumx.push_back(0);
		sumy.push_back(0);
		for (int i = 0; i < n; ++i) {
			sumx.push_back(sumx.back() + x[i]);
			sumy.push_back(sumy.back() + y[i]);
		}
		pair<int, int> ans;
		long long bestcost = 1ll << 61;
		for (int i = 0; i < n; ++i) {
			int tx = lower_bound(x.begin(), x.end(), v[i].first) - x.begin(), ty = lower_bound(y.begin(), y.end(), v[i].second) - y.begin();
			long long cost = (long long)v[i].first * (tx + 1) - sumx[tx + 1] 
				+ sumx.back() - sumx[tx + 1] - (long long)v[i].first * (n - 1 - tx) 
				+ (long long)v[i].second * (ty + 1) - sumy[ty + 1] 
				+ sumy.back() - sumy[ty + 1] - (long long)v[i].second * (n - 1 - ty);
			if (cost < bestcost) {
				bestcost = cost;
				ans = v[i];
			}
		}
		static int id = 0;
		cout  << "Case #" << ++id << ": " << ans.first << ' ' << ans.second << ' ' << bestcost << endl;
	}
	return 0;
}
