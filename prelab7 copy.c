#include<stdio.h>
#include<time.h>
#include<stdlib.h>

    int check_error(int);
    void create_array(int[],int);
    void print_array(int[],int);

int main()
{  
    srand(time(NULL));
    int A[100];
    int size;
    printf("Enter the size of the input");
    scanf("%d",&size);
    while(check_error(size)==0)
    {
	printf("Invalid input enter the size of the input again");
	scanf("%d",&size);
    }
    create_array(A,size);
    print_array(A,size);
    return 0;
}
int check_error(size)
{
    if(size<=100)
    {
	return 1;
    }
    return 0;
}
void create_array(int A[],int size)
{
    int count;
  // srand(time(NULL)); 
    for(count=0;count<size;count++)
    {
	A[count]=rand()%10;
    }

}
void print_array(int A[],int size)
{
    int count;
    for(count=0;count<size;count++)
	{
	    printf("%d\n",A[count]);
	}
}

