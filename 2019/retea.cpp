void garages(int** D, int m, int n)
{
  for (int i=m; i < m+n; i++)
  {
    int k = i;
    while (k >= m)
      for (int j=0; j < m+n; j++)
        if (D[j][k])
        {
          k = j;
          break;
        }
    cout << "locatie: " << i << ", garaj: " << k << '\n';
  }
}
int prev(int** D, int m, int n, int i)
{
  for (int j=0; j < m+n; j++)
    if (D[j][i]) return j;
  return -1;
}
