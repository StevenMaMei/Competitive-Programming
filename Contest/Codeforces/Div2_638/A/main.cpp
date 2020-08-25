#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int sum1= 1<<n;
        int sum2=0;
        for(int i = n-1;i>=n/2;i--){
            sum2 += 1<<i;
        }
        for(int i = 1; i<n/2;i++){
            sum1+= 1<<i;
        }
        cout<<abs(sum1-sum2)<<"\n";

    }
    return 0;
}
