#include<stdio.h>
#include<conio.h>
#include<string.h>
#include"htlmgr.h"
#include"cltmgr.h"


hmgr items[50];
int itemcount;
hmgr oitem[20];
float amount[20];
int oc;

void initialize()

{

FILE *p ;
hmgr litem ;

p=fopen(hfile,"rb");

itemcount=0;

while(fread(&litem,sizeof(hmgr),1,p))
{
items[itemcount].code=litem.code;
strcpy(items[itemcount].name,litem.name);
items[itemcount].price=litem.price ;
items[itemcount].qty=litem.qty;
items[itemcount].txn=litem.txn ;
itemcount++;
}
fclose(p);

}

void ViewItems()
{
FILE *p ;
hmgr litem ;
p=fopen(hfile,"rb");
printf("\n Item.code  Name              Price\n "); 
while(fread(&litem,sizeof(hmgr),1,p))
{
printf("\n %-9d  %-16s  %-5.2f ",litem.code,litem.name,litem.price);
}
printf("\n");

fclose(p);
}

void OrderItem()
{
FILE *o ;
CD cus ;
hmgr fitem ;
char opt;
float amt ;
int i  ;
initialize();
o=fopen(cfile,"ab");
printf("\n Enter your name : ");
gets(cus.name);
cus.billamt=0;
oc=0;
do 
{
system("cls");
printf("\n HI %s Welcome to HOTEL RAJESHWARI\n ",cus.name);
printf("\n Enter Item code : ");
scanf("%d",&fitem.code );
oitem[oc].code=fitem.code ;
fflush(stdin);
if(fitem.code<=itemcount)
{
for(i=0;i<itemcount;i++)
{
if(fitem.code==items[i].code )
{
printf("\n Item Name  : %s ",items[i].name);
strcpy(fitem.name,items[i].name);
strcpy(oitem[oc].name,fitem.name);
printf("\n Item Price : %.2f\n" ,items[i].price);
oitem[oc].price=items[i].price;
printf("\n Enter Quantity : ");
scanf("%d",&fitem.qty);
oitem[oc].qty=fitem.qty ;
fflush(stdin);
amt=fitem.qty * items[i].price ;
amount[oc]=amt;
printf("\n Amount : %.2f RS ",amt);
cus.billamt+=amt;
}
}
}
else
{
printf("\n Invalid Item code .. ");
}
printf("\n Do You want to continue (Y/N) ? ");
opt=getchar();
fflush(stdin);
oc++;
}while(opt=='Y'||opt=='y');
printf("\n Finalized Bill Amount : %.2f RS",cus.billamt);
fwrite(&cus,sizeof(CD),1,o);
fclose(o);
}

void viewTxn()

{

int i ;

float total ;

total=0;

printf("\n Hi Please find your transaction below....\n");

printf("\n S.NO  Item.code  Item.name           QTY  Price(1pcs)  Amount ");
printf("\n ----- ---------  -----------------   ---  -----------  -------");

for(i=0;i<oc;i++)

{

printf("\n %-4d  %-9d  %-18s  %-3d  %-11.2f  %.2f RS",i+1,oitem[i].code,oitem[i].name,oitem[i].qty,oitem[i].price,amount[i]);
total+=amount[i];
}
if(total>0)
{
printf("\n---------------------------------------------------------------");
printf("\n                                            Bill Amount  %.2f RS",total);
printf("\n---------------------------------------------------------------");
}
else
{

printf("\n 'NO TRANSACTION FOUND");
}

}     


int GetItemcode(int itemcode)
{

int i ;

int flag=0 ;

for(i=0;i<itemcount;i++)

{

if(items[i].code==itemcode)

{

flag=1;
break;
}

}

return flag ;

}

