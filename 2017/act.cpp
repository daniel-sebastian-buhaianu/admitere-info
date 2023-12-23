void actioneazaComutator(bool** a, int n, int m, int i, int j)
{
  a[i][j] = !a[i][j];
  a[i][j-1] = !a[i][j-1];
  a[i-1][j-1] = !a[i-1][j-1];
  a[i-1][j] = !a[i-1][j];
}
