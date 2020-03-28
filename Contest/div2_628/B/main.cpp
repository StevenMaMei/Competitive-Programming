#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        set<int> setsito;
        for(int i = 0; i<n;i++){
            int x; cin>>x;
            setsito.insert(x);
        }
        cout<<setsito.size()<<"\n";
    }
    return 0;
}
