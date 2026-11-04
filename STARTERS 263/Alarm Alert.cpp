#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int t;
	cin >> t;
	while(t--){
	    int x,y,d;
	    cin >> x >> y >> d;
	    int a=x,b=y;
	    while(abs(a-b)>d){
	        if(a<b) a+=x;
	        else b+=y;
	    }
	    cout << max(a,b) << endl;
	}

}