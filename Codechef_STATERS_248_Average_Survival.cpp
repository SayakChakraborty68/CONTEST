#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<float> a(n);
	    float sum = 0 ;
	    for(int i=0;i<n;i++){
	         cin >> a[i];
	         sum += a[i];
	    }
	    sort(a.begin(),a.end());
	    float l = n;
	    float avg = sum/l;
	    for(int i=0;i<n;i++){
	        if(avg > a[i]){
	            sum-=a[i];
	            l--;
	            avg = sum/l;
	        }
	        else break;
	    }
	    cout << l << endl;  
	    
	}

}
