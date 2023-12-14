int compute(int a)
{
  // rezolv cerinta a)
  int na=0;
  for (int ca=a; ca; na++, ca/=10)
    if (ca%10 == 0) return -1;
  if (na < 4) return -1;
  // rezolv cerinta b)
  int n=0, m=0;
  for (int pn=1, pm=1, ca=a, i=na; i >= 1; i--)
  {
    if (i%2)
    {
      n += ca%10 * pn;
      pn *= 10;
    }
    else
    {
      m += ca%10 * pm;
      pm *= 10;
    }
    ca /= 10;
  }
  // rezolv cerinta c)
  // calculez ultima cifra a lui n^m
  // si o retin in variabila uc1
  int b = n%10;
  int r = m%4 ? m%4 : 4;
  int p = b;
  while (r > 1)
  {
    p *= b;
    r--;
  }
  int uc1 = p%10; 
  // calculez ultima cifra a lui n!
  // si o retin variabila uc2
  int uc2;
  if (n >= 5) uc2 = 0;
  else
  {
    p = 1;
    for (int i = 2; i <= n; i++) p *= i;
    uc2 = p%10;
  }
  return uc1-uc2-1 == 0;
}
