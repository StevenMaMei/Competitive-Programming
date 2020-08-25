#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(long long i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;
typedef long long ll;
class IterateOverACube{
    ll howManyWithSum(ll s, int N){
        if(s<=N-1) return (s+1)*(s+2)/2;
        if(s>=2*N-2){
            s= 3*N-3-s;
            return (s+1)*(s+2)/2;
        }
        ll m = s-(N-1);
        ll ans = (s+1)*(s+2)/2;
        ans -= 3*(m+1)*m/2;
        return ans;
    }
    public: vector <int> findCell(int N, long long index){
        ll sum=0;
        for( sum = 0; sum<=3*N-3;sum++){
            ll calc = howManyWithSum(sum,N);
//            cout<<sum<<" "<<calc<<"\n";
            if(calc<= index)index-=calc;
            else break;
        }

        ll x=0;
        for(; x<=N-1;x++){
            ll rem= sum-x;
            if(rem <0)continue;
            if(rem>2*N-2)continue;
            ll calc = (rem<=N-1)?rem+1: 2*N-1-rem;
//            cout<<sum<<"\n";
//            cout<<x<<" "<<calc<<"\n";
            if(calc<=index) index-= calc;
            else break;
        }
        vector<int> ans;
        ans.pb(int(x));
        for(ll y=0;y<N;y++){
            ll z = sum-x-y;
            if(z<0 || z>=N)continue;
            if(index==0){
                ans.pb(int(y)); ans.pb(int(z));
                return ans;
            }
            index--;
        }
        return ans;
    };
};

//int main(){FIN;
//    IterateOverACube c;
//    c.findCell(3,9);
//    return 0;
//}
