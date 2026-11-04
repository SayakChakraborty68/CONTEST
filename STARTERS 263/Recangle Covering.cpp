#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int t;
	cin >> t;
	while(t--){
	    int n,m;
	    cin >> n >> m;
	    int mnx,mny,mxx,mxy;
	    mny=mnx=1e9;
	    mxx=mxy=-1e9;
	    for(int i=0;i<n;i++){
	        string s;
	        cin >> s;
	        for(int j=0;j<m;j++){
	            if(s[j]=='1'){
	                mnx=min(mnx,i);
	                mny=min(mny,j);
	                mxx=max(mxx,i);
	                mxy=max(mxy,j);
	            }
	        }
	    }
	    int h=mxx-mnx+1;
	    int w=mxy-mny+1;
	    cout << h*w << endl;
	}
}