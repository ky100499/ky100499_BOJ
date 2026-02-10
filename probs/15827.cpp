#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using ssc = tuple<string, string, char>;

map<string, pll> V, ans;
map<string, ssc> M;

ll gcd(ll a, ll b)
{
    if (b == 0) return a;
    else return gcd(b, a%b);
}

pll rdc(pll a)
{
    auto [p, q] = a;
    ll g = gcd(abs(p), abs(q));
    p /= g; q /= g;
    if (q < 0) p *= -1, q *= -1;
    return {p, q};
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    queue<string> q;
    while (N--) {
        string A; char o; cin >> A >> o;
        if (o == 'E') {
            int v; cin >> v;
            V[A] = {v,1};
        }
        else {
            string x, y; cin >> x >> y;
            M[A] = {x, y, o};
            q.push(A);
        }
        ans[A] = {0,1};
    }

    while (!q.empty()) {
        string A = q.front(); q.pop();
        auto [x, y, o] = M[A];

        if (V.find(x) == V.end() || V.find(y) == V.end()) q.push(A);
        else {
            auto [p1, q1] = V[x];
            auto [p2, q2] = V[y];

            if (o == 'A') V[A] = rdc({p1*q2 + p2*q1, q1*q2});
            else if (o == 'S') V[A] = rdc({p1*q2 - p2*q1, q1*q2});
            else if (o == 'M') V[A] = rdc({p1*p2, q1*q2});
            else V[A] = rdc({p1*q2, q1*p2});
        }
    }

    ans["HAPPY"] = {1,1};
    q.emplace("HAPPY");
    while (!q.empty()) {
        auto A = q.front(); q.pop();
        if (M.find(A) == M.end()) continue;

        auto [x, y, o] = M[A];
        auto [p1, q1] = ans[A];
        auto [p2, q2] = V[x];
        auto [p3, q3] = V[y];

        if (o == 'A') {
            ans[x] = ans[y] = ans[A];
        }
        else if (o == 'S') {
            ans[x] = {p1, q1};
            ans[y] = {-p1, q1};
        }
        else if (o == 'M') {
            ans[x] = rdc({p1*p3, q1*q3});
            ans[y] = rdc({p1*p2, q1*q2});
        }
        else {
            auto [px, qx] = rdc({p1*q3, q1*p3});
            auto [pt, qt] = rdc({p2*q3, q2*p3});
            auto [py, qy] = rdc({-px*pt, qx*qt});

            ans[x] = {px, qx};
            ans[y] = {py, qy};
        }

        q.emplace(x);
        q.emplace(y);
    }

    for (auto [k, v] : ans) cout << k << ' ' << v.first << '/' << v.second << '\n';

    return 0;
}
