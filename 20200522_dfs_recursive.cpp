#include <bits/stdc++.h>
using namespace std;

vector<bool> seen;

void dfs(const vector<vector<int>> &G, int v){
  seen[v] = true;
  for (auto next: G[v]){
    if (!seen[next]) dfs(G, next);
  }
}

int main() {
  int V, E;
  cin >> V >> E;
  int s, t;
  cin >> s >> t;

  vector<vector<int>> G(V);
  for (int i = 0; i < E; i++) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
  }

  seen.assign(V, false);
  dfs(G, s);

  if (seen[t]) {
    cout << "yes" << endl;
  } else {
    cout << "no"  << endl;
  }
}
