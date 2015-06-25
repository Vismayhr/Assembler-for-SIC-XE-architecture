/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>*/

/*for create func, pass name and addr(as a ptr). for search func, only pass name. #include<stdlib> to avoid malloc related warnings*/




//creating a new label
void CreateVar(char *str)
{
	int q = 0,r=0;	
	int num =0;	
	int count;
	count = strlen(str);
	int i=0;	
	struct var *temp; 
	temp = malloc(sizeof(struct var));
	temp->link = NULL;
	strcpy(temp->val,"NULL");


	strcpy(temp->name,str);	
	
	while(count != 0)										//creating hash value
	{
		num += (temp->name[i++]);	
		count--;
	}
	num = num%10;
	if(varIndex[num] == NULL)
		varIndex[num] = temp;
	else
	{
		temp->link = varIndex[num];
		varIndex[num] = temp;
	}
	globalVarStruct = temp;
}


//Search for an already created label. return 1 if found, else 0

int SearchVar(char *str)
{
	int q=0,r=0;	
	int n;	
	struct var *temp;	
	int i =0;	
	char tempstr[20];
	strcpy(tempstr,str);	
	int num = 0;
	for(i=0;i<strlen(tempstr);i++)
		num += *str++;

	num = num%10;
	temp = varIndex[num];

	if(temp == NULL)
		return 0;

	else
	{
		while(1)
		{		
			if(!strcmp(temp->name,tempstr))
			{	
				SearchVarStruct = temp;		//Used to obtain the addr of var in pass 2			
				return 1;
			}

			temp = temp->link;

			if(temp == NULL)		
				return 0;	
		}
	}
}






void vardisplay()
{
	//printf("\nEntering var display function\n"); 	
	printf("\nThe values in the hash table are: \n\n");
	int i,j;
	for(i=0;i<10;i++)
	{
		if(varIndex[i] == NULL)
		{
			printf("\t%d --> Empty\n",i);
		}
		else
		{
			struct var *temp; 
			temp = varIndex[i];
			printf("\t%d",i);
			while(temp != NULL)
			{	
				printf("--> %s,%d,%s ",temp->name,temp->addr,temp->val);
				temp =  temp->link;
			}
			printf("\n");
		}
	}
}


