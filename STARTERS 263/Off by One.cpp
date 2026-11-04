#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
const int MAXN=4005;
int fact[MAXN];
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	fact[0]=1;
	for(int i=1;i<MAXN;i++) fact[i]=(fact[i-1]*i)%MOD;
	while(t--){
	    int n;
	    string s;
	    cin >> n >> s;
	    vector<int> w;
	    int sz=1;
	    for(char c:s){
	        if(c=='1') sz++;
	        else{
	            w.push_back(sz>=2?2:1);
	            sz=1;
	        }
	    }
	    w.push_back(sz>=2?2:1);
	    int k=w.size();
	    vector<int> dp_prev(k+1,0);
	    dp_prev[0]=1;
	    int ans=0;
	    for(int i=1;i<=k;i++){
	        vector<int> dp_cur(k+1,0);
	        int S=0;
	        for(int j=1;j<=k;j++){
	            if(j>=2){
	                S=(-S-dp_prev[j-2])%MOD;
	                if(S<0) S+=MOD;
	            }
	            dp_cur[j]=(dp_prev[j-1]*w[j-1]%MOD+2*S)%MOD;
	        }
	        ans=(ans+dp_cur[k]*fact[i])%MOD;
	        dp_prev=dp_cur;
	    }
	    cout << ans << endl;
	}
}