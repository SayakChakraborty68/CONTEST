#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int l,r;
        cin >> l >> r;
        int ans;
        if(l>0 || r<0) ans = r-l;
        else if(l+r == 0) ans = 0;
        else ans = abs(l+r)-1;
        cout << ans << endl;
    }
    return 0;
}