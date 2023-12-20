int maxColor(int n, int c, int** a, int* col)
{
  int* viz = new int[n];
  for (int i = 0; i < n; viz[i++] = 0);
  int* cd = new int[n];
  int inc = 0, sf = -1, nrmax = 0;
  for (int i = 0; i < n; i++)
    if (!viz[i])
    {
      int* uz = new int[c];
      for (int j = 0; j < c; uz[j++] = 0);
      int nr = 0;
      if (!uz[col[i]]) uz[col[i]] = 1, nr++;
      viz[i] = 1, cd[++sf] = i;
      while (inc <= sf)
      {
        int vf = cd[inc++];
        for (int j = 0; j < n; j++)
          if (!viz[j] && a[vf][j])
          {
            if (!uz[col[j]]) uz[col[j]] = 1, nr++;
            viz[j] = 1, cd[++sf] = j;
          }
      }
      if (nr > nrmax) nrmax = nr;
    }
    return nrmax;
}
