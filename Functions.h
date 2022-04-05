#ifndef USERS_H
#define USERS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define buflen 20

struct Users
{
    int Uid;
    char email[30];
    char Upasswd[buflen];
    char Uname[buflen];
    int acc_status;
};

typedef struct Users USERS;

struct movieReserationDetails
{
    int movieId;
    int userid;
    int reservedSeats[10];
    int moviePrice;
    int ticketstatus;
    int totalvalue;
};

typedef struct movieReserationDetails m;

void setUsers(USERS *);
void getUsers(USERS);
int choice(void);
int choice2(void);
int choice2(void);
void options(USERS *, int);
void seatReservation(int **, int);
int choice4(void);
void guest(int n);
void welcomeScreen(void);

// int checkUser(USERS, int, char[]);


void welcomeScreen()
{

    printf(" ******************************************************************\n");
    printf(" ==================================================================\n");
    printf(" ==================================================================\n");
    printf("                              WELCOME TO \n");
    printf("                      MOVIE TICKET BOOKING SYSTEM\n");
    printf(" ==================================================================\n");
    printf(" ==================================================================\n");
    printf(" ******************************************************************\n");
    sleep(2);
       
}






// choice for the first page
int choice(void)
{
    system("clear");
    int choice;
    printf(" ********************************************************************\n");
    printf("                      Movie Ticket Booking System\n");
    printf(" ====================================================================\n");
    printf("||                  1- To User Login                                ||\n");
    printf("||                  2- To User Register                             ||\n");
    printf("||                  3- Guest User                                   ||\n");
    printf("||                  4- To Admin Login                               ||\n");
    printf("||                  5- Exit system:                                 ||\n");
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
    printf("||             1- To Book Tickets                                ||\n");
    printf("||             2- To View Tickets                                ||\n");
    printf("||             3- To Cancel Tickets                              ||\n");
    printf("||             4- Exit system:                                   ||\n");
    printf("||================================================================||\n");
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

void options(USERS *U, int n)
{
    int i, a,**j, *b;
    m *details;
    FILE *ft;
    switch (n)
    {
    case 1:
        i = movie();
    label1:
        printf("\nHow many seats Would You like to book=");
        scanf("%d", &a);
        if (a > 10)
        {
            printf("\nYou are not allowed to book more than 10 tickets\n");
            goto label1;
        }
        else
        {
            j = (int *)malloc(sizeof(int) * n);
            seatReservation(j, n);
            ft = fopen("MovieReservationdetails.dat", "a");
            details->movieId = i;
            details->userid = U->Uid;
            details->ticketstatus = 1;
            for(i=0;i<n;i++)
            details->reservedSeats[i]=**(j+i);
            fwrite(&details, sizeof(details), 1, ft);
            if (fwrite != 0)
            printf("Tickets Book Successfully");
             else
                printf("\nSomething Went Wrong\n");
        }

        break;
    case 2:
        printf("Work on progress");
        break;
    case 3:
        printf("Work on progress");

        break;
    case 4:
        exit(EXIT_SUCCESS);

        break;
    default:
        printf("\n Please Enter a valid Input");
        break;
    }
}

int movie(void)
{
    int i;
    system("clear");
    printf("\t\t\twhich movie you want to see?\n");
    printf("\t\t\t----------------------------\n\n");
    printf("\t\t\tpress 1 for Avengers: EndGame\n\n");
    printf("\t\t\tpress 2 for Captain Marvel\n\n");
    printf("\t\t\tpress 3 for Spider-Man: Far From Home\n");
    scanf("%d", &i);
    system("clear");
    return i;
}

void seatReservation(int **j, int n)
{
    int i = 1, seatno;
    printf("\n==============================================================================\n");
    printf("\n                                  Screen This Side                            \n");
    printf("\n==============================================================================\n");

    printf("\n\n\n");


    for (i = 1; i <= 100; i++)
    {
        printf("%d\t", i);
        if (i % 10 == 0)
            printf("\n\n");
    }
    printf("\n Please Select the Seat No.\n");
    printf("\nEnter Your Choice=");
    for (i = 0; i < n; i++)
    {
        scanf("%d",*(j + i));
    }
   
}


int choice4(void)
{

    int choice;
    printf("====================================================================\n");
    printf("                      Movie Ticket Booking System\n");
    printf("====================================================================\n");
    printf("||                  1- To User Login                                ||\n");
	printf("||                  2- Exit system                                  ||\n");
	printf("Enter your choice : ");
	scanf("%d",&choice);
	return choice;
}	

void guest(int n)
{

    int i,a,*j,*b;
    m *details;
    FILE *ft;
    switch (n)
    {
    case 1:
         i = movie();
         label1:
         printf("\nHow many seats Would You like to book=");
         scanf("%d",&a);
         if(a>10){
         printf("\n You are not allowed to book more than 10 tickets");
         goto label1;
         }
         else{
         j=(int *)malloc(sizeof(int)*n);
         seatReservation(&j,n);
         ft = fopen("MovieReservationdetails.dat", "a+");
         details->movieId=i;
       //  details->userid=U->Uid;
         printf("Tickets Book Successfully");
         }

        break;
	case 2:

      exit(EXIT_SUCCESS);

        break;
        default:
        printf("\n Please Enter a valid Input");
        break;
	}
}




// int checkUser(USERS U, int id, char pass[])
// {
// 	int count=0;
// 	if(U.Uid== id)
// 	{
// 		count=1;
// 		if(strcmp(U.Upasswd, pass)==0)
// 		{
// 			count=2;
// 		printf("\n User Id and password matches Successfully\n");
// 		getUsers(U);
// 		}
// 	}
// 	return count;
// }

#endif
