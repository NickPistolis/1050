// Nick Pistolis Prelab 6
// Turning Lab 3 into Functions
//
#include<stdio.h>

void display_option();
int check_option(int);
int check_year(int);
int check_amount(float);


int main()
{
    int option;
    int year;
    float amount;

    display_option();
    scanf("%d",&option);

    while(check_option(option)==0)
    {
	printf("invalid choice\n");
	display_option();
	scanf("%d",&option);
    }
    printf("Please enter a year\n");
    scanf("%d",&year);
    while(check_year(year)==0)
    {
	printf("Incorrect value of year enter the year again\n");
	scanf("%d",&year);


    }
    printf("Please enter an amount\n");
    scanf("%f",&amount);
    while(check_amount(amount)==0)
    {
	printf("incorrect amount please enter amount again\n");
	scanf("%f",&amount);
    }

    if(option==1)
    {
	printf("Account selected is checking\n Year entered is %d years\n Amount entered is %.2f dollars",year,amount);
	return 0;
    }
    else if(option==2)
    {
	printf("Account selected is savings\n Year entered is %d years\n Amount enter is %.2f dollars",year,amount);
	return 0;
    }
    else if(option==3)
    {

	printf("Account selected is Fixed Deposit\n Year entered is %d years\n Amount enter is %.2f dollars",year,amount);
	return 0;
    }
    return 0;


}


void display_option()
{
    printf("Bank account type\n (1) Checking\n (2) Saving\n (3) Fixed deposit\n");
}
int check_option(option)
{
    if(option>3 || option<1)
    {

	return 0;

    }
    return 1;
}
int check_year(year)
{
    if(year>10 || year<1)
	{
	
	    return 0;
	}
    return 1;
}
int check_amount(float amount)
{
    if(amount<0)
    {
    
	return 0;
    }
    return 1;
}
