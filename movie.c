#include<stdio.h>
#include<stdlib.h>
#include<string.h>



char r;
void login(){
	int a=0,i=0;
	char uname[10],c=' ',pword[10],code[10],user[]="user",pass[]="pass";
	do{
		printf("\n---------------------------LOGIN----------------------\n");
		printf("\n\t\tEnter Username: ");
		scanf("%s",uname);
		getchar();
		printf("\t\tEnter Password: ");
		/*while(i<10){
			pword[i]=getch();
			c=pword[i];
			if(c==13)//enter key
				break;
			else
				printf("*");
			i++;
		}
		pword[i]='\0';
		i=0;*/
		scanf("%s",pword);
		if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0){
			printf("\n\nWELCOME TO THE BOOKING SYSTEM. LOGIN SUCCESSFUL\n");
			printf("\n\t\tPress enter to continue........");
			scanf("%c%c",&r,&r);
			break;
		}
		else{
			printf("\n\nLOGIN UNSUCCESSFUL.....");
			a++;
		}
	}
	while(a<2);
	if(a>1){
		printf("\nSorry you entered an incorrect password 3 times. Press Enter to continue");
		scanf("%c%c",&r,&r);
	}
	system("clear");
}
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
void main(){
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
            printf("\nEnter the gmail id for search in the database=");
            scanf("%s", &email);
            while (fread(&u, sizeof(u), 1, ft))
            {
                if (strcmp(u.email, email) == 0)
                {
                    flag = 1;
                    printf("\nEnter the Password=\n");
                    scanf("%s", &pass);
                    if (strcmp(u.Upasswd, pass) == 0)
                    {
                        flag=2;
                        printf("\n Login Successfull\n");
                        n1 = choice2();
                        options(&u, n1);
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
             ft = fopen("guest.dat", "r");
            if (ft == NULL)
            {
                printf("\n No Database Found\n");
                printf("\n First Create a Database\n");
              
            }
            ft=fopen("guest.dat","a+");
			n2=choice4();
			guest(n2);

            break;

        case 4:
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
                            adminOptions(movies, u, n3);
                            printf("\nProcess Complete\n");
                        }
                    }
                }
                if (flag == 0)
                    printf("\n Admin id doesnot found in the database\n");
                else if (flag == 1)
                    printf("\nUserid Found But Password Doesn't Match..!!\n");
            }

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













	login();










	int ch;
 	while(1){
		printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");	
		printf("\n\t Book Movie Ticket \n");
		printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
		printf("\nEnter >1< To Insert A Movie\nEnter >2< To View All Movies\nEnter >3< To Find A Movie\nEnter >4< To Book A Ticket(s)\nEnter >5< To View All Recent Transactions\nEnter >0< To Exit \nEnter your Choice :");
	   	scanf("%d",&ch);
	   	system("clear");	
	   	switch (ch){
	    		case 1: insert_details();
	   			break;
			case 2: view_All();
	   			break;    		
			case 3: find();
	   			break;
			case 4: book_ticket();
				break;	
			case 5: old_records();
				break;
	    		case 0: exit(0);
	    		default: printf("Enter a valid option.");
	   	}
	 }
}

void welcomeScreen()
{

    printf(" ******************************************************************\n");
    printf(" ==================================================================\n");
    printf(" ==================================================================\n");
    printf("                              WELCOME TO                           \n");
    printf("                      MOVIE TICKET BOOKING SYSTEM                  \n");
    printf(" ==================================================================\n");
    printf(" ==================================================================\n");
    printf(" ******************************************************************\n");
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
    printf("||                  4- To Admin Login                               ||\n");
    printf("||                  5- Exit system:                                 ||\n");
    printf("||==================================================================||\n");
    printf(" ********************************************************************\n");

    printf("  Enter your choice: ");
    scanf("%d", &choice);
    return choice;
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
		printf("FIle not Found");
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
				printf("\n Record Found\n");
				printf("\n\t\tCode :%s",b.code);
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
	printf("\n For Book ticket Choice Movie(Enter Movie Code First Latter Of Movie)\n");
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
	printf("\n Total number of tickets :");
	scanf("%d",&total_seat);	
	total_amount = b.cost * total_seat;
	printf("\n ENJOY YOUR MOVIE \n");
	printf("\n\t\tName : %s",name);
	printf("\n\t\tMobile Number : %d",mobile);
	printf("\n\t\tMovie name : %s",b.name);
	printf("\n\t\tTotal seats : %d",total_seat);
	printf("\n\t\tCost per ticket : %d",b.cost);
	printf("\n\t\tTotal Amount : %d",total_amount);
	ufp=fopen("oldTransection.txt","a");
	if(ufp == NULL){
		printf("File not Found");
	}
	else{
		fprintf(ufp,"%s %d %d %d %s %d \n",name,mobile,total_seat,total_amount,b.name,b.cost);
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
		while((ch=fgetc(fp))!=EOF)
      		printf("%c",ch);	
	}
	printf("\n\t\tPress enter to continue........");
	scanf("%c%c",&r,&r);
	fclose(fp);
}