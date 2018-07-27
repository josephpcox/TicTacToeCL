/* Joseph Cox                                                                 *
 *                                                                            *
 * ticTacToe.c                         6/21/17                                *
 *                                                                            *
 * @Def: C program creats a game of tic-tac-toe and allows the user to play   *
 *       multiple times.Game ends on draw player 1 win or player 2 win a win  *
 *       is defind as three in a row in any column or row as well as a        *
 *       a diagonal going left to right or rigt to left. Rows and columns     *
 *       start at 0 and end at 2. Program quits when the user selects 'y' or  *
 *       'n' after one complete game is complete.                             *  
 ******************************************************************************/


#include <stdio.h>
// player definitions and tokens
#define PLAYER_ONE 'O'
#define PLAYER_TWO 'X'

// booleans for loop control and eror checks 
#define TRUE 1
#define FALSE 0



/**************************************************************************************************************
 * @Def: creats the tic tac toe game and can also be used to reset the board, it uses pointer
 *       arthimetic to set evry character in the tic tac toe arry to the space character
 * @param: char c [], char *pointer
 **************************************************************************************************************/
void make_game(char c[9], char *pointer)
{
    for(pointer =c; pointer< c+9; pointer++)
    {
        *pointer =' ';
    }
}
/**************************************************************************************************************
 * @Def: creats the tic tac toe board
 * @param: char c [], char *pointer
 **************************************************************************************************************/
void print_game(char c [9], char *pointer){

    for(pointer = c; pointer<c+9 ; pointer++)
    {

        if(pointer == c+2 || pointer == c+5 )
        {
            printf(" %c\n",*pointer);
            printf("---+---+---\n");
        }
        else if( pointer == c+1 || pointer == c+4 || pointer == c+7)
        {
             printf(" | %C |" ,*pointer);
        }
        else
        {
            printf(" %c", *pointer);
        }

    }

    printf("\n\n");
}
/**************************************************************************************************************
 * @Def: Allows changes for the values of the Tic Tac Toe board, if the move is sucesseful the function
 *       Returns a 1 for TRUE and if move is not sucessful it return 0 for FALSE.
 * @param: int row, int column, char wh_player, char c[]
 **************************************************************************************************************/
int move(int row,int column,char wh_player,char c [])
{
   char* row_zero=c;
   char* row_one=c+3;
   char* row_two=c+6;
   int boolean =TRUE;

   // controlls moves made in row 0.............................................................................
   if(row>=0 && row<1)
   {
       if(*(row_zero+column)== ' ')
       {
           *(row_zero+column)=wh_player;
       }
       else
       {
           boolean = FALSE;
           printf("Error: Space is filled, select a different space\n");
       }
        
   }
   // controlls moves made in row 1...............................................................................
   else if(row>=1 && row<2)
   {
       if(*(row_one + column)== ' ')
       {
           *(row_one + column)=wh_player;
       }
       else
       {
           boolean = FALSE;
           printf("Error: Space is filled, select a different space\n");
       }
       
   }
   // controlls moves made in row 2..................................................................................
   else if(row>=2 && row<3)
   {
       if(*(row_two+column)== ' ')
       {
           *(row_two+column) = wh_player;
       }
       else
       {
           boolean = FALSE;
           printf("Error: Space is filled, select a different space\n");
       }
       
   }
   else 
   {
       boolean =FALSE;
       printf("Error: No move was made, move went out of bounds\n");
   }
   return boolean;
}
/**************************************************************************************************************
 * @Def: Checks to see if there is a three in a row for the tic tak toe board or if there 
 *        is a draw. Makes sure that the spaces are not empty then checks rows, columns, 
 *        and diagonals. If there is a winner it will print out who won, as well as print 
 *        out a draw if there is no winner.
 * @param: char c[], char * pointer
 **************************************************************************************************************/
