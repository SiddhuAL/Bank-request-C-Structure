#include<stdio.h>

struct customer 
{
	int acc;
	char name[51];
	int bal ;
} bank[10];

int trans(int acc,int req,int amount,struct customer bank[10])
{
	for(int i=0;i<10;i++)
	{
		if(bank[i].acc==acc)
		{
			if(req == 0)
			{
				bank[i].bal+=amount;
				printf("\nTHE BALANCE OF %s AFTER TRANSACTION IS %d",bank[i].name,bank[i].bal);
				return 1;
			}
			else 
			{
				if(bank[i].bal<amount)
				{
					return 0;
				}
				else
				{
					bank[i].bal-=amount;
					printf("\nTHE BALANCE AFTER TRANSACTION IS %d",bank[i].bal);
					return 1;
				}
			}
			break;
		}
	}	
}

int main()
{
	int n;
	printf("Welcome.....\n");
	printf("Enter how many customers are there in the bank :");
	scanf("%d",&n);
	printf("Start entering values for %d customers :\n",n);
	
	for(int i=0;i<n;i++)
	{
		int q=0;
		printf("\nFor customer %d :",i+1);
		printf("\n\tEnter Name of the customer :");
		scanf(" %s",bank[i].name);
		while(q==0)
		{
		printf("\tEnter account number :");
		scanf("%d",&bank[i].acc);
		printf("\tEnter the balance :");
		scanf("%d",&bank[i].bal);
		if(bank[i].acc<=0||bank[i].bal<0)
		{
		printf("\n\tINVALID INPUTS\n");
		q=0;
		}
		else 
		q=1;
		}
	}
	printf("\nValues are successfully taken....\n");
	int req,amount,acc,p=0;
	char ans = 'y';
	while(ans=='y'||ans=='Y')
	{
	printf("\nEnter your request :\n*PRESS O FOR DEPOSIT*\n*PRESS 1 FOR WITHDRAWAL*\n Enter here :");
	scanf("%d",&req);
	p=0;
	while(p==0)
	{
		if(req==0)
		{
			printf("\nEnter the amount you want to deposit :");
			scanf("%d",&amount);
			printf("Enter the account number : ");
			scanf("%d",&acc);
			p=1;
		}
		else if(req==1)
		{
			printf("\nEnter the amount you want to withdrawal :");
			scanf("%d",&amount);
			printf("Enter the account number : ");
			scanf("%d",&acc);
			p=1;
		}
		else 
		{
			printf("\nWRONG INPUT..\n");
			p=0;
		}
	}
	trans(acc,req,amount,bank);
	printf("\n\nDo you wanna continue requesting :");
	scanf(" %c",&ans);
	}
	
	return 0;
}


