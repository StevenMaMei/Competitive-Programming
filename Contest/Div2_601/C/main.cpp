#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;
int numOfAppears[100005];
bool tpicked[100005];
bool npicked[100005];
vector<vector<int>> positions;
struct triple{
    int t[3];
};
bool ascComp(int n1, int n2){
    return numOfAppears[n1]>numOfAppears[n2];
}
bool desComp(int n1, int n2){
    return numOfAppears[n1]<numOfAppears[n2];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
      freopen("input.txt", "r", stdin);
    #else
      #define endl '\n'
    #endif
    int n;cin>>n;
    positions.resize(n+1);
    triple triples[n-2];
    for(int i = 0 ; i < n-2; i++){
        int a,b,c; cin>>a>>b>>c;
        positions[a].pb(i);
        positions[b].pb(i);
        positions[c].pb(i);
        triples[i].t[0]=a;
        triples[i].t[1]=b;
        triples[i].t[2]=c;
        numOfAppears[a]+=1;
        numOfAppears[b]+=1;
        numOfAppears[c]+=1;
    }
    int cant =0;
    int index=0;
    for(int i =1; i<=n; i++){
        if(numOfAppears[i]==1){
            index=i;
            break;
        }
    }
    triple currTriple;
    vector<triple> r;
    for(int i =0;i<n-1;i++){
        triple t= triples[i];
        if(t.t[0]== index || t.t[1]== index || t.t[2]== index){
            currTriple=t;
            tpicked[i]= true;
            r.pb(t);
            break;
        }
    }
    vector<int> res;
    while(cant != n-2){
        int vec[3];
        copy(begin(currTriple.t),end(currTriple.t),begin(vec));
        if(cant%2 !=0){
            sort(begin(vec),end(vec),ascComp);
        }else{
            sort(begin(vec),end(vec),desComp);
        }
        res.pb(vec[0]);
        res.pb(vec[1]);
        res.pb(vec[2]);
        int num= vec[0];
        for(int i =0 ; i< positions[num].size();i++){
            int currPos= positions[num][i];
            if(!tpicked[currPos]){
                tpicked[currPos]=true;
                r.pb(triples[currPos]);
                break;
            }
        }


        num= vec[1];
        for(int i =0 ; i< positions[num].size();i++){
            int currPos= positions[num][i];
            if(!tpicked[currPos]){
                tpicked[currPos]=true;
                r.pb(triples[currPos]);
                break;
            }
        }


         num= vec[2];
        for(int i =0 ; i< positions[num].size();i++){
            int currPos= positions[num][i];
            if(!tpicked[currPos]){
                tpicked[currPos]=true;
                r.pb(triples[currPos]);
                break;
            }
        }

        cant++;
        if(cant != n-2)
            currTriple=r[cant];
    }
    cant=0;
    for(int i =0 ; i< res.size();i++){
        if(!npicked[res[i]]){
            npicked[res[i]]=true;
            cant++;
            if(cant == n){
                cout<<res[i]<<endl;
            }else{
                cout<<res[i]<<" ";
            }

        }
    }
    return 0;
}
