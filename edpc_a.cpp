#include <bits/stdc++.h>
using namespace std;

int NMAX = 100000;
int MAX  =  10000;

int main(){
  int N;
  cin >> N;

  int h[NMAX + 1];
  for (int i = 0; i <= NMAX; i++ ) h[i] = 0;

  for (int i = 1; i <= N; i++ ) cin >> h[i];

  int dp[NMAX + 1];
  for (int i = 0; i <= NMAX; i++ ) dp[i] = MAX;

  dp[1] = 0;
  dp[2] = abs(h[2] - h[1]);
  for (int i = 3; i <= N; i++ ) {
    dp[i] = min( abs(h[i] - h[i - 1]) + dp[i - 1], abs(h[i] - h[i - 2]) + dp[i - 2]);
  }
  cout << dp[N] << endl;
}
