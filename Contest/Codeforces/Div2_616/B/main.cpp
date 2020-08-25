#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)

using namespace std;

int main()
{FIN;
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        vector<int> a(n);

        fore(i,0,n){
            cin>>a[i];

        }

        bool can = true;
        int i = 0, j= n-1;
        while(i<=j){
            if(i+1 == j && a[i]<=i &&a[j]<=i){
                can= false;
                break;
            }
            if(a[i]< i || a[j]<i){
                can= false;
                break;
            }
            i++;
            j--;
        }
        if(can)cout<<"Yes\n";
        else cout<<"No\n";

    }
    return 0;
}
