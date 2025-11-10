#include <bits/stdc++.h>

using namespace std;

string S;

int cvt(char c)
{
    if ('A' <= c && c <= 'F') return c-'A'+10;
    else return c-'0';
}

int solve(int i)
{
    return i == 0 ? 0 : 16 * solve(i-1) + cvt(S[i-1]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> S;
    cout << solve(S.size()) << '\n';

    return 0;
}
