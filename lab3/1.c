  #include <stdio.h>
         int CountWords(void);
         main()
         {
            printf("Enter a string\n");
            CountWords();

         }
        int CountWords(void)
        {
            char c;
            int num=0;
            int flag= 0;
             while((c=getchar())!='\n')
            {
              if(c==' ')
              {
                flag=0 ;        
              }                         
              else if(flag==0)
              {
                num++;
                flag=1;     
              }                      
           }
              printf("Number of words is %d\n",num);
         }
