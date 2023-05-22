#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
char warrior[5][10]={{"dragon"},{"ninja"},{"iceman"},{"lion"},{"wolf"}};
int number[2][5]={{0,0,0,0,0},{0,0,0,0,0}};
int hp[5]={};
int attark[5]={};
int blueline[5]={3,0,1,2,4};
int redline[5]={2,3,4,1,0};
class Basis{
public: 
    int M;
    int Number=0;
    Basis(int x):M(x){}
};
int main(){
    int n;
    cin>>n;
    for(int p=1;p<=n;p++){
        cout<<"Case:"<<p<<endl;
        int time=0;
        int M;
        bool b=true,r=true;
        cin>>M;
        int mi=20000;
        Basis blue(M);
        Basis red(M);
        for(int j=0;j<=4;j++){
            cin>>hp[j];
            mi=min(mi,hp[j]);
        }
        int j1=0,j2=0;
        while(r||b){
            if(r){
                if(red.M<mi){
                    cout<<setw(3)<<setfill('0')<<time<<" red headquarter stops making warriors"<<endl;
                    r=false;
                }
                else{
                    while(1){
                        if(red.M<hp[redline[j1]]){
                            j1++;
                            if(j1==5)j1=0;
                            continue;  
                        }
                        red.M-=hp[redline[j1]];
                        number[1][redline[j1]]++;
                        red.Number++;
                        cout<<setw(3)<<setfill('0')<<time<<" red "<<warrior[redline[j1]]<<' '<<red.Number<<" born with strength "<<hp[redline[j1]]<<','
                        <<number[1][redline[j1]]<<" "<<warrior[redline[j1]]<<" in red headquarter"<<endl;
                        j1++;
                        if(j1==5)j1=0;
                        break;
                    }
                }
            }   
            if(b){
                if(blue.M<mi){
                    cout<<setw(3)<<setfill('0')<<time<<" blue headquarter stops making warriors"<<endl;
                    b=false;
                }
                else{
                    while(1){
                        if(blue.M<hp[blueline[j2]]){
                            j2++;
                            if(j2==5)j2=0;
                            continue;  
                        }
                        blue.M-=hp[blueline[j2]];
                        number[0][blueline[j2]]++;
                        blue.Number++;
                        cout<<setw(3)<<setfill('0')<<time<<" blue "<<warrior[blueline[j2]]<<' '<<blue.Number<<" born with strength "<<hp[blueline[j2]]<<','
                        <<number[0][blueline[j2]]<<" "<<warrior[blueline[j2]]<<" in blue headquarter"<<endl;
                        j2++;
                        if(j2==5)j2=0;
                        break;
                    }
                }
            } 
            time++;
        }
        memset(number,0,sizeof(number));
    }
    return 0;
}