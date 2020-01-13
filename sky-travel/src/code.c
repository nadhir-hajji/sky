#include <gtk/gtk.h>
#include "code.h"
#include <string.h>
int verifiercode(char p[])
{
FILE *f;
f=fopen("code.txt","r");
char codeprom[300];
int i=0;
if (f!=NULL) while(fscanf(f,"%s \n",codeprom)!=EOF)
				{if (strcmp(codeprom,p)==0) i=1;
						}

return i ;
fclose(f);





}
