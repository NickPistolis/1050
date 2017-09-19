#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int load_data(char*, char**,int*,float*,int);
void print_data(char**,int*,float*,int);
int check_account(char**,int*,char*,int,int);
int string_compare(char*,char*);
int highest_amount(float*,int);
int lowest_amount(float*,int);
float average_amount(float*,int);
void write_data(char*,char**,int*,float*,int,int,int,float);
int main(int argc,char** argv)
{
    if(argc!=4)
    {
	printf("\n Insufficient arguments \n ");
	return 0;
    }

    int n=atoi(argv[2]);

    int *acn,d, choice;
    float *amt, amount;
    int accnum = 0;

    char **name;


    acn=malloc(sizeof(int)*n);	
    amt=malloc(sizeof(float)*n);
    name=malloc(sizeof(char*)*n);
    char *str=malloc(sizeof(char)*n);

    int i;
    for (i=0;i<n;i++)
    {
	*(name+i)=malloc(sizeof(char)*100);
    }


    int size = load_data(argv[1], name, acn, amt, n);

    if(size==0)
    {
	printf("\n Unable to open the input file \n");
	return 0;
    }

    

    print_data(name, acn, amt, n);
    
    printf("\nEnter a name: ");
    scanf("%s", str);
    
    printf("\n");

    printf("Enter an account number: ");
    //scanf("%d", &d);
    scanf("%d", &d);

    if(check_account(name,acn,str,d,n)==-1)
    {
	printf("The user does not have a bank account\n");
    }
    else
    {
    choice=0;
	while(choice!=1||choice!=2)
	{
	printf("Would you like to \n 1) Withdraw \n 2) Deposit \n");
	scanf("%d",&choice);
	}

    int pizza=check_account(name,acn,str,d,n);
    if(choice==1)
    {
	printf("Enter the amount\n");
	scanf("%f", &amount);
    int size=load_data(argv[1], name, acn, amt, n);
	if(*(amt+pizza)<amount)
	{
	    printf("Not enough money in the account\n");
	}
    }
    if(choice==2)
    {
	printf("Enter the amount\n");
	scanf("%f",&amount);
	*(amt+pizza)+=amount;
    }

    }	
    int index= highest_amount(amt, n);

    printf("\n%s has the highest amount $%.2f in the account number %d \n", *(name+index),*(amt+index),*(acn+index));

    int index2= lowest_amount(amt, n);

    printf("%s has the lowest amount $%.2f in the account number %d \n", *(name+index2),*(amt+index2),*(acn+index2));

    float avg= average_amount(amt, n);

    printf("The average amount is $%.2f \n", avg);

    write_data(argv[3],name, acn, amt, n, index, index2,avg );							    

    free(acn);
    free(amt);

    for (i=0;i<n;i++)
    {
	free(*(name+i));
    }

    free(name);

    return 0;
}


int load_data(char* filename, char **name, int *x , float *y, int size)
{
    int i=0;
    FILE* file=fopen(filename,"r");
    if(file==NULL)
    {
	return 0;
    }


    int id ;
    float amt;
    char n[100];
    printf("%d", size);
    for(i=0;i<size;i++)
    {
	fscanf(file,"%s %d %f",n,&id,&amt);

	strcpy(*(name+i),n);
	*(x+i)=id;
	*(y+i)=amt;


    }


    fclose(file);
    return 1;				

}
void print_data(char**name,int*acn,float*amt,int n)
{
    int count=0;
    printf("Name\tAccount No.\tAmount\n");
    
    for(count=0;count<n;count++)
    {
	printf("%s\t%d\t%.2f\n",*(name+count),*(acn+count),*(amt+count));
    }
    
}

int check_account(char** name,int* acn,char* string,int account,int length)
{
    printf("we get here");
    int count=0;
    while(string_compare(*(name+count),string)==0)
	count++;
    if(*(acn+count)==account)
	return count;
    
    return -1;



}
int string_compare(char* name1,char* name2)
{
    printf("we get here");
    int count=0;
    while(*(name1+count)!='\0' && *(name2+count)!='\0')
    {
	if(*(name1+count)==*(name2+count))
	{
	    if(*(name1+count)=='\0')
	    {
		return 1;
	    }
	    else
		count++;
	}
    }
    return 0;
}
int highest_amount(float* amt,int n)
{
    int count=0;
    int max=1;


    for(count=0;count<n-1;count++)
    {
	if(*(amt+count)>*(amt+max))
	{
	    max=count;
	}
    }
    return max;
}
int lowest_amount(float* amt,int n)
{
    int count=0;
    int min;

    for(count=0;count<n-1;count++)
    {
	if(*(amt+count)<*(amt+min))
	{
	    min=count;
	}
    }
    return min;
}
float average_amount(float* amt,int n)
{
    int count;
    float sum;
    for(count=0;count<n;count++)
    {
	sum=sum+*(amt+count);
    }
    return sum/count;
}
void write_data(char* filename,char** name,int* acn,float* amt,int Numacc,int index1,int index2,float average)
{
    FILE* file=fopen(filename,"w+");
    int count;
    for(count=0;count<Numacc;count++)
    {
	fprintf(file,"%s\t%d\%.2f\n",*(name+count),*(acn+count),*(amt+count));
    }
    fprintf(file,"\n\n\n %s has the highest amount %.2f in the account number %d\n %s has the lowest amount %.2f in the account number %d\n the average amount is %.2f",*(name+index1),*(amt+index1),*(acn+index1),*(name+index2),*(amt+index2),*(acn+index2),average);
    fclose(file);
}

