int sum5(int a, int b, int c, int d, int e){
  int sum1 = a + b;
  int sum2 = c + d;
  int sum3 = sum1 + sum2;
  return sum3 + e;
}

int useFunc(void) { return sum5(1,2,3,4,5); }

int main()
{
  useFunc();
  return 0;
}
