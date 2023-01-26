#include <iostream>

using namespace std;

int main()
{
  int n;
  cout << "n= ";
  cin >> n;
  n++;
  int a[n];

  for (int i = 0; i < n ; i++)
    a[i] = i;

  for (int p = 2; p < n ; p++)
  {
    if (a[p]!=0)
    {
      cout << a[p] << endl;
      for (int j = p*p; j < n ; j += p)
        a[j] = 0;
    }
  }

  //cin.get();
  return 0;

}
