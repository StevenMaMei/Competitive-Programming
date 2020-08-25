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

bool isPrime(int n){
    for(int i=2; i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int main(){FIN;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        if(n==1){
            cout<<"FastestFinger\n";
            continue;
        }else if(n==2 || n%2){
            cout<<"Ashishgup\n";
            continue;
        }
        int cant2=0;
        while(n%2==0){
            cant2++;
            n/=2;
        }
        if( (cant2==1 && isPrime(n)) || (cant2>1 && n==1) ){
            cout<<"FastestFinger\n";
            continue;
        }else{
            cout<<"Ashishgup\n";
            continue;
        }
    }
    return 0;
}
