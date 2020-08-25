#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
vector<int> heights;

int main(){FIN;
    int Q; cin>>Q;
    while(Q--){
        int h,n; cin>>h>>n;
        heights.clear(); heights.resize(n);
        int currH= h;
        int gems = 0;
        fore(i,0,n)cin>>heights[i];
        fore(i,1,n){
            if(currH-1 == heights[i]){
                if(i+1 < n){
                    if(heights[i+1]== currH-2){
                        currH = heights[i+1];
                        i +=1;
                    }
                    else{
                        currH -=2;
                        gems++;
                    }
                }else{
                    if(currH-2!= 0){
                        gems++;
                        currH = currH-2;
                    }
                }
            }else{
                currH = heights[i]+1;
                i--;
            }
        }
        cout<<gems<<"\n";
    }
    return 0;
}
