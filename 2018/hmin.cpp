int hmin(int** a, int n, int m, int L, int C)
{
  int** b = new int*[n+2];
  int** viz = new int*[n+2];
  for (int i = 0; i < n+2; i++)
  {
    b[i] = new int[m+2];
    viz[i] = new int[m+2];
    b[i][0] = b[i][m+1] = -1;
    for (int j = 0; j < m+2; j++)
      viz[i][j] = 0;
  }
  for (int j = 0; j < m+2; j++)
    b[0][j] = b[n+1][j] = -1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      b[i][j] = a[i-1][j-1];
  int dx[] = {-1, 0, 1, 0};
  int dy[] = {0, 1, 0, -1};
  int h = 2000000000;
  while (viz[L][C] < 3)
  {
    viz[L][C]++;
    if (viz[L][C] > 1 && b[L][C] < h) h = b[L][C];
    int dmin = 2000000000, xmin, ymin;
    for (int i = 0; i < 4; i++)
    {
      int x = L + dx[i];
      int y = C + dy[i];
      if (b[x][y] != -1)
      {
        int d = b[L][C] - b[x][y];
        if (d < 0) d *= -1;
        if (d < dmin
            || (d == dmin && b[x][y] < b[xmin][ymin]))
              dmin = d, xmin = x, ymin = y;
      }
    }
    L = xmin, C = ymin;
  }
  return h;
}
