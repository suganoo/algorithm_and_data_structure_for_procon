#include <bits/stdc++.h>
using namespace std;

int NMAX = 100000;
int MAX  = 1000000000;

int main(){
  int N;
  cin >> N;

  int a[NMAX+1],b[NMAX+1],c[NMAX+1], dp[NMAX+1];
  for (int i = 0; i < NMAX; i++) a[i] = 0;b[i] = 0;c[i] = 0;dp[i] = 0;

  for (int i = 1; i <= N; i++) {
    cin >> a[i];
    cin >> b[i];
    cin >> c[i];
  }

}
