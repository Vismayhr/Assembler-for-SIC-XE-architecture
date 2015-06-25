void InsertIntoErrorBuff(char *str)			//Func to insert error messages into the error buffer 
{
	int i=0;
	int x,y,z;
	z=lineCount-1;
	y = z%10;
	y = y+ 0x30;
	z = z/10;
	x = z + 0x30;
	errorBuff[errorBuffIndex++] = x;
	errorBuff[errorBuffIndex++] = y;
	errorBuff[errorBuffIndex++] = ':';
	errorBuff[errorBuffIndex++] = ' ';	
	while(str[i] != '\0')
		{
			errorBuff[errorBuffIndex++] = str[i++];
			//errorBuffIndex++;
		}
	errorBuff[errorBuffIndex++] = '\n';
	//errorBuff[errorBuffIndex] = '\0';		//will get overwritten if new strings are added into buffer
	return;
} 


void InsertWithinRange(char *str,int i, int j,char *str2)	//Return type changed from char* to void
{
	int index,l=0;
	index = i;
	while((index >= i) && (index<=j))
		str2[l++] = str[index++];
	str2[l] = '\0';
	//return str2;

}
		

int CheckVarAndLabel()						//Check if all variables and labels have been defined
{
	struct var *v;
	struct labl *l;
	int i=0,flag = 1;
	while(i < 10)
	{
		v = varIndex[i];
		l = labelIndex[i];
		i++;		
	
		if((v==NULL) && (l==NULL))
			continue;
	
		while(v != NULL)
		{
			if(!strcmp(v->val,"NULL"))
			{
				flag = 0;
				InsertIntoErrorBuff(missingVar); 	
			}				
			v = v->link;
		}

		while(l != NULL)
		{
			if(l->addr == 0)
			{
				flag = 0;
				InsertIntoErrorBuff(missingLabel);
			}
			l = l->link;
		}
	}
	return flag;
}





/*void InsertIntoVarLabErrorBuff(char *str, char *str1)			//Func to insert error messages into the error buffer 
{
	int i=0;
	
	while(str[i] != '\0')
	{
		varLabErrorBuff[varLabErrorBuffIndex++] = str[i++];
	}
	varLabErrorBuff[varLabErrorBuffIndex++] = ':';	
	i=0;
	
	while(str1[i] != '\0')
	{
		varLabErrorBuff[varLabErrorBuffIndex++] = str[i++];
	}
	varLabErrorBuff[varLabErrorBuffIndex++] = '\n';
	return;
} */


		


		


