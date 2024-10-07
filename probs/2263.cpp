#include <bits/stdc++.h>

using namespace std;

vector<int> IO, PO, IO_index;

/*
** Inorder:   (left)  root   (right)
** Postorder: (left) (right) root
*/

void preord(int is, int ie, int ps, int pe)
{
    if (is > ie) return;

    cout << PO[pe] << ' ';

    int io_root = IO_index[PO[pe]];
    preord(is, io_root-1, ps, ps+io_root-1-is);
    preord(io_root+1, ie, ps+io_root-is, pe-1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    IO.resize(N); PO.resize(N); IO_index.resize(N+1);
    for (int i = 0; i < N; i++) {
        cin >> IO[i];
        IO_index[IO[i]] = i;
    }
    for (int i = 0; i < N; i++)
        cin >> PO[i];

    preord(0, N-1, 0, N-1);

    return 0;
}
