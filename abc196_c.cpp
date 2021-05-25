#include <bits/stdc++.h>
using namespace std;

int main () {
    long long N;
    cin >> N;
    int cnt = 0;
    //int power_num = to_string(N).size();
    //int MAX = N * pow(10, -1 * power_num / 2);
    for (int i = 1; i <= N; i++) {
        string ans = to_string(i) + to_string(i);
        if (stoll(ans) <= N) cnt++;
        if (stoll(ans) > N) break;
    }
    cout << cnt << endl;
}