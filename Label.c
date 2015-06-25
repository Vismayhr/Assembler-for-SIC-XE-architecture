/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>*/

/*for create func, pass name and addr(as a ptr). for search func, only pass name. #include<stdlib> to avoid malloc related warnings*/




//creating a new label
void CreateLabel(char *str)
{
	int num =0;	
	int count;
	count = strlen(str);
	int i=0;	
	struct labl *temp; 
	temp = malloc(sizeof(struct labl));
	temp->link = NULL;				
	temp->addr = 0;						//assign address value
	strcpy(temp->name,str);						//assign name of the label
	while(count != 0)						//creating hash value
	{
		num += (temp->name[i++]);	
		count--;
	}
	num = num%10;
	if(labelIndex[num] == NULL)
		labelIndex[num] = temp;
	else
	{
		temp->link = labelIndex[num];
		labelIndex[num] = temp;
	}
	globalLabelStruct = temp;
}


//Search for an already created label. return 1 if found, else 0

int SearchLabel(char *str)
{
	int n;	
	struct labl *temp;	
	int i =0;	
	char tempstr[20];
	strcpy(tempstr,str);	
	int num = 0;
	for(i=0;i<strlen(tempstr);i++)
		num += *str++;

	num = num%10;
	temp = labelIndex[num];

	if(temp == NULL)
	{
		return 0;
	}
	else
	{
		while(1)
		{		
			if(!strcmp(temp->name,tempstr))	
			{	
				SearchLabelStruct = temp; 	
				return 1;
			}

			temp = temp->link;

			if(temp == NULL)
			{
				return 0;
			}	
		}
	}
}





void labdisplay()
{
	printf("\nLabel hash table: \n"); 	
	//printf("\nThe values in the hash table are: \n\n");
	int i,j;
	for(i=0;i<10;i++)
	{
		if(labelIndex[i] == NULL)
		{
			printf("\t%d --> Empty\n",i);
		}
		else
		{
			struct labl *temp; 
			temp = labelIndex[i];
			printf("\t%d",i);
			while(temp != NULL)
			{	
				printf("--> %s,%d ",temp->name,temp->addr);
				temp =  temp->link;
			}
			printf("\n");
		}
	}
}

/*

int main(void)
{
	char str[20];
	int choice;
	int i;
	while(1)
	{
		printf("\nEnter choice value: ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
					printf("\nEnter the label: ");
					scanf("%s",str);
					CreateLabel(str);
					break;
			case 2:
					printf("\nEnter the label to be searched for: ");
					scanf("%s",str);
					if(SearchLabel(str))	
						printf("\nLabel is found");
					else
						printf("\nLabel not found");
					break;
			case 3:
					display();
					break;
			default: printf("\nInvalid value is entered as choice\n"); 
				 break;
		}
	}
}*/
