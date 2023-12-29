char*** stpatrat(int n, char S[], char T[])
{
  char*** stp = new char**[n];
  for (int i = 0; i < n; i++)
  {
    stp[i] = new char*[n];
    for (int j = 0; j < n; j++)
    {
      stp[i][j] = new char[6];
      char str[6];
      str[0] = '(';
      str[1] = S[j];
      str[2] = ',';
      str[3] = T[j];
      str[4] = ')';
      str[5] = 0;
      strcpy(stp[i][j], str);
    }
    // permutare la dreapta cu o pozitie
    char tmp = S[n-1];
    for (int j = n-1; j > 0; j--) S[j] = S[j-1];
    S[0] = tmp;
    // permutare la stanga cu o pozitie
    tmp = T[0];
    for (int j = 0; j < n-1; j++) T[j] = T[j+1];
    T[n-1] = tmp;
  }
  return stp;
}
