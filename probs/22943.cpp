#include <iostream>
#include <cmath>
#include <vector>

#define MAX 100000

using namespace std;

vector<int> primes(MAX, 1);
int U[10] = { 0, }, K, M;

int bt(int n, int l)
{
    if (l == K) {
        int ans = 0;

        for (int i = 2; i < n/2; i++) {
            if (primes[i] && primes[n-i] && i != n-i) {
                ans += 1;
                break;
            }
        }

        while (n && n%M == 0) n /= M;

        for (int i = 2; i <= sqrt(n); i++) {
            if (primes[i] && primes[n/i] && n % i == 0) {
                ans += 1;
                break;
            }
        }

        return ans == 2;
    }

    int ret = 0;
    for (int i = 0; i < 10; i++) {
        if (!U[i]) {
            U[i] = 1;
            ret += bt(10*n+i, l+1);
            U[i] = 0;
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    primes[0] = primes[1] = 0;
    for (int i = 2; i < sqrt(MAX); i++)
        if (primes[i])
            for (int j = i*i; j < MAX; j += i)
                primes[j] = 0;

    cin >> K >> M;

    int ans = 0;
    for (int i = 1; i < 10; i++) {
        U[i] = 1;
        ans += bt(i, 1);
        U[i] = 0;
    }
    cout << ans << '\n';

    return 0;
}
