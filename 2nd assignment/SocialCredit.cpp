#include <iostream>
#include <vector> 
using namespace std;

long long int ceilElement(long long int a[],long long int start,long long int end,long long int key){
    while(end-start > 1){
        long long int mid = start +(end - start)/2;
        if(a[mid]>=key){
            end = mid;
        }
        else{
            start = mid;
        }
    }
    return end;
}

long long int floorElement(long long int a[],long long int start,long long int end,long long int key){
    while(end-start > 1){
        long long int mid = start +(end - start)/2;
        if(a[mid]<=key){
            end = mid;
        }
        else{
            start = mid;
        }
    }
    return end;
}

long long int lis(long long int input[],long long int size)
{
    if(size==0)
        return 0;
  
    long long int a[size];
    long long int length=1;
  
    a[0] = input[0];
  
    for(long long int i=1; i<size; i++)
    {
        if(input[i]< a[0]){
            a[0]=input[i];
        }
        else if(input[i]>a[length-1]){
            a[length++]=input[i];
        }
        else
            a[ ceilElement(a,0,length,input[i]) ]= input[i];
    }
    return length;
}

long long int lds(long long int input[],long long int size)
{
    if(size==0)
        return 0;
  
    long long int a[size];
    long long int length=1;
  
    a[0] = input[0];
  
    for(long long int i=1; i<size; i++)
    {
        if(input[i]>a[0]){
            a[0]=input[i];
        }
        else if(input[i]<a[length-1]){
            a[length++]=input[i];
        }
        else
            a[ floorElement(a,0,length,input[i]) ]= input[i];
    }
    return length;
}

int main() {
    long long int N;
    cin >> N;
    long long int S[N];
    long long int rev_S[N];
    long long int A[N],B[N];
    for (long long int i = 0; i < N; i++) {
        long long int si;
        cin >> si;
        S[i] = si;
    }
    for (long long int i=0; i<N; i++){
        A[i]=lis(S,i+1);
    }
    for (long long int i = 0; i <N ; i++) {
        rev_S[i]=S[N-i-1];
    }
    for (long long int i=0; i<N;i++){
        B[i]=lds(rev_S,i);
    }

    long long int max=A[1]+B[N-1];
    for(long long int i=0; i<N; i++){
        long long int temp=A[i]+B[N-1-i];
        if(temp>max){
            max=temp;
        }
    }
    cout<<max<<"\n";
    
    return 0;
}