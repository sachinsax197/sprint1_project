#include <stdio.h>
#include <stdlib.h>
#include "moviedetails.c"
#include "Declaration.h"
#include <strings.h>



int main()
{
	system("clear");

	USERS u;
//	char t[2] = {'\0'};
	int n;
	char ch;
	int uid, flag = 0;
	char passwd[20] = {'\0'};
	char name[20] = {'\0'};

	FILE *ft;
//	int **seat, choice, price = 500, slection, i;
//	seat = (int **)calloc(101, sizeof(int *));
	for (i = 0; i < 3; i++)
		*(seat + i) = (int *)calloc(101, sizeof(int));
	int x, y;

	while (y != 4)
	{
		choice = choice2();
		switch (choice)
		{
		case 1:
			printf("\nUser Login\n");
			ft = fopen("Users.dat", "r");
			if (ft == NULL)
			{
				printf("\n No Database Found\n");
				printf("\n First Create a Database\n");
				break;
			}
			printf("Enter the User Id=");
			scanf("%d", &uid);
			while (fread(&u, sizeof(u), 1, ft))
				if (u.Uid == uid)
				{
					flag = 1;
					printf("\nEnter the Password=\n");
					scanf("%s", &passwd);
					if (strcmp(u.Upasswd, passwd) == 0)
					{
						printf("\n Login Successfull\n");
					}
				}

			if (flag == 1)
			{
				printf("\n User Id Found But Password Mismatch\n");
			}
			else
			{
				printf("\n User Id Not Found!!!.. Please Try Again\n");
			}

			break;
		case 2:
			printf("\nRegisteration screen\n");
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
				printf("\n Data Inserted Successfully\n");
			else
				printf("\n Data not Inserted\n");
			
			break;
		case 3:
			printf("\n Admin Login");
			ft = fopen("Admin.dat", "r");
			if (ft == NULL)
			{
				printf("\n No Database Found\n");
				printf("\n First Create a Database\n");
				break;
			}
			printf("Enter the Admin Id=\n");
			scanf("%d", &uid);
			while (fread(&u, sizeof(u), 1, ft))
				if (u.Uid == uid)
				{
					flag = 1;
					printf("\nEnter the Admin Password=\n");
					scanf("%s", &passwd);
					if (strcmp(u.Upasswd, passwd) == 0)
					{
						printf("\n Login Successfull\n");
					}
				}

			if (flag == 1)
			{
				printf("\n Admin Id Found But Password Mismatch\n");
			}
			else
			{
				printf("\n Admin Id Not Found!!!.. Please Try Again\n");
			}

			break;
		case 4:
			y = 4;
			printf("\nExit");
			break;
		default:
			printf("\n Enter the correct Choice\n");

			break;
		}
	}

/*	while (x != 5)
	{
		choice = choice1();
		switch (choice)
		{
		case 1:
			price = changeprize(price);
			break;
		case 2:
			details();
			break;
		case 3:
			slection = movie();
			reservation(seat[slection - 1], price, slection);
			count++;
			break;
		case 4:
			slection = cmovie();
			cancel(seat[slection - 1]);
			break;
		case 5:
			x = 5;
			break;
		default:
			printf("Choice not available\n");
			break;
		}
	}*/
	return 0;
}
