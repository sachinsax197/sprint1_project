#ifndef ADMIN_H
#define ADMIN_H
#include <stdio.h>
#include <stdlib.h>

#define buflen 20



struct Admin
{
    int Uid;
    char email[30];
    char Upasswd[buflen];
    char Uname[buflen];
};

typedef struct Admin admin;

void setAdmin(admin *);
void getAdmin(admin);

void setAdmin(admin *a)
{
    printf("\nEnter User Name: ");
    scanf("%s", a->Uname);
    printf("\nEnter the gmail id:");
    scanf("%s",a->email);
    printf("\nEnter User password: ");
    scanf("%s", a->Upasswd);
    a->Uid=(rand() % (10000 - 1 + 1)) + 1;
}

void getAdmin(admin U)
{
    printf("\nUser Name: ");
    printf("%s", U.Uname);
    printf("\nUser ID: ");
    printf("%d", U.Uid);
    printf("\nUser password: ");
    printf("%s", U.Upasswd);
    printf("\n\n");
}





//choices after admin login
int choice3(void)
{
    system("clear");
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















#endif