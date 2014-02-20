#include <stdio.h> 
#include <locale.h> 
#include <string.h>
 
int main(int argc, char *argv[]) {
    char str[101] = "";
    char res[101] = "";
    
    printf("Enter a string:\n");
    fgets (str, 101, stdin);
    
    
    int j = 0;
    int i;
    for (i = 0; i<strlen(str) ; i++) {
        if (str[i] == ' ')
        {
          if (j==0) continue;
          if (str[i+1] == ' ') continue;
        }
        res[j] = str[i];
        j++;
    }
    i=strlen(res);
    if(res[i-2] == ' ')
        res[i-2] = '\0';
 
    printf("\nThe result:\n%s\nThe termination has been trimmed :)\n", res);
    return 0;
}
