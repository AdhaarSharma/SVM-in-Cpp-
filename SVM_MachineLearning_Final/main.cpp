#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <cmath>
#include <tuple>

using namespace std;

double getHingeLoss(double &x1, double &x2, int &y, double &w1, double &w2){
double loss = 0;
if(y==1){
loss = 1-(w1*x1 + w2*x2);
}
else{
loss = 1+(w1*x1 + w2*x2);
}
if(loss < 0) loss = 0;
return loss;
}

double getSVMCost(vector<double> &x1, vector<double> &x2, vector<int> &y,
double w1, double w2, double &dw1, double &dw2){
int n = static_cast<int>(y.size());

double cost=0;
dw1 = 0;
dw2 = 0;
for(int i = 0; i<n;i++){
double loss = getHingeLoss(x1[i], x2[i], y[i], w1, w2);
cost += loss;

if(loss > 0){
dw1 += (-x1[i]*y[i]);
dw2 += (-x2[i]*y[i]);
}
}

cost /= n;
dw1 /= n;
dw2 /= n;

return cost;
}

std::tuple<double, double> trainSVM(vector<double> &x1, vector<double> &x2, vector<int> &y){
double lrate = 0.0005;
double threshold = 0.001;
double w1 = 1;
double w2 = 1;
double dw1 = 0;
double dw2 = 0;
int iter = 0;
while(iter<1000000){
double cost = getSVMCost(x1, x2, y, w1, w2, dw1, dw2);
if(iter%1000==0){
cout<<"Iter: "<<iter<< " cost = "<<cost<< " dw1 = " << dw1 << " dw2 = " << dw2 << endl;
}
iter++;

w1 -= lrate* dw1;
w2 -= lrate* dw2;
}
cout<<"y = "<<w1<<" * x1 + "<<w2<<" * x2"<<endl;
return make_tuple(w1, w2);
}

int main(){

int T, N, flag=0, x{0}, y{0}, z{0};
    cin>>T;
    cin>>N;
    vector<int> Y;
    vector<double> X1, X2;
    double W1=0, W2=0;
    for(int i=0; i<T; i++){
        if(T<=10 && T>=1){
            for(int i=0; i<N; i++){
                cin>>x>>y>>z;
                X1.push_back(x);
                X2.push_back(y);
                Y.push_back(z);
            }
        }
    
    
    tie(W1,W2) = trainSVM(X1, X2, Y);

    cout<<endl<<"W1: "<<W1<<endl<<"W2: "<<W2<<endl;

    for(int i=0; i<N; i++){
        if(((Y[i]==1) && (W1*X1[i] + W2*X2[i])>=0) || ((Y[i]== -1) && (W1*X1[i] + W2*X2[i])<=0))
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
return 0;
}