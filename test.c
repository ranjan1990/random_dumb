#include<stdio.h>
#include<iostream>
#include<omp.h>


using namespace  std;

main()
{


int A[5][10];
for(int j=0;j<4;j++)
{

	for(int i=0;i<10;i++)
	{
		A[j][i]=0;
	}
}



int i,j;
int N=1000000;


#pragma  omp parallel private(i,j)
{
	for(int k=0;k<N;k++)
	{
		i=std::rand()%10;
	 	j=omp_get_thread_num();
		A[j][i]+=1;
	}
}

for(j=0;j<4;j++)
{

	for(i=0;i<10;i++)
	{
		
		cout<<" "<<float(A[j][i])/(N/10);
	}
	cout<<endl;

}


}
