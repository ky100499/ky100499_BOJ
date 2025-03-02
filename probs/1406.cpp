#include <bits/stdc++.h>

using namespace std;

list<char> L;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    string S; cin >> S;
    for (char c : S) L.push_back(c);
    auto csr = L.end();

    int M; cin >> M;
    while (M--) {
        char op; cin >> op;
        if (op == 'L' && csr != L.begin()) csr = prev(csr);
        if (op == 'D' && csr != L.end()) csr = next(csr);
        if (op == 'B' && csr != L.begin()) L.erase(prev(csr));
        if (op == 'P') {
            char c; cin >> c;
            L.insert(csr, c);
        }
    }
    for (char c : L) cout << c; cout << '\n';

    return 0;
}
