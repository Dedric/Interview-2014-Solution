#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n;
char s[200000];
int c[200000];

int main() {
    int ch;
    n = 0;
    while ((ch = getchar()) != EOF) {
        s[n++] = ch;
    }

    int count = 0;
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] == '/' && s[i + 1] == '*') {
            ++count;
            ++c[i++];
        } else if (s[i] == '*' && s[i + 1] == '/') {
            if (count > 0) {
                --count;
                --c[i + 2];
                ++i;
            }
        }
    }

    printf("Case #1:\n");
    for (int i = 0, count = 0; i < n; ++i) {
        count += c[i];
        //if (count < 0) putchar('~');
        //assert(count >= 0);
        if (count == 0) {
            putchar(s[i]);
        }
    }

    return 0;
}
