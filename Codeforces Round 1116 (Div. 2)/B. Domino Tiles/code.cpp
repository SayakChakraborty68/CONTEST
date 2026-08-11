#include <bits/stdc++.h>
using namespace std;
 
const long long MOD = 998244353;
 
int main() {
    int t;
    cin >> t;
 
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<long long> dp_0(n,0), dp_1(n,0);
        if(s[0]=='0' || s[0]=='?') dp_0[0] = 1;
        if(s[0]=='1' || s[0]=='?') dp_1[0] = 1;
        if(s[1]=='0' || s[1]=='?') dp_0[1] = 1;
        if(s[1]=='1' || s[1]=='?') dp_1[1] = 1;

        for(int i=2;i<n;i++){
            if(s[i]=='0' || s[i]=='?'){
                dp_0[i] = dp_1[i-2];
            }
            if(s[i]=='1' || s[i]=='?'){
                dp_1[i] = dp_0[i-2];
            }
        }
        long long ans1 = (dp_0[n-1]+dp_1[n-1])%MOD;
        long long ans2 = (dp_0[n-2]+dp_1[n-2])%MOD;
        cout <<(ans1*ans2)%MOD<< endl;
    }
 
    return 0;
}