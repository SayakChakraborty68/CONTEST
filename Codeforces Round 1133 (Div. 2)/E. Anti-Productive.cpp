#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--){
		int n,l;
		cin >> n >> l;
		vector<int> a(n);
		int total=0;
		for(int i=0;i<n;i++){
			cin >> a[i];
			total+=a[i];
		}
		sort(a.begin(),a.end());
		vector<int> prx(n+1,0);
		for(int i=0;i<n;i++) prx[i+1]=prx[i]+a[i];
		int ans=0;
		int S=sqrt(max(0LL,l-1));
		int p=0;
		for(int i=0;i<=S;i++){
			while(p<n-1 && a[p]<=i) p++;
			int sum=prx[p]+(n-1-p)*i;
			if(i==0) sum+=a[n-1];
			else{
				int M=(l-1)/i;
				sum+=min(a[n-1],M);
			}
			ans=max(ans,sum);
		}
		cout << total-ans << endl;
	}
 
	return 0;
}