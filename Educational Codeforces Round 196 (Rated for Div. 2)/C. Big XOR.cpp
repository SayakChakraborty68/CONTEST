
#include <bits/stdc++.h>
using namespace std;
#define int long long
int bs[25],msk[25],idx[25];
bool check(int x,int &res){
	res=0;
	for(int i=24;i>=0;i--){
		if(x>>i&1) {
			if(!bs[i]) return false;
			x^=bs[i];
			res^=msk[i];
		}
	}
	return x==0;
}
 
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		memset(bs,0,sizeof(bs));
		memset(msk,0,sizeof(msk));
		int cnt=0;
		vector<int> v;
		for(int i=1;i<=n;i++){
			int x=i^(2*i);
			int cur=1<<cnt;
			for(int j=24;j>=0;j--){
				if(x>>j&1) {
					if(bs[j]) {
						x^=bs[j];
						cur^=msk[j];
					}
					else{
						bs[j]=x;
						msk[j]=cur;
						v.push_back(i);
						cnt++;
						break;
					}
				}
			}
		}
		int x=0;
		for(int i=1;i<=n;i++) x^=i;
		int P=0;
		while((1<<P)<=n) P++;
		int k=(1<<P)-1;
		int T1=(2*k)^x;
		int T2=(2*k+1)^x;
		int res=0;
		if(!check(T1,res)) check(T2,res);
		vector<int> d(n+1,0);
		for(int i=0;i<cnt;i++){
			if(res>>i&1) d[v[i]]=1;
		}
		for(int i=1;i<=n;i++) 
			cout<<d[i]<<" \n"[i==n];
		
	}
	return 0;
}