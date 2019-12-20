#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ullong;

ullong power(ullong x, ullong n, ullong M){
  cout << "n: " << n << endl;
  ullong res = 1;
  if (n > 0) {
    res = power(x, n / 2, M);
    if ( n % 2 == 0 ) {
      cout << "n%2==0" << endl;
      res = (res * res) % M;
    } else {
      cout << "n%2==1" << endl;
      res = ((((res * res)) % M ) * x ) % M;
    }
    cout << "res: " << res << endl;
  }
  return res;
}
ullong power2(ullong x, ullong n, ullong M){
  ullong res = 1;
  while ( n > 0 ) {
    if ( n & 1 ) res = res * x %M;
    x = x * x % M;
    n >>= 1;
  }
  return res;
}

int main() {
  int m,n;
  cin >> m >> n;

  cout << power(m, n, 1000000007) << endl;
  return 0;
}
