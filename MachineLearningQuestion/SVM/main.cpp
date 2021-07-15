#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <time.h>

using namespace std;

int main(){
    int T, N, y[2], flag=0;
    cin>>T;
    cin>>N;
    float x1[100], x2[100];
    float w1=0, w2=0;
    for(int i=0; i<T; i++){
        if(T<=10 && T>=1){
            srand(time(NULL));
            for(int i=0; i<N; i++){
                cin>>x1[i]>>x2[i]>>y[i];
                    w1= rand()%100;
                    w2= rand()%100;
                    if(((y[i]==1) && (w1*x1[i] + w2*x2[i])>=0) || ((y[i]== -1) && (w1*x1[i] + w2*x2[i])<=0))
                        flag=1;
                    else
                        flag=0;
            }
            if(flag==0){
            cout<<"NO"<<endl;
            }
            else{
            cout<<"YES"<<endl;
            }
        }
        flag=0;
    }
}