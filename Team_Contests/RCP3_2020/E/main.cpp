#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;
const int MAXN= 1e6+10;
string a,b;
int corresParentesis[MAXN];
int corresCorchet[MAXN];
int nxt(int currPos, string& s){
    if(s[currPos]=='['){
        return corresCorchet[currPos];
    }else{
        return corresParentesis[currPos+1];
    }
    assert(false);
}
vector<int> getNums(int l, int r, string& s){
    vector<int> nums;
    for(int i=l;i<=r;i++){
        string curr="";
        if(isdigit(s[i])){
            while(isdigit(s[i])){
                curr+= s[i];
                i++;
            }
            nums.pb(stoi(curr));
        }
    }
    return nums;
}
string go(int l,int r, string& s){
    string t ="";
    if(s[l]=='c'){
        int ind1=nxt(l+2,s), ind2= ind1+2;
        t = go(l+2,ind1,s);

        t +=",";
        t += go(ind2,nxt(ind2,s),s);
//        cout<<ind2<<" "<<nxt(ind2,s)<<"\n";
    }else if(s[l] == 'o'){
        vector<int> nums = getNums(l,r,s);
        sort(nums.begin(),nums.end());
        fore(i,0,sz(nums)){
            t += to_string(nums[i]) + (i+1!=sz(nums)?",":"");
        }
    }else if(s[l] == 's'){
        vector<int> nums = getNums(l,r,s);
        sort(nums.begin(),nums.end());
        int last = nums[0];
        bool allSame=true;
        fore(i,0,sz(nums)){
            if(last != nums[i]){
                allSame=false;
            }
            t += to_string(nums[i]);
            if(i+1 != sz(nums))t+=",";
//            cout<<t<<"jejej\n";
        }

        if(!allSame){
            t = "s("+t+")";
        }

    }else if(s[l]=='['){
        vector<int> nums=getNums(l,r,s);
        fore(i,0,sz(nums)){
            t += to_string(nums[i]) + (i+1!=sz(nums)?",":"");
        }
    }
    return t;
}
void reduce(string& r){
    int n = r.size();
    string t="";
    fore(i,0,n){
        if(r[i]=='c'){
            t += r[i];
            while(r[i]!='('){
                i++;
            }
            t +=r[i];
        }else if(r[i]=='s'){
            int cnt = 0;
            while(r[i]!='('){
                i++;
                cnt++;
            }
            if(cnt==7){
                t+='s';
            }else{
                t+='o';
            }
            t+=r[i];
        }else{
            t+=r[i];
        }
    }
    stack<int> st;
    stack<int> st2;
    fore(i,0,sz(t)){
        if(t[i]=='(') st.push(i);
        if(t[i]=='[') st2.push(i);
        if(t[i]==')'){
            int p = st.top(); st.pop();
            corresParentesis[p]=i;
        }
        if(t[i]==']'){
            int p = st2.top(); st2.pop();
//            cout<<p<<" "<<i<<"\n";
            corresCorchet[p]=i;
        }
    }
    r= t;
}

int main(){FIN;
    cin>>a>>b;
    reduce(a);
    string s1 =go(0,sz(a)-1,a);

    reduce(b);
    string s2 = go(0,sz(b)-1,b);

    bool same = s2==s1;

    if(same){
        cout<<"equal\n";
    }else{
        cout<<"not equal\n";
    }
    return 0;
}
