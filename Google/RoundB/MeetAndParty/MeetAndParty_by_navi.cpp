#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int T, n;

void gao(map<int, ll>& mp, int* x1, int* y1, int* x2, int* y2) {
    int minx = *min_element(x1, x1 + n);
    int left = 0, right = 0;
    ll total = 0;
    map<int, int> count;
    for (int i = 0; i < n; ++i) {
        //printf("i = %d, (%d, %d) -> (%d, %d)\n", i, x1[i], y1[i], x2[i], y2[i]);
        for (int x = x1[i]; x <= x2[i]; ++x) {
            int t = y2[i] - y1[i] + 1;
            if (x != minx) {
                right += t;
            } else {
                left += t;
            }
            total += (ll)(x - minx) * t;
            count[x] += t;
        }
    }

    //printf("total = %lld\n", total);
    //for (auto i : count) printf("%d %d\n", i.first, i.second);

    vector<pii> v(count.begin(), count.end());
    for (int i = 0; i < (int)v.size(); ++i) {
        mp[v[i].first] = total;
        if (i + 1 < (int)v.size()) {
            total = total - (right - left) * (v[i + 1].first - v[i].first);
            right -= v[i + 1].second;
            left += v[i + 1].second;
        }
    }
    //for (auto i : mp) printf("%d %lld\n", i.first, i.second);
}

int main() {
    int x1[1000], y1[1000], x2[1000], y2[1000];

    scanf("%d", &T);
    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
        }

        map<int, ll> mpx;
        gao(mpx, x1, y1, x2, y2);
        map<int, ll> mpy;
        gao(mpy, y1, x1, y2, x2);

        int resx = -1, resy = -1;
        ll res = 0x3f3f3f3f3f3f3f3fLL;
        for (int i = 0; i < n; ++i) {
            for (int x = x1[i]; x <= x2[i]; ++x) {
                for (int y = y1[i]; y <= y2[i]; ++y) {
                    ll cur = mpx[x] + mpy[y];
                    if (cur < res || (cur == res && (x < resx || (x == resx && y < resy)))) {
                        res = cur;
                        resx = x;
                        resy = y;
                    }
                }
            }
        }

        printf("Case #%d: %d %d %lld\n", caseNum, resx, resy, res);
    }
    return 0;
}
