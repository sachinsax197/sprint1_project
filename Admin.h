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

struct movieDetails
{
    int movieId;
    char movieName[buflen];
    int moviePrice;
    int movieStatus;
    char movieTimings[buflen];
};
typedef struct movieDetails m1;

void setAdmin(admin *);
void getAdmin(admin);
void adminOptions(m1 *, int);

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

// choices after admin login
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

void adminOptions(m1 *movie, int n)
{
    FILE *ft;
    switch (n)
    {
    case 1:
        ft = fopen("Movies.dat", "a+");
        setMovie(&movie);
        getMovie(*movie);
        fwrite(&movie, sizeof(movie), 1, ft);
        if (fwrite != 0)
            printf("\n Movie Add Successfully\n");
        else
            printf("\nSomething Went Wrong\n");

        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    }
}


void setMovie(m1 *movie)
{
    printf("\nEnter Movie Name: ");
    scanf("%s", movie->movieName);
    printf("\nEnter the movie price:");
    scanf("%d", movie->moviePrice);
    printf("\nEnter the movie timing: ");
    scanf("%s", movie->movieTimings);
    printf("\nEnter the movie timing: ");
    scanf("%d", movie->movieStatus);
    
    movie->movieId = (rand() % (10000 - 1 + 1)) + 1;
}

void getMovie(m1 movie)
{
    printf("\nMovie ID: ");
    printf("%s", movie.movieId);
    printf("\nMovie Name: ");
    printf("%s", movie.movieName);
    printf("\nMovie Price: ");
    printf("%s", movie.moviePrice);
    printf("\nMovie Timing: ");
    printf("%d", movie.movieTimings);
    printf("\nMovie Status: ");
    printf("%s", movie.movieStatus);
    printf("\n\n");
}
#endif