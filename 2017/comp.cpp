bool comp(int n, int m, int** R, int* a)
{
  for (int i = 0; i < m; i++)
    if (a[R[i][0]] > a[R[i][1]])
      swap(a[R[i][0]], a[R[i][1]]);
  for (int i = 1; i < n; i++)
    if (a[i-1] > a[i]) return 0;
  return 1;
}
