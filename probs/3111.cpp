#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    string A; cin >> A;
    deque<char> L, M, R;
    while (1) {
        char c; cin >> c;
        if (cin.eof()) break;
        M.push_back(c);
    }

    int i, l = A.size();
    while (1) {
        i = 0;
        while (!M.empty() && i < l) {
            if (M.front() == A[i]) {
                M.pop_front();
                i++;
            }
            else if (i) {
                L.push_back(A[0]);
                for (int j = i-1; j > 0; j--)
                    M.push_front(A[j]);
                i = 0;
            }
            else {
                L.push_back(M.front());
                M.pop_front();
            }
        }

        if (M.empty()) break;
        for (int j = 0; j < l*2 && !L.empty(); j++) {
            M.push_front(L.back());
            L.pop_back();
        }

        i = 0;
        while (!M.empty() && i > -l) {
            if (M.back() == A[l+i-1]) {
                M.pop_back();
                i--;
            }
            else if (i) {
                R.push_front(A[l-1]);
                for (int j = i+1; j < 0; j++)
                    M.push_back(A[l+j-1]);
                i = 0;
            }
            else {
                R.push_front(M.back());
                M.pop_back();
            }
        }

        if (M.empty()) break;
        for (int j = 0; j < l*2 && !R.empty(); j++) {
            M.push_back(R.front());
            R.pop_front();
        }
    }
    i %= l;

    for (char c : L) cout << c;
    for (int j = 0; j < i; j++) cout << A[j];
    for (int j = i+1; j <= 0; j++) cout << A[l+j-1];
    for (char c : R) cout << c;
    cout << '\n';

    return 0;
}
