//
//  MineSweeper.c
//  helloworld
//
//  Created by 이지현 on 2017. 10. 24..
//  Copyright © 2017년 이지현. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RAW         100
#define MAX_COLUMN      MAX_RAW

char mineMap[MAX_RAW][MAX_COLUMN] = {0,};
int  mineNumberMap[MAX_RAW][MAX_COLUMN] = {0,};

void initVectors(){
    
    int i;
    for ( i = 0 ; i < MAX_RAW ; ++i ){
        memset(mineMap[i], 0, sizeof(char)*MAX_COLUMN);
        memset(mineNumberMap[i], 0, sizeof(int)*MAX_COLUMN);
    }
}

void printMineMap(int raw, int column){
    int i;
    int j;
    
    printf("print mineMap :\n");
    for( i = 0 ; i < raw; ++i ){
        
        for (j = 0 ; j < column ; ++j ){
            //printf("[%d][%d]%c\n",i,j,mineMap[i][j]);
            printf("%c", mineMap[i][j]);
        }
        printf("\n");
    }
}
void printMineNumberMap(int raw, int column){
    int i;
    int j;
    
    //printf("print mineNumberMap :\n");
    for( i = 0 ; i < raw; ++i ){
        
        for (j = 0 ; j < column ; ++j ){
            //printf("[%d][%d]%c\n",i,j,mineMap[i][j]);
            if( mineNumberMap[i][j] == '*' )
                printf("%c", mineNumberMap[i][j]);
            else
                printf("%d", mineNumberMap[i][j]);
        }
        printf("\n");
    }
}

int receiveInputData( int * pRaw, int * pColumn ){
    int i, j;
    
    printf("input raw and column :");
    scanf("%d %d",pRaw, pColumn);
    printf("%d %d\n",*pRaw, *pColumn);
    //flush newline
    getchar();
    
    if ( *pRaw < 0 || *pColumn < 0)
        return -1;
    if ( *pRaw > 100 || *pColumn > 100)
        return -2;
    if ( *pRaw == 0 && *pColumn == 0)
        return 1;
    printf("input mineMap :\n");
    for( i = 0 ; i < *pRaw; ++i ){
        
        for (j = 0 ; j < *pColumn ; ++j ){

            mineMap[i][j]=getchar();
            
        }
        //flush newline
        getchar();
    }
    //printMineMap(*pRaw, *pColumn);
    
    return 0;
}

int searchMines(int raw, int column){
    
    int i,j;
    int tempI=0,tempJ=0;
    static int count=0;
    for ( i = 0 ; i < raw; ++i ){
        
        for( j = 0 ; j < column ; ++j )
        {
            if(mineMap[i][j] == '*'){
                mineNumberMap[i][j]='*';
                continue;
            }

            
            for ( tempI=i-1 ; tempI < (i + 2) ; ++tempI ){
                if( tempI < 0 )
                    continue;
                if( tempI == raw )
                    continue;
                
                for( tempJ=j-1; tempJ < (j + 2); ++tempJ ){
                    if( tempJ < 0 )
                        continue;
                    if( tempJ == column )
                        continue;
                    
                    if( mineMap[tempI][tempJ] == '*'){
                        ++mineNumberMap[i][j];
                        //printf("[%d][%d]\n",tempI,tempJ);
                    }
                    
                }
            }

            
        }
    }
    printf("Field #%d:\n",++count);
    printMineNumberMap(raw, column);
    return 0;
}


int main(void){
    
    
    printf("Start MineSweeper\n");
    //1. receive row and column
    //2. receive matrix of mine map
    //3. calculate the number of mines
    int raw;
    int column;
    int result;
    
    while (1){
        
        //init vector.
        initVectors();
    
        if ( (result=receiveInputData( &raw, &column )) < 0){
            printf("Error invaild value received. terminate program\n");
            break;
        } else if ( result == 1 ){
            printf("the end\n");
            break;
        }
        searchMines(raw, column);
    }
    return 0;
}
