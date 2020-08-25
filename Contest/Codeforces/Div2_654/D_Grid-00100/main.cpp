#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> ii;


int main(){FIN;
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<vector<int>> grid(n,vector<int>(n));
        int i=0,j=0;
        fore(l,0,k){
            grid[i][j]=1;
            i = i+1; j= (j+1)%n;
            if(i==n){
                i=0; j=(j+1)%n;
            }
        }

        if(k%n==0){
            cout<<0<<"\n";
        }else{
            cout<<2<<"\n";
        }
        fore(i,0,n){
            fore(j,0,n){
                cout<<grid[i][j];
            }
            cout<<"\n";
        }
    }
    return 0;
}
