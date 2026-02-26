#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int A, B; cin >> A >> B;

    cout << A/B << '.'; A %= B;
    for (int i = 0; i < 1111 && A; i++) {
        A *= 10;
        cout << A/B;
        A %= B;
    }
    cout << '\n';

    return 0;
}
