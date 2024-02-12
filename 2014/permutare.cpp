#include <iostream>
using namespace std;
int pozitie(int x, int v[], int n);
void insereaza(int x, int v[], int n, int poz);
int main()
{
    int n; cout << "n = "; cin >> n;
    if (n < 2) {
        cout << "n >= 2";
        return 1;
    }
    int v[n], ap[n];
    int nv = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        int poz = pozitie(x, v, nv);
        if (poz >= 0 && poz < nv && v[poz] == x) {
            ap[poz]++;
        } else {
            insereaza(x, v, nv, poz);
            insereaza(1, ap, nv, poz);
            nv++;
        }
    }
    for (int i = 0; i < nv-1; i++) {
        for (int j = i+1; j < nv; j++) {
            if (ap[i] > ap[j]) {
                swap(ap[i], ap[j]);
                swap(v[i], v[j]);
            }
        }
    }
    int p[n];
    p[0] = v[0];
    ap[0]--;
    for (int i = 1, j = 1; i < n; i++, j++) {
        if (j >= nv) {
            j = 0;
        }
        if (ap[j] > 0) {
            p[i] = v[j];
            if (p[i] == p[i-1]) {
                cout << "nu exista";
                return 1;
            }
            ap[j]--;
        }
        else {
            i--;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << p[i] << ' ';
    }
    return 0;
}
void insereaza(int x, int v[], int n, int poz)
{
    for (int i = n; i > poz; i--) {
        v[i] = v[i-1];
    }
    v[poz] = x;
}
int pozitie(int x, int v[], int n)
{
    int st = -1;
    int dr = n;
    while (dr-st > 1) {
        int mij = st + (dr-st)/2;
        if (v[mij] < x) {
            st = mij;
        } else {
            dr = mij;
        }
    }
    return dr;
}
