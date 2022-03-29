#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "Users.h"


int main()
{
	EMP *e=NULL, *temp=NULL;
	int NoOfElems=1,ch=0;
	FILE *fp;
	char up_name[20];
	int id;

OpenLabel:
	fp = fopen("EmpInfo.dat","r+");
	if(fp == NULL)
	{
		printf("\nDataBase file not present. Hence creating one!\n");
		system("touch EmpInfo.dat");
		goto OpenLabel;
	}
	//printf("\nSizeof EMP=%d\n",sizeof(EMP));
	ch = dispMenu();
	switch(ch)
	{
		case 1: 
			//printf("\nEnter the no of employees: ");
			//scanf("%d",&NoOfElems);
			e = (EMP *)allocateEMP(NoOfElems);

			if(e == NULL)
			{
				printf("\nUnable to allocate Memory\n");
				exit(EXIT_FAILURE);
			}
			//temp is assigned to the BA returned by malloc
			//temp is storing the BA
			//temp = e;
			inputData(e, NoOfElems);
			//e = temp;
			Write2db(e,fp);
			
			break;
git 
		case 2:
			//e = temp;
			NoOfElems = ReadFromDB(e,fp);
			printf("\nNo of records = %d",NoOfElems);
			//display(e,NoOfElems);

			break;
		case 3:
				printf("\nEnter the id to be Updated with: ");
				scanf("%d",&id);
				printf("\nEnter the name to be updated with id =%d\n",id);
				scanf("%s",up_name);

				if(UpdatedRec(up_name,id,fp)==1)
				{
					printf("\nUpdated the record\n");
				}
				else
					printf("\nRecord Not Found\n");
				break;

		case 4:
				printf("\nEnter the id to be set to Inactive: ");
				scanf("%d",&id);
				
				if(UpdatAccState(id,fp)==1)
				{
					printf("\nDeactivated the record\n");
				}
				else
					printf("\nRecord Not Found\n");
				break;
		case 5:
			exit(EXIT_SUCCESS);
			break;
		default:
			printf("\nEnter the correct choice\n");


	}

		

	e = temp;
	free(e);
	
	fclose(fp);
	printf("\n\n");
	return 0;
}


