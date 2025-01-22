#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(ll n)
{
    if (n < 2) return n;

    ll ret = 0, l = 0, r;

    while ((1LL<<(l+1)) <= n) l++;
    r = n - (1LL<<l);

    // 1000...000 ~ n 맨 앞자리 1
    ret += r + 1;
    // 1000...000 ~ n 맨 앞자리 제외한 1 개수 합
    ret += solve(r);
    // 1 ~ 1000...000 1 개수 (0 1 정확히 반반씩 길이만큼)
    ret += l * (1LL<<(l-1));

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll A, B; cin >> A >> B;

    cout << solve(B) - solve(A-1) << '\n';

    return 0;
}
