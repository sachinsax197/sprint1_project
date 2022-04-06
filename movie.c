#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define buflen 30

char r;

struct Users
{
    int Uid;
    char email[30];
    char Upasswd[buflen];
    char Uname[buflen];
    int acc_status;
};
typedef struct Users USERS;


struct Admin
{
    int Uid;
    char email[buflen];
    char Upasswd[buflen];
    char Uname[buflen];
};

typedef struct Admin admin;


struct book{
	char code[20];
	char name[20];
	char date[20];
	int cost;
}b;
int seat=80;
void insert_details();
void view_All();
void find();
void book_ticket();
void old_records();
void welcomeScreen(void);
int choice(void);
int choice2(void);
void setAdmin(admin *);
void getAdmin(admin);
void setUsers(USERS *);
void getUsers(USERS);
void options(int);

void main(){

     system("clear");

    USERS u;
    admin a;
   
    char t[2] = {'\0'};
    int n, n1, n2, n3;
    char ch;

    char pass[20] = {'\0'};
    char name[20] = {'\0'};
    char email[30] = {'\0'};

    int uid = 0, flag = 0;

    FILE *ft;

    welcomeScreen();
    
 do
    {
        n = choice();
        switch (n)
        {
        case 1:
            ft = fopen("Users.dat", "r");
            if (ft == NULL)
            {
                printf("\n No Database Found\n");
                printf("\n First Create a Database\n");
                break;
            }
            printf("\n");
            printf("\n                   Login Here               \n");
            printf("\nEnter the gmail id for search in the database=");
            scanf("%s", &email);
            while (fread(&u, sizeof(u), 1, ft))
            {
                if (strcmp(u.email, email) == 0)
                {
                    flag = 1;
                    printf("\nEnter the Password=");
                    scanf("%s", &pass);
                    if (strcmp(u.Upasswd, pass) == 0)
                    {
                        flag=2;
                        printf("\n Login Successfull\n");
                        n1 = choice2();
                        options(n1);
                        printf("\n Process complete\n");
                    }
                }
            }
            if (flag == 0)
                printf("\n User doesnot found in the database\n");
            else if (flag == 1)
                printf("\nUser Found But Password Doesn't Match..!!\n");

            break;

        case 2:
            ft = fopen("Users.dat", "r");
            if (ft == NULL)
            {
                printf("\nUser Database File Doesnot Exist\n");
                printf("\nCreating User Record File\n");
            }

            ft = fopen("Users.dat", "a");
            setUsers(&u);
            fwrite(&u, sizeof(u), 1, ft);
            if (fwrite != 0)
                printf("\n User Add Successfully\n");
            else
                printf("\nSomething Went Wrong\n");

            break;

        
        case 3:
            ft = fopen("Admins.dat", "r");
            if (ft == NULL)
            {
                printf("\n No Database Found\n");
                printf("\n First Create a Database\n");
                ft = fopen("Admins.dat", "w");
                setAdmin(&a);
                getAdmin(a);
                fwrite(&a, sizeof(a), 1, ft);
                if (fwrite != 0)
                    printf("\n User Add Successfully\n");
                else
                    printf("\nSomething Went Wrong\n");
            }

            else
            {
                printf("\n\n");
                printf("\n               Login here                \n");

                printf("Enter the Admin Id for search in the database=");
                scanf("%d", &uid);
                //fseek(ft, 0, SEEK_SET);
                while (fread(&a, sizeof(a), 1, ft))
                {
                    if (a.Uid == uid)
                    {
                        flag = 1;
                        printf("\nEnter the Password=");
                        scanf("%s", &pass);
                        if (strcmp(a.Upasswd, pass) == 0)
                        {
                            flag=2;
                            printf("\n Login Successfull\n");
                            n3 = choice3();
                            adminOptions(n3);
                            printf("\nProcess Complete\n");
                        }
                    }
                }
                if (flag == 0)
                    printf("\n Admin id doesnot found in the database\n");
                else if (flag == 1)
                    printf("\nAdminid Found But Password Doesn't Match..!!\n");
            }

            break;

        case 4:
            exit(EXIT_SUCCESS);
            break;

        default:
            printf("\n Enter the valid Option\n");
            break;
        }

        printf("\nDo You want to continue (y/n):-");
        getc(stdin);
        scanf("%c", &ch);

    } while (ch == 'y');

    fclose(ft);
   

}

void setAdmin(admin *a)
{
    printf("\nEnter User Name: ");
    scanf("%s", a->Uname);
    printf("\nEnter the gmail id:");
    scanf("%s", a->email);
    printf("\nEnter User password: ");
    scanf("%s", a->Upasswd);
    a->Uid = (rand() % (10000 - 1 + 1)) + 1;
}

void getAdmin(admin U)
{
    printf("\nUser Name: ");
    printf("%s", U.Uname);
    printf("\nUser password: ");
    printf("%s", U.email);
    printf("\nUser ID: ");
    printf("%d", U.Uid);
    printf("\nUser password: ");
    printf("%s", U.Upasswd);
    printf("\n\n");
}

