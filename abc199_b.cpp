#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(1100,0);
    vector<int> B(1100,1<<21);
    for (int i = 0; i < N; i++){
        int x;
        cin >> x;
        A.push_back(x);
    }
    for (int i = 0; i < N; i++){
        int x;
        cin >> x;
        B.push_back(x);
    }

    int max_a = *max_element(A.begin(), A.end());
    int min_b = *min_element(B.begin(), B.end());

    int ans = (min_b - max_a) < 0 ? 0 : (min_b - max_a + 1);
    cout << ans << endl;

    return 0;
}