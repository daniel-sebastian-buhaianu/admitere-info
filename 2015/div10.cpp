#include <iostream>
using namespace std;
int div10(int n)
{
  int m;
  for (m = 0; m+10 <= n; m += 10);
  int s, i;
  for (s = i = 0; s < m; s += 10, i++);
  return i;
}
int main()
{
  cout << "n = "; int n; cin >> n;
  cout << "n/10 = " << div10(n);
  return 0;
}

