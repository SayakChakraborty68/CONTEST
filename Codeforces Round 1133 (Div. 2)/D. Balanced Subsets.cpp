#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod=998244353;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> pos(3*n+69,-1);
        for(int i=0;i<n;i++){
            cin >>a[i];
            pos[a[i]]=i;
        }
        vector<vector<int>> dp(n,vector<int>(4,0));
        int ans = ((n*(n-1))/2+n)%mod;
        for(int i=0;i<n;i++){
            dp[i][0]=1;
            // for the diff 1 
            if(a[i]-1>=1 && pos[a[i]-1]!=-1){
                int j=pos[a[i]-1];
                dp[i][1] = (dp[i][1]+dp[j][0]+dp[j][3])%mod;
                dp[i][2] = (dp[i][2]+dp[j][1])%mod;
                ans = (ans+dp[j][1]+dp[j][3])%mod;
            }
            // diff 2
            if(a[i]-2>=1 && pos[a[i]-2]!=-1){
                int j=pos[a[i]-2];
                dp[i][3] = (dp[i][3]+dp[j][0]+dp[j][1]+dp[j][2])%mod;
                ans = (ans+dp[j][1]+dp[j][2])%mod;
            }
        }
        cout << ans << endl;
       
        
        
    }
 
    return 0;
}