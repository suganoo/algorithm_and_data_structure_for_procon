#include <bits/stdc++.h>
using namespace std;

int H, W, A, B, ans = 0;

void dfs(int pos, int bit, int A, int B) {
    if ( pos == H * W ) {
        ans++;
        return ;
    }

    if ( bit & (1 << pos) ) dfs(pos + 1, bit, A, B);

    if (B) dfs(pos + 1, bit | (1 << pos ), A, B -1 );

    if (A) {
        if (pos % W != W - 1 && ~bit & 1 << (pos + 1)) {
            dfs(pos+1, bit | (1 << pos) | 1 << (pos + 1), A-1, B);
        }
        if (pos + W <= H*W ) {
            dfs(pos+1, bit | (1<<pos) | 1<<(pos+W),A-1,B );
        }
    }
}

int main() {
    cin >> H >> W >> A >> B;
    dfs(0, 0, A, B);
    cout << ans << endl;
}