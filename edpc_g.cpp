#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

int N, M;
vector<int> G[MAX + 1];
int dp[MAX + 1] = {0};
int seen[MAX + 1] = {false};

int rec(int now_pos) {
  if (seen[now_pos]) return dp[now_pos];

  seen[now_pos] = true;

  int distance = 0;
  for (int next: G[now_pos]) {
    distance = max(distance, rec(next) + 1 );
  }
  return dp[now_pos] = distance;
}

int main(){
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
  }

  int ans = 0;
  for (int i = 1; i <= N; i++) {
    ans = max(ans, rec(i));
  }
  cout << ans << endl;
}
