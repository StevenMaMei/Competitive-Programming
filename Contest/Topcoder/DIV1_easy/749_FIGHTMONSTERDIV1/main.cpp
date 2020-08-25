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
class FightMonsterDiv1{
    public:  long long fightTime(long long hp, long long attack, int level, long long duration){
        ll increment = attack/100*level;
        ll noMagicTime = getNoMagicTime(hp,attack,increment);
        ll left = -1;
        ll right= noMagicTime;
        while(right - left >1){
            ll mid = (right+left)/2;
            ll first = attack;
            ll last = attack + increment*(mid-1);
            ll exact = (first+last) * mid/2;
            ll extra = getNoMagicTime(hp-exact, (last+increment)*5, increment*5);
            if(extra<= duration){
                right = mid;
            }else{
                left = mid;
            }
        }
        {
            ll mid = right;
            ll first = attack;
            ll last = attack + increment*(mid-1);
            ll exact = (first+last)* mid/2;
            ll extra =getNoMagicTime(hp-exact,(last+increment)*5, increment*5);
            return min(noMagicTime, extra+1+mid);
        }
    };

    ll getNoMagicTime(ll hp, ll base, ll increment){
        ll left = -1;
        ll right = hp/base +ll(10);
        while(right -left >1){
            ll mid= (right+left)/2;
            ll first = base;
            ll last = base + increment*(mid-1);
            double approx = (first + last) * ((double) mid / 2);
            ll exact = (first+last) *mid/2;
            if(approx > hp * 10 || exact >= hp){
                right=mid;
            }else{
                left = mid;
            }
        }
        return right;
    }
};

int main(){FIN;
    return 0;
}
