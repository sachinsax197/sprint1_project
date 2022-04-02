#ifndef USERS_H
#define USERS_H
#include <stdio.h>
#define buflen 20

struct Users
{
    int Uid;
    char Upasswd[buflen];
    char Uname[buflen];
    int acc_status;
};

typedef struct Users USERS;

struct movieDetails
{
	int movieId;
	char movieName[buflen];
	int moviePrice;
    int movieStatus;
    char movieTimings[buflen];
};

typedef struct movieDetails movie;




void setUsers(USERS *);
void getUsers(USERS);
int choice(void);
int choice2(void);
int choice2(void);
void options(USERS, int);
//int checkUser(USERS, int, char[]);

// choice for the first page
int choice(void)
{
    int choice;
    printf("                      Movie Ticket Booking System\n");
    printf(" ==================================================================\n");
    printf("||                  1- To User Login                                ||\n");
    printf("||                  2- To User Register                             ||\n");
    printf("||                  3- Guest User                                   ||\n");
    printf("||                  3- To Admin Login                               ||\n");
    printf("||                  4- Exit system:                                 ||\n");
    printf("||==================================================================||\n");
    printf("  Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// choice after user login
int choice2(void)
{
    int choice;
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


//choices after admin login
int choice3(void)
{
    int choice;
    printf("                      Movie Ticket Booking System\n");
    printf(" ==================================================================\n");
    printf("||                  1- Add Movie                                    ||\n");
    printf("||                  2- Update Movie Details                         ||\n");
    printf("||                  3- View All Users                               ||\n");
    printf("||                  4- View Total Collection                        ||\n");
    printf("||                  5- Exit system:                                 ||\n");
    printf("||==================================================================||\n");
    printf("  Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}



void setUsers(USERS *U)
{

    printf("\nEnter User Name: ");
    scanf("%s", U->Uname);

    // fflush(stdin);
    printf("\nEnter User ID: ");
    scanf("%d", &U->Uid);
    printf("\nEnter User password: ");
    scanf("%s", U->Upasswd);
}

void getUsers(USERS U)
{
    printf("\nUser Name: ");
    printf("%s", U.Uname);
    printf("\nUser ID: ");
    printf("%d", U.Uid);
    printf("\nUser password: ");
    printf("%s", U.Upasswd);
    printf("\n\n");
}

void options(USERS U, int n)
{
    int i,j;
    switch (n)
    {
    case 1:
        // i = movie();
        // j=seatreservation();
      

        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    }
}

int movie(void)
{
    int i;
    system("cls");
    printf("\t\t\twhich movie you want to see?\n");
    printf("\t\t\t----------------------------\n\n");
    printf("\t\t\tpress 1 for Avengers: EndGame\n\n");
    printf("\t\t\tpress 2 for Captain Marvel\n\n");
    printf("\t\t\tpress 3 for Spider-Man: Far From Home\n");
    scanf("%d", &i);
    system("cls");
    return i;
}


int seatReservation(void)
{
    int i=1,seatno;
    printf("\n Please Select the Seat No.\n");

    for(i=1;i<10;i++)
    {
        printf("%d\t",i);
        if(i%10==0)
        printf("\n\n");

    }
    printf("\nEnter Your Choice=");
    scanf("%d",&seatno);
    return seatno;
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