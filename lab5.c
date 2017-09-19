#include<stdlib.h>
#include<stdio.h>

typedef enum
{
    PENNY=1;
    NICKEL=5;
    DIME=10;
    QUARTER=25;
}Denomination;
typedef struct
{
    Denomination denomination;
    int quantity;
}Coin;
typedef Coin* PiggyBank;

int main(int argc, char* argv[])
{
    FILE fp=fopen(argv[1],"r");
    int lenPtr;
    fscanf(fp,"%d",&lenPtr);
    PiggyBank=malloc(sizeof(Coin)*lenPtr);
    PiggyBank=loadBank(argv[1],&lenPtr);
    totalMoney(PiggyBank,lenPtr);


}
PiggyBank loadBank(const char* filename, int* lenPtr)
{
    PiggyBank bank=malloc(sizeof(PiggyBank)**lenPtr);
    int count=0;
    for(count=0;count<*lenPtr;count++)
    {

    }
}


    
