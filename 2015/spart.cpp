#include <iostream>
using namespace std;
void afiseazaMultime(const char* prefix, int* m, int n);
void eliminaDinMultime(int x, int*& v, int& n);
void adaugaInMultime(int x, int*& v, int& n);
int main()
{
  // cerinta a)
  int n;
  cin >> n;
  if (n < 4 || n%4)
  {
    cout << "date invalide";
    return 1;
  }
  int p;
  cin >> p;
  if (p < 1 || p > n/2)
  {
    cout << "date invalide";
    return 1;
  }
  // cerinta b)
  int lgA = n/2;
  int lgB = n/2;
  int* A = new int[lgA];
  int* B = new int[lgB];
  for (int i = 0; i < n/2; i++)
  {
    A[i] = i < n/4 ? 2*i+1 : 2*i+2;
    B[i] = i < n/4 ? 2*i+2 : 2*i+1;
  }
  afiseazaMultime("A: ", A, lgA);
  afiseazaMultime("B: ", B, lgB);
  // cerinta c)
  if (p%2)
    cout << "partitie inexistenta";
  else
  {
    // p este par si p <= n/2, deci p se afla in B
    eliminaDinMultime(p, B, lgB);
    // Fie d un numar natural astfel incat:
    // sumaElemente(A) - d = sumaElemente(A') = sumaElemente(B')
    int d = p/2;
    if (d%2)
    {
      eliminaDinMultime(d, A, lgA);
      adaugaInMultime(d, B, lgB);
    }
    else
    {
      eliminaDinMultime(d+1, A, lgA);
      // elimin pe 1 din A si il adaug pe 2 in locul sau
      A[0] = 2;
      // elimin pe 2 din B si il adaug pe 1 in locul sau
      B[0] = 1;
      adaugaInMultime(d+1, B, lgB);
    }
    afiseazaMultime("A': ", A, lgA);
    afiseazaMultime("B': ", B, lgB);
  }
  return 0;
}
void afiseazaMultime(const char* prefix, int* m, int n)
{
  cout << prefix;
  for (int i = 0; i < n; i++)
    cout << m[i] << ' ';
  cout << '\n';
}
void eliminaDinMultime(int x, int*& v, int& n)
{
  int poz = 0;
  while (poz < n && v[poz] != x)
    poz++;
  n--;
  for (int i = poz; i < n; i++)
    v[i] = v[i+1];
}
void adaugaInMultime(int x, int*& v, int& n)
{
  int poz = 0;
  while (poz < n && v[poz] < x)
    poz++;
  n++;
  for (int i = n-1; i > poz; i--)
    v[i] = v[i-1];
  v[poz] = x;
}
