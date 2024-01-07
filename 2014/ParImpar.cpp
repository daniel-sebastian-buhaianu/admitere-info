#include <iostream>
using namespace std;
int main()
{
  // citeste n
  int n;
  cin >> n;
  // valideaza pe n
  if (n < 2)
  {
    cout << "n trebuie sa fie >= 2";
    return 1;
  }
  // citeste matricea A
  int a[n][n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];
  // calculeaza matricea B = A x A
  int b[n][n];
  bool parimpar = 1;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      b[i][j] = 0;
      for (int k = 0; k < n; k++)
        b[i][j] += a[i][k]*a[k][j];
      cout << b[i][j] << ' ';
      if (j > 0
          && b[i][j]%2 != b[i][0]%2)
        parimpar = 0;
    }
    cout << '\n';
  }
  if (parimpar)
    cout << "B are proprietatea ParImpar";
  else
    cout << "B nu are proprietatea ParImpar";
  return 0;
}

