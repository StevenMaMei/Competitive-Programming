#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;

class  FixedPointReversals{
    int findPos(int num,int cur,int fixed, int *arr){
        for(int i = cur; i>=0;i--){
            if(i == fixed)continue;
            if(arr[i]==num){
                return i;
            }
        }
//        cout<<num<<" "<<cur<<"\n";
//        cout<<arr[cur]<<"\n";
        assert(false);
        return 0;
    }
    int findPos2(int num,int cur,int fixed,int n, int *arr){
        for(int i = cur; i<n;i++){
            if(i == fixed)continue;
            if(arr[i]==num){
                return i;
            }
        }
//        cout<<num<<" "<<cur<<"\n";
//        cout<<arr[cur]<<"\n";
        assert(false);
        return 0;
    }
    public: vector <int> sort(vector <int> A, int fixed){
        vector<int> obj(sz(A));
        fore(i,0,sz(A)){
            obj[i] =A[i];
        }
        std::sort(obj.begin(),obj.end());
        int a[sz(A)];
        fore(i,0,sz(A)){
            a[i] =A[i];
        }
        vector<int> ans;
        if(obj[fixed]!= a[fixed]){
            ans.pb(-1); return ans;
        }
        if(fixed >= (sz(A)-fixed-1)){
            for(int i = sz(A)-1; i>=0; i--)if(i!= fixed){
    //            cout<<i<<" "<<a[i]<<" "<<obj[i]<<"\n";
                if(a[i]== obj[i])continue;
                int pos = findPos(obj[i],i,fixed,a);
                if( (pos >fixed && i>fixed) || (pos<fixed && i<fixed) ){
                    reverse(a+pos, a+i+1);
                    ans.pb(pos); ans.pb(i+1);
                }else{
//                    cout<<pos<<" "<<a[i]<<" "<<obj[i]<<"\n";
                    int mirror = fixed - (i-fixed);
                    if(mirror != pos){
                        if(pos<mirror){
                            ans.pb(pos); ans.pb(mirror+1);
                            reverse(a+pos,a+mirror+1);
                        }else{
                            ans.pb(mirror); ans.pb(pos+1);
                            reverse(a+mirror,a+pos+1);
                        }
                    }
                    ans.pb(mirror); ans.pb(i+1);
                    reverse(a+mirror, a+i+1);
                }
            }
        }else{
            for(int i = 0; i< sz(A); i++)if(i!= fixed){
    //            cout<<i<<" "<<a[i]<<" "<<obj[i]<<"\n";
                if(a[i]== obj[i])continue;
                int pos = findPos2(obj[i],i,fixed,sz(A),a);
                if( (pos >fixed && i>fixed) || (pos<fixed && i<fixed) ){
                    reverse(a+i,a+ pos+1);
                    ans.pb(i); ans.pb(pos+1);
                }else{
    //                cout<<pos<<" "<<a[i]<<" "<<obj[i]<<"\n";
                    int mirror = fixed + (fixed-i);
                    if(mirror != pos){
                        if(mirror < pos){
                            ans.pb(mirror); ans.pb(pos+1);
                            reverse(a+mirror,a+pos+1);
                        }else{
                            ans.pb(pos);ans.pb(mirror+1);
                            reverse(a+pos,a+mirror+1);
                        }
                    }
                    ans.pb(i); ans.pb(mirror+1);
                    reverse(a+i, a+mirror+1);
                }
            }
        }
//        fore(i,0,sz(A)){
//            cout<<a[i]<<" ";
//        }
//        cout<<"\njejej\n";
        return ans;
    };
};

int main(){FIN;
    FixedPointReversals f;
    vector<int> A=

{5,4,3,2,1};
    vector<int> ans = f.sort(A,2);
    fore(i,0,sz(ans)){
        cout<<ans[i]<<" ";
    }
    return 0;
}
