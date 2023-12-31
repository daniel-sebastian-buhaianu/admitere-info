int lgsp(int N, int M, int** A, int i1, int j1, int i2, int j2)
{
  int ri = i2 - i1;
  int rj = j2 - j1;
  int ra = A[i2][j2] - A[i1][j1];
  int lg = 2;
  i1 = i2, i2 = i1 + ri;
  j1 = j2, j2 = j1 + rj;
  while (i2 >= 1 && i2 <= N
        && j2 >= 1 && j2 <= M
        && A[i2][j2] - A[i1][j1] == ra)
  {
    lg++;
    i1 = i2, i2 = i1 + ri;
    j1 = j2, j2 = j1 + rj;
  }
  return lg;
}
