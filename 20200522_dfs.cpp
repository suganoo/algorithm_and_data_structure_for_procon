#include <bits/stdc++.h>
using namespace std;

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

  vector<bool> seen(V, false);

  stack<int> st;
  st.push(s);
  seen[s] = true;
  while (st.size() != 0) {
    int state = st.top();
    st.pop();
    for (auto next: G[state]) {
      if (!seen[next]) {
        seen[next] = true;
        st.push(next);
	break;
      }
    }
  }
  if (seen[t]) {
    cout << "yes" << endl;
  } else {
    cout << "no"  << endl;
  }
}
