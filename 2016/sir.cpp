#include <iostream>
#include <cstring>
using namespace std;
int main()
{
  cout << "s: "; char s[100]; cin >> s;
  int lg;
  for (lg = 0; s[lg]; lg++)
    if (s[lg] < 'a' || s[lg] > 'b')
    {
      cout << "Date invalide";
      return 1;
    }
  if (lg < 3)
  {
    cout << "Date invalide";
    return 1;
  }
  char S[7][4] = {"aab","aba","abb","baa","bab","bba","bbb"};
  char R[7][4] = {"aaa","aab","aba","abb","aba","baa","bab"};
  int nr = 0;
  for (int i = 0; i+2 < lg; i++)
  {
    char str[4]; strncpy(str, s+i, 3);
    while (strcmp(str, "aaa"))
    {
      nr++;
      for (int j = 0; j < 7; j++)
        if (!strcmp(S[j], str))
        {
          strcpy(str, R[j]);
          break;
        }
    }
    s[i] = s[i+1] = s[i+2] = 'a'; 
  }
  cout << nr << '\n';
  int i;
  for (i = 0; s[i] == 'a'; i++);
  if (i == lg)
    cout << "Sirul final este format doar din caractere egale cu a.";
  else
    cout << "Sirul final nu este corect.";
  return 0;
}

