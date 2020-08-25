#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i = low; i<n;i++)

using namespace std;
typedef pair<int,int> ii;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
     freopen("input.txt","r", stdin);
    #else
     #define endl '\n'
    #endif // LOCAL

    int t; cin>> t;
    while(t--){
        vector<ii> pairs;
        pairs.clear();
        int n; cin >> n;
        bool can = true;
        if(n/2<3)
            can = false;
        int num; cin>> num;
        int cant = 1;
        fore(i,0,n-1){
            int temp; cin >> temp;
            if(num == temp){
                cant++;
            }else{
                pairs.pb({num,cant});
                num = temp;
                cant = 1;
            }
            if(i + 1 == n -1){
                pairs.pb({num,cant});
            }
        }
        int gold = 0;
        int silver = 0;
        int bronze = 0;
        int rest = n/2;
        if(can){
            int temp = pairs[0].ss;
            if(n/2 - temp >= 2*temp + 2){
                gold = temp;
                rest -= gold;
                int index = 1;
                bool stop = false;
                while(!stop)
                {   if(index >= pairs.size())
                    {
                        stop =true;
                        can = false;
                    }
                    silver += pairs[index].ss;
                    rest -= pairs[index].ss;
                    if(silver >= gold+1){
                        stop = true;
                    }
                    index++;
                }
                stop = false;
                if(rest >= gold+1){
                    while(!stop){
                        if(index >= pairs.size())
                        {
                            stop =true;
                            can = false;
                        }
                        bronze += pairs[index].ss;
                        rest -= pairs[index].ss;
                        if(bronze >= gold+1){
                            stop = true;
                        }
                        index++;
                    }
                    if(bronze >= gold+1){
                        stop = false;
                        while(!stop && rest > 0){
                            if(index >= pairs.size())
                                stop =true;
                            if(pairs[index].ss <= rest){
                                bronze += pairs[index].ss;
                                rest -= pairs[index].ss;
                            }else{
                                stop = true;
                            }
                            index++;
                        }
                    }else{
                        can = false;
                    }
                    if(rest <0){
                        can = false;
                    }
                }else{
                    can = false;
                }
            }else{
                can = false;
            }

            if(can){
                cout<<gold<<" "<<silver <<" "<<bronze<<endl;
            }else{
                cout <<"0 0 0"<<endl;
            }
        }else{
            cout <<"0 0 0"<<endl;
        }
    }
    return 0;
}
