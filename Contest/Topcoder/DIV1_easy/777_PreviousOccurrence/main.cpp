#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;
typedef pair<int,int> ii;
class 	PreviousOccurrence{
    public: int findValue(int defaultValue, int query){
        map<int,int> lastOcur;
        int last =0;
        if(query == 0)return 0;
        if(defaultValue==1 && query>1)return -1;

        fore(i,1,10000000){
            int toput=0;
            if(lastOcur.find(last)==lastOcur.end()){
                toput=defaultValue;
            }else{
                toput=i-1-lastOcur[last];
            }
            if(query == toput)return i;
            lastOcur[last]=i-1;
            last=toput;

        }
        return -1;
    };
};

//int main(){FIN;
//    PreviousOccurrence p;
//    cout<<p.findValue(47,6763);
//    return 0;
//}
