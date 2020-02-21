#include <iostream>
#include <stack> 
#include <vector>

using namespace std;


class pat  {
	public:
	long long int number;
	long long int count;
};

stack<pat*> zombie;


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

	long long int metr=0;
	long long int sum=0;
	//first element goes in the stack
    pat* p=new pat;
    p->number=H[0];
    p->count=1;
    zombie.push(p);
    metr++;
    sum=H[0];	
    tax_sum_left[0]=sum;
	//calc sum from the left
	for(long long int i=1;i<N;i++){
		if(H[i]<=H[i-1]){
			sum=sum+H[i];
			pat* y=new pat;
            y->number=H[i];
            y->count=1;
            zombie.push(y);
            metr++;
		}
		else{
			long long int counter=1;
			pat* t=zombie.top();
			long long int n=t->number;
			long long int c=t->count;
			long long int steps=metr;
			while(H[i]>n && steps!=0){ //prosoxi ston termatismo
				counter=counter+c;
				sum=sum-(c*n);
				zombie.pop();
				metr--;
				steps--;
				if(steps!=0){
				t=zombie.top();
			    n=t->number;
			    c=t->count;}
			}
			sum=sum+(counter*H[i]);
			pat* r=new pat;
            r->number=H[i];
            r->count=counter;
			zombie.push(r);
			metr++;
		}
		tax_sum_left[i]=sum;
	}
	
	metr=0;
    pat* x=new pat;
    x->number=H[N-1];
    x->count=1;
    zombie.push(x);
    metr++;
    sum=H[N-1];	
    tax_sum_right[N-1]=sum;
	//calc sum from the left
	for(long long int i=N-2;i>=0;i--){
		if(H[i]<=H[i+1]){
			sum=sum+H[i];
			pat* q=new pat;
            q->number=H[i];
            q->count=1;
            zombie.push(q);
            metr++;
		}
		else{
			long long int counter=1;
			pat* t=zombie.top();
			long long int n=t->number;
			long long int c=t->count;
			long long int steps=metr;
			while(H[i]>n && steps!=0){ 
				counter=counter+c;
				sum=sum-(c*n);
				zombie.pop();
				metr--;
				steps--;
				if(steps!=0){
				t=zombie.top();
			    n=t->number;
			    c=t->count;}
			}
			sum=sum+(counter*H[i]);
			pat* s=new pat;
            s->number=H[i];
            s->count=counter;
			zombie.push(s);
			metr++;
		}
		tax_sum_right[i]=sum;
	}
	
	
	long long int min_tax;
	for(long long int i=0; i <N;i++){
		long long int f=tax_sum_left[i]-H[i]+tax_sum_right[i];
		if(f<min_tax){
			min_tax=f;
		}
	}
	cout<<min_tax<<"\n";
	return 0 ;
	
}