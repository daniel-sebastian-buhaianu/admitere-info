#include <fstream>
using namespace std;
bool verifica(int**, int, int);
int complet(int**, int, int);
int optim(int**, int, int, int);
int main()
{
  ifstream f("piscina.in");
  int n, m;
  f >> n >> m;
  int** a = new int*[n];
  for (int i = 0; i < n; i++)
  {
    a[i] = new int[m];
    for (int j = 0; j < m; j++)
      f >> a[i][j];
  }
  int k;
  f >> k;
  f.close();
  ofstream g("piscina.out");
  g << verifica(a, n, m) << '\n';
  g << complet(a, n, m) << '\n';
  g << optim(a, n, m, k);
  g.close();
  return 0;
}
int optim(int** a, int n, int m, int k)
{
  // TODO
  return 0;
}
int complet(int** a, int n, int m)
{
    return n*m; 
}
bool verifica(int** a, int n, int m)
{
  for (int i = 0; i < n-1; i++)
    for (int j = 0; j < m-1; j++)
    {
      if (a[i][j] < a[i][j+1] && a[i+1][j+1] < a[i][j+1]
          && a[i][j] < a[i+1][j] && a[i+1][j+1] < a[i+1][j])
            return 0; 
      if (a[i+1][j] < a[i][j] && a[i][j+1] < a[i][j]
          && a[i+1][j] < a[i+1][j+1] && a[i][j+1] < a[i+1][j+1])
            return 0; 
    }
  return 1;
}
