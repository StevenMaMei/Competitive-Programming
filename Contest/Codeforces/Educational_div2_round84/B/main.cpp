#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)


using namespace std;

int main()
{
    int t; cin>> t;
    while(t--){
        int n; cin>>n;
        n++;
        vector<int> kingsPicked;
        vector<vector<int>> options;
        queue<int> remPrincess;
        vector<int> remKings;
        options.resize(n);
        kingsPicked.resize(n);
        fore(i,1,n){
            int k; cin>>k;
            int ch = -1;
            if(k == 0){
                remPrincess.push(i);
            }
            fore(j,0,k){
                int currKing; cin>>currKing;
                options[i].pb(currKing);
                if(kingsPicked[currKing]== 0 && ch == -1){
                    ch = currKing;
                    kingsPicked[currKing]=1;
                }
            }
            if(ch == -1){
                remPrincess.push(i);
            }
        }
        if(remPrincess.size()){
            bool picked = false;
            int indxP = -1;
            int indxK = -1;
            fore(i,1,n){
                if(kingsPicked[i]== 0) remKings.pb(i);
            }

            while(remPrincess.size() && !picked){
                int currPrin = remPrincess.front();
                remPrincess.pop();
                for(int k : remKings){
                    auto it = find(options[currPrin].begin(),options[currPrin].end(),k);
                    if(it == options[currPrin].end()){
                        indxP= currPrin;
                        indxK= k;
                        picked = true;
                        cout<<"IMPROVE\n";
                        cout<<indxP<<" "<<indxK<<"\n";
                        break;
                    }
                }
            }

        }else{
            cout<<"OPTIMAL"<<"\n";
        }

    }
    return 0;
}
