#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6;

int primes[MAX+1],
    cnt[MAX+1] = {},
    cnt2[MAX+1] = {};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    fill(primes+2, primes+MAX, 1);
    for (int i = 2; i <= sqrt(MAX); i++)
        if (primes[i])
            for (int j = i*i; j <= MAX; j += i)
                primes[j] = 0;

    cnt[2] = cnt2[2] = 1;
    for (int i = 3; i <= MAX; i++) {
        cnt[i] = primes[i] ? cnt[i-1]+1 : cnt[i-1];
        cnt2[i] = primes[i] && i%4 == 1 ? cnt2[i-1]+1 : cnt2[i-1];
    }

    while (1) {
        int L, U; cin >> L >> U;
        if (L == -1 && U == -1) break;
        cout << L << ' ' << U << ' ' << cnt[max(U, 0)]-cnt[max(L-1, 0)] << ' ' << cnt2[max(U, 0)] - cnt2[max(L-1, 0)] << '\n';
    }

    return 0;
}
