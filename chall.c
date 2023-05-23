#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
    {
        char *username = "";
        char *password = "";
        char *role = "";
        char *display_name = "Guest";
        printf("Enter Your Credential to Login!\n");
        while(1)
        {
            printf("\n1: Insert Credential\n");
            printf("2: Configure Display Name\n");
            printf("3: Reset Credential\n");
            printf("4: Login\n");
            printf("5: Exit\n");
            printf("Selection? ");
            int num = 0;
            scanf("%d", &num);

            switch(num)
            {
            case 1:
                while (1) {
                    username = malloc(20*sizeof(char));
                    printf("Insert Username: ");
                    scanf("%254s", username);

                    if (strcasecmp(username,"admin") == 0)
                    {
                        printf("admin not allowed.\n");
                        strcpy(username,"");
                    }
                    else break;
                }
                
                password = malloc(20*sizeof(char));
                printf("Insert Password: ");
                scanf("%254s", password);

                while (1) {

                    role = malloc(20*sizeof(char));
                    printf("Insert Role (User/Admin): ");
                    scanf("%254s", role);

                    if (strcasecmp(role,"admin") == 0)
                    {
                        printf("admin not allowed.\n");
                        strcpy(role,"");
                    }
                    else if (strcasecmp(role,"user") != 0)
                    {
                        printf("not valid role.\n");
                        strcpy(role,"");
                    }
                    else break;
                }
            break;
            case 2:
                display_name = malloc(20*sizeof(char));
                printf("Insert Display Name: ");
                scanf("%254s", display_name);
            break;
            case 3:
                printf("Your Credential has be reseted!\n");

                free(username);
                free(password);
                free(role);
            break;
            case 4:
                if (strcasecmp(username,"admin") == 0 && strcasecmp(role,"admin") == 0)
                {
                    printf("You are logged in as admin!\n");
                    system("echo \"Hi, here is your flag\"; cat flag.txt");
                    exit(0);
                } 
                else if (strcasecmp(username,"") != 0 && strcasecmp(role,"") != 0) {
                    if (strcasecmp(display_name,"") == 0) {
                        printf("Welcome!\n");
                    } else {
                        printf("Welcome, %s!\n", display_name);
                    }
                    
                    exit(0);
                } 
                else {
                    printf("Please enter your credential!\n");
                }
            break;
            case 5:
                exit(0);
            default:
                printf("Please enter valid input!\n");
            }
        }

    }   