void adminOptions(int n)
{
   
    char ch;
    do {
    switch (n)
    {
    case 1:
       insert_details();
        break;
    case 2:
       view_All();
        
        break;
    case 3:
     old_records();

        break;
   
    case 4:
        exit(EXIT_SUCCESS);
        break;

        default:
        printf("\nEnter a valid option\n");
        break;
    }
    printf("\nDo you want to continue with the same option....(y/n):\n");
    getc(stdin);
    scanf("%c",&ch);
    }while(ch=='y');
}








void options(int n)
{
   
    char ch; 
    do {
    switch (n)
    {
    case 1:
         book_ticket();
         break;
    case 2:
        find();
        break;
    case 3:
        exit(EXIT_SUCCESS);
        break;
    default:
        printf("\n Please Enter a valid Input");
        break;
    }
     printf("\n Do you want to continue with the same option....(y/n):\n");
     getc(stdin);
     scanf("%c",&ch);
    }while(ch=='y');

}

void welcomeScreen()
{


    printf("\n\n\n");
    printf(" ****************************************************************************************************\n");
    printf(" =================================================================================================\n");
    printf(" =================================================================================================\n");
    printf("                                              WELCOME TO                           \n");
    printf("                                     MOVIE TICKET BOOKING SYSTEM                  \n");
    printf("                      \n                  \n");
    printf("                                         Created By Group 2                  \n");
    printf("                                           Team Members:-                  \n");
    printf("                     Rubi Singh, Sachin Saxena, Austosh Zoting, Deeveprashad, Biplab                \n");
    printf(" ==================================================================================================\n");
    printf(" ===================================================================================================\n");
    printf(" ****************************************************************************************************\n");
    sleep(2);
       
}


