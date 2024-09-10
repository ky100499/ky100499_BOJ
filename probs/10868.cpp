#include <iostream>
#include <vector>

#define INF 1e9

using namespace std;

vector<int> ST;

int init(int i, int l, int h)
{
    if (l == h) {
        cin >> ST[i];
    }
    else {
        int m = (l+h)/2;
        init(i*2, l, m);
        init(i*2+1, m+1, h);
        ST[i] = min(ST[2*i], ST[2*i+1]);
    }
    return ST[i];
}

int find(int i, int l, int h, int s, int e)
{
    if (s <= l && h <= e) {
        return ST[i];
    }
    else if (e < l || h < s) {
        return INF;
    }
    else {
        int m = (l+h)/2;
        return min(find(i*2, l, m, s, e), find(i*2+1, m+1, h, s, e));
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    ST.resize(4*N);
    init(1, 0, N-1);

    while (M--) {
        int a, b; cin >> a >> b;
        cout << find(1, 0, N-1, a-1, b-1) << '\n';
    }
}
