#include <bits/stdc++.h>

using namespace std;

int N, ans = -0x7fffffff;
string F;

int calc(int a, char op, int b)
{
    if (op == '+') return a+b;
    if (op == '-') return a-b;
    if (op == '*') return a*b;
    return 0;
}

void bt(int i, int v)
{
    if (i == N) {
        ans = max(ans, v);
        return;
    }

    bt(i+2, calc(v, F[i], F[i+1]-'0'));
    if (i+2 < N) bt(i+4, calc(v, F[i], calc(F[i+1]-'0', F[i+2], F[i+3]-'0')));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> N >> F;
    bt(1, F[0]-'0');
    cout << ans << '\n';

    return 0;
}