int check_win(char c[], char* pointer)
{
    pointer = c;
    int boolean = FALSE;

    // checking row zero........................................................................
    if(*pointer== 'X'|| *pointer== 'O')
    {
        if(*pointer == *(pointer+1) && *pointer == *(pointer+2))
        {
            if(*pointer == PLAYER_ONE)
            {
                printf("****player 1 wins!****\n");
                boolean= TRUE;
            }
            else
            {
                printf("****player 2 wins!****\n");
                boolean= TRUE;
            }
        }
    }
    // checking row one.............................................................................
    if((*(pointer +3)== 'X') || (*(pointer+3)=='O'))
    {

        if((*(pointer +3) == *(pointer+4)) && (*(pointer +3) == *(pointer+5)))
        {
            if(*(pointer+3) == PLAYER_ONE)
            {
                printf("****player 1 wins!****\n");
                boolean= TRUE;
            }
            else
            {
                printf("****player 2 wins!****\n");
                boolean= TRUE;
            }  
        }
    }
    // checking row two..................................................................................
    if((*(pointer+6)=='X')||(*(pointer+6)=='O'))
    {

        if((*(pointer +6) == *(pointer+7)) && (*(pointer+6) == *(pointer+8)))
        {
            if(*pointer == PLAYER_ONE)
            {
                printf("****player 1 wins!****\n");
                boolean=TRUE;
            }
            else
            {
                printf("****player 2 wins!****\n");
                boolean= TRUE;
            }  
        }
    }
    // checkig column zero ...............................................................................
    if((*pointer == 'X') || (*pointer=='O'))
    {
        if((*pointer == *(pointer+3)) && (*pointer == *(pointer+6)))
        {
             if(*pointer == PLAYER_ONE)
            {
                printf("****player 1 wins!****\n");
                boolean =TRUE;
            }
            else
            {
                printf("****player 2 wins!****\n");
                boolean =TRUE;
            }  
        }
    }
    // checking column one................................................................................
    if((*(pointer+1)== 'X') || (*(pointer+1)=='O'))
    {
        if((*(pointer+1) == *(pointer+4)) && (*(pointer+1) == *(pointer+7)))
        {
             if(*(pointer+1) == PLAYER_ONE)
            {
                printf("****player 1 wins!****\n");
                boolean= TRUE;
            }
            else
            {
                printf("****player 2 wins!****\n");
                boolean=TRUE;
            } 
        }
    }
    // checking column two ...............................................................
    if((*(pointer+2)=='X')|| (*(pointer+2)=='O'))
    {
         if((*(pointer+2) == *(pointer+5)) && (*(pointer+2) == *(pointer+8)))
        {
             if(*pointer == PLAYER_ONE)
            {
                printf("****player 1 wins!****\n");
                boolean= TRUE;
            }
            else
            {
                printf("****player 2 wins!****\n");
                boolean = TRUE;
            } 
        }
    }
    // checking left to right diagonal........................................................ 
    if((*pointer== 'X') || (*pointer=='O'))
    {
          if((*pointer == *(pointer+4)) && (*pointer == *(pointer+8)))
        {
             if(*pointer == PLAYER_ONE)
            {
                printf("****player 1 wins!****\n"); 
                boolean = TRUE;
            }
            else
            {
                printf("****player 2 wins!****\n\n");
                boolean = TRUE;
            } 
        }
    }
    // right to left diagonal ................................................................
    if((*(pointer+2)== 'X') || (*(pointer+2)=='O'))
    {
            if((*(pointer+2)==*(pointer+4)) && (*(pointer+2)==*(pointer+6)))
            {
                if(*(pointer+2) == PLAYER_ONE)
                {
                    printf("****player 1 wins!****\n");
                    boolean = TRUE;
                }
                else
                {
                    printf("****player 2 wins!****\n");
                    boolean = TRUE;
                }
            }
    }
    // cheking draw............................................................................
    if(boolean ==FALSE)
    {
        if(*pointer!=' ' && *(pointer+1)!=' ' && *(pointer+2)!=' ' && *(pointer+3)!=' ' && *(pointer+4)!=' '
        && *(pointer+5)!=' '&& *(pointer+6)!=' '&& *(pointer+7)!=' '&& *(pointer+8)!=' ')
        {
            boolean = TRUE;
            printf("****Draw !****\n");
        }
    }
    return boolean;
   
} 

int main(void)
{
    // initiliazation of game and necessary variables.
    char board [9];
    char *point;
    point = board;
    make_game(board,point);
    int turn=TRUE;
    int row =0;
    int column =0;
    char another = 'y';
    
    printf("\n\n**** Tic-Tac-Toe ****\n");
    print_game(board,point);
    
    while(another!='n')
    {
        // player 1's turn 
        if(turn==TRUE)
        {
            printf("\nCurrent move: player %d\n",1);
            printf("Enter row: ");
            scanf("%d",&row);
            printf("Enter column: ");
            scanf("%d",&column);

            // since the function move() returns 0 or 1 it can see if a sucessful move was made
            //loope won't break untill a sucessful move is made
            while(move(row,column,PLAYER_ONE,board)!=TRUE)
            {
                printf("\nCurrent move: player %d\n",1);
                printf("Enter row: ");
                scanf("%d",&row);
                printf("Enter column: ");
                scanf("%d",&column);
            }
            print_game(board,point);

            // changes turn to false to controll who moves player 1 or player 2
            turn=FALSE;

        }
        // player 2's turn
        else if(turn == FALSE)
        {
            printf("\nCurrent move: player %d\n",2);
            printf("Enter row: ");
            scanf("%d",&row);
            printf("Enter column: ");
            scanf("%d",&column);
            
            // since the function move() returns 0 or 1 it can see if a sucessful move was made
            //loope won't break untill a sucessful move is made
            while(move(row,column,PLAYER_TWO,board)!=TRUE)
            {
                printf("\nCurrent move: player 2\n");
                printf("Enter row: ");
                scanf("%d",&row);
                printf("Enter column: ");
                scanf("%d",&column);
            }
            print_game(board,point);
            turn=TRUE;

        }

        if(check_win(board,point)==TRUE)
        {
            // clear key board buffer
            while(getchar()!='\n');

            printf("would you like to play another game? (y/n): ");
            scanf("%c",&another);
            if(another == 'y')
            {
                printf("\n\n**** Tic-Tac-Toe ****\n");
                make_game(board,point);
                print_game(board,point);
            }
            else
            {
                printf("****Thank you for playing Tic-Tac-Toe!****\n");
            }
        }

    }
    
    return 0;
}