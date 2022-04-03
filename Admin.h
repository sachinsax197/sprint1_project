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
void adminOptions(m1 *,USERS ,int);

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
    printf("||                  2- View All Movie's List                        ||\n");
    printf("||                  3- Update Movie Details                         ||\n");
    printf("||                  4- View All Users                               ||\n");
    printf("||                  5- View Total Collection                        ||\n");
    printf("||                  6- Exit system:                                 ||\n");
    printf("||==================================================================||\n");
    printf("  Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}

void adminOptions(m1 *movie,USERS U, int n)
{
    FILE *ft;
    int flag = 0;
    int mId, k;
    int price, status;
    char timing[20] = {'\0'};
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
        ft = fopen("Movies.dat", "r");
        if (ft == NULL)
        {
            printf("\n No Database Found\n");
            printf("\n First Create a Database\n");
            break;
        }
        else
        {
            Printf("\nMovies Present in the Database\n");
            while (fread(&movie, sizeof(movie), 1, ft))
                getMovie(*movie);
        }
        
        break;
    case 3:

        ft = fopen("Movies.dat", "r+");
        if (ft == NULL)
        {
            printf("\n No Database Found\n");
            printf("\n First Create a Database\n");
            exit(EXIT_FAILURE);
        }
        printf("Enter the User Id for search in the database=\n");
        scanf("%d", &mId);
        while (fread(&movie, sizeof(movie), 1, ft))
            if (movie->movieId == mId)
            {
                flag = 1;
                break;
            }

        if (flag != 1)
            printf("\n MovieID doesnot found in the database\n");
        else
        {
            printf("\nMovie Found In the Database\n");
            printf("Current Details of the Movie=\n");
            getMovie(*movie);
            // break;
            printf("\nWhat do want to Update in the Movie..... Please Select Option:\n");
            printf("\n1-Update Price");
            printf("\n2-Update Status");
            printf("\n3-Update Timing");
            scanf("%d", &k);
            switch (k)
            {
            case 1:
                printf("\nEnter the new price of the movie:- ");
                scanf("%d", &price);
                movie->moviePrice = price;
                break;

            case 2:
                printf("\nEnter the status of the movie:- ");
                scanf("%d", &status);
                movie->movieStatus = status;
                break;

            case 3:
                printf("\nEnter the new timings of the movie:- ");
                scanf("%s", timing);
                strcpy(movie->movieTimings, timing);
                break;

            default:
                break;
            }

            fseek(ft, sizeof(movie) * (-1), SEEK_CUR);
            fwrite(&movie, sizeof(movie), 1, ft);
            printf("\n Movie Details Updated Successfully\n");
            getMovie(*movie);
        }

        break;
    case 4:
     ft = fopen("Users.dat", "r");
        if (ft == NULL)
        {
            printf("\n No Database Found\n");
            printf("\n First Create a Database\n");
            break;
        }
        else
        {
            Printf("\nAll Users Present in the Database\n");
            while (fread(&U, sizeof(U), 1, ft))
                getUsers(U);
        }
        break;
    case 5:
        break;
    case 6:
        exit(EXIT_SUCCESS);
        break;
    }
}

void setMovie(m1 *movie)
{
    printf("\nEnter Movie Name: ");
    scanf("%s", movie->movieName);
    fflush(stdin);
    printf("\nEnter the movie price:");
    scanf("%d", movie->moviePrice);
    printf("\nEnter the movie timing: ");
    scanf("%s", movie->movieTimings);
    fflush(stdin);
    printf("\nEnter the movie status: ");
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