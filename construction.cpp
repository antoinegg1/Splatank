#include<iostream>
#include<time.h>
using namespace std;
int main(){
    int t0=time(NULL);
    int n=4000000;
    printf("%d\n",n);
    printf("%d",2);
    for(int j=2;j<=n;j+=2){
        printf(" %d",j-1);
    }
    for(int j=1;j<=n;j+=2){
        printf(" %d",j-1);
    }
    printf("\n%d",time(NULL)-t0);
    return 0;
}