#include <bits/stdc++.h>

using namespace std;

int cnt[10] = {};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;

    int upper = 0;
    for (long long i = 1; i <= N; i *= 10) {
        int q = N/(i*10), r = N%(i*10)/i;

        for (int j = 0; j < r; j++) cnt[j] += (q+1)*i;
        cnt[0] -= i;
        for (int j = r; j < 10; j++) cnt[j] += q*i;
        cnt[r] += upper+1;

        upper += r*i;
    }

    for (int i = 0; i < 10; i++) cout << cnt[i] << ' ';
    cout << '\n';

    return 0;
}
