#include <fstream>
#include <iostream>
using namespace std;
bool** retea(int);
int main()
{
  int n;
  cout << "n = "; cin >> n;
  bool** a = retea(n);
  ofstream g("retea.out");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      g << a[i][j] << ' ';
    g << '\n';
  }
  g.close();
  return 0;
}
bool** retea(int n)
{
  bool** a = new bool*[n];
  for (int i = 0; i < n; i++)
  {
    a[i] = new bool[n];
    if (i > 0) a[0][i] = a[i][0] = 1;
  }
  int* nr = new int[n];
  for (int i = 0; i < n; i++)
    nr[i] = i ? 2 : 0;
  for (int i = 1; i < n-1; i++)
      for (int j = i+1; j < n && nr[i] > 0; j++)
      {
        a[i][j] = a[j][i] = 1;
        nr[i]--, nr[j]--;
      }
  return a;
}
