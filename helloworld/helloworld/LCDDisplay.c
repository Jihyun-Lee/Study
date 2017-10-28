//
//  LCDDisplay.c
//  helloworld
//
//  Created by 이지현 on 2017. 10. 26..
//  Copyright © 2017년 이지현. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE      100000
char gLedPannel[MAX_SIZE][MAX_SIZE];


int receiveInputToDisplay( int * size, char * numberToDisplay ){
    
    printf("input size and number to be displayed : ");
    scanf("%d %s",size , numberToDisplay);
    printf("size : %d number : %s\n", *size, numberToDisplay );
    
    if ( *size == 0 && !strcmp(numberToDisplay,"0") )
        return -1;
    return 0;
}

//raw       2s+3
//column    s+2
//ex1)     (5,3) , (7,4)

#if 1
char dashLine   = '-';
char rightBar   = '|';
char leftBar    = '|';
char whiteSpace = ' ';
#else//easy to think considering right and left.
char * dashLine  = "--";
char * rightBar   = " |";
char * leftBar    = "| ";
char * whiteSpace = "  ";
#endif
void drawOne( int size, int pos ){
    
    int i,j;
    int raw = 2 * size + 3;
    int column= size + 2;
    int relativePos = (size + 2 )*pos;

    //printf("[%d,%d]\n",raw , column);
    for ( i = 0 ; i < raw  ; ++i ){
        
        for ( j = 0 ; j < column ; ++j ){
            if ( i % (size + 1) == 0 ){
                gLedPannel[i][j + relativePos]=whiteSpace;//printf("%s", whiteSpace );
                continue;
            }

            if ( j == column-1 )
                gLedPannel[i][j + relativePos]=rightBar; //printf("%s", rightBar);
            else
                gLedPannel[i][j + relativePos]=whiteSpace; //printf("%s", whiteSpace);
        }
        //printf("\n");
        
    }
}
void drawEight( int size , int pos){
    
    int i,j;
    int raw = 2 * size + 3;
    int column= size + 2;
    int relativePos = (size + 2 )*pos;
    
    //printf("[%d,%d]\n",raw , column);
    for ( i = 0 ; i < raw  ; ++i ){
        
        for ( j = 0 ; j < column ; ++j ){
            if ( i % (size + 1) == 0 ){
                
                if ( (j == column-1) || j == 0 ){
                    gLedPannel[i][j + relativePos]=whiteSpace;// printf("%s", whiteSpace );
                } else {
                    gLedPannel[i][j + relativePos]=dashLine;//  printf("%s", dashLine );
                }
                continue;
            }
            
            if ( j == 0 )
                gLedPannel[i][j + relativePos]=rightBar; //printf("%s", rightBar);
            else if (j == column-1)
                gLedPannel[i][j + relativePos]=leftBar; //printf("%s", leftBar);
            else
                gLedPannel[i][j + relativePos]=whiteSpace; //printf("%s", whiteSpace);
        }
        //printf("\n");
        
    }
}

void drawFour( int size , int pos){
    
    int i,j;
    int raw = 2 * size + 3;
    int column= size + 2;
    int relativePos = (size + 2 )*pos;
    
    //printf("[%d,%d]\n",raw , column);
    for ( i = 0 ; i < raw  ; ++i ){
        
        for ( j = 0 ; j < column ; ++j ){
            if ( i % (size + 1) == 0 ){
                
                if ( (j == column-1) || j == 0 ){
                    gLedPannel[i][j + relativePos]=whiteSpace;//printf("%s", whiteSpace );
                }
                else if( i == 0 || i == raw - 1 ){
                    gLedPannel[i][j + relativePos]=whiteSpace;//printf("%s", whiteSpace );
                }
                else {
                    gLedPannel[i][j + relativePos]=dashLine;//printf("%s", dashLine );
                }
                continue;
            }
            
            if ( j == 0 && i < raw/2 )
                gLedPannel[i][j + relativePos]=rightBar; //printf("%s", rightBar);
            else if (j == column-1)
                gLedPannel[i][j + relativePos]=leftBar; //printf("%s", leftBar);
            else
                gLedPannel[i][j + relativePos]=whiteSpace;//printf("%s", whiteSpace);
        }
        //printf("\n");
        
    }
}

