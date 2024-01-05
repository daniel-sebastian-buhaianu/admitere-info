#include <fstream>
using namespace std;
bool** cerintaB(int** a, int n, int m);
int main()
{
  ifstream f("minesweeper.in");
  int n, m;
  f >> n >> m;
  int** a = new int*[n];
  for (int i = 0; i < n; i++)
  {
    a[i] = new int[m];
    for (int j = 0; j < m; j++)
      f >> a[i][j];
  }
  f.close();
  bool** b = cerintaB(a, n, m);
  ofstream g("minesweeper.out");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      g << b[i][j] << ' ';
    g << '\n';
  }
  g.close();
  return 0;
}
bool** cerintaB(int** a, int n, int m)
{
  int** tmp = new int*[n+2];
  for (int i = 0; i < n+2; i++)
  {
    tmp[i] = new int[m+2];
    for (int j = 0; j < m+2; j++)
      if (i >= 1 && i <= n && j >= 1 && j <= m)
        tmp[i][j] = a[i-1][j-1];
      else
        tmp[i][j] = 0;
  }
  bool** b = new bool*[n];
  int dx[] = {-1,-1,-1,1,1,1,0,0};
  int dy[] = {-1,0,1,-1,0,1,-1,1};
  for (int i = 1; i <= n; i++)
  {
    b[i-1] = new bool[m];
    for (int j = 1; j <= m; j++)
    {
      bool ok = 0;
      for (int d = 0; d < 8; d++)
      {
        int lin = dx[d] + i;
        int col = dy[d] + j;
        if (tmp[lin][col] == -1)
        {
          ok = 1;
          break;
        }
      }
      b[i-1][j-1] = ok;
    }
  }
  return b;
}
