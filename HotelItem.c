#include<stdio.h>
#include<conio.h>
#include<string.h>
#include"htlmgr.h"
#include"cltmgr.h"


hmgr items[100];
int ic ;


void filetoarray()

{

FILE *p ;
hmgr litem ;

p=fopen(hfile,"rb");

ic=0;

while(fread(&litem,sizeof(hmgr),1,p))
{
items[ic].code=litem.code;
strcpy(items[ic].name,litem.name);
items[ic].price=litem.price ;
items[ic].qty=litem.qty;
items[ic].txn=litem.txn ;
ic++;
}
fclose(p);

}

void AddItem()
{

hmgr item ;
int i ;    
FILE *p ;

filetoarray() ;

p=fopen(hfile,"ab");

printf("\n Enter Food code : ");
scanf("%d",&item.code);
fflush(stdin);
for(i=0;i<ic;i++)
{

if(items[i].code==item.code)
{
printf("\n Item code %d. %s already avaliable",items[i].code,items[i].name);
return;
}
}

printf("\n Eneter Food Name : ") ;
gets(item.name);

for(i=0;i<ic;i++)
{
if(strcmp(items[i].name,item.name)==0)
{

printf("\n Item name (%s) already Exist ! ",item.name);
return;
}
}
printf("\n Enter the price of Food : " );
scanf("%f",&item.price);
fflush(stdin);

printf("\n Enter the Quantity of Food : " );
scanf("%d",&item.qty);
fflush(stdin);
item.txn='C';
fwrite(&item,sizeof(hmgr),1,p);
fclose(p);

}

void ViewItem()

{


hmgr litem ;
FILE *p ;

p=fopen(hfile,"rb");


printf("\n Item.code  Name              Price     Quantity\n "); 
while(fread(&litem,sizeof(hmgr),1,p))
{

printf("\n %-9d  %-16s  %-8.2f    %d",litem.code,litem.name,litem.price,litem.qty);
}

printf("\n");
fclose(p);

}


void ViewTxn()

{
int i=0 ;
float income;
FILE *o;
CD cus;
o=fopen(cfile,"rb");
income=0;
printf("\n S.NO  Customer.Name     Paid ");
printf("\n ----- ----------------  ----- \n");
while(fread(&cus,sizeof(CD),1,o))
{
printf("\n %-4d  %-16s  %-4.2f RS ",i+1,cus.name,cus.billamt);

i++;
income+=cus.billamt;
}
printf("\n                         -------");
printf("\n                   TOTAL %-4.2f RS",income); 
printf("\n                         -------");            
fclose(o);
}

