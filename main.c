#include<stdio.h>
#include<conio.h>

int main()

{


int opt ;


while(1)

{

system("cls");
printf("\n                   HOTEL STOCK MANAGER          ");
printf("\n                   -------------------          ");
printf("\n S.N  Activity ");
printf("\n ---  --------\n" );
printf("\n 1.  ADD ITEMS ");
printf("\n 2.  VIEW ITEMS ");
printf("\n 3.  VIEW TRANSACTIONS");
printf("\n 4.  EXIT");

printf("\n\n Enter Option :  ");
scanf("%d",&opt);
fflush(stdin);
switch(opt)
{

case 1 : 
AddItem();
break ;

case 2 : 
ViewItem();
break ;

case 3 : 
ViewTxn();
break ;

case 4 : 
return;
break ;

default :
printf("\n Invalid option selected Pleas try again !"); 
break ;

}
printf("\n\n  Press a Key to continue............");
getchar();
}


}

