void actioneazaComutator(bool** a, int n, int m, int i, int j)
{
  a[i][j] = !a[i][j];
  a[i][j-1] = !a[i][j-1];
  a[i-1][j-1] = !a[i-1][j-1];
  a[i-1][j] = !a[i-1][j];
}
bool sePotStingeToateLuminile(bool** a, int n, int m)
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (a[i][j])
      {
        if (i == n-1) return 0;
        if (j == m-1) return 0;
        if (a[i][j+1])
          actioneazaComutator(a, n, m, i+1, j+1);
        else
        {
          if (j+2 >= m) return 0;
          actioneazaComutator(a, n, m, i+1, j+2);
          actioneazaComutator(a, n, m, i+1, j+1);
        }
      }
      return 1;
}
