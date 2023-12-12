#include <fstream>
using namespace std;
void ordonare(int n, int a[][100]);
int main()
{
  ifstream f("ordonare.in");
  int n;
  f >> n;
  int a[n][100];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      a[i][j] = 0;
  for (int i = 0; i < n*(n-1)/2; i++)
  {
    int x, y;
    f >> x >> y;
    a[x][y] = 1;
  }
  f.close();
  ordonare(n, a);
  return 0;
}
void ordonare(int n, int a[][100])
{
  int v[n];
  if (a[0][1]) v[0]=0, v[1]=1;
  else v[0]=1, v[1]=0;
  int dr=1;
  for (int i=2; i < n; i++)
  {
    int poz;
    if (a[i][v[0]]) poz=0;
    else if (a[v[dr]][i]) poz=dr+1;
    else for (poz=1; poz < dr && !a[i][v[poz]]; poz++);
    for (int j=dr+1; j > poz; j--) v[j]=v[j-1];
    v[poz]=i;
    dr++;
  }
  ofstream g("ordonare.out");
  for (int i=0; i < n; i++)
    g << v[i] << ' ';
  g.close();
}
