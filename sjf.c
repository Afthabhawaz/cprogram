#include<stdio.h>
struct pr
{	
	char nm[10];
	int a;
	int b; 
	int m,tat,wt;	
}s[12],t,sm;

int k,bt,tt;
float avt,avw;
int main()
{
	int i,j,c,n;
	printf("\n enter the no of process");
	scanf("%d",&n);
	printf("enter the process details");
	for(i=0;i<n;i++)
	{
		printf("\n process %d",i+1);
		printf("\nenter process name");
		scanf("%s",s[i].nm);
		printf("\n enter the arrival time");
		scanf("%d",&s[i].a);
		printf("\n enter the burst");
		scanf("%d",&s[i].b);
		s[i].m=0;
	}
	for(i=0;i<n-1;i++)
		for(j=0;j<n;j++)
		{
			if(s[i].b>s[j].b)
			{
				t=s[j];
				s[j]=s[i];
				s[i]=t;
			}
		}
	c=small(n,s);
	s[c].tat=s[c].b;
	s[c].wt=0;
	printf("scheduling:\n\n");
	printf("name arrtime bursttime waittime turaroundtime\n");
	printf("%s",s[c].nm);
	printf("%d %d %d %d \n ",s[c].a,s[c].b,s[c].wt,s[c].tat);
	int d=s[c].a;
	bt=s[c].b;
	avt=s[c].b;
	avw=s[c].wt;
	s[c].m=++k;
	int f=0;
	while(k<n)
	{
		for(i=0;i<n;i++)
		{
			if((s[i].a<=bt)&&(s[i].m==0))	
			{
				printf("%s",s[i].nm);
				s[i].m=++k;
				s[i].wt=bt-s[i].a+d;
				if(s[i].wt<0)
				s[i].wt=0;
				bt+=s[i].b;
				s[i].tat=s[i].b+s[i].wt;
				avt+=s[i].tat;
				avw+=s[i].wt;
				printf("\n%d %d %d %d\n",s[i].a,s[i].b,s[i].wt,s[i].tat);
				f=1;
			}
		}
		if(f=0)
		{
			c=small(n,s);
			if(c==-1)
			break;
			printf("%s",s[c].nm);
			s[c].m=++k;
			s[c].wt=bt-s[c].a+d;
			if(s[c].wt<0)
				s[c].wt=0;
				bt+=s[c].b;
				s[c].tat=s[c].b+s[c].wt;
				avt+=s[c].tat;
				avw+=s[c].wt;
				printf("\n %d %d %d %d \n",s[c].a,s[c].b,s[c].wt,s[c].tat);
		}
	}
		avw/=n;
		avt/=n;
		printf("\n navg waiting time=%f",avw);
		printf("\n navg turnaroundtime=%f\n",avt);

	}
	int small(int n,struct pr s[])
	{
		int i,j=-1;
		for(i=0;i<n;i++)
		{
			if(s[i].m==0)
			{
				sm=s[i];
				j=i;
				break;
			}
		}
		for(i=0;i<n;i++)
		{
			if((s[i].a<sm.a)&&(s[i].m==0))
			{
				sm=s[i];
				j=i;
			}
		}
		return j;
}
		