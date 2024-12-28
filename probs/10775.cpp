#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5;

int parent[MAX+1];

int find(int a)
{
    if (a == parent[a]) return a;
    else return parent[a] = find(parent[a]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a < b) parent[b] = a;
    else if (b < a) parent[a] = b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int G, P; cin >> G >> P;
    for (int i = 1; i <= G; i++) parent[i] = i;

    int ans = P;
    for (int i = 0; i < P; i++) {
        int g; cin >> g;
        if (find(g) == 0) {
            ans = i;
            break;
        }
        else {
            merge(g, find(g)-1);
        }
    }

    cout << ans << '\n';

    return 0;
}
