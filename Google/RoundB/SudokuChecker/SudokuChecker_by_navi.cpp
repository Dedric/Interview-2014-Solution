#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, n;
int a[36][36];

bool check(const vector<int>& v) {
    vector<bool> exists(N + 1, false);
    for (auto i : v) {
        if (exists[i]) {
            return false;
        }
        exists[i] = true;
    }
    return true;
}

bool gao() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (a[i][j] < 1 || a[i][j] > N) {
                return false;
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        {
            vector<int> v;
            for (int j = 0; j < N; ++j) {
                v.push_back(a[i][j]);
            }
            if (!check(v)) {
                return false;
            }
        }
        {
            vector<int> v;
            for (int j = 0; j < N; ++j) {
                v.push_back(a[j][i]);
            }
            if (!check(v)) {
                return false;
            }
        }
        {
            vector<int> v;
            for (int j = 0; j < N; ++j) {
                v.push_back(a[i / n * n + j / 3][i % n * n + j % 3]);
            }
            if (!check(v)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    scanf("%d", &T);
    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        scanf("%d", &n);
        N = n * n;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        printf("Case #%d: %s\n", caseNum, gao() ? "Yes" : "No");
    }
    return 0;
}
