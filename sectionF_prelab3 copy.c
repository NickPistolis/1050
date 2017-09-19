#include<stdio.h>

	int main(void)
{
int length=1;
int radius=1;
int choice=1;
int score=0;
int numcheck=0;
int area=0;
	while(choice>=1 && choice<=3)
	{
		printf("Area calculation\n(1) Square\n(2) Cube\n(3) Circle\n Please make a selection:");
		scanf("%d",&choice);
	while(choice<1 || choice>3)
	{
	printf("invalid choice\n");
	scanf("%d",&choice);
	}	
	
		switch(choice)
		{
			case 1:
			score=1;
			while(numcheck==0)
			{
				printf("Please enter a positive number\n");
				scanf("%d",&length);
				if(length>0)
				{
				numcheck=1;
				printf("The length of the square is:%d\n",length);
				area=length*length;
				printf("The area of the square is %d\n",area);
				}
				else
				{
				numcheck=0;
				}
			choice=0;
			break;
			}

			 case 2:
			score=1;
                        while(numcheck==0)
                        {
                                printf("Please enter a positive number\n");
                                scanf("%d",&length);
                                if(length>0)
                                {
                                numcheck=1;
                                printf("The length of a side of a cube is:%d\n",length);
                                area=6*length*length;
                                printf("The area of the cube is %d\n",area);
                                }
                                else
                                {
                                numcheck=0;
                                }
			choice=0;
			break;
                        }

			 case 3:
			score=1;
                        while(numcheck==0)
                        {
                                printf("Please enter a positive number\n");
                                scanf("%d",&radius);
                                if(radius>0)
                                {
                                numcheck=1;
                                printf("The radius of the cirle is:%d\n",radius);
                                area=3.14159*radius*radius;
                                printf("The area of the circle is: %d\n",area);
                                }
                                else
                                {
                                numcheck=0;
                               	}
			choice=0;
			break;
                        }
			
				
				
						


		}	
	


	}


return 0;
}
