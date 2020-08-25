#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)


using namespace std;

int parent[28];
int ranks[28];
bool picked[28];
bool counted[28];

void makeSet(int v){
    parent[v] = v;
    ranks[v] = 0;
}
int findSet(int v){
    if(v == parent[v]){
        return v;
    }
    return parent[v] = findSet(parent[v]);
}
void unionSets(int a, int b){
    a = findSet(a);
    b = findSet(b);
    if(a != b){
        if(ranks[a] < ranks[b])
            swap(a,b);
        parent[b] = a;
        if(ranks[a] == ranks[b])
            ranks[a]++;
    }
}
int main()
{

    int n; cin>>n;
    for(int i = 0; i<n; i++){
        string s; cin>>s;
        for(int j = 0; j<s.size(); j++){
           // cout<<s[j]-'a'<<" ";
            if(!picked[s[j]-'a']){
                picked[s[j]-'a'] = true;
                makeSet(s[j]-'a');
            }
            unionSets(s[0]-'a', s[j]-'a');
        }
    }
    int quant = 0;
    for(int i = 0; i< 28; i++){
        if(picked[i]){
            int currSet = findSet(i);
            if(!counted[currSet]){

                quant++;
                counted[currSet] = true;
            }
        }
    }
    cout<<quant<<endl;
    return 0;
}
