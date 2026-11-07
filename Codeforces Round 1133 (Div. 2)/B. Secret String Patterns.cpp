#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << "? 1 " << n << endl;
		int k;
		cin >> k;
		if(k==0){
			cout <<"! NO"<< endl;
			continue;
		}
		cout << "? 1 " << k << endl;
		int x;
		cin >> x;
		if(x==k){
			cout << "! NO" << endl;
		}
		else{
			cout << "! YES" << endl;
		}
	}
 
	return 0;
}