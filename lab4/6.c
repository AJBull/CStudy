#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <limits.h>
 
void main() {
	char **names;
	char buffer[128];
        int i=0,size=0,length=0;
        int age=0,min=INT_MAX,max=INT_MIN;
        char *young;
        char *old;
        puts("Enter number of teammates");
        scanf("%d",&size);
        names = (char**) malloc(size*sizeof(char*));
	for(i=0; i<size; i++) {
		printf("Enter name of [%d] teammates: ", i+1);
		scanf("%127s", buffer);
		length = strlen(buffer);
		names[i] = (char*) malloc(length + 1);
		strcpy(names[i], buffer);
		printf("Enter age of [%d] teammates: ", i+1);
		scanf("%d", &age);
			if (age < min) 
					{
					min=age;
					young=names[i];
					}
			else if (age > max)
					{
					max=age;
					old=names[i];
					}		
	}
	
	for (i = 0; i < size; i++) 
		{
	        printf("%s\n", names[i]);
	        }
	                getchar();
	                 
printf("Young teammate is %s. His age is %d\n",young,min);
printf("Old teammate is %s. His age is %d\n",old,max);
	                     
	for (i = 0; i < size; i++) 
		{
	        free(names[i]);
	        }
	        free(names);
	}	  
	                                   

