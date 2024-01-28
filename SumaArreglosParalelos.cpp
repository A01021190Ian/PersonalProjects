#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#include <iostream>
#include <ctime>   
#include <cstdlib>
using namespace std;

int main()
{   
    double itime, ftime, exec_time;
    int size = 1000;
    int a[size];
    int b[size];
    int c[size];
    int d[size];
    srand(time(0));
    cout<<"\nArray A:\n";
    for(int j=0; j<size; ++j)
    {
        a[j]=rand();
        cout<<a[j]<<" ";
    }
    cout<<"\nArray B:\n";
    for(int k=0; k<size; ++k)
    {
        b[k]=rand();
        cout<<b[k]<<" ";
    }
    itime = omp_get_wtime();
    #pragma omp parallel for
    for(int i=0; i<size; ++i)
    {
        c[i]=a[i]+b[i];
    }
    ftime = omp_get_wtime();
    exec_time = ftime - itime;
    cout<<"\nArray C:\n";
    for(int m=0; m<size; ++m)
    {
       cout<<c[m]<<" ";
    } 
    cout<<"\nWith parallel processing time is: "<< exec_time;
}