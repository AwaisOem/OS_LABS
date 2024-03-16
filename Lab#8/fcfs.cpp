#include<iostream>
using namespace std;
const int n=5;
class fifo
{
private:
	int cpu[n],arr_t[n],turn_tm[n],wait_tm[n];
	int assign[n],comp[n];
	float avg_turn_aroud_time,avg_waiting_time;
public:
	void get()
	{
		for(int i=0;i<n;i++)
		{
			cout<<"enter the cpu burst of p"<<i<<"\tprocess";
			cin>>cpu[i];
			cout<<"enter the Arrival time of p"<<i<<"process\t";
			cin>>arr_t[i];
			if(i==0)
			{
				assign[i]=arr_t[i];
				comp[i]=arr_t[i]+cpu[i];
			}
			else
			{
				assign[i]=comp[i-1];
				comp[i]=comp[i-1]+cpu[i];
			}
		}
		cout<<"\n==================================================\n";
	}
	void turn_around_time()
	{
		float sum=0;
		for(int i=0;i<n;i++)
		{
			turn_tm[i]=comp[i]-arr_t[i];
			sum=sum+turn_tm[i];
		}
		avg_turn_aroud_time=sum/n;
	}
	void waiting_time()
	{
		float sum=0.0;
		for(int i=0;i<n;i++)
		{
			wait_tm[i]=assign[i]-arr_t[i];
			sum=sum+wait_tm[i];
		}
		avg_waiting_time=sum/n;
	}
	void show()
	{
		cout<<"Process \tcpu burst \tArrival Time\twaiting Time/tturn around time"<<endl;
		for(int i=0;i<n;i++)
		{
	cout<<"p"<<i<<"\t\t"<<cpu[i]<<"\t\t"<<arr_t[i]<<"\t\t"<<wait_tm[i]<<"\t\t"<<turn_tm[i]<<endl;
			cout<<endl;
		}
		cout<<"The average waiting time is ="<<avg_waiting_time;
		cout<<endl;
		cout<<"The average turn around time is ="<<avg_turn_aroud_time<<endl;
	}
};
int main()
{
	fifo f;
	f.get();
	f.waiting_time();
	f.turn_around_time();
	f.show();
	return 0;
}
