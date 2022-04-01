typedef struct CD 

{

char name[25];
float billamt;

}CD;

void OrderItem() ;
void viewTxn();

int GetItemcode(int itemcode);

char hfile[]="./StockItem.bin";
char cfile[]="./Customerdetails.bin";



