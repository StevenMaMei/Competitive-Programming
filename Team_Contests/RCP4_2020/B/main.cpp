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
bool comp(ii a, ii b){
    if(a.ff != b.ff){
        return a.ff>b.ff;
    }
    return  a.ss<b.ss;
}
int n,k,mnDisp=1;
vector<bool> minimPicked;
int getMinDisp(){
    for(int i = mnDisp; i<=k;i++){
        if(!minimPicked[i]){
            return i;
        }
    }
    return 1e9;
}
int main(){FIN;
     cin>>n>>k;
     minimPicked.resize(k+1);
    vector<int> nums;
    fore(i,0,n){
        int a; cin>>a;
        nums.pb(a);
    }
    vector<int> suf(n);
    vector<int> firstApp(k+1);
    set<int> picked;
    for(int i= n-1; i>=0; i--){
        if(picked.count(nums[i])==0){
             firstApp[nums[i]]=i;
        }
        picked.insert(nums[i]);
        suf[i]=sz(picked);
    }
    int mnNum=1e9,mnIndex=0;
    for(int i = 0;i<n;i++){
        if(nums[i]<mnNum && suf[i]==k){
            mnNum=nums[i];
            mnIndex=i;
        }
    }
//    for(int i = 1; i<=k;i++){
//        cout<<i<<" "<<firstApp[i]<<"\n";
//    }
    vector<int> ans;
    ans.pb(mnNum);
    minimPicked[mnNum]=true;
    mnIndex++;
    while(sz(ans)<k ){
        if( minimPicked[nums[mnIndex]]){
            mnIndex++;
            continue;
        }
        if(ans.back()<nums[mnIndex] ){
            ans.pb(nums[mnIndex]);
            minimPicked[nums[mnIndex]]=true;
        }else if(ans.back()>nums[mnIndex]){
//            cout<<nums[mnIndex]<<" "<<mnIndex<<"\n";
//
            while(firstApp[ans.back()]>mnIndex && ans.back()>nums[mnIndex] ){
                minimPicked[ans.back()]=false;
                ans.pop_back();
            }
                ans.pb(nums[mnIndex]);
                minimPicked[ans.back()]=true;
        }
        mnIndex++;
    }

    fore(i,0,sz(ans)){
        if(i+1==sz(ans)){
            cout<<ans[i]<<"\n";
        }else{
            cout<<ans[i]<<" ";
        }
    }


    return 0;
}

//5 4
//2 4 1 3 2
//
//6 4
//2 4 1 4 3 2
//
//5 4
//2 3 4 1 3
//R// 2 3 4 1
//
//8 5
//5 2 3 2 4 1 3 2
//R// 5 2 4 1 3
//
//7 5
//5 2 3 4 1 3 2
//
//7 5
//2 3 2 4 1 3 5
