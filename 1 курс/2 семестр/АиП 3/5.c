#include <stdio.h>
#include <string.h>
int main()
{   setlocale(0,"RUS");
	int start = 0, i = 0, j;
    char w[][20]={"",""}, ch;
    FILE *f;
    f = fopen("1.txt","rt");
	if (f==NULL)
    {   fprintf(stderr,"Не могу открыть файл \n"); 
		return 1; 
    }
	while(1)
    {   
		for(j=0; j<2;j++)
        { 
			while(1)
          	{ 	ch = fgetc(f);
            	if(ch==EOF || (ch==' ' && start)) 
            	{   
					w[j][i]='\0';
                	i = 0;
                	start--;
                	break;
            	}
            	if(ch!=' ')
            	{   
					if(!start) start++;
                	w[j][i] = ch;
                	i++;
            	}
          	}
        	if(ch==EOF) break;
       }
    	printf(" %s %s", w[1],w[0]);
        if(ch==EOF) break;
        for(j=0; j<2;j++) strcpy(w[j],"");
    }
    fclose(f);
    return 0;
}
