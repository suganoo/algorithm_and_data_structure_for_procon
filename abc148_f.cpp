#include<bits/stdc++.h>
using namespace std;

vector<int> paths[10500];
int dist[2][10500];

int ans;

// 0 u takahashi
// 1 v aoki

void dfs(int index, int now, int from){
  for (int to : paths[now]){
    if (to == from) continue;
    cout << "index: " << index << " now: " << now << " to: " << to << endl;
    dist[index][to] = dist[index][now] + 1;
    cout << "now: " << dist[index][now] << endl;
    cout << "to:  " << dist[index][to] << endl;

    dfs(index, to, now);
  }
}

void search(int now) {
  if (dist[0][now] >= dist[1][now]){
    ans = max(ans, dist[1][now]);
    return;
  }
  if (paths[now].size() == 1){
    ans = max(ans, dist[1][now] - 1);
  }
  for (int to : paths[now]){
    if (dist[0][to] < dist[0][now]) continue;
    search(to);
  }
}

int main(){
  int N, u, v;
  cin >> N >> u >> v;

  for (int i = 0; i < (N - 1); i++) {
    int x, y;
    cin >> x >> y;
    paths[x].push_back(y);
    paths[y].push_back(x);
  }
  dfs(0, u, -1);
  dfs(1, v, -1);
  search(u);
  for (int i = 0; i <= N; i++){
    cout << dist[0][i] << " ";
  }
  cout << endl;
  for (int i = 0; i <= N; i++){
    cout << dist[1][i] << " ";
  }
  cout << endl;
  cout << ans << endl;
  return 0;
}
