bool propt(int n, int** a)
{
  // verific conditia i)
  int nr = a[0][0] ? 1 : 0;
  for (int p = 2; p <= n; p++)
  {
    for (int i = 0; i < p-1; i++)
    {
      if (a[p-1][i]) nr++;
      if (a[i][p-1]) nr++;
    }
    if (a[p-1][p-1]) nr++;
    if (nr != 2*p-2) return 0;
  }
  // verific conditia ii)
  for (int j = 0; j < n; j++)
    for (int i = j; i < n; i++)
      if (!((a[i][j] == 0 && a[i][j] == a[j][i])
             || a[i][j] == a[j][i]+1)) return 0;
  // verific conditia iii)
  for (int i = 0; i < n; i++)
  {
    int j;
    for (j = 0; j < n && !a[i][j]; j++);
    int x = a[i][j];
    for (j++; j < n; j++)
      if (a[i][j] && a[i][j] != x) return 0;
  }
  return 1;
}

