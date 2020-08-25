#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;
typedef long long ll;
class ModularQuadrant{
    ll countS(int r,int c){
        if(r>c)swap(r,c);
        ll x = r - (r%3);
        ll y = c-x;
        y =y -(y%3);
        return 4*x/3+x*x+y*r+(c%3==2)*r+(r%3==2)*(x+1);
    }
    public:  long long sum(int r1, int r2, int c1, int c2){
        return countS(r2+1,c2+1)-countS(r1,c2+1)-countS(r2+1,c1)+countS(r1,c1);
    };
};

int main(){FIN;
    fore(i,0,10){
        fore(j,0,13){
            int a= max(i,j)%3;
            cout<<a;
        }
        cout<<"\n";
    }
    return 0;
}
