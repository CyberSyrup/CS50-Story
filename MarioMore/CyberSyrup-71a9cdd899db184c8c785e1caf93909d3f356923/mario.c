#include <cs50.h>
#include <stdio.h>

int main(void)
{
    
    //Prompting the user
    int x;
    do
    {
        x = get_int("Height: ");
    }
    while (x > 8 || x < 1);

    //Creating the loop
    for (int n = 0; n < x; n++)
    {
        //Creating a loop inside loop
        for (int j = 1; j < x; j++)
        {
            printf(" ");
        }
        printf("#  #\n");
        
        for (n = 1; n < x; n++)
        {
            for (int j = 2; j < x; j++)
            {
                printf(" ");
            }
            printf("##  ##\n");
            
            for (n = 2; n < x; n++)
            {
                for (int j = 3; j < x; j++)
                {
                    printf(" ");
                }
                printf("###  ###\n");
                for (n = 3; n < x; n++)
                {
                    for (int j = 4; j < x; j++)
                    {
                        printf(" ");
                    }
                    printf("####  ####\n");
                    for (n = 4; n < x; n++)
                    {
                        for (int j = 5; j < x; j++)
                        {
                            printf(" ");
                        }
                        printf("#####  #####\n");
                        for (n = 5; n < x; n++)
                        {
                            for (int j = 6; j < x; j++)
                            {
                                printf(" ");
                            }
                            printf("######  ######\n");
                            for (n = 6; n < x; n++)
                            {
                                for (int j = 7; j < x; j++)
                                {
                                    printf(" ");
                                }
                                printf("#######  #######\n");
                                for (n = 7; n < x; n++)
                                {
                                    //Don't need another loop
                                    printf("########  ########\n");
                                }
                     
                            }
                    
                        }
                   
                    }
                  
                }
                 
            }
                  
                 
        }
        
    }
    
}