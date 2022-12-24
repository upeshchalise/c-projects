#include <stdio.h>
#include <stdbool.h>

char checkTurn(int);
//tictactoe
void main() {
    char tictactoeArray[3][3] = {
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };
    int i,j,running=1,row,column,count=1;
    char previousValue=' ';
    char winner = ' ';
    bool win = false;

    printf("player with O starts first\n\n");

    while(running==1) {
        printf("Enter row column: ");
        scanf("%d %d",&row,&column);
        tictactoeArray[row][column] = checkTurn(count);
        
        printf("   0   1   2\n");
        for(i=0;i<3;i++) {  
            printf("%d ",i);
            printf("|");
            for(j=0;j<3;j++) {
                printf("%c |",tictactoeArray[i][j]);
            }
            printf("\n");
        }
        
        for(j=0;j<3;j++) {
            previousValue = tictactoeArray[j][0];
            if(previousValue==' ') continue;
            for(i=1;i<3;i++) {
                if(previousValue != tictactoeArray[0][i]) break;
                if(i>=2)
                    win = true;
                
            }
            if(win)
                winner = checkTurn(count);
        }

        for(j=0;j<3;j++){
            previousValue = tictactoeArray[0][j];
            if(previousValue==' ') continue;
            for(i=1;i<3;i++) {
                if(previousValue!=tictactoeArray[i][0]) break;
                if(i>=2)
                    win =true;
                
            }
            if(win)
                winner = checkTurn(count);
        }

        previousValue = tictactoeArray[0][0];
        for(i=1;i<3;i++) {
            if(previousValue==' ') break;
            if(previousValue!=tictactoeArray[i][i]) break;
            if(i>=2) {
                win=true;
                winner=checkTurn(count);
            }
        }

        previousValue = tictactoeArray[0][2];
        for(i=1;i<3;i++) {
            if(previousValue==' ') break;
            if(previousValue!=tictactoeArray[i][2-i]) break;
            if(i>=2) {
                win=true;
                winner=checkTurn(count);
            }
        }

        if(win){
            running =0;
            printf("\n%c  Won! \n",winner);
        }
        count++;
    }
      
}

char checkTurn(int value) {
    if(value%2!=0)
        return 'O';
    else
        return 'X';
}

