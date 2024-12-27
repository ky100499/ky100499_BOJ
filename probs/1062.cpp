#include <bits/stdc++.h>

using namespace std;

vector<int> W;
int N, K, ans = 0;

int bit_count(int n)
{
    int ret = 0;
    while (n) {
        ret += n&1;
        n >>= 1;
    }
    return ret;
}

void bt(int b, int c, int n)
{
    if (n == K || c == 0) {
        int cnt = 0;
        for (int w : W)
            if ((w & b) == w) cnt++;
        ans = max(ans, cnt);
    }
    else if (n < K) {
        for (int i = 0; i < 26; i++) {
            if (c & (1<<i) && (b & (1<<i)) == 0) {
                c ^= 1<<i;
                bt(b|(1<<i), c, n+1);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> N >> K; W.resize(N);
    for (int i = 0; i < N; i++) {
        string ipt; cin >> ipt;
        int x = 0;
        for (char c : ipt) x |= 1<<(c-'a');
        W[i] = x;
    }

    int b = 0, c = 0;
    for (char ch : string("antatica")) b |= 1<<(ch-'a');
    for (int w : W) c |= w;

    bt(b, b^c, bit_count(b));
    cout << ans << '\n';

    return 0;
}
