#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b;i<thxicesi;i++)


using namespace std;
int n,k;

vector<int> getSteps(vector<int> studs){
    vector<int> toreturn;
    fore(i,0,n-1){
        if(studs[i]== 1 && studs[i+1]==0){
            toreturn.pb(i);
        }
    }
    return toreturn;
}
int main()
{
     cin>>n>>k;
    vector<int> students(n);
    fore(i,0,n){
        char x; cin>>x;
        students[i]= x=='L'?0:1;
    }
    int last=-1,mini=0,maxi=0,cnt=0;
    for(int i=n-1;i>=0;i--){
        if(students[i]==0){
            cnt++;
        }else{
            if(cnt==0)continue;
            maxi+= cnt;
            mini = max(cnt,last+1);
            last= mini;
        }
    }
    if(k< mini || k>maxi){
        cout<<"-1"<<endl;
        return 0;
    }
    bool isMin=false;
    vector<int> leftSteps;
    fore(i,0,k){
        if(!isMin){
            auto steps= getSteps(students);
            cout<<min(int(steps.size()), maxi-k+i+1)<<" ";
            int cur = 0;
            while(k-i-1<maxi && cur <int( steps.size())){
                cout<<steps[cur]+1<<" ";
                students[steps[cur]]=0;
                students[steps[cur]+1]=1;
                cur++;
                maxi--;
            }
            if(maxi == k-i-1){
                isMin=true;
                leftSteps = getSteps(students);
            }
        }else{
            int v = leftSteps.back();
            leftSteps.pop_back();
            cout<<"1 "<<v+1<<" ";
            students[v]=0;
            students[v+1]=1;
            if(v>0 && students[v-1]==1){
                leftSteps.pb(v-1);
            }
            if(v+2<n && students[v+2]==0){
                leftSteps.pb(v+1);
            }
        }
        cout<<"\n";
    }
    return 0;
}
