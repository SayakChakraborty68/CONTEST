#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while(t--){
        long long a,b,c;
        cin >>a>>b>>c;
        vector<long long> v ={a,b,c};
        sort(v.begin(),v.end());
        a=v[0];
        b=v[1];
        c=v[2];
        cout <<min(c-a,b)<< '\n';
    }
 
    return 0;
}