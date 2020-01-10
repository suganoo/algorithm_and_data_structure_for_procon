#include<bits/stdc++.h>
using namespace std;

bool is_prime(int n){
  if (n == 1) return true; 
  for (int i = 2; i * i <= n; i++) {
    if ((n % i) == 0) return false;
  }
  return true;
}

int main(){
  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    if (is_prime(i)) cout << i << " " ;
  }
  cout << endl;
}
