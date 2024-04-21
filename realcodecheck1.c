#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//
// float Balance(struct node** acc_address,int pin);  // peek operation in dll
// void Deposit(struct node** acc_address,int pin,int deposit);   // add new node and get data from privious node and add the given amount to the data and store it in data of new node
// void Withdraw(struct node** acc_address,int pin,int Withdraw);  //add new node and get data from privious node and substract the given amount to the data and store it in data of new node
// void Last_Transactions(struct node** acc_address,int pin); // store the data the stack and the pop out the data {this function shows the property of stack in the showing the balance of perticular user}
// void newuser_details(int ATM_number, int pin);//triply linked list havind 2 linked pd node type and 1 node of single_node type and havind two data first ATM_number and second pin
// void newnode(struct single_node **top,int D_W);// it has two data first D_W and second is current and have  one link next to connecct privious node
//
//
struct single_node
{
  float D_W;
  float current;
  struct single_node *next;
};

struct node
{
  long int ATM_number;
  int pin;
  struct node *prv;
  struct node *next;
  struct single_node *transactionlog;
};
struct node *head=NULL;
struct node *top=NULL;

void balance_node(struct node** account_address,float D_W)
{

  struct single_node **head_bal=&((*account_address)->transactionlog);
  struct single_node *new_node;
  new_node=(struct single_node*)malloc(sizeof(struct single_node));
  if(new_node==NULL)
  {
    printf("Memory allocation fails.\n");
    return;
  }
  else if ((*head_bal)==NULL)
  {
    new_node->D_W=D_W;
    new_node->current=D_W;
    new_node->next=NULL;
    (*head_bal)=new_node;
  }
  else
  {
    new_node->D_W=D_W;
    new_node->current=((*head_bal)->current) + D_W;
    new_node->next=(*head_bal);
    (*head_bal)=new_node;
  }
}
//
struct node* isalreadyexit(long int ATM_number)
{
  struct node (*ptr)=head;
  if(ptr==NULL)
  {
  	return NULL;
  }
  while (ptr->ATM_number!=ATM_number && (ptr->next)!= NULL)
   {
    ptr=ptr->next;
   }
   if(ptr->ATM_number==ATM_number)
   {
     return ptr;
   }
   else
   {
     return NULL;
   }
}
//
struct node* newuser_details(long int ATM_number,int pin)
{
    struct node *new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node==NULL)
    {
      printf("Memory allocation fails.\n");
      return;
    }
    else if(head==NULL)
    {
      new_node->prv=NULL;
      new_node->next=NULL;
      new_node->ATM_number=ATM_number;
      new_node->pin=pin;
      new_node->transactionlog = NULL;
      top=head=new_node;
    }
    else
    {
      new_node->prv=top;
      new_node->next=NULL;
      new_node->ATM_number=ATM_number;
      new_node->pin=pin;
      new_node->transactionlog = NULL;
      top->next=new_node;
      top=new_node;
    }
    return head;
}

//
//
float Balance(struct node** acc_address,int pin)
{
  if((*acc_address)==NULL||((*acc_address)->transactionlog)==NULL)
  {
    return;
  }
  if((*acc_address)->pin!=pin)
  {
    printf("Invalid pin\n\n");
    return;
  }
  return ((*acc_address)->transactionlog)->current;
}

int Deposit(struct node** acc_address,int pin,float deposit)
{
  if(((*acc_address)->pin)!=pin)
  {
    printf("Invalid pin\n\n");
    return 0;
  }
  balance_node(acc_address,deposit);
   return 1;
}
//
int Withdraw(struct node** acc_address,int pin,float Withdraw)
{
  if((*acc_address)->pin!=pin)
  {
    printf("Invalid pin");
    return 0;
  }
  balance_node(acc_address,(-Withdraw));
  return 1;
}
//
void Last_Transactions(struct node** acc_address,int pin)
{
   if((*acc_address)==NULL||((*acc_address)->transactionlog)==NULL)
   {
     return;
   }
  struct single_node *tamp=(*acc_address)->transactionlog;
  printf("\n\t\t###  ([D_W]   \t\t   [Balance])\n");
  while (tamp!=NULL) {
    printf("\t\t###  ([%f]    \t   [%f])\n",tamp->D_W,tamp->current);
    tamp= tamp->next;
  }
}




int main()
{
   char str[6];
   do
   {
     long int ATM_number;
     printf("\t\t\t\tSTART\n\n\n");
     printf("Enter your ATM_number[12 digit] : ");
     scanf("%ld",&ATM_number);
     struct node *exist;
     exist=isalreadyexit(ATM_number);
     if(exist==NULL)
     {
       printf("You need to add your card first to continue.\n");
       int pin;
       printf("Enter your pin : ");
       scanf("%d",&pin);
       exist=newuser_details(ATM_number,pin);
       printf("Your account added susscefully.\n");
     }
     int option=1;
     while(option)
     {
       printf("\t\tWELCOME SCREEN\n");
       printf("\t# 1.Balance(Enter-1).\n");
       printf("\t# 2.Deposit(Enter-2).\n");
       printf("\t# 3.Withdraw(Enter-3).\n");
       printf("\t# 4.Last Transactions(Enter-4).\n");
       printf("\t# 0.Exit(Enter-0).\n");
       printf("Enter the option : ");
       scanf("%d",&option);

       switch (option) {
         case 1:
         {
           int pin;
           printf("\t# Enter the pin(4-digit).\n");
           scanf("%d",&pin);
           printf("Your Balance is : %f",Balance(&exist,pin));
           break;
         }
         case 2:
         {
           int pin;
           float deposit;
           printf("\t# Enter the pin(4-digit).\n");
           scanf("%d",&pin);
           printf("\t# Enter the amount to diposit.\n");
           scanf("%f",&deposit);
           int susscefully_transection=Deposit(&exist,pin,deposit);
           if(susscefully_transection!=0)
           {
             printf("Your Deposit of rupess %f is susscefully\n",deposit);
             printf("Your Balance is now : %f.\n",Balance(&exist,pin));
           }
           break;
         }
         case 3:
         {
           int pin;
           float Withdrawal;
           printf("\t# Enter the pin(4-digit).\n");
           scanf("%d",&pin);
           printf("\t# Enter the Withdrawal amount.\n");
           scanf("%f",&Withdrawal);
           int susscefully_transection=Withdraw(&exist,pin,Withdrawal);
           if(susscefully_transection!=0)
           {
             printf("Your Withdrawal of rupess %f is susscefully\n",Withdrawal);
             printf("Your Balance is : %f",Balance(&exist,pin));
           }
           break;
         }
         case 4:
         {
           int pin;
           printf("\t# Enter the pin(4-digit).\n");
           scanf("%d",&pin);
           Last_Transactions(&exist,pin);
           break;
         }
         default :
         {
           printf("Exit the program.\n");
           break;
         }
       }
     }
     printf("Enter `close` to close the machine or `new` to continue: ");
     scanf("%s", str);
   } while(strcmp(str, "close")!= 0);
return 0;
}
