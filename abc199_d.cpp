#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

int N,M;
vector<int> G[30];
vector<bool> used(30, false);
vector<int> SG;
vector<int> color(30, -1);
ll tmp;

void dfs(int n) {
    used[n] = true;
    SG.push_back(n);
    for (auto x: G[n]) {
        if (!used[x])dfs(x);
    }
}

void dfs2(int n){
    if (n == SG.size()){
        tmp++;
        return;
    }
    int v = SG[n];
    for (int i = 0; i < 3; i++) {
        color[v] = i;
        bool ok = true;
        for (auto x: G[n]){
            if (color[x]==i)ok=false;
        }
        if (!ok)continue;
        dfs2(n+1);
    }
    color[v] = -1;
}

int main() {
    cin >> N >> M;
    ll res = 1;
    for (int i = 0; i < M; i++) {
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 1; i <= N; i++) {
        if (used[i])continue;
        res *= 3;
        SG = vector<int>();
        dfs(i);
        cout << "--- SG ---" << endl;
        for (auto x: SG) {
            cout << x << endl;
        }
        cout << "--- SG end---" << endl;
        color[SG[0]] = 0;
        tmp = 0;
        dfs2(1);
        res *= tmp;
    }
    cout << res << endl;
    return 0;
}