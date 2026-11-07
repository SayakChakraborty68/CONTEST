#include <bits/stdc++.h>
using namespace std;
#define int long long
bool check(int k,vector<int> &a){
    int n=a.size()-1;
    vector<int> gap;
    for(int i=1;i<n;i++){
        if(abs(a[i]-a[i+1])>k) gap.push_back(i);
    }
    if(gap.size()>2) return false;
    if(gap.size()==0) return true;
    if(gap.size()==2){
        int l=gap[0]+1;
        int r=gap[1];
        for(int i=l;i<r;i++){
            if(2*abs(a[i]-a[i+1])>k) return false;
        }
        if(abs(a[l-1]-2*a[r])>k || abs(2*a[l]-a[r+1])>k) return false;
        return true;
    }
    if(gap.size()==1){
        int idx=gap[0];
        bool f=false;
        for(int i=idx+1;i<=n;i++){
            if(i>idx+1 && 2*abs(a[i]-a[i-1])>k) break;
            if(abs(a[idx]-2*a[i])<=k && (i==n || abs(2*a[idx+1]-a[i+1])<=k)){
                f=true;
                break;
            }
        }
        if(f) return true;
        for(int i=idx;i>=1;i--){
            if(i<idx && 2*abs(a[i]-a[i+1])>k) break;
            if((i==1 || abs(a[i-1]-2*a[idx])<=k) && abs(2*a[i]-a[idx+1])<=k){
                f=true;
                break;
            }
        }
        if(f) return true;
        return false;
    }
    return false;
}
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n+1);
        for(int i=1;i<=n;i++) cin >> a[i];
        int l=0,r=1e9;
        while(l<r){
            int m=(l+r)/2;
            if(check(m,a)) r=m;
            else l=m+1;
            
        }
        cout << l << endl;
    }
 
    return 0;
}