void secvmax(int n, int** a)
{
  int* col = new int[n];
  for (int i = 0; i < n; i++) col[i] = -1;
  int lgmax = 1, imax = 1;
  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < i; j++)
      if (a[i][j])
      {
        col[i] = j;
        break;
      }
    int lg = 0;
    for (int k = i; col[k] >= 0; lg++, k = col[k]);
    if (lg > lgmax) lgmax = lg, imax = i;
  }
  for (int i = imax; i >= 0; i = col[i])
    g << i+1 << ' ';
}
