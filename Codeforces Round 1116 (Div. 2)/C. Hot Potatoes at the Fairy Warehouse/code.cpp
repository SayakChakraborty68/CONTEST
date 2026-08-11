#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while(t--){
        long long n,k;
        cin >> n>> k;
        int m = 2*n;
        string s;
        cin >> s;
        long long o = count(s.begin(),s.end(),'1');
        long long r = 0, b = 0;
        if(o == 0){
            cout << 0 << " " << 0 << '\n';
            continue;
        }
        if(o == m){
            for(int i=0;i<m;i++){
                if(i%2==0) b++;
                else r++;
            }
            cout << r << " " << b << '\n';
            continue;
        }
        int z = -1;
        for(int i=0;i<m;i++){
            if(s[i]=='0'){
                z = i;
                break;
            }
        }
        vector<int> v;
        v.reserve(m);
        int i = (z+1)%m;
        for(int q=0;q<m;q++){
            if(s[i]=='1'){
                v.push_back(i);
            }
            else{
                if(!v.empty()){
                    int l = v.size();
                    for(int j=0;j<l-1;j++){
                        if(v[j]%2==0) b++;
                        else r++;
                    }
                    if(v[l-1]%2==0) r++;
                    else b++;
                    v.clear();
                }
            }
            i = (i+1)%m;
        }
        cout << r << " " << b << '\n';
    }
 
    return 0;
}