#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

int main(){
  int N, M;
  cin >> N >> M;

  int G[MAX + 1][MAX + 1] = {0};
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    G[a][b] = 1;
  }

  int dp[MAX + 1] = {0};

  bool seen[MAX + 1] = {false};

  queue<int> q;
  q.push(1);
  while (q.size()) {
    
  }
}
