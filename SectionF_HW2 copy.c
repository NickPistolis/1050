
#include<stdio.h>
int checkID(int stuInfo[6][2],int IDEntered);
void processUndergrad(float billInfo[6][3],int IDEntered,int rowNumber);
void processGrad(float billInfo[6][3],int ID,int rowNumber);
void processPHD(float billInfo[6][3],int IDEntered,int rowNumber);
int checkHours(int hours,int type);
void processFinalReport(int stuInfo[6][2],float billInfo[6][3]);
int main()
{
    
	    int IDEntered;
	    int exit=1;
	    int stuInfo[6][2]={{394003920,2},{388920394,3},{499230076,1},{298760112,2},{592493811,3},{355982306,3}};
	    float billInfo[6][3]={{0.0,0.0,0.0},{0.0,0.0,0.0},{0.0,0.0,0.0},{0.0,0.0,0.0},{0.0,0.0,0.0},{0.0,0.0,0.0}};
	    while(exit==1)
     {
		        printf("Please enter the ID: ");
	        	scanf("%d",&IDEntered);
	     if(checkID(stuInfo,IDEntered)==-1)
	    {
		 while(checkID(stuInfo,IDEntered)==-1)
		 {
		     printf("Please Enter a valid ID");
		     scanf("%d",&IDEntered);
		 }
	    }

		    int rowID = checkID(stuInfo, IDEntered);

		switch(stuInfo[rowID][1])
		{
		    case 1: processUndergrad(billInfo,IDEntered,rowID);
		    break;
		    case 2: processGrad(billInfo,IDEntered,rowID);
		    break;
		    case 3: processPHD(billInfo,IDEntered,rowID);
		    break;
		}
		processFinalReport(stuInfo,billInfo);
		printf("Do you want to continue for the next student? If yes hit 1 else hit 0:\n");
		scanf("%d",&exit);
       
	}
	    return 1;
}
int checkID(int stuInfo[6][2],int IDEntered)
{
    int count;

    for(count=0;count<6;count++)
    {
	if(stuInfo[count][0]==IDEntered)
	{
	    return count;
	}

    }
    return -1;
}
void processUndergrad(float billInfo[6][3],int IDEntered,int rowID)
{
    int hours;
    float amount;
    printf("Enter the number of credit hours");
    scanf("%d",&hours);
    while(hours<=3 || hours >=18)
    {
	printf("Undergrads must be enrolled in 3-18 hours. Enter again:");
	scanf("%d",&hours);
    }
    printf("Enter the scholarship amount:");
    scanf("%f",&amount);
    while(amount>.5*750*hours)
    {
	printf("Scholarships can not be greater than 50 percent of the tution. Enter the correct amount again\n");
	scanf("%f",&amount);
    }
    billInfo[rowID][0]=750*hours;
    billInfo[rowID][1]=amount;
    billInfo[rowID][2]=billInfo[rowID][0]-billInfo[rowID][1];
}
void processGrad(float billInfo[6][3],int IDEntered,int rowID)
{
    int hours;
    float amount;
    printf("Enter the number of credit hours");
    scanf("%d",&hours);
    while(hours<=3 || hours>=12)
    {
	printf("Grads must be enrolled 3-12 hours. Enter again:");
	scanf("%d",&hours);
    }
    printf("Enter the scholarship amount:");
    scanf("%f",&amount);
    while(amount>.75*1000*hours)
    {
	printf("Scholarships can not be greater than 75 percent of the tution. Enter the correct amount again\n");
	scanf("%f",&amount);
    }
    billInfo[rowID][0]=1000*hours;
    billInfo[rowID][1]=amount;
    billInfo[rowID][2]=billInfo[rowID][0]-billInfo[rowID][1];
}
void processPHD(float billInfo[6][3],int IDEntered,int rowID)
{
    int hours;
    float amount;
    printf("Enter the number of credit hours");
    scanf("%d",&hours);
    while(hours<=3 || hours>=9)
    {
	printf("PHD students must be enrolled in 3-9 hours. Enter again:");
	scanf("%d",&hours);
    }
    printf("Enter the scholarship amount");
    scanf("%f",&amount);
    while(amount>10000)
    {
	printf("Scholarships can not be greater than 10,000 dollars. Enter the correct amount again\n");
	scanf("%f",&amount);
    }
    billInfo[rowID][0]=1200*hours;
    billInfo[rowID][1]=amount;
    billInfo[rowID][2]=billInfo[rowID][0]-billInfo[rowID][1];

}
void processFinalReport(int stuInfo[6][2],float billInfo[6][3])
{
    int count;

	for(count=0;count<6;count++)
	{
	    if(billInfo[count][0]!=0)
	    {
		if(stuInfo[count][1]==1)
		{
		    printf("Undergrad student %d tuition is:\n",stuInfo[count][0]);
		    printf("Gross                     %.2f\n",billInfo[count][0]);
		    printf("Scholarship amount        %.2f\n",billInfo[count][1]);
		    printf("Total Tuition Bill        %.2f\n",billInfo[count][2]);
		}
		else if(stuInfo[count][1]==2)
		{
		    printf("Grad student %d tution is:\n",stuInfo[count][0]);
		    printf("Gross                     %.2f\n",billInfo[count][0]);								    
		    printf("scholarship amount       %.2f\n",billInfo[count][1]);
		    printf("Total Tuition Bill        %.2f\n",billInfo[count][2]);
		}
		else if(stuInfo[count][1]==3)
		{
		    printf("PHD student %d tuition is:\n",stuInfo[count][0]);
		    printf("Gross                     %.2f\n",billInfo[count][0]);
                    printf("Scholarship amount        %.2f\n",billInfo[count][1]);
	            printf("Total Tuition Bill        %.2f\n",billInfo[count][2]);
	        }

	    }
    }
}
