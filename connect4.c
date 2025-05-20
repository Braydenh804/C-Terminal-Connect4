#include <stdio.h>
#include <stdbool.h>
#include "checkForWin.h"


char line1[] = "X X X X X X X";
char line2[] = "X X X X X X X";
char line3[] = "X X X X X X X";
char line4[] = "X X X X X X X";
char line5[] = "X X X X X X X";
char line6[] = "X X X X X X X";
char line[] =  "-------------";
char rowNumbers[] = "1 2 3 4 5 6 7";
int turnCount = 1;

bool isRedsTurn = true;
bool isYellowsTurn = false;
bool gameIsOver = false;
char *lines[] = {line1, line2, line3, line4, line5, line6};
char placedRow = 0;  
int gameArray[6][7] = {0};
int numInRow[] = {5, 5, 5, 5, 5, 5, 5};


void printBoard() {
    printf("Connect 4\n");
    printf("(Turn %d)\n", turnCount);
    if(gameIsOver) {
        printf("(Game Over)\n");
    } else if(isRedsTurn) {
        printf("(Red's Turn)\n");
    } else {
        printf("(Yellow's Turn)\n");
    }
    printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", line1, line2, line3, line4, line5, line6, line, rowNumbers);
}

void resetGame() {
    char line1[] = "X X X X X X X";
    char line2[] = "X X X X X X X";
    char line3[] = "X X X X X X X";
    char line4[] = "X X X X X X X";
    char line5[] = "X X X X X X X";
    char line6[] = "X X X X X X X";
    bool isRedsTurn = true;
    bool isYellowsTurn = false;
    bool gameIsOver = false;
    turnCount = 1;
}

int main() {
    while(!gameIsOver) {
        printBoard();
        printf("Type A Number 1-7 To Place Your Piece: ");
        scanf("%d", &placedRow);

        if(placedRow == 69) {
            return 0;
        }

        if(placedRow > 0 && placedRow < 8) {
            int rowHeight = numInRow[placedRow-1];
            numInRow[placedRow-1] -= 1;
            if(rowHeight > -1) {
                if(isRedsTurn) {
                    lines[rowHeight][2*(placedRow - 1)] = 'R';
                    gameArray[rowHeight][placedRow-1] = 1;
                    if(checkForWin(gameArray)) {
                        printf("Red Wins\n");
                        gameIsOver = true;
                    }
                    isRedsTurn = false;
                    isYellowsTurn = true;
                    turnCount++;
                } else if(isYellowsTurn) {
                    lines[rowHeight][2*(placedRow - 1)] = 'Y';
                    gameArray[rowHeight][placedRow-1] = 2;
                    if(checkForWin(gameArray)) {
                        printf("Yellow Wins\n");
                        gameIsOver = true;                    
                    }
                    isYellowsTurn = false;
                    isRedsTurn = true;
                    turnCount++;
                }
                
                if(turnCount > 42 || gameIsOver) {
                    turnCount -= 1;
                    printBoard();
                    char yOrN;
                    if(!gameIsOver) {
                        printf("Game Is A Tie Do You Want To Play Again\nEnter (y/n) For Yes And No: ");
                    }
                    scanf("%c", yOrN);
                    if(yOrN == 'y') {
                        resetGame();
                        continue;
                    } else {
                        return 0;
                    }
                }
            } else {
                printf("Row %d Is Full Try A Different One!\n", (placedRow));
                continue;
            }
        } else {
            printf("Only 1-7 Are Valid Try Again!\n");
            gameIsOver = false;
            continue;
        }
    }
    return 0;
}