void drawTwo( int size, int pos ){
    
    int i,j;
    int raw = 2 * size + 3;
    int column= size + 2;
    int relativePos = (size + 2 )*pos;
    
    //printf("[%d,%d]\n",raw , column);
    for ( i = 0 ; i < raw  ; ++i ){
        
        for ( j = 0 ; j < column ; ++j ){
            if ( i % (size + 1) == 0 ){
                
                if ( (j == column-1) || j == 0 ){
                    gLedPannel[i][j + relativePos]=whiteSpace;//printf("%s", whiteSpace );
                } else{
                    gLedPannel[i][j + relativePos]=dashLine;//printf("%s", dashLine );
                }
                continue;
            }
            
            if ( j == 0 && i > raw/2 )
                gLedPannel[i][j + relativePos]=rightBar; //printf("%s", rightBar);
            else if (j == column-1 && i < raw/2 )
                gLedPannel[i][j + relativePos]=leftBar; //printf("%s", leftBar);
            else
               gLedPannel[i][j + relativePos]=whiteSpace ; //printf("%s", whiteSpace);
        }
        //printf("\n");
        
    }
}
void drawNine( int size , int pos ){
    
    int i,j;
    int raw = 2 * size + 3;
    int column= size + 2;
    int relativePos = (size + 2 )*pos;
    
    //printf("[%d,%d]\n",raw , column);
    for ( i = 0 ; i < raw  ; ++i ){
        
        for ( j = 0 ; j < column ; ++j ){
            if ( i % (size + 1) == 0 ){
                
                if ( (j == column-1) || j == 0 ){
                    gLedPannel[i][j + relativePos]=whiteSpace;//printf("%s", whiteSpace );
                }
                else if( i == raw - 1 ){
                    gLedPannel[i][j + relativePos]=whiteSpace;//printf("%s", whiteSpace );
                }
                else {
                    gLedPannel[i][j + relativePos]=dashLine; //printf("%s", dashLine );
                }
                continue;
            }
            
            if ( j == 0 && i < raw/2 )
                gLedPannel[i][j + relativePos]=rightBar; //printf("%s", rightBar);
            else if (j == column-1)
                gLedPannel[i][j + relativePos]=leftBar; //printf("%s", leftBar);
            else
                gLedPannel[i][j + relativePos]=whiteSpace;// printf("%s", whiteSpace);
        }
        //printf("\n");
        
    }
}


void drawFive( int size ,int pos){
    
    int i,j;
    int raw = 2 * size + 3;
    int column= size + 2;
    int relativePos = (size + 2 )*pos;
    
    //printf("[%d,%d]\n",raw , column);
    for ( i = 0 ; i < raw  ; ++i ){
        
        for ( j = 0 ; j < column ; ++j ){
            if ( i % (size + 1) == 0 ){
                
                if ( (j == column-1) || j == 0 ){
                    gLedPannel[i][j + relativePos]=whiteSpace;//printf("%s", whiteSpace );
                } else{
                    gLedPannel[i][j + relativePos]=dashLine;//printf("%s", dashLine );
                }
                continue;
            }
            
            if ( j == 0 && i < raw/2 )
                gLedPannel[i][j + relativePos]=rightBar;//printf("%s", rightBar);
            else if (j == column-1 && i > raw/2 )
                gLedPannel[i][j + relativePos]=leftBar;//printf("%s", leftBar);
            else
                gLedPannel[i][j + relativePos]=whiteSpace;//printf("%s", whiteSpace);
        }
        //printf("\n");
        
    }
}
void drawSix( int size ,int pos){
    
    int i,j;
    int raw = 2 * size + 3;
    int column= size + 2;
    int relativePos = (size + 2 )*pos;
    
    //printf("[%d,%d]\n",raw , column);
    for ( i = 0 ; i < raw  ; ++i ){
        
        for ( j = 0 ; j < column ; ++j ){
            if ( i % (size + 1) == 0 ){
                
                if ( (j == column-1) || j == 0 ){
                    gLedPannel[i][j + relativePos]=whiteSpace;//printf("%s", whiteSpace );
                } else{
                    gLedPannel[i][j + relativePos]=dashLine;//printf("%s", dashLine );
                }
                continue;
            }
            
            if ( j == 0 )
                gLedPannel[i][j + relativePos]=rightBar;//printf("%s", rightBar);
            else if (j == column-1 && i > raw/2 )
                gLedPannel[i][j + relativePos]=leftBar;//printf("%s", leftBar);
            else
                gLedPannel[i][j + relativePos]=whiteSpace;//88printf("%s", whiteSpace);
        }
        //printf("\n");
        
    }
}
void drawThree( int size ,int pos){
    
    int i,j;
    int raw = 2 * size + 3;
    int column= size + 2;
    int relativePos = (size + 2 )*pos;
    
    //printf("[%d,%d]\n",raw , column);
    for ( i = 0 ; i < raw  ; ++i ){
        
        for ( j = 0 ; j < column ; ++j ){
            if ( i % (size + 1) == 0 ){
                
                if ( (j == column-1) || j == 0 ){
                    gLedPannel[i][j + relativePos]=whiteSpace;//printf("%s", whiteSpace );
                } else {
                    gLedPannel[i][j + relativePos]=dashLine;//printf("%s", dashLine );
                }
                continue;
            }
            
            if ( j == 0 )
                gLedPannel[i][j + relativePos]=whiteSpace;//printf("%s", whiteSpace);
            else if (j == column-1 )
                gLedPannel[i][j + relativePos]=leftBar;//printf("%s", leftBar);
            else
                gLedPannel[i][j + relativePos]=whiteSpace; //printf("%s", whiteSpace);
        }
        //printf("\n");
        
    }
}
void drawSeven( int size ,int pos){
    
    int i,j;
    int raw = 2 * size + 3;
    int column= size + 2;
    int relativePos = (size + 2 )*pos;
    
    //printf("[%d,%d]\n",raw , column);
    for ( i = 0 ; i < raw  ; ++i ){
        
        for ( j = 0 ; j < column ; ++j ){
            if ( i % (size + 1) == 0 ){
                
                if ( (j == column-1) || j == 0 || i != 0 ){
                    gLedPannel[i][j + relativePos]=whiteSpace;//printf("%s", whiteSpace );
                } else {
                    gLedPannel[i][j + relativePos]=dashLine;//printf("%s", dashLine );
                }
                continue;
            }
            
            if ( j == 0 )
                gLedPannel[i][j + relativePos]=whiteSpace;//printf("%s", whiteSpace);
            else if (j == column-1 )
                gLedPannel[i][j + relativePos]=leftBar;// printf("%s", leftBar);
            else
                gLedPannel[i][j + relativePos]=whiteSpace;//printf("%s", whiteSpace);
        }
        //printf("\n");
        
    }
}


