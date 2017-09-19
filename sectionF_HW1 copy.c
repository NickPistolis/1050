#include<stdio.h>
/* Nick Pistolis 9-11-15
	For Some reason when I run the program it will run fine up until 
	I have to type -1 in which the case the program will not shut down until you imput another command after the -1. The same thing is happening for trying to rerun the program without shutting down
*/
	int main(void)
{
	int employeetype=0;
	float  WeeklySales=0;
	float  ComRate=0;
	float  Com=0;
	float NetIn=0;
	int exit =0;
	int score=0;
	
	while(exit!=-1)
	{
		while(score==0)
		{
			printf("Employee type\n (1) Part time\n (2) Full time\n Please make a selection\n");

		
			scanf("%d", &employeetype);

			if(employeetype==1||employeetype==2)
			{

			score=1;

			}
			if(employeetype != 1 && employeetype!=2 )
			{

			printf("invalid choice, make a selection again\n");
			
			}


		}	
	
	
		
		switch ( employeetype )
	{
		case 1:

		printf("Enter the weekly sales\n");

		scanf("%f", &WeeklySales);

		if(WeeklySales <= 10000)
		{
		 ComRate=7;
		}
			else if(WeeklySales <= 20000)
			{
			ComRate= 10;
			}	
				else if(WeeklySales <= 30000)
				{
				ComRate= 15;
				}
					else if(WeeklySales <= 50000)
					{
					ComRate=17;
					}
						else if(WeeklySales>50000)
						{
						ComRate = 20;
						}
		printf("Commission rate is %.2f\n",ComRate);


		Com= WeeklySales*ComRate/100;

		printf("Total commision on sales is %.2f\n" ,Com);

		NetIn= Com + 200;

		printf("Net income is %.2f\n", NetIn);

		printf("If you want to exit type -1\n");

                scanf("%d\n" ,&exit);// I think the mistake is happening here
		       if(exit==-1)
                        {
                                printf("Exiting the sale commission calculator");
                      		 score=1;
			 }			
 			else
			{
			score=0;
			}
		break;

		case 2:
       		 printf("Enter the weekly sales\n");

       		 scanf("%f" ,&WeeklySales);

       			 if(WeeklySales <= 10000)
      			 {
        		 ComRate=5;
       			 }
    	   			 else if(WeeklySales <= 20000)
       				 {
       				 ComRate= 9;
				}
       					 else if(WeeklySales <= 30000)
      			 		 {
      			 		 ComRate= 12;
      					  }
       						 else if(WeeklySales <= 50000)
       						 {
       						 ComRate=15;
      	 					 }
       							 else if(WeeklySales>50000)
       								 {
       								 ComRate = 20;
       								 }
       		 printf("Commission rate is %.2f\n",ComRate);

       		 Com= WeeklySales*ComRate/100;

       		 printf("Total commision on sales is %.2f\n" ,Com);

       		 NetIn= Com + 300;

       		 printf("Net income is %.2f\n", NetIn);
	
		printf("If you want to exit type -1\n");

                 scanf("%d\n" ,&exit);// I think the mistake is happening here
		if(exit==-1)
			{
			        printf("Exiting the sale commission calculator");
		
				score=1;
			}
			else
			{
			score=0;
			}
		break;
		default:
		printf("Please enter a 1 or 2\n");
		scanf("%d\n", &employeetype);
		break;
		
		}
	}
return 0;

}
