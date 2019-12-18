#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> as(n,0);
  for (int i = 0; i < n; i++) {cin >> as[i];as[i]--;}

  map<int, int> cnt;
  cnt[0] = 1;
  int ans = 0;

  vector<int> sm(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cout << "i: " << i << endl;
    if (k < i + 1) cnt[sm[ i + 1 - k ]]--;
    cout << "sm[" << i << "]: " << sm[i] << endl;
    cout << "as[" << i << "]: " << as[i] << endl;
    sm[ i + 1 ] = (sm[i] + as[i]) % k;
    cout << "sm[" << i + 1 << "]: " << sm[i+1] << endl;
    cout << "cnt[sm[" << i + 1 << "]]: " << cnt[sm[i+1]] << endl;
    ans += cnt[sm[i + 1]];
    cout << "ans: " << ans << endl;
    cnt[sm[i + 1]]++;
    cout << "cnt[sm[" << i + 1 << "]]: " << cnt[sm[i+1]] << endl;
  }
  cout << ans << endl;
  return 0;
}
