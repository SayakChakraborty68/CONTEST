#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        long long MOD = 998244353;
        for(int i=0;i<n;i++) cin >> a[i];
        if(n==1){
            cout << 1 << endl;
            continue;
        }
        vector<long long> dp_o(n,0),dp_e(n,0);
        if(a[0]&1){
            dp_o[0] = 1;
            dp_e[0] = 0;
        }
        else{
            dp_o[0] = 0;
            dp_e[0] = 1;
        }
        for(int i=1;i<n;i++){
            if(a[i] & 1){
                dp_o[i] = (dp_o[i-1]+dp_e[i-1])%MOD;
                dp_e[i] = dp_o[i-1];
                if(i > 1 && a[i-1]&1) dp_e[i] =  (dp_e[i]+dp_e[i-2])%MOD;
            }
            else {
                dp_o[i] = 0;
                dp_e[i] = (dp_o[i-1]+(dp_e[i-1]*2)%MOD)%MOD;
            }
        }
        cout << (dp_o[n-1]+dp_e[n-1])%MOD << endl;
    }

}