void drawZero( int size , int pos ){
    
    int i,j;
    int raw = 2 * size + 3;
    int column= size + 2;
    int relativePos = (size + 2 )*pos;
    
    //printf("[%d,%d]\n",raw , column);
    for ( i = 0 ; i < raw  ; ++i ){
        
        for ( j = 0 ; j < column ; ++j ){
            if ( i % (size + 1) == 0 ){
                
                if ( (j == column-1) || j == 0 ){
                    //printf("%s", whiteSpace );
                    gLedPannel[i][j + relativePos]=whiteSpace;
                } else if (i == 0 || i == raw -1 ) {
                    //printf("%s", dashLine );
                     gLedPannel[i][j + relativePos]=dashLine;
                }
                else {
                    //printf("%s", whiteSpace );
                    gLedPannel[i][j + relativePos]=whiteSpace;
                }
                continue;
            }
            
            if ( j == 0 )
                gLedPannel[i][j + relativePos]=rightBar; //printf("%s", rightBar);
            else if (j == column-1)
                gLedPannel[i][j + relativePos]=leftBar; //printf("%s", leftBar);
            else
                gLedPannel[i][j + relativePos]=whiteSpace;//printf("%s", whiteSpace);
        }
        //printf("\n");
        
    }

}


void initLed(){
    
    int i;
    for ( i = 0; i < MAX_SIZE ; ++i )
    {
        memset( gLedPannel[i], 0x00, MAX_SIZE );
    }
    
}

void drawNumbersToLed(int size, char * numberToDisplay ){
    int i;
    int j;
    int number;
    for ( i = 0 ; i < strlen(numberToDisplay) ; ++i ){
        number = numberToDisplay[i]-48;//asci to integer
        switch(number){
            case 0:
                drawZero(size, i);
                break;
            case 1:
                drawOne(size, i);
                break;
            case 2:
                drawTwo(size, i);
                break;
            case 3:
                drawThree(size, i);
                break;
            case 4:
                drawFour(size, i);
                break;
            case 5:
                drawFive(size, i);
                break;
            case 6:
                drawSix(size, i);
                break;
            case 7:
                drawSeven(size, i);
                break;
            case 8:
                drawEight(size, i);
                break;
            case 9:
                drawNine(size, i);
                break;
            default:;
        }
        
    }
    printf("debug>>>\n");
    for (i=0 ; i < 20 ; ++i){
        for (j = 0 ; j <30 ; ++j){
            printf("%c",gLedPannel[i][j]);
        }
        printf("\n");
    }
    
}

int main(void){
    
    int size;
    char numberToDisplay[16]={0,};
    printf("LCD display\n");
    while ( 1 ){
        
        initLed( );
        //printf("%d %d",'1'-48, '2'-48 );
        if( receiveInputToDisplay( &size, numberToDisplay ) < 0 )
        {
            printf("terminate program\n");
            return 0;
        }
        
        drawNumbersToLed(size, numberToDisplay);
        
        
        //test
        //drawZero(size);
        //drawOne(size);
        //drawTwo(size);
        //drawThree(size);
        //drawFour(size);
        //drawFive(size);
        //drawSix(size);
        //drawSeven(size);
        //drawEight(size);
        //drawNine(size);
    }
    
    return 0;
}
