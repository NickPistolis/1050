#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void display_option();
int check_option(int);
int generate_number(void);
float division(int ,int);

int main(void)
{
    srand(time(NULL));
    int x,z;
    int y;
    int exit=0;
    x=generate_number();
    z=generate_number();
    while(exit==0)
    {
	     display_option();
	     scanf("%d",&y);
	     if(check_option(y)==1)
		 {
		     exit=1;
		 }
	     else if(check_option(y) == 0)
		 {
		     printf("invalid choice, please try again\n");
		 }
    }
    if(y==1)
    {
	printf("The cube of %d is %d",x,cube(x));
	return 0;
    }
    if(y==2 && x>=z)
    {
	printf("%d divided by %d is %.2f\n",x,z,division(x,z));
    }
    else if( y==2 && z>=x)
    {
     printf("%d divided by %d is %.2f\n",z,x,division(z,x));
    }
return 0;
}

    void display_option(void)
    {
	 printf("Please select an operation\n 1 : Cube\n 2 : Division\n");

    }
    int check_option(int y)
    {
	if(y==1 || y==2)
	{
	     return 1;
	}
	else
	{
    
	     return 0;
	}
    }
    int generate_number(void)
    {
    return rand()%10;
    }
    int cube(int x)
    {
	int answer=x*x*x;
	return answer;
    }
    float division(int x,int z)
    {
	float answer;
	 if(x==0 || z ==0)
        {
	    return 0;
        }
	 else if(x>=z)
	{
	    answer=(float)x/(float)z;
	    return answer;
        }
	else if(z>=x)
	{
	    answer=(float)z/(float)x;
	return answer;
	}
    
    }   

