#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const int MAXN = 1000006;
long long fact[MAXN], invfact[MAXN];
long long power(long long a,long long b){
    long long res = 1;
    while(b){
        if(b&1) res = res*a%MOD;
        a = a*a%MOD;
        b >>= 1;
    }
    return res;
}
 
void precompute(){
    fact[0] = 1;
    for(int i=1;i<MAXN;i++){
        fact[i] = fact[i-1]*i%MOD;
    }
    invfact[MAXN-1] = power(fact[MAXN-1],MOD-2);
    for(int i=MAXN-2;i>=0;i--){
        invfact[i] = invfact[i+1]*(i+1)%MOD;
    }
}
 
long long C(long long n,long long k){
    if(k<0 || n<0 || k>n) return 0;
    return fact[n]*invfact[k]%MOD*invfact[n-k]%MOD;
}
 
int main(){
    int t;
    cin >> t;
    precompute();
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        long long t0 = 0;
        long long t1 = 0;
        long long k0 = 0;
        long long k1 = 0;
        int i = 0;
        while(i<n){
            int j = i;
            while(j<n && s[j]==s[i]) j++;
            int len = j-i;
            if(s[i]=='0'){
                t0 += len;
                k0++;
            }
            else{
                t1 += len;
                k1++;
            }
            i=j;
        }
        long long f0 = 1;
        long long f1 = 1;
        if(k0>0) f0 = C(t0-1,k0-1);
        if(k1>0) f1 = C(t1-1,k1-1);
        long long ans = f0*f1%MOD;
        cout << ans << endl;
    }
    return 0;
}