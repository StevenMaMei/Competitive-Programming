#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define SZ(s) int(s.size())
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> pp;
int n;
char sudoku[7][7];
char restrictionsRow[7][7];
char restrictionsCols[7][7];
int rows[7];
int cols[7];
bool allMatrixFilled(){
    fore(i,0,n){
        fore(j,0,n){
            if(sudoku[i][j]== '-')return false;
        }
    }
    return true;
}
bool meetConditions(){
    int comp = 1;
    comp = comp<<n;
    comp-=1;
    fore(i,0,n){
        //cout<<rows[i] <<endl;
        if(rows[i] != comp || cols[i] != comp) return false;
    }

    return true;
}
bool canIPutNumber(int n1, int n2,char op){
    if(op == '.')return true;
    if(op == '<') return n1<n2;
    if(op == '>') return n1>n2;
    if(op =='v') return n1>n2;
    if(op == '^') return n1<n2;
}
pair<int,int> getPos(){
    fore(i,0,n){
        fore(j,0,n){
            if(sudoku[i][j]=='-')return {i,j};
        }
    }
    return {-1,-1};
}
bool solve(int ii, int jj){

    bool can = false;
    fore(k,1,n+1){
        //cout<<k<<endl;
        int num = 1;
        num= num <<(k-1);
        //cout<<ii<<" "<<" "<<jj<<" "<<k<<" "<<cols[jj]<<endl;
        if(((rows[ii] & num) == 0 ) && ((cols[jj] & num) == 0)){
            bool thisNumCan = true;
            //if(ii==0 && jj== 0)cout<<k<<endl;
            //cout<<ii<<" "<<jj<<" "<<k<<endl;;
            if(jj-1>=0 && sudoku[ii][jj-1] != '-'){
                //cout<<jj-1<<endl;
               thisNumCan = thisNumCan&& canIPutNumber(sudoku[ii][jj-1] -'0',k,restrictionsCols[ii][jj-1]);
            }
            if(jj+1<n && sudoku[ii][jj+1]!= '-'){
                 //cout<<jj<<endl;
                thisNumCan =thisNumCan&& canIPutNumber(k,sudoku[ii][jj+1] -'0',restrictionsCols[ii][jj]);
            }
            if(ii-1>=0 && sudoku[ii-1][jj] != '-'){
                 //cout<<ii-1<<endl;
                thisNumCan = thisNumCan &&canIPutNumber(sudoku[ii-1][jj]-'0',k,restrictionsRow[ii-1][jj]);
            }
            if(ii+1<n && sudoku[ii+1][jj] != '-'){
                //cout<<ii<<endl;
                //cout<<restrictionsRow[ii][jj]<<endl;
                thisNumCan = thisNumCan&& canIPutNumber(k,sudoku[ii+1][jj]-'0',restrictionsRow[ii][jj]);
            }

            if(thisNumCan){

                rows[ii] =rows[ii] |num;
                cols[jj] =cols[jj]| num;
                sudoku[ii][jj] = '0'+k;
                pp next = getPos();
                if(next.ff != -1){
                        //cout<<ii<<" "<<jj<<" "<<next.ff<<" "<<next.ss<<endl;
                    thisNumCan = thisNumCan && solve(next.ff,next.ss);
                }else{
                    thisNumCan = thisNumCan && meetConditions();
                }
            }
            if(thisNumCan){
                can = true;
                break;
            }else{
                //cout<<(rows[ii])<<endl;
               // cout<<(rows[ii] & (~num))<<endl;
                num = ~num;
                rows[ii] = (rows[ii] & num);
                cols[jj] = (cols[jj] & num);
                sudoku[ii][jj] = '-';

            }

        }
    }
    return can;

}
int main()
{
    FIN;
    cin>>n;
    fore(i,0,2*n-1){
        string s; cin>>s;
        if(i%2==0){
            fore(j,0,SZ(s)){
                if(j%2==0){
                   sudoku[i/2][j/2] = s[j];
                   int k=s[j]-'0';
                   k--;
                   int num = 1;
                   num = num<<k;

                   if(s[j]!= '-'){

                        cols[j/2] = cols[j/2] | num;

                        rows[i/2] = rows[i/2] | num;
                   }
                   //cout<<s[j]<<endl;
                }else{
                    restrictionsCols[i/2][(j-1)/2] = s[j];
                }
            }
        }else{
            fore(j,0,SZ(s)){
                if(j%2==0){
                    restrictionsRow[(i-1)/2][j/2]=s[j];

                }
            }
        }
    }

    pp firstPos= getPos();
    if(firstPos.ff != -1)
        solve(firstPos.ff,firstPos.ss);
    fore(i,0,n){
        fore(j,0,n){
            cout<<sudoku[i][j]<<"";
        }
        cout<<"\n";
    }



    return 0;
}
