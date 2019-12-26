#include<bits/stdc++.h>
using namespace std;

int gcd(int m, int n){
  if (m == 0) return n;
  return gcd(n % m, m);
}

int main(){
  int M, N;
  cin >> M >> N;
  cout << gcd(M, N) << endl;
  cout << M * N / gcd(M, N) << endl;
  return 0;
}
