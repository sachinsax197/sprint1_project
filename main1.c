#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Functions.h"
#include "Admin.h"

int main(int argc, char const *argv[])
{
    system("clear");

    USERS u;
    admin a;
    char t[2] = {'\0'};
    int n, n1, n2,n3;
    char ch;

    char pass[20] = {'\0'};
    char name[20] = {'\0'};
    char email[30] = {'\0'};

    int uid = 0, flag = 0;

    FILE *ft;

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
            printf("\nEnter the gmail id for search in the database=");
            scanf("%s", &email);
            while (fread(&u, sizeof(u), 1, ft))
            {
                if (strcmp(u.email,email)==0)
                {
                    flag = 1;
                    printf("\nEnter the Password=\n");
                    scanf("%s", &pass);
                    if (strcmp(u.Upasswd, pass) == 0)
                    {
                        printf("\n Login Successfull\n");
                        n1 = choice2();
                        options(&u,n1);
                        printf("\n Process complete\n");
                    }
                }
            }
            if (flag == 0)
                printf("\n Userid doesnot found in the database\n");
            else if (flag == 1)
                printf("\nUserid Found But Password Doesn't Match..!!\n");

            break;




        case 2:
            ft = fopen("Users.dat", "r");
            if (ft == NULL)
            {
                printf("\nUser Database File Doesnot Exist\n");
                printf("\nCreating User Record File\n");
            }

            ft = fopen("Users.dat", "a+");
            setUsers(&u);
            fwrite(&u, sizeof(u), 1, ft);
            if (fwrite != 0)
                printf("\n User Add Successfully\n");
            else
                printf("\nSomething Went Wrong\n");

            break;




            case 3:
            ft = fopen("Admin.dat", "r");
            if (ft == NULL)
            {
                printf("\n No Database Found\n");
                printf("\n First Create a Database\n");
                break;
            }
            printf("Enter the Admin Id for search in the database=\n");
            scanf("%d", &uid);
            printf("\nEnter the password=");
            scanf("%s", &pass);
            while (fread(&u, sizeof(u), 1, ft))
            {
                if (u.Uid == uid)
                {
                    flag = 1;
                    printf("\nEnter the Password=\n");
                    scanf("%s", &pass);
                    if (strcmp(u.Upasswd, pass) == 0)
                    {
                        printf("\n Login Successfull\n");
                        n3 = choice3();
                        // options(u,n1);
                    }
                }
            }
            if (flag == 0)
                printf("\n Userid doesnot found in the database\n");
            else if (flag == 1)
                printf("\nUserid Found But Password Doesn't Match..!!\n");
            else if (flag == 2)
                printf("\nLogin Successfull");

            // fclose(ft);
            break;




        case 4:
            ft = fopen("Admins.dat", "r");
            if (ft == NULL)
            {
                printf("\n No Database Found\n");
                printf("\n First Create a Database\n");
                break;
            }
             ft = fopen("Admins.dat", "a+");
            setAdmin(&a);
            getAdmin(a);
            fwrite(&u, sizeof(u), 1, ft);
            if (fwrite != 0)
                printf("\n User Add Successfully\n");
            else
                printf("\nSomething Went Wrong\n");

            printf("Login here=\n");

            printf("Enter the Admin Id for search in the database=\n");
            scanf("%d", &uid);
            while (fread(&u, sizeof(u), 1, ft))
            {
                if (u.Uid == uid)
                {
                    flag = 1;
                    printf("\nEnter the Password=\n");
                    scanf("%s", &pass);
                    if (strcmp(u.Upasswd, pass) == 0)
                    {
                        printf("\n Login Successfull\n");
                        n3 = choice3();
                        // options(u,n1);
                    }
                }
            }
            if (flag == 0)
                printf("\n Userid doesnot found in the database\n");
            else if (flag == 1)
                printf("\nUserid Found But Password Doesn't Match..!!\n");
            else if (flag == 2)
                printf("\nLogin Successfull");

            // fclose(ft);
            break;



        case 5:
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
    printf("\nEnd of Program\n");

    return 0;
}