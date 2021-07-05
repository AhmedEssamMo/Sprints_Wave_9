#include "XOgame.h"
#include <stdio.h>
#include <conio.h>

char X_O_arr[3][3]={{'-','-','-'},
                    {'-','-','-'},
                    {'-','-','-'}};
char Player_One_char=0;
char Player_Two_char=0;
char Winner_Player=0;
char Index=0;
int row=0;
int col=0;
void Player_One(void)
{

    printf("Player One\n");
    while(1)
    {
        row=0;
        col=0;
        printf("ROW: ");
        scanf("%d",&row);// row is a global int
        fflush(stdin);
        printf("COL: ");
        scanf("%d",&col);// col is a global int
        fflush(stdin);
        system("cls");


        if((row>3)||(col>3)||(row<=0)||(col<=0))
        {
            Print_Game_arr();
            printf("\nInvalid\n");
        }
        else if(((row<=3)||(col<=3))&&((row>0)||(col>0)))
        {

            if(X_O_arr[row-1][col-1]=='-'){

                if(Player_One_char=='X')
                {
                    X_O_arr[row-1][col-1]='X';
                }
                else if(Player_One_char=='O')
                {
                    X_O_arr[row-1][col-1]='O';
                }
                else{}

            Print_Game_arr();
            printf("\n");
            Index++;
            break;
            }
            else
            {
                Print_Game_arr();
                printf("This place is taken,Please choose another place\n");
            }

        }
    }

}
void Player_Two(void)
{
    printf("Player Two\n");
    while(1)
    {
        row=0;
        col=0;
        printf("ROW: ");
        scanf("%d",&row);// row is a global int
        fflush(stdin);
        printf("COL: ");
        scanf("%d",&col);// col is a global int
        fflush(stdin);

        system("cls");


        if((row>3)||(col>3)||(row<=0)||(col<=0))
        {

            Print_Game_arr();
            printf("\nInvalid\n");
        }
        else if(((row<=3)||(col<=3))&&((row>0)||(col>0)))
        {

            if(X_O_arr[row-1][col-1]=='-')
            {
            if(Player_One_char=='X')
            {
                X_O_arr[row-1][col-1]='O';
            }
            else if(Player_One_char=='O')
            {
                X_O_arr[row-1][col-1]='X';
            }
            else{}

            Print_Game_arr();
            printf("\n");
            Index++;
            break;
            }
            else
            {
                Print_Game_arr();
                printf("This place is taken,Please choose another place\n");
            }
        }
    }
}
void Print_Game_arr(void)
{
    for(row=0;row<3;row++)
    {
        printf("-------------\n");
        printf("|");
        for(col=0;col<3;col++)
        {

            printf(" %c |",X_O_arr[row][col]);
        }

        printf("\n");
    }
    printf("-------------\n");
}
void Choose_X_O(void)
{
        while(1)
    {
        printf("Please choose X or O for Player one\n");
        Player_One_char= getch();
        if((Player_One_char=='x')||(Player_One_char=='X')){
            printf("Player one is 'X'\n");
            Player_One_char='X';
            printf("Player Two is 'O'\n");
            Player_Two_char='O';
            break;
        }
        else if((Player_One_char=='o')||(Player_One_char=='O')){
            printf("Player one is 'O'\n");
            Player_One_char='O';
            printf("Player Two is 'X'\n");
            Player_Two_char='X';
            break;
        }
        else
        {
            printf("Wrong!\n");
        }
    }
}

char Pickinig_the_winner()
{
    if((Index%2)==0)
    {
        for(row=0;row<3;row++)
        {
            if((X_O_arr[row][0]==X_O_arr[row][1])&&(X_O_arr[row][0]!='-'))
                {
                if(X_O_arr[row][0]==X_O_arr[row][2])
                {
                    Winner_Player=2;
                    return 1;
                }
            }
        }

        if((X_O_arr[0][0]==X_O_arr[1][1])&&(X_O_arr[0][0]!='-'))
        {
            if(X_O_arr[0][0]==X_O_arr[2][2])
            {
                Winner_Player=2;
                return 1;
            }
        }
        if((X_O_arr[2][0]==X_O_arr[1][1])&&(X_O_arr[1][1]!='-'))
        {
            if(X_O_arr[2][0]==X_O_arr[0][2])
            {
                Winner_Player=2;
                return 1;
            }
        }

        for(col=0;col<3;col++)
        {
            if(((X_O_arr[0][col])==(X_O_arr[1][col]))&&((X_O_arr[0][col])!='-'))
            {
                if(X_O_arr[1][col]==X_O_arr[2][col])
                {
                    Winner_Player=2;
                    return 1;
                }
            }
        }
    }
    if((Index%2)==1)
    {
        for(row=0;row<3;row++)
        {
            if((X_O_arr[row][0]==X_O_arr[row][1])&&(X_O_arr[row][0]!='-'))
                {
                if(X_O_arr[row][0]==X_O_arr[row][2])
                {
                    Winner_Player=1;
                    return 1;
                }
            }
        }

        if((X_O_arr[0][0]==X_O_arr[1][1])&&(X_O_arr[0][0]!='-'))
            {
            if(X_O_arr[0][0]==X_O_arr[2][2])
            {
                Winner_Player=1;
                return 1;
            }
        }
        if((X_O_arr[2][0]==X_O_arr[1][1])&&(X_O_arr[1][1]!='-'))
        {
            if(X_O_arr[2][0]==X_O_arr[0][2])
            {
                Winner_Player=1;
                return 1;
            }
        }

        for(col=0;col<3;col++)
        {
            if((X_O_arr[0][col]==X_O_arr[1][col])&&(X_O_arr[0][col]!='-'))
                {
                if(X_O_arr[1][col]==X_O_arr[2][col])
                {
                    Winner_Player=1;
                    return 1;
                }
            }
        }
    }
    return 0;
}
void X_O_Game(void)
{
    Choose_X_O();
    while(Index!=9)
    {
        if(Index>=4){

            if(Pickinig_the_winner()==1){
                printf("The winner is Player No. %d \n",Winner_Player);
                break;
            }

            if((Index%2)==0)
            {
            Player_One();
            }
            else if((Index%2)==1)
            {
             Player_Two();
            }
            else{}

        }
        else
        {
            if((Index%2)==0)
            {
            Player_One();
            }
            else if((Index%2)==1)
            {
             Player_Two();
            }
            else{}

        }
    }
    if((Pickinig_the_winner()==0)&&(Index==9))
            {
                printf("No winner\n");

            }
}
