#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int i,j;
int main_exit;
void menu();
void Password();
void welcome();
void see_1();
void list();
void gotoxy(int x,int y);
void rectangle(int x,int y,int l,int b);
char password[10]={"bubt"};
struct date{
    int month,day,year;

    };
struct {

    char name[60];
    int acc_no,age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

    }add,upd,check,rem,transaction;

float interest(float t,float amount,int rate)
{
    float SI;
    SI=(rate*t*amount)/100.0;
    return (SI);

}
void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

void new_acc()

{
    int choice;
    FILE *ptr;

    ptr=fopen("record.dat","a+");
    account_no:
    system("cls");
    rectangle(5,5,95,45);
    gotoxy(6,6);
    printf("\t\t\t\xB2\xB2\xB2\ ADD RECORD  \xB2\xB2\xB2\xB2");
    gotoxy(8,12);
    printf("Enter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    gotoxy(8,14);
    printf("Enter the account number:");
    scanf("%d",&check.acc_no);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (check.acc_no==add.acc_no)
            {printf("Account no. already in use!");
            fordelay(1000000000);
                goto account_no;

            }
    }
    add.acc_no=check.acc_no;
    gotoxy(8,16);
        printf("Enter the name:");
    scanf("%s",add.name);
    gotoxy(8,18);
    printf("Enter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    gotoxy(8,20);
    printf("Enter the age:");
    scanf("%d",&add.age);
    gotoxy(8,22);
    printf("Enter the address:");
    scanf("%s",add.address);
    gotoxy(8,24);
    printf("Enter the citizenship number:");
    scanf("%s",add.citizenship);
    gotoxy(8,26);
    printf("Enter the phone number: ");
    scanf("%lf",&add.phone);
    gotoxy(8,28);
    printf("Enter the amount to deposit (Taka): ");
    scanf("%f",&add.amt);
    gotoxy(8,30);
    printf("Type of account:");
    gotoxy(9,31);
    printf("# Saving");
    gotoxy(9,32);
    printf("# Current");
    gotoxy(9,33);
    printf("# Fixed1(for 1 year)");
    gotoxy(9,34);
    printf("# Fixed2(for 2 years)");
    gotoxy(9,35);
    printf("# Fixed3(for 3 years)");
    gotoxy(10,40);
    printf("Enter your choice:");
    scanf("%s",add.acc_type);

        fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);


    fclose(ptr);
    system("cls");
    rectangle(5,5,95,45);
    gotoxy(10,20);
    printf("Account created successfully!");
    add_invalid:
    gotoxy(12,23);
    printf("\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {
            gotoxy(18,52);
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}
void view_list()
{
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    system("cls");
    rectangle(20,6,80,10);
    gotoxy(28,8);
  printf(" PERSONAL INFORMATION OF THE CUSTOMERS ");
    printf("\n\n\n\n\n\tACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");
    printf("\n\t=============================================================================\n");

    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
       {
           printf("\n\n\t%d\t\t%s\t\t\t%s\t\t\t%.0lf",add.acc_no,add.name,add.address,add.phone);
           printf("\n\t------------------------------------------------------------------------------");
           test++;
       }

    fclose(view);
    if (test==0)
        {   system("cls");
        rectangle(8,8,66,30);
        gotoxy(15,15);
            printf("NO RECORDS!!");}

    view_list_invalid:
        gotoxy(9,38);
     printf("Enter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}
void edit(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    gotoxy(5,10);
    printf("Enter the account no. of the customer whose info you want to change:");
    scanf("%d",&upd.acc_no);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (add.acc_no==upd.acc_no)
        {   test=1;
            gotoxy(6,12);
            printf("Which information do you want to change?");
            gotoxy(7,14);
            printf("1.Address");
            gotoxy(7,16);
            printf("2.Phone");
            gotoxy(7,19);
            printf("Enter your choice(1 for address and 2 for phone):");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
                {
                rectangle(7,7,80,20);
                gotoxy(10,10);
                printf("Enter the new address:");
                scanf("%s",upd.address);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                  rectangle(7,7,80,20);
                 gotoxy(20,12);
                printf("Changes saved!");
                }
            else if(choice==2)
                {
                    rectangle(7,7,80,20);
                     gotoxy(10,10);
                    printf("Enter the new phone number:");
                    gotoxy(38,10);
                scanf("%lf",&upd.phone);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,upd.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
               // system("cls");
                rectangle(7,7,80,20);
                 gotoxy(20,12);
                printf("Changes saved!");
                }

        }
        else
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            edit_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)

                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    edit();
                else
                    {printf("\nInvalid!\a");
                    goto edit_invalid;}
        }
    else
        {
            gotoxy(20,15);
            printf("Enter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
        }
}

void transact(void)
{   int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
 rectangle(7,7,80,20);
gotoxy(10,10);
        printf("Enter the account no. of the customer:");
    scanf("%d",&transaction.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {

            if(add.acc_no==transaction.acc_no)
            {   test=1;
                if(strcmpi(add.acc_type,"fixed1")==0||strcmpi(add.acc_type,"fixed2")==0||strcmpi(add.acc_type,"fixed3")==0)
                {
                    printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                    fordelay(1000000000);
                    system("cls");
                    menu();

                }
                 rectangle(7,7,80,20);
                gotoxy(10,12);
                printf("Do you want to");
                gotoxy(10,14);
                printf("1.Deposit");
                gotoxy(10,16);
                printf("2.Withdraw?");
                gotoxy(10,18);
                printf("Enter your choice(1 for deposit and 2 for withdraw):");
                scanf("%d",&choice);
                if (choice==1)
                {
                    system("cls");
                    rectangle(7,7,80,20);
                     gotoxy(11,12);
                    printf("Enter the amount you want to deposit (Taka): ");
                    scanf("%f",&transaction.amt);
                    add.amt+=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    gotoxy(11,14);
                    printf("Deposited successfully!");
                }
                else
                {
                     system("cls");
                     rectangle(7,7,80,20);
                     gotoxy(11,12);
                    printf("Enter the amount you want to withdraw (Taka): ");
                    scanf("%f",&transaction.amt);
                    add.amt-=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                     gotoxy(11,14);
                     printf("Withdrawn successfully!");
                }

            }
            else
            {
               fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test!=1)
   {
       printf("\n\nRecord not found!!");
       transact_invalid:
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&main_exit);
      system("cls");
      if (main_exit==0)
        transact();
    else if (main_exit==1)
        menu();
    else if (main_exit==2)
        close();
    else
    {
        printf("\nInvalid!");
        goto transact_invalid;
    }

   }
   else
   {
       gotoxy(16,16);
       printf("Enter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
   }

}
void erase(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    rectangle(6,6,95,30);
    gotoxy(15,15);
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d",&rem.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
        if(add.acc_no!=rem.acc_no)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

        else
            {test++;
            gotoxy(17,18);
            printf("Record deleted successfully!");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test==0)
        {
            printf("\nRecord not found!!\a\a\a");
            erase_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    erase();
                else
                    {printf("\nInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {
            gotoxy(16,20);
            printf("Enter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
        }

}

void see(void)
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    ptr=fopen("record.dat","r");
    rectangle(5,5,90,45);
    gotoxy(10,10);
    printf("Do you want to check by");
    gotoxy(12,12);
    printf("1.Account no");
    gotoxy(12,14);
    printf("2.Name");
    gotoxy(12,16);
    printf("Enter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {
        gotoxy(12,19);
        printf("Enter the account number:");
        scanf("%d",&check.acc_no);

        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(add.acc_no==check.acc_no)
            {   system("cls");
                test=1;
                rectangle(5,5,90,45);
                gotoxy(8,8);
                printf("Account NO.:%d",add.acc_no);
                gotoxy(8,10);
                printf("Name:%s ",add.name);
                gotoxy(8,12);
                printf("DOB:%d/%d/%d ",add.dob.month,add.dob.day,add.dob.year);
                gotoxy(8,14);
                printf("Age:%d",add.age);
                gotoxy(8,16);
                printf("Address:%s",add.address);
                gotoxy(8,18);
                printf("Citizenship No:%s ",add.citizenship);
                gotoxy(8,20);
                printf("Phone number:%.0lf ",add.phone);
                gotoxy(8,22);
                printf("Type Of Account:%s ",add.acc_type);
                gotoxy(8,24);
                printf("Amount deposited (Taka): %.2f ",add.amt);
                gotoxy(8,26);
                printf("Date Of Deposit:%d/%d/%d",add.deposit.month,add.deposit.day,add.deposit.year);

                if(strcmpi(add.acc_type,"fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        gotoxy(8,29);
                        printf("You will get taka%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmpi(add.acc_type,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        gotoxy(8,29);
                        printf("You will get taka.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
                else if(strcmpi(add.acc_type,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        gotoxy(8,29);
                        printf("You will get taka.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

                    }
                 else if(strcmpi(add.acc_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        gotoxy(8,29);
                        printf("You will get taka.%.2f as interest on %d of every month",intrst,add.deposit.day);

                     }
                 else if(strcmpi(add.acc_type,"current")==0)
                    {
                        gotoxy(8,29);
                        printf("You will get no interest\a\a");

                     }

            }
        }
    }
    else if (choice==2)

    {
        gotoxy(12,19);
    printf("Enter the name:");
        scanf("%s",&check.name);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(strcmpi(add.name,check.name)==0)
            {   system("cls");
                test=1;
                rectangle(5,5,90,45);
                gotoxy(8,8);
                printf("Account NO.:%d",add.acc_no);
                gotoxy(8,10);
                printf("Name:%s ",add.name);
                gotoxy(8,12);
                printf("DOB:%d/%d/%d ",add.dob.month,add.dob.day,add.dob.year);
                gotoxy(8,14);
                printf("Age:%d",add.age);
                gotoxy(8,16);
                printf("Address:%s",add.address);
                gotoxy(8,18);
                printf("Citizenship No:%s ",add.citizenship);
                gotoxy(8,20);
                printf("Phone number:%.0lf ",add.phone);
                gotoxy(8,22);
                printf("Type Of Account:%s ",add.acc_type);
                gotoxy(8,24);
                printf("Amount deposited (Taka): %.2f ",add.amt);
                gotoxy(8,26);
                printf("Date Of Deposit:%d/%d/%d",add.deposit.month,add.deposit.day,add.deposit.year);

                if(strcmpi(add.acc_type,"fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        gotoxy(8,29);
                        printf("You will get taka %.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmpi(add.acc_type,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        gotoxy(8,29);
                        printf("You will get taka .%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
                else if(strcmpi(add.acc_type,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        gotoxy(8,29);
                        printf("You will get taka .%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

                    }
                 else if(strcmpi(add.acc_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        gotoxy(8,29);
                        printf("You will get taka .%.2f as interest on %d of every month",intrst,add.deposit.day);

                     }
                 else if(strcmpi(add.acc_type,"current")==0)
                    {
                        gotoxy(8,29);
                        printf("You will get no interest\a\a");

                     }


            }
        }
    }


    fclose(ptr);
     if(test!=1)
        {   system("cls");
        rectangle(8,8,75,25);
        gotoxy(10,10);
            printf("Record not found!!\a\a\a");
            see_invalid:
                gotoxy(11,13);
              printf("Enter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    see();
                else
                    {
                        system("cls");
                        printf("\nInvalid!\a");
                        goto see_invalid;}
        }
    else
        {
            gotoxy(8,31);
            printf("Enter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);}
        if (main_exit==1)
        {
            system("cls");
            menu();
        }

        else
           {

             system("cls");
            close();
            }

}


void close(void)
{
    system("cls");
    rectangle(10,10,80,30);
    gotoxy(40,15);
    printf("THANK YOU");
    gotoxy(15,20);
    printf("This Project is developed by 'WE_r_BUBTIN'!\n\n\n\n\n\n\n\n\n\n\n");

    }


void menu(void)
{   int choice;
    system("cls");
   // system("color 9");
    rectangle(5,5,95,45);
    rectangle(18,7,80,10);
    gotoxy(8,8);
    printf("\t\tCUSTOMER ACCOUNT'S  MANAGEMENT DEPARTMENT");
    gotoxy(6,12);
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(8,14);
    printf("\t1.Create new account");
    gotoxy(8,16);
    printf("\t2.Update information of existing account");
    gotoxy(8,18);
    printf("\t3.For transactions");
    gotoxy(8,20);
    printf("\t4.Check the details of existing account");
    gotoxy(8,22);
    printf("\t5.Removing existing account");
    gotoxy(8,24);
    printf("\t6.View customer's list");
    gotoxy(8,26);
    printf("\t7.Main menu ");
    gotoxy(8,28);
    printf("\t8.Exit");
    gotoxy(10,32);
    printf("\t Enter your choice:");
    gotoxy(38,32);
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:new_acc();
        break;
        case 2:edit();
        break;
        case 3:transact();
        break;
        case 4:see();
        break;
        case 5:erase();
        break;
        case 6:view_list();
        break;
        case 7:welcome();
        break;
        case 8:close();
        break;

    }

}
int main()
{
    int i;
    rectangle(5,5,95,45);
    rectangle(6,6,94,44);
    rectangle(21,14,70,16);
    gotoxy(34,15); printf("   BANK MANAGEMENT SYSTEM");
    gotoxy(34,16); for(i=0;i<27;i++) printf("%c",196);
    gotoxy(34,19); printf("Designed and Programmed by:");
    gotoxy(34,20);for(i=0;i<27;i++) printf("%c",196);
    gotoxy(34,24); printf("\tTasnim Nusrat");
    gotoxy(34,26); printf("\tKhurshida Rahman");
    gotoxy(34,28); printf("\tSabrina Rahman Mim");
    gotoxy(34,30); printf("\tMosabbir Ali Mir");
    gotoxy(34,32); printf("\tShadman Sakib Khan");
    gotoxy(34,34); printf("\tKhadiza Khatun");
    gotoxy(36,36);
    printf("Press Any key to continue...");
  getch();
  welcome();

        return 0;
}
void Password(void) //for password option
{
    system("cls");
    rectangle(5,5,95,45);
   char d[33]=" This area is Password Protected ";
   char ch,pass[10];
   int i=0,j;
   //textbackground(WHITE);View customer's list
   //textcolor(RED);
    gotoxy(10,4);
    for(j=0;j<20;j++)
    {
    Sleep(50);
    gotoxy(8+j,8);
    printf("*");
    }
    for(j=0;j<33;j++)
   {
   Sleep(50);
   printf("%c",d[j]);
   }
   for(j=0;j<20;j++)
   {
   Sleep(50);
   printf("*");
   }
   gotoxy(10,10);
   gotoxy(20,20);
   printf("Enter Password:");

   while(ch!=13)
   {
	ch=getch();

	if(ch!=13 && ch!=8){
	putch('*');
	pass[i] = ch;
	i++;
	}
   }
   pass[i] = '\0';
   if(strcmp(pass,password)==0)
   {

	gotoxy(25,25);
	//textcolor(BLINK);
	printf("Password match");
	gotoxy(25,28);
	printf("Press any key to countinue.....");
	getch();
	menu();
   }
   else
   {
	 gotoxy(25,25);
	 printf("\aWarning!! Incorrect Password");
	 gotoxy(25,28);
	 printf("TRY AGAIN");
	// gotoxy(26,30);
	// printf("REFRESE THE PAGE");
	 getch();
	 system("cls");
	 gotoxy(8,8);
	 printf(">>>>>>>>>>>>>>>>>>>> This area is password protected <<<<<<<<<<<<<<<<<<<<");
	 Password();
   }
}
void welcome()
{
    int i,s;
  system("cls");
  rectangle(5,5,95,45);
  rectangle(6,6,94,44);
  gotoxy(14,8);
  printf("\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE NATIONAL BANK MANAGEMENT SYSTEM  \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
  gotoxy(12,12);
    printf("Enter Your Choice : ");
    gotoxy(12,16);
    printf("ENTER 1 TO GO TO ADMINISTRATION DEPARTMENT. ");
    gotoxy(12,18);
    printf("ENTER 2 TO GO TO STUFF DEPAETMENT. ");
    gotoxy(12,20);
    printf("ENTER 3 TO  EXIT ");
    gotoxy(13,23);
    printf("OPTION..  ");
    scanf("%d",&s);
    switch(s)
    {
    case 1:
        Password();
        break;
    case 2:
        user();
    case 3:
        close();
    }
    getch();
}
void rectangle(int x,int y,int l,int b)
{
    int i,m;
    gotoxy(x,y); printf("%c",201);
    for(i=x+1;i<l-1;i++)
    {
        gotoxy(i,y);
        printf("%c",205);
    }
    gotoxy(i,y); printf("%c",187);

    for (m=y+1;m<b;m++)
    {
        gotoxy(x,m);
        for(i=x;i<l;i++)
        {
            if(i==x||i==l-1)
            {
                gotoxy(i,m); printf("%c",186);
            }

        }
    }

    gotoxy(x,m); printf("%c",200);
    for(i=x+1;i<l-1;i++)
    {
        gotoxy(i,m);
        printf("%c",205);
    }
    gotoxy(i,m); printf("%c",188);
}

COORD coord = {0, 0};
void gotoxy (int x, int y)
        {
        coord.X = x;
        coord.Y = y; // X and Y coordinates
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        }
void user()
{
    system("cls");
    rectangle(5,5,95,45);
     char d[37]=" This area is not Password Protected ";
      int i=0,j,j1,ch;
   //textbackground(WHITE);
   //textcolor(RED);
    gotoxy(10,4);
    for(j=0;j<20;j++)
    {
    Sleep(50);
    gotoxy(8+j,8);
    printf(">");
    }
    for(j=0;j<37;j++)
   {
   Sleep(50);
   printf("%c",d[j]);
   }
   for(j=0;j<20;j++)
   {
   Sleep(50);
   printf("<");
   }
   gotoxy(10,20);
   printf(" Press ENTER to proceed ");
   getch();
  /* for(j1=0;j1<=6;j1++)
        {
            fordelay(100000000);
            printf(".");
        }*/
    system("cls");
    printf("\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM\n\n");
    gotoxy(30,10);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WElCOME TO THE STUFF DEPARTMENT \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    rectangle(5,5,95,45);
    gotoxy(20,20);
    printf("Enter Your Choice :");
    gotoxy(21,22);
    printf("1. Check the details of existing account");
    gotoxy(21,24);
    printf("2. View customer's list");
    gotoxy(21,26);
    printf("3. Main menu");
    gotoxy(24,28);
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:see_1();
        break;
    case 2:list();
        break;
    case 3:welcome();
        break;
    }



}
void see_1(void)
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    ptr=fopen("record.dat","r");
    system("cls");
    rectangle(5,5,90,45);
    gotoxy(10,10);
    printf("Do you want to check by");
    gotoxy(12,12);
    printf("1.Account no");
    gotoxy(12,14);
    printf("2.Name");
    gotoxy(12,16);
    printf("Enter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {
        gotoxy(12,19);
        printf("Enter the account number:");
        scanf("%d",&check.acc_no);

        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(add.acc_no==check.acc_no)
            {   system("cls");
                test=1;
                rectangle(5,5,90,45);
                gotoxy(8,8);
                printf("Account NO.:%d",add.acc_no);
                gotoxy(8,10);
                printf("Name:%s ",add.name);
                gotoxy(8,12);
                printf("DOB:%d/%d/%d ",add.dob.month,add.dob.day,add.dob.year);
                gotoxy(8,14);
                printf("Age:%d",add.age);
                gotoxy(8,16);
                printf("Address:%s",add.address);
                gotoxy(8,18);
                printf("Citizenship No:%s ",add.citizenship);
                gotoxy(8,20);
                printf("Phone number:%.0lf ",add.phone);
                gotoxy(8,22);
                printf("Type Of Account:%s ",add.acc_type);
                gotoxy(8,24);
                printf("Amount deposited (Taka): %.2f ",add.amt);
                gotoxy(8,26);
                printf("Date Of Deposit:%d/%d/%d",add.deposit.month,add.deposit.day,add.deposit.year);

                if(strcmpi(add.acc_type,"fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        gotoxy(8,29);
                        printf("You will get taka %.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmpi(add.acc_type,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        gotoxy(8,29);
                        printf("You will get taka .%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
                else if(strcmpi(add.acc_type,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        gotoxy(8,29);
                        printf("You will get taka .%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

                    }
                 else if(strcmpi(add.acc_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        gotoxy(8,29);
                        printf("You will get taka.%.2f as interest on %d of every month",intrst,add.deposit.day);

                     }
                 else if(strcmpi(add.acc_type,"current")==0)
                    {
                        gotoxy(8,29);
                        printf("You will get no interest\a\a");

                     }

            }
        }
    }
    else if (choice==2)

    {
        gotoxy(12,19);
    printf("Enter the name:");
        scanf("%s",&check.name);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(strcmpi(add.name,check.name)==0)
            {   system("cls");
                test=1;
                rectangle(5,5,90,45);
                gotoxy(8,8);
                printf("Account NO.:%d",add.acc_no);
                gotoxy(8,10);
                printf("Name:%s ",add.name);
                gotoxy(8,12);
                printf("DOB:%d/%d/%d ",add.dob.month,add.dob.day,add.dob.year);
                gotoxy(8,14);
                printf("Age:%d",add.age);
                gotoxy(8,16);
                printf("Address:%s",add.address);
                gotoxy(8,18);
                printf("Citizenship No:%s ",add.citizenship);
                gotoxy(8,20);
                printf("Phone number:%.0lf ",add.phone);
                gotoxy(8,22);
                printf("Type Of Account:%s ",add.acc_type);
                gotoxy(8,24);
                printf("Amount deposited (Taka): %.2f ",add.amt);
                gotoxy(8,26);
                printf("Date Of Deposit:%d/%d/%d",add.deposit.month,add.deposit.day,add.deposit.year);

                if(strcmpi(add.acc_type,"fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        gotoxy(8,29);
                        printf("You will get taka %.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmpi(add.acc_type,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        gotoxy(8,29);
                        printf("You will get taka .%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
                else if(strcmpi(add.acc_type,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        gotoxy(8,29);
                        printf("You will get taka .%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

                    }
                 else if(strcmpi(add.acc_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        gotoxy(8,29);
                        printf("You will get taka .%.2f as interest on %d of every month",intrst,add.deposit.day);

                     }
                 else if(strcmpi(add.acc_type,"current")==0)
                    {
                        gotoxy(8,29);
                        printf("You will get no interest\a\a");

                     }


            }
        }
    }


    fclose(ptr);
     if(test!=1)
        {   system("cls");
        rectangle(8,8,75,25);
        gotoxy(10,10);
            printf("Record not found!!\a\a\a");
            see_invalid:
                gotoxy(8,31);
              printf("Enter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)
                    user();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    see();
                else
                    {
                        system("cls");
                        printf("\nInvalid!\a");
                        goto see_invalid;}
        }
    else
        {
            gotoxy(11,33);
            printf("Enter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);}
        if (main_exit==1)
        {
            system("cls");
            user();
        }

        else
           {

             system("cls");
            close();
            }
}

void list()
{
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    system("cls");
    rectangle(20,6,80,10);
    gotoxy(28,8);
  printf(" PERSONAL INFORMATION OF THE CUSTOMERS ");
    printf("\n\n\n\n\n\tACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");
    printf("\n\t=============================================================================\n");

    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
       {
           printf("\n\n\t%d\t\t%s\t\t\t%s\t\t\t%.0lf",add.acc_no,add.name,add.address,add.phone);
           printf("\n\t------------------------------------------------------------------------------");
           test++;
       }

    fclose(view);
    if (test==0)
        {   system("cls");
        rectangle(8,8,66,30);
        gotoxy(15,15);
            printf("NO RECORDS!!");}

    view_list_invalid:
         gotoxy(9,38);
     printf("Enter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            user();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}

