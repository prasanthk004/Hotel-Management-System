#include<stdio.h>
#include<conio.h>
int main()

{
    int opt;
    while(1)
    {
    system("cls");
    
    printf("\n\n Hi Welcome to   ") ; 
    printf("\n  HOTEL RAJESHWARI ") ;
    printf("\n -----------------\n");
    
    printf("\n Option   Activity ");
    printf("\n ------   --------\n ");
    
    printf("\n  1       VIEW ITEMS");
    printf("\n  2       ORDER FOOD ");
    printf("\n  3       View Transactions");
    printf("\n  4       EXIT ");
    
    printf("\n\n Please select option : ");
        scanf("%d",&opt);
        fflush(stdin);
    switch(opt)
        {
        case 1: 
        ViewItems();
        break;

        case 2:
        OrderItem();
        break;

        case 3:
        viewTxn() ;
        break;

        case 4: 
            return ;
        break;

        default :
         printf("\n Invalid Option Selected ....");
        break ;
        }
        printf("\n\n Please Enter a Key to continue.......");
        getchar();
      }
}

