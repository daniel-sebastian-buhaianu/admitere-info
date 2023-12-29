#include <iostream>
using namespace std;
int max(int u, int v)
{
  return u > v ? u : v;
}
int F(int u, int v)
{
  if (u == v || !u || !v) return max(u, v);
  if (u%2 == 0)
  {
    if (v%2 == 0) return 2*F(u/2, v/2);
    return F(u/2, v);
  }
  if (v%2 == 0) return F(u, v/2);
  if (u < v) return F(u, (v-u)/2);
  return F((u-v)/2, v);
}
int main()
{
  cout << "u = "; int u; cin >> u;
  cout << "v = "; int v; cin >> v;
  cout << "F(" << u << "," << v << ") = " << F(u, v);
  return 0;
}

