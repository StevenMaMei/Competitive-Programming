#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;


int main(){FIN;
    int n; cin>>n;
    vector<int> times(n);
    fore(i,0,n)cin>>times[i];
    int acA=0, cantA=0,acB=0,cantB=0;
    int time = 0;
    while(cantA+cantB<n){
        if(cantA == n-cantB-1 && acA == acB){
            acA+=times[cantA];
            cantA++;
        }else{
            if(acA<acB){
                acA += times[cantA];
                cantA++;
            }else  if(acA>acB){
                acB+= times[n-cantB-1];
                cantB++;
            }else if(cantA != n-cantB-1){
                acB+= times[n-cantB-1];
                cantB++;
                acA += times[cantA];
                cantA++;
            }
        }
    }
//    cout<<acA<<" "<<acB<<"\n";
    cout<<cantA<<" "<<cantB<<"\n";
    return 0;
}
