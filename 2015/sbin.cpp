#include <iostream>
#define NRBITI 8
#define LGMAX 101
using namespace std;
bool** convert_string(char* s, int& n);
int submatrix_size(bool** bits, int n);
int main()
{
  char s[LGMAX];
  cin >> s;
  int n;
  bool** bits = convert_string(s, n);
  cout << submatrix_size(bits, n);
  return 0;
}
int submatrix_size(bool** bits, int n)
{
  int dmax = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < NRBITI; j++)
    {
      int min = n-i < 8-j ? n-i : 8-j;
      int k;
      for (k = 1; k < min; k++)
      {
        if (bits[i+k][j+k] != bits[i][j])
          break;
        bool ok = 1;
        for (int p = 0; p < k && ok; p++)
          if (bits[i+k][j+p] != bits[i][j]
              || bits[i+p][j+k] != bits[i][j])
          {
            ok = 0;
            break;
          }
        if (!ok)
          break;
      }
      if (k > dmax)
        dmax = k;
    }
  return dmax;
}
bool* convert_char(char c)
{
  bool* bits = new bool[NRBITI];
  int i, x;
  for (i = 7, x = (int)c; x; i--)
  {
    bits[i] = x%2;
    x = x/2;
  }
  while (i >= 0)
  {
    bits[i] = 0;
    i--;
  }
  return bits;
}
bool** convert_string(char* s, int& n)
{
  for (n = 0; s[n]; n++);
  bool** bits = new bool*[n];
  for (int i = 0; i < n; i++)
    bits[i] = convert_char(s[i]);
  return bits;
}

