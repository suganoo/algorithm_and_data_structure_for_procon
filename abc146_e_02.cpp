#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, K, ans=0;
  cin >> N >> K;
  vector<int> A(N+1, 0);
  vector<int> sum(N+1, 0);
  map<int,int> mp;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
    A[i]--;
    A[i] %= K;
    sum[i] = (sum[i-1] + A[i]) % K;
  }

  for (int i = 1; i <= N; i++) {
    cout << "sum[" << i << "]: " << sum[i] << endl;
  }

  for (int i = 0; i <=N; i++){
    ans += mp[sum[i]];
    mp[sum[i]]++;
    if (i >= K - 1) {
      mp[sum[i - K + 1]]--;
    }
  }
  cout << ans << endl;
}
