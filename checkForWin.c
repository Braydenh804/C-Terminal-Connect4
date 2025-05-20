#include <stdio.h>
#include "checkForWin.h"

bool checkForWin(int gameArray[6][7]) {
    // Check if won by row
    for(int i=5; i > -1; i--) {
        int redInARow1 = 0;
        int yellowInARow1 = 0;
        for(int j=0; j < 7; j++) {
            if(gameArray[i][j] == 1) {
                redInARow1++;
                yellowInARow1 = 0;
            } else if(gameArray[i][j] == 2) {
                yellowInARow1++;
                redInARow1 = 0;  
            } else {
                redInARow1 = 0;
                yellowInARow1 = 0;
            }
            if(redInARow1 == 4 || yellowInARow1 == 4){
                return true;
            }
        }
    }

    // Check if won by column
    for(int j=0; j < 7; j++) {
        int redInARow2 = 0;
        int yellowInARow2 = 0;
        for(int i=5; i > -1; i--) {
            if(gameArray[i][j] == 1) {
                redInARow2++;
                yellowInARow2 = 0;
            } else if(gameArray[i][j] == 2) {
                yellowInARow2++;
                redInARow2 = 0;
            } else {
                redInARow2 = 0;
                yellowInARow2 = 0;
            }
            if(redInARow2 == 4 || yellowInARow2 == 4) {
                return true;
            }
        }
    }

    
    /*
    Check Diagonal from left to right

        X X X 5 4 0 1
        X X 5 4 0 1 2
        X 5 4 0 1 2 3
        5 4 0 1 2 3 X
        4 0 1 2 3 X X
        0 1 2 3 X X X
        ---------------------------------------------------------------------------
        k=0: [i=5][j=0], [i=4][j=1], [i=3][j=2], [i=2][j=3], [i=1][j=4], [i=0][j=5]
        k=1: [i=5][j=1], [i=4][j=2], [i=3][j=3], [i=2][j=4], [i=1][j=5], [i=0][j=6]
        k=2: [i=5][j=2], [i=4][j=3], [i=3][j=4], [i=2][j=5], [i=1][j=6]
        k=3: [i=5][j=3], [i=4][j=4], [i=3][j=5], [i=2][j=6]
        k=4: [i=4][j=0], [i=3][j=1], [i=2][j=2], [i=1][j=3], [i=0][j=4]
        k=5: [i=3][j=0], [i=2][j=1], [i=1][j=2], [i=0][j=3] 
    */
    for(int k = 0; k < 6; k++) {
        int loopCountI = 0;
        int redInARow3 = 0;
        int yellowInARow3 = 0; 
        int plusVal = k;
        for(int i=5; i >= 0; i--) {
            if(k==4 && i==5) {
                plusVal = 0;
                i = 4;
            }
            if(k==5 && i==5) {
                plusVal = 0;
                i = 3;
            }
            if(k==2 && i==0 || k==3 && i==1) {
                break;
            }
            //printf("i=%d ", i);
            //printf("k=%d ", plusVal);
            //printf("j=%d\n", loopCountI+plusVal);
            
            if(gameArray[i][loopCountI+plusVal] == 1) {
                redInARow3++;
                yellowInARow3 = 0;
            } else if(gameArray[i][loopCountI+plusVal] == 2) {
                yellowInARow3++;
                redInARow3 = 0;
            } else {
                redInARow3 = 0;
                yellowInARow3 = 0;
            }
            if(redInARow3 == 4 || yellowInARow3 == 4){
                return true;
            }
            loopCountI++;
        }
        
    }

    /* Check Diagonal from right to left
    5 6 2 1 X X X
    4 5 6 2 1 X X
    3 4 5 6 2 1 X
    X 3 4 5 6 2 1
    X X 3 4 5 6 2
    X X X 3 4 5 6
    ---------------------------------------------------------------------------
    k=6: [i=5][j=6], [i=4][j=5], [i=3][j=4], [i=2][j=3], [i=1][j=2], [i=0][j=1]
    k=5: [i=5][j=5], [i=4][j=4], [i=3][j=3], [i=2][j=2], [i=1][j=1], [i=0][j=0]
    k=4: [i=5][j=4], [i=4][j=3], [i=3][j=2], [i=2][j=1], [i=1][j=0]
    k=3: [i=5][j=3], [i=4][j=2], [i=3][i=1], [i=2][j=0]
    k=2: [i=4][j=6], [i=3][j=5], [i=2][j=4], [i=1][j=3], [i=0][j=2]
    k=1: [i=3][j=6], [i=2][j=5], [i=1][j=4], [i=0][j=3]
    */    
    for(int k = 6; k > 0; k--) {
        int loopCountI = 0;
        int redInARow4 = 0;
        int yellowInARow4 = 0; 
        int minusVal = k;
        for(int i=5; i >= 0; i--) {
            if(k==2 && i==5) {
                minusVal = 6;
                i = 4;
            }
            if(k==1 && i==5) {
                minusVal = 6;
                i = 3;
            }
            if(k==4 && i==0 || k==3 && i==1) {
                break;
            }
            //printf("i=%d ", i);
            //printf("k=%d ", minusVal);
            //printf("j=%d\n", minusVal-loopCountI);
            
            if(gameArray[i][minusVal-loopCountI] == 1) {
                redInARow4++;
                yellowInARow4 = 0;
            } else if(gameArray[i][minusVal-loopCountI] == 2) {
                yellowInARow4++;
                redInARow4 = 0;
            } else {
                redInARow4 = 0;
                yellowInARow4 = 0;
            }
            if(redInARow4 == 4 || yellowInARow4 == 4){
                return true;
            }
            loopCountI++;
        }
    }
}
