
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
		string s;
		cin >> s;
		int A=n*(n+1)*(n+2)/6;
		vector<int> preF(n+1,0);
		for(int i=1;i<=n;i++){
			preF[i]=preF[i-1];
			if(s[i-1]=='0') preF[i]++;
			else preF[i]--;
		}
		sort(preF.begin(),preF.end());
		vector<int> pre(n+1,0);
		for(int i=1;i<=n;i++) pre[i]=pre[i-1]+preF[i-1];
		int B=0;
		for(int i=1;i<=n;i++) B+=preF[i]*i-pre[i];
		cout << (A+B)/2 << endl;
	}
}
