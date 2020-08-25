#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thx=b;i<thx;i++)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

int main()
{FIN;
    int n,m,p; cin>>n>>m>>p;
    vector<int> a(n),b(m);
    fore(i,0,n){
        cin>>a[i];
    }
    fore(i,0,m){
        cin>>b[i];
    }
    int f = 0;
    fore(i,0,n){
        if(a[i]%p != 0){
            f= i;
            break;
        }
    }
    int s = 0;
    fore(i,0,m){
        if(b[i]%p != 0){
            s= i;
            break;
        }
    }
    cout<<f+s<<"\n";
    return 0;
}
