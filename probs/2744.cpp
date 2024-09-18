#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    string S; cin >> S;
    for (int i = 0; i < S.length(); i++) cout << (char)(32^S[i]); cout << '\n';

    return 0;
}
