int maxConnect(int n, int c, int** a, int* col)
{
  int* viz = new int[n];
  for (int i = 0; i < n; viz[i++] = 0);
  int* cd = new int[n];
  int inc = 0, sf = -1;
  int** cc = new int*[n];
  for (int i = 0; i < n; i++)
  {
    cc[i] = new int[n+1];
    cc[i][0] = 0;
  }
  int ncc = 0;
  for (int i = 0; i < n; i++)
    if (!viz[i])
    {
      cc[ncc][++cc[ncc][0]] = i;
      viz[i] = 1, cd[++sf] = i;
      while (inc <= sf)
      {
        int vf = cd[inc++];
        for (int j = 0; j < n; j++)
          if (!viz[j] && a[vf][j])
          {
            cc[ncc][++cc[ncc][0]] = j;
            viz[j] = 1, cd[++sf] = j;
          }
      }
      ncc++;
     }
  int nrmax = maxColor(n, c, a, col);
  bool ok = 0;
  for (int i = 0; i < ncc-1; i++)
    for (int j = i+1; j < ncc; j++)
    {
      int x = cc[i][1];
      int y = cc[j][1];
      a[x][y] = a[y][x] = 1;
      int nr = maxColor(n, c, a, col);
      if (nr > nrmax) ok = 1, nrmax = nr;
      a[x][y] = a[y][x] = 0;
    }
  if (!ok) return -1;
  return nrmax;
}
