#include<iostream>
#include<cmath>
#include<chrono>
using namespace std;
using namespace std::chrono;
int main()
{
    double primelmt,maxval,count;
    cout<<"Please enter maximum number below which to find primes \n";
    cin>>primelmt;
    maxval=primelmt;
    //maxval=int(sqrt(primelmt));
    //cout<<maxval;
    long unsigned int mv=maxval+1,i,j;
    double numbool[mv];
    for(i=0;    i<=maxval;  i++)
    {
        numbool[i]=1;
    }
    numbool[0]=0;
    numbool[1]=0;
    auto start = high_resolution_clock::now();
    for(i=2;    i<=sqrt(maxval);  i++)
    {
        if(numbool[i]==1)
        {
            for(j=(i+1);    j<=maxval;  j++)
            {
                if((fmod(j,i))==0)
                {
                    numbool[j]=0;
                }
            }
        }
    }
    count=0;
    for(i=2;    i<=maxval;  i++)
    {
        if(numbool[i]==1)
        {
            count++;
            //cout<<i;
            //cout<<"\n";
        }
    }
    auto stop=high_resolution_clock::now();
    for(i=2;    i<=maxval;  i++)
    {
        if(numbool[i]==1)
        {
            //count++;
            cout<<i;
            cout<<"\n";
        }
    }
    //count=0;
    auto duration=duration_cast<microseconds>(stop-start);
    cout<<"The number of primes below ";
    cout<<maxval;
    cout<<" is ";
    cout<<count;
    cout<<"\n";
    cout<<"time for execution is "<<duration.count()<<" microseconds"<<endl;
}