#include <iostream>
using namespace std;
int main()
{
  int m; cin >> m;
  char A[m];
  for (int i = 0; i < m; i++) A[i] = 'a' + i;
  int n; cin >> n;
  char S[n][m+1];
  int** ap = new int*[n+1];
  for (int i = 0; i <= n; i++)
  {
    ap[i] = new int[m];
    for (int j = 0; j < m; j++)
      ap[i][j] = 0;
  }
  int p = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> S[i];
    int lg;
    for (lg = 0; S[i][lg]; lg++)
    {
      ap[i][S[i][lg]-'a']++;
      ap[n][S[i][lg]-'a']++;
    }
    if (!i) p = lg;
    else if (lg != p) p = 0;
  }
  if (!p) cout << "NU";
  else
  { 
    bool ok = 1;
    for (int i = 0; i < m && ok; i++)
      if (!ap[n][i]) ok = 0;
    for (int i = 0; i < n-1 && ok; i++)
      for (int j = i+1; j < n && ok; j++)
      {
        int nr = 0;
        for (int k = 0; k < m; k++)
          if (ap[i][k] && ap[j][k]) nr++;
        if (nr != 1) ok = 0;
      }
    if (!ok) cout << "NU";
    else cout << "DA";
  }
  return 0;
}

