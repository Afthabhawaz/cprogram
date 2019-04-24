#include<stdio.h>
struct process
{
	int artime;
	int burst;
	char name[20];
	int wait;
	int ttime;
}a[10],temp;

int main()
{
	int n,i,j,waitsum=0,bstsum;
	float avgwait,avgttime;

	printf("\n enter the no of process");
	scanf("%d",&n);
	printf("\n enter the process details(name,cpu burst,arrival time)");
	for(i=0;i<n;i++)
	{
		printf("\n process %d",i+1);
		printf("\n enter the process name");
		scanf("%s",a[i].name);
		printf("\n enter the cpu burst");
		scanf("%d",&a[i].burst);
		printf("\n enter the arrival time");
		scanf("%d",&	a[i].artime);
	}
	for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++)
				if(a[i].artime>a[j].artime)
				{
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
	avgttime=0;
	a[0].ttime=a[0].burst;
	bstsum=a[0].burst;
	a[0].wait=0;
	for(i=1;i<n;i++)
	{
		a[i].wait=bstsum-a[i].artime;
		waitsum+=a[i].wait;
		bstsum+=a[i].burst;
		a[i].ttime=a[i].wait+a[i].burst;
	}
	avgwait=(float)waitsum/n;
	printf("\n\tprocess\tarrival time\tburst\t turn around time\n ");
	for(i=0;i<n;i++)
	{
		printf("\n\t%s \t\t%d \t%d \t%d\n",a[i].name,a[i].artime,a[i].burst,a[i].ttime);		
		avgttime+=a[i].ttime;

	}
	avgttime=(float)avgttime/n;
	printf("\n avg turn around time is %f",avgttime);
	printf("\n avg waiting time %f\n",avgwait);
	return(0);	

}