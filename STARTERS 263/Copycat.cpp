#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    string s;
	    cin >> s;
	    int l,h;
	    if(s[n-1]=='0'){
	        l=n,h=n;
	    }
	    else{
	        l=0,h=n-1;
	    }
	    int ans=1e18;
	    for(int i=l;i<=h;i++){
	        int cur=0;
	        for(int j=0;j<n;j++){
	            char ch=(j<i)?'0':'1';

	            if(s[j]!=ch) cur++;
	        }
	        ans=min(ans,cur);
	    }
	    cout << ans << endl;
	}
}