int choice(void)
{
    system("clear");
    int choice;
    printf(" ********************************************************************\n");
    printf("                      Movie Ticket Booking System\n");
    printf(" ====================================================================\n");
    printf("||                  1- To User Login                                ||\n");
    printf("||                  2- To User Register                             ||\n");
    printf("||                  3- To Admin Login                               ||\n");
    printf("||                  4- Exit system:                                 ||\n");
    printf("||==================================================================||\n");
    printf(" ********************************************************************\n");

    printf("  Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}



// choice after user login
int choice2(void)
{
    system("clear");
    int choice;
    printf(" ==================================================================\n");
    printf("               Movie Ticket Booking System\n");
    printf(" ==================================================================\n");
    printf("||             1- To Book Tickets                                 ||\n");
    printf("||             2- To All Movies                                   ||\n");
    printf("||             3- Exit system:                                    ||\n");
    printf("||================================================================||\n");
    printf("  Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int choice3(void)
{
    system("clear");
    int choice;
    printf("                      Movie Ticket Booking System\n");
    printf(" ==================================================================\n");
    printf("||                  1- Add Movie                                    ||\n");
    printf("||                  2- View All Movie's List                        ||\n");
    printf("||                  3- View All Record                              ||\n");
    printf("||                  4- Exit system:                                 ||\n");
    printf("||==================================================================||\n");
    printf("  Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}




void setUsers(USERS *U)
{
    printf("\nEnter User Name: ");
    scanf("%s", U->Uname);
    printf("\nEnter the gmail id:");
    scanf("%s", U->email);
    printf("\nEnter User password: ");
    scanf("%s", U->Upasswd);
    U->Uid = (rand() % (10000 - 1 + 1)) + 1;
}

void getUsers(USERS U)
{
    printf("\nUser Name: ");
    printf("%s", U.Uname);
    printf("\nUser ID: ");
    printf("%d", U.Uid);
    printf("\nUser email: ");
    printf("%s", U.email);
    printf("\n\n");
}


void insert_details(){
	FILE *fp;
	struct book b;
	printf("Enter movie code :- ");	
	scanf("%s",b.code);
	printf("Enter  name :- ");	
	scanf("%s",b.name);
	printf("Enter Release Date:- ");	
	scanf("%s",b.date);
	printf("Enetr Ticket Price:- ");	
	scanf("%d",&b.cost);
	fp=fopen("data.txt","a");
	if(fp == NULL)
		printf("\nA new record is creating\n");
	else{
		fprintf(fp,"%s %s %s %d \n",b.code,b.name,b.date,b.cost);
		printf("Recorded Successfully\n");
	}
	fclose(fp);
	system("clear");
}
void find(){
	struct book b;
	FILE *fp;
	char ch[20];
	printf("Enter movie code :");
	scanf("%s",ch);
	fp = fopen("data.txt","r");
	if(fp == NULL){
		printf("File Not Found");
		exit(0);
	}
	else{	
		while(getc(fp) != EOF){
			fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
			if(strcmp(b.code,ch) == 0){	
				printf("\n Record Found\n\n");
				printf("\n\t\tMovie Code :%s",b.code);
				printf("\n\t\tMovie Name :%s",b.name);
				printf("\n\t\tMovie Date :%s",b.date);
				printf("\n\t\tPrice of Ticket :%d",b.cost);
			}
		}	
	}
	fclose(fp);
	printf("\n\t\tPress enter to continue........");
	scanf("%c%c",&r,&r);
	system("clear");
}
void view_All(){
	char ch;
	FILE *fp;
	fp = fopen("data.txt","r");
	if(fp == NULL){
		printf("File Not Found");
		exit(0);
	}
	else{	
		system("clear");
        printf("\n\n");
        printf("\nAll Movies Present\n");

        printf("\nMovie Code Movie Name Ticket Price Release Date\n\n");
		while((ch=fgetc(fp))!=EOF)
      			printf("%c",ch);	
	}
	printf("\n\t\tPress enter to continue........");
	scanf("%c%c",&r,&r);
	system("clear");
	fclose(fp);
}
void book_ticket(){
	struct book b;
	FILE *fp;
	FILE *ufp;
    int seatno[10];
	int total_seat,mobile,total_amount;
	char name[20];
	char ch;
	char movie_code[20];
	fp = fopen("data.txt","r");
	if(fp == NULL){
		printf("file not found !");
		exit(1);
	}
	else{	
		system("clear");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
	}
	fclose(fp);
	printf("\n For Book ticket Choice Movie(Enter Movie Code)\n");
	printf("\n Enter movie code :");
	scanf("%s",movie_code);
	fp = fopen("data.txt","r");
	if(fp == NULL){
		printf("file not found !");
		exit(1);
	}
	else{	
		while(getc(fp) != EOF){
			fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
			if(strcmp(b.code,movie_code) == 0){	
				printf("\n Record Found\n");
				printf("\n\t\tCode :%s",b.code);
				printf("\n\t\tMovie name :%s",b.name);
				printf("\n\t\tdate name :%s",b.date);
				printf("\n\t\tPrice of ticket:%d",b.cost);
			}
		}
	}
	printf("\n* Fill Your Details  *");
	printf("\n Your Name :");
	scanf("%s",name);
	printf("\n Mobile Number :");
	scanf("%d",&mobile);
    lebel1:
	printf("\n Enter Total number of tickets :");
	scanf("%d",&total_seat);
    if (total_seat>10)
    {
    printf("\n You Are not allowed to book more than 10 tickets\n");
    goto lebel1;
    }
    printf("\n==============================================================================\n");
    printf("\n                                  Screen This Side                            \n");
    printf("\n==============================================================================\n");

    printf("\n\n\n");


    for (int i = 1; i <= 60; i++)
    {
        printf("%d\t", i);
        if (i % 10 == 0)
            printf("\n\n");
    }
    printf("\n Please Select the Seat No.\n");
    printf("\nEnter Your Choice=");
    for (int i = 0; i < total_seat; i++)
    {
        scanf("%d",&seatno);
    }



	total_amount = b.cost * total_seat;

   int ran=(rand() % (10000000 - 1 + 1)) + 1;
	printf("\n ENJOY YOUR MOVIE \n");
      printf("\t----------------------------------THEATER BOOKING TICKET--------------------------\n");
        printf("\t=================================================================================\n");
        printf("\t Booking ID :  %d",ran);
        printf("\n\t Customer  : %s\n",name);
        printf("\n\t\tMobile Number : %d",mobile);
        printf("\n\t\tMovie name : %s\n",b.name);
        printf("\t\t\t                                          Date        : 06-04-2022\n");
        printf("\t                                              Hall        : 04\n");
        printf("\t                                              Total seats : %d  \n",total_seat);
        printf("\t                                              price . : %d  \n\n",b.cost);
        printf("\n\t                                       Total Amount : %d\n",total_amount);
        printf("\t==================================================================================\n");
	
	
	ufp=fopen("oldTransection.txt","a");
	if(ufp == NULL){
		printf("File not Found");
	}
	else{
		fprintf(ufp,"%s %d %d %d %s %d %d \n",name,mobile,total_seat,total_amount,b.name,b.cost,seatno);
		printf("\n Record insert Sucessfull to the old record file");
	}
	printf("\n");
	printf("\n\t\tPress enter to continue........");
	scanf("%c%c",&r,&r);	
	fclose(ufp);
	fclose(fp);
}
void old_records(){
	char ch;
	FILE *fp;
	fp = fopen("oldTransection.txt","r");
	if(fp == NULL){
		printf("file not found !");
		exit(1);

	}
	else{	
		system("clear");
        printf("\n All Transaction Record\n");
		while((ch=fgetc(fp))!=EOF)
      		printf("%c",ch);	
	}
	printf("\n\t\tPress enter to continue........");
	scanf("%c%c",&r,&r);
	fclose(fp);
}