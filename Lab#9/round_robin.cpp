#include<iostream>
using namespace std;
struct p
{
	int AT;
	int processno;
	int cpuburst;
	int complationtime;
	int turnaround;
};
int main()
{
	p arr[5];
	int i=0;
	p newi[5];
 int j;
	 int total=0;   //  Cpu burst by user......
 	int x;
	{   cout<<endl;
            cout<<endl;
	cout<<"\t\t..........WELCOME TO ROUND ROBIN ALGO..........."<<endl;
           cout<<endl;
            cout<<endl;
            cout<<endl;
	}
for( i=0;i<5;i++)
	{
			cout<<"\t\tEnter process no "<<i<<" :";
			cin>>arr[i].processno;
			cout<<"\t\tEnter cpu burst for :";
			cin>>arr[i].cpuburst;
			cout<<"\t\tEnter arrival time for :";
			cin>>arr[i].AT;
			cout<<"\t\t.............................................."<<endl;
			cout<<endl;    
		}//end
		cout<<endl;
		cout<<endl;
		cout<<endl;
		 for(i=0;i<5;i++)
		 {     
 total=arr[i].cpuburst+total;
		   }// Find total cpu burst.....    
	 	int complete=0;
		newi[0]=arr[0];
		newi[1]=arr[0];
		i=0; x=0;
		{			
			
	    	do
			{
				for(j=0;j<5;j++)
				{
					if(newi[j].cpuburst==0)
					{   
						 complete=complete+0;
					}
					else if(newi[j].cpuburst -1==0)
					{
					newi[j].cpuburst=newi[j].cpuburst-1;
					complete=complete+1;
					newi[j].complationtime=complete;
					
					}
					else if(newi[j].cpuburst -2==0)
					{
					newi[j].cpuburst=newi[j].cpuburst-2;
					complete=complete+2;
					newi[j].complationtime=complete;
					}
				else
				{
					newi[j].cpuburst=newi[j].cpuburst-3;
					complete=complete+3;
					newi[j].complationtime=complete;
				}
 				if(i==4)
				{
newi[i-4]=arr[x+1];
					i++;
				}//  last cheker......................
				if(complete>=arr[x+1].AT && i<4)
				{
					while(complete>=arr[x+1].AT && i<4)
					{
						newi[i+1]=arr[x+1];
						i++; x++;
					}
					if(i==4)
					{newi[i-4]=arr[x+1];
					}
					else
					{
						newi[i+1]=newi[j];
						i++;
					}
				}//end of if/////
				}//end for
			}while(total>complete);//end of complete while...
			

}
for(i=0;i<5;i++)
{	newi[i].turnaround=newi[i].complationtime-newi[i].AT;
}
{
 cout<<" PROCESS #:"<<"\tCPU BURST"<<"\tARRIVAL TIME"<<"\tTURN ARONUD TIME"<<endl;
}
for(i=0;i<5;i++)
{
cout<<"P"<<newi[i].processno<<":"<<"\t\t"<<newi[i].cpuburst<<"\t\t"<<newi[i].AT<<"\t\t"<<newi[i].turnaround<<endl; 				
}
}