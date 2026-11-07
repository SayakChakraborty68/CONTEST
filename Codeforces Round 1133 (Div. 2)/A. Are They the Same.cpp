#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];
        int c0a=0,c1a=0,c0b=0,c1b=0;
        for(int i=0;i<n;i++){
            if(a[i]&1) c1a++;
            else c0a++;
            if(b[i]&1) c1b++;
            else c0b++;
        }
        if(k&1){
            if(c0a>=c0b) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else{
            if(c1a>=c1b) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
	}
 
	return 0;
}