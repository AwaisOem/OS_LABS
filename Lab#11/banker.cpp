#include<iostream>
using namespace std;
int main()
{
	int i,j,p,r,all[3][3],max[3][3],avail[3],need[3][3];
	cout<<"\t Enter the number of process: ";
	cin>>p;
	cout<<"\n\t Enter the number of resources: ";
	cin>>r;
	cout<<"\n\tEnter the allocation table:\n";
		for(i=0;i<p;i++)
		{
			cout<<"\tEnter the detail for process p"<<i+1<<"\n";
			for(j=0;j<r;j++)
			{
				cout<<"\t\tEnter resources R"<<j+1<<"\t";
				cin>>all[i][j];
			}
		}
	cout<<"\tEnter the max table: \n";
	for( i=0;i<p;i++)
	{
		cout<<"\tEnter the detail for process p"<<i+1<<"\n";
		for(j=0;j<r;j++)
		{
			cout<<"\t\tEnter resources R"<<j+1<<"\t";
			cin>>max[i][j];
		}
	}

	cout<<"\tEnter the available table: \n";
	for( i=0;i<r;i++)
	{
		cout<<"\t\tEnter resources R"<<i+1<<"\t";
		cin>>avail[i];
	}
	cout<<"The Remaining Needs Are :\n";
	cout<<"\t";
	for( i=0;i<r;i++)
	{
		cout<<"\tR"<<i+1<<"  ";
	}
	cout<<"\n";
	for( i=0;i<p;i++)
	{
		cout<<" process p"<<i+1<<"  ";
		for(j=0;j<r;j++)
		{
			need[i][j]=max[i][j]-all[i][j];
			cout<<need[i][j]<<"  ";
		}
		cout<<"\n";
	}
	for(i=0;i<p;i++)
		for(j=0;j<r;j++)
			if(need[i][j]<0)
				cout<<"\n\n\t\t The Process P "<<i+1<<" is in UnSafe State:"<<endl;
			else
				cout<<"\n\n\t\t The Process P "<<i+1<<" is in Safe State:"<<endl;
return 0;
}