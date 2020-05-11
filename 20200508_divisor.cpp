#include <bits/stdc++.h>
using namespace std;

vector<long long> divisor(long long n){
  vector<long long> ret;
  for (long long i = 1; i <= n; i++){
    if ( n % i == 0) {
      ret.push_back(n / i);
    }
  }
  return ret;
}

vector<long long> divisor2(long long n){
  vector<long long> ret;
  for (long long i = 1; i * i <= n; i++){
    if ( n % i == 0) {
      ret.push_back(i);
      if (i * i != n) ret.push_back(n / i);
    }
  }
  sort(ret.begin(), ret.end());
  return ret;
}

int main(){
  int N = 0;
  vector<long long> divisors;

  cin >> N;
  divisors = divisor2(N);

  for (long long n : divisors){
    cout << n << endl;
  }
}
