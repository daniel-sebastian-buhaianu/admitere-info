int value(const char* s)
{
  int lg;
  for (lg = 0; s[lg]; lg++)
    if (!(s[lg] >= 'a' && s[lg] <= 'z'))
      return 0;
  if (lg < 1 || lg > 5) return 0;
  int cod = 0;
  for (int p = 1, i = 0; i < lg; i++, p *= 2)
    cod += (int)s[i] * p;
  return cod;
}
