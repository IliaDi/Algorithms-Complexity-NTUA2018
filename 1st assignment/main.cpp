#include <iostream>    
#include <stack>     
#include <vector>    
    
using namespace std;    
    
    
class pat  {    
    public:    
    long long int number;    
    long long int pos;    
};    
    
stack<pat*> maxes;    
    
int main() {    
    long long int N;    
    cin >> N;    
    long long int H[N];    
    long long int tax_sum_left[N];    
    long long int tax_sum_right[N];    
    for (long long int i = 0; i < N; i++) {    
        long long int h;    
        cin >> h;    
        H[i]=h;    
            
    }    
    //apo aristera prospelasi pinaka H    
    tax_sum_left[0]=H[0];    
    pat* p=new pat;    
    p->number=H[0];    
    p->pos=(1);    
    maxes.push(p);    
    for(long long int i=1;i<N;i++){    
    
        if(H[i]<=H[i-1]){    
            tax_sum_left[i]=(tax_sum_left[i-1]+H[i]);    
        }    
        else{ //H[i]>H[i-1]    
            pat *temp=maxes.top();    
            long long int j=(*temp).pos;     
            long long int n=(*temp).number;    
            if(H[i]>=n){    
                maxes.pop();    
                tax_sum_left[i]=(H[i]*(i+1));    
                pat* e=new pat;    
                e->number=H[i];    
                e->pos=(i+1);    
                maxes.push(e);    
            }    
            else{    
                long long int x=j+1,c=j+1;    
                while(x<i){    
                    if(H[x]>=H[i]){c=x; x++;}    
                    else{break;}    
                }    
                tax_sum_left[i]=(tax_sum_left[c]+H[i]*(i-c));    
            }    
            
        }    
    }    
        
    tax_sum_right[N-1]=H[N-1];    
    pat* d=new pat;    
    d->number=H[N-1];    
    d->pos=N;    
    maxes.push(d);    
    for(long long int i=(N-2);i>=0;i--){    
        if(H[i]<=H[i+1]){    
            tax_sum_right[i]=(tax_sum_right[i+1]+H[i]);    
        }    
        else{ //H[i]>H[i-1]    
            pat* temp=maxes.top();    
            long long int j=(*temp).pos;     
            long long int n=(*temp).number;    
            if(H[i]>=n){    
                maxes.pop();    
                tax_sum_left[i]=(H[i]*(N-i));    
                pat* f=new pat;    
                f->number=H[i];    
                f->pos=(i+1);    
                maxes.push(f);    
            }    
            else{    
                long long int x=j-1,c=j-1;    
                while(x>i){    
                    if(H[x]>=H[i]){c=x; x--;}    
                    else{break;}    
                }    
                tax_sum_right[i]=(tax_sum_right[c]+H[i]*(c-i));    
            }    
            
        }    
    }  
    long long int temp =tax_sum_right[0]-H[0];  
    long long int min_tax=tax_sum_left[0]+temp;    
    long long int t;    
    for(long long int i=0;i<N;i++){    
        t=tax_sum_left[i]+tax_sum_right[i]-H[i];    
        if(t<min_tax){    
            min_tax=t;    
        }    
    }    
        
    cout<<min_tax;    
        
    return 0 ;    
        
}    