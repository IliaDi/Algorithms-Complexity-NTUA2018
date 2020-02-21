#include <iostream>    
using namespace std;    
    
    
int main(){    
    long long int N,a,b,c;    
    cin>>N;    
    cin>>a;    
    cin>>b;    
    cin>>c;    
    long long int temp;    
    long long int x[N];    
    for(long long int i=0;i<N;i++){    
        cin>>x[i];    
    }    
    long long int G[N]; //MIAM for 1...n dishes    
    long long int S[N]; //sum of xi from 1 till i    
    long long int max=0;    
    S[0]=x[0];    
    for(long long int i=1;i<N;i++){    
        S[i]=S[i-1]+x[i];    
    }    
    
    G[0]=a*(x[0]*x[0])+b*x[0]+c;     
    for(long long int i=1;i<N;i++){    
        max=(S[i]*S[i])*a+b*S[i]+c;       
        for(long long int j=1;j<=i;j++){    
            long long int t=S[i]-S[j-1];    
            long long int h=a*(t*t)+b*t+c;    
            if((G[j-1]+h)>max){    
                max=G[j-1]+h;    
            }    
        }    
        G[i]=max;    
    }    
      
    cout<<G[N-1]<<"\n";    
    return 0;    
}     