//
//  CheckTheCheck.c
//  helloworld
//
//  Created by 이지현 on 2017. 10. 30..
//  Copyright © 2017년 이지현. All rights reserved.
//



/**
 Input case
 
 ..k.....
 ppp.pppp
 ........
 .R...B..
 ........
 ........
 PPPPPPPP
 K.......
 
 rnbqkbnr
 pppppppp
 ........
 ........
 ........
 ........
 PPPPPPPP
 RNBQKBNR
 
 rnbqk.nr
 ppp..ppp
 ....p...
 ...p....
 .bPP....
 .....N..
 PP..PPPP
 RNBQKB.R
 
 ........
 ........
 ........
 ........
 ........
 ........
 ........
 ........
 
 
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

///#define DBG

#define TRUE    1
#define FALSE   0

#define WIDTH       8
#define LENGTH      WIDTH
char chessMap[LENGTH][WIDTH];
int gameCount;

typedef struct RESULT_T {
    int isCheck;
    int isWhite;
}RESULT;

RESULT result;

static void initChessMap(){
    
    for(int i = 0 ; i < LENGTH ; ++i )
        memset(chessMap, 0x0 , sizeof(char)*WIDTH);
}
static void receiveChessMap(){
    
    for(int i = 0 ; i < LENGTH ; ++i ){
        scanf("%s", chessMap[i]);
        //chessMap[i][LENGTH]='\n';
        getchar();
    }
}
static void printChessMap(){
    
    printf("[DBG] %s\n", __func__);
    for(int i = 0 ; i < LENGTH ; ++i ){
        for(int j = 0 ; j < LENGTH ; ++j ){
            printf("%c", chessMap[i][j]);
        }
        printf("\n");
    }
}

static void printResult(RESULT result){
    
    if( result.isCheck ){
        printf("Game #%d: %s king is in check\n",gameCount, result.isWhite == TRUE? "white" : "black");
    } else {
        printf("Game #%d: no king is in check\n",gameCount);
    }
    
}
static int isMapEmpty(){
    for(int i = 0 ; i < LENGTH ; ++i )
    {
        for(int j = 0 ; j < WIDTH ; ++j )
        {
            if ( chessMap[i][j] != '.' )
                return FALSE;
        }
    }
    
    return TRUE;
}
static void findKing(int *x, int *y, int isWhite){
    
    char king='k';
    if(isWhite)
        king='K';
        
    for (int i = 0 ; i < WIDTH ; ++i ){
        for (int j = 0 ; j < LENGTH ; ++j ){
            
            if(chessMap[i][j]==king)
                {
                    *x=i;
                    *y=j;
                }
        }
    }
    
    
    return;
}
RESULT isCheckWithLook(int x, int y , int i, int j, int isWhite ){
  
    RESULT result;
    char king = (isWhite == TRUE) ? 'K' : 'k';
    int posX=i;
    int posY=j;
    
    //check below sequence
    //1. --x
    //2. ++x
    //3. --y
    //4, ++y
    result.isWhite=isWhite;
    
    while ( --posX >= 0 )
    {
        /*there's obsticle between bishop and king */
#ifdef DBG
        printf("posX posY : %d %d [%c]\n",posX,posY,chessMap[posX][posY]);
#endif
        if (chessMap[posX][posY] != '.' && chessMap[posX][posY] != king ){
            result.isCheck=0;
            return result;
        }
       
        if ( posX==x && posY==y )
        {
            /*found king*/
             result.isCheck=1;
            return result;
        }
        result.isCheck=0;
        return result;
    }
    
    posX=i;
    posY=j;
    
    while ( ++posX < WIDTH )
    {
        /*there's obsticle between bishop and king */
#ifdef DBG
        printf("posX posY : %d %d [%c]\n",posX,posY,chessMap[posX][posY]);
#endif
        if (chessMap[posX][posY] != '.' && chessMap[posX][posY] != king ){
            result.isCheck=0;
            return result;
        }
        
        if ( posX==x && posY==y )
        {
            /*found king*/
            result.isCheck=1;
            return result;
        }
        
        result.isCheck=0;
        return result;
    }
    
    posX=i;
    posY=j;
    
    while ( --posY >= 0 )
    {
        /*there's obsticle between bishop and king */
#ifdef DBG
        printf("posX posY : %d %d [%c]\n",posX,posY,chessMap[posX][posY]);
#endif
        if (chessMap[posX][posY] != '.' && chessMap[posX][posY] != king ){
            result.isCheck=0;
            return result;
        }
        
        if ( posX==x && posY==y )
        {
            /*found king*/
            result.isCheck=1;
            return result;
        }
        
        result.isCheck=0;
        return result;
    }
    
    posX=i;
    posY=j;
    
    while ( ++posY < WIDTH )
    {
        /*there's obsticle between bishop and king */
#ifdef DBG
        printf("posX posY : %d %d [%c]\n",posX,posY,chessMap[posX][posY]);
#endif
        if (chessMap[posX][posY] != '.' && chessMap[posX][posY] != king ){
            result.isCheck=0;
            return result;
        }
        
        if ( posX==x && posY==y )
        {
            /*found king*/
            result.isCheck=1;
            return result;
        }
        
        result.isCheck=0;
        return result;
    }
    result.isCheck=0;
    return result;
    
}

RESULT isCheckWithBishop( int x, int y , int i, int j, int isWhite )
{
    RESULT result;
    char king = (isWhite == TRUE) ? 'K' : 'k';
    
    int posX=i;
    int posY=j;
    
    //check below sequence
    //1. --x,--y
    //2. ++x,--y
    //3. --x,++y
    //4, ++x,++y
    
    result.isWhite=isWhite;
    
    while ( --posX >= 0 && --posY >= 0 )
    {
        /*there's obsticle between bishop and king */
#ifdef DBG
        printf("posX posY : %d %d [%c]\n",posX,posY,chessMap[posX][posY]);
#endif
        if (chessMap[posX][posY] != '.' && chessMap[posX][posY] != king ){
            result.isCheck=0;
            return result;
        }
        
        if ( posX==x && posY==y )
        {
            /*found king*/
            result.isCheck=1;
            return result;
        }

    }
    
    posX=i;
    posY=j;
    
    while ( ++posX < WIDTH && --posY >= 0 )
    {
        /*there's obsticle between bishop and king */
#ifdef DBG
        printf("posX posY : %d %d [%c]\n",posX,posY,chessMap[posX][posY]);
#endif
        if (chessMap[posX][posY] != '.' && chessMap[posX][posY] != king ){
            result.isCheck=0;
            return result;
        }
        
        if ( posX==x && posY==y )
        {
            /*found king*/
            result.isCheck=1;
            return result;
        }
    }
    
    posX=i;
    posY=j;
    
    while ( --posX >= 0 && ++posY < WIDTH )
    {
        /*there's obsticle between bishop and king */
#ifdef DBG
        printf("posX posY : %d %d [%c]\n",posX,posY,chessMap[posX][posY]);
#endif
        if (chessMap[posX][posY] != '.' && chessMap[posX][posY] != king ){
            result.isCheck=0;
            return result;
        }
        
        if ( posX==x && posY==y )
        {
            /*found king*/
            result.isCheck=1;
            return result;
        }
    }
    
    posX=i;
    posY=j;
    
    while ( ++posX < WIDTH  && ++posY < WIDTH )
    {
        /*there's obsticle between bishop and king */
#ifdef DBG
        printf("posX posY : %d %d [%c]\n",posX,posY,chessMap[posX][posY]);
#endif
        if (chessMap[posX][posY] != '.' && chessMap[posX][posY] != king ){
            result.isCheck=0;
            return result;
        }
        
        if ( posX==x && posY==y )
        {
            /*found king*/
            result.isCheck=1;
            return result;
        }
    }
    result.isCheck=0;
    return result;
}
RESULT isCheckWithKnight( int x, int y , int i, int j, int isWhite ){
    RESULT result;
    char king = (isWhite == TRUE) ? 'K' : 'k';
    
    int posX=i;
    int posY=j;
    
    result.isWhite=isWhite;
    //check below sequence
    //1. x-1 ,y-2
    //1. x+1 ,y-2
    //2. x-1 ,y+2
    //2. x+1 ,y+2
    //3. x-2 ,y-1
    //3. x-2 ,y+1
    //4. x+2 ,y-1
    //4. x+2 ,y+1
    posX=i-1;
    posY=j-2;
    if ( posX >= 0 && posY >= 0){
        if ( chessMap[posX][posY] == king )
        {
            result.isCheck=1;
            return result;
        }
    }
    posX=i+1;
    posY=j-2;
    if ( posX < WIDTH && posY >= 0){
        if ( chessMap[posX][posY] == king )
        {
            result.isCheck=1;
            return result;
        }
    }
    posX=i-1;
    posY=j+2;
    if ( posX >= 0 && posY < WIDTH ){
        if ( chessMap[posX][posY] == king )
        {
            result.isCheck=1;
            return result;
        }
    }
    posX=i+1;
    posY=j+2;
    if ( posX < WIDTH && posY < WIDTH ){
        if ( chessMap[posX][posY] == king )
        {
            result.isCheck=1;
            return result;
        }
    }
    
    posX=i-2;
    posY=j-1;
    if ( posX >= 0 && posY >= 0){
        if ( chessMap[posX][posY] == king )
        {
            result.isCheck=1;
            return result;
        }
    }
    
    posX=i-2;
    posY=j+1;
    if ( posX >= 0 && posY < WIDTH ){
        if ( chessMap[posX][posY] == king )
        {
            result.isCheck=1;
            return result;
        }
    }
    posX=i+2;
    posY=j-1;
    if ( posX < WIDTH && posY >= 0){
        if ( chessMap[posX][posY] == king )
        {
            result.isCheck=1;
            return result;
        }
    }
    posX=i+2;
    posY=j+1;
    if ( posX < WIDTH && posY < WIDTH ){
        if ( chessMap[posX][posY] == king )
        {
            result.isCheck=1;
            return result;
        }
    }
    result.isCheck=0;
    return result;
    
}

RESULT checkTheCheckMate(){
    RESULT result={0};
    
    for(int i = 0 ; i < LENGTH ; ++i )
    {
        for(int j = 0 ; j < WIDTH ; ++j )
        {
            
            switch(chessMap[i][j])
            {
                case 'p':
                {
#ifdef DBG
                    printf("pon\n");
#endif
                    // (i+1, j-1),(i+1, j+1)
                    if ( i+1 < LENGTH && j-1 >=0 && j+1 < WIDTH )
                    {
                        if( chessMap[i+1][j-1] == 'K' || chessMap[i+1][j-1] == 'K'){
                            result.isCheck = 1;
                            result.isWhite = 1;
                            return result;
                        }
                    }
                    
                }
                    break;
                case 'P':
                {
#ifdef DBG
                    printf("Pon\n");
#endif
                    // (i-1, j-1),(i-1, j+1)
                    if ( i+1 < LENGTH && j-1 >=0 && j+1 < WIDTH )
                    {
                        if( chessMap[i-1][j-1] == 'k' || chessMap[i-1][j-1] == 'k'){
                            result.isCheck = 1;
                            result.isWhite = 0;
                            return result;
                        }
                    }
                }
                    break;

                case 'R':
                case 'r':
                {
                    int x,y;
#ifdef DBG
                    printf("ROOK\n");
#endif
                    findKing(&x, &y, (chessMap[i][j] == 'r')? TRUE : FALSE);
                    result = isCheckWithLook(x, y , i, j ,(chessMap[i][j] == 'r')? TRUE : FALSE);
                    if ( result.isCheck==1) return result;
                }

                    break;
                case 'n':
                case 'N':
                {
                    int x,y;
                    findKing(&x, &y, (chessMap[i][j] == 'n')? TRUE : FALSE);
                    result = isCheckWithKnight(x, y , i, j ,(chessMap[i][j] == 'n')? TRUE : FALSE);
                    if ( result.isCheck==1) return result;
                }
                    break;
                case 'q':
                case 'Q':
                {
                    int x,y;
                    findKing(&x, &y, (chessMap[i][j] == 'q')? TRUE : FALSE);
                    
                    result = isCheckWithBishop(x, y , i, j ,(chessMap[i][j] == 'q')? TRUE : FALSE);
                    if ( result.isCheck == 1){
                      
                        return result;
                    }
                    
                    result = isCheckWithLook(x, y , i, j ,(chessMap[i][j] == 'q')? TRUE : FALSE);
                    if ( result.isCheck == 1){
                        return result;
                    }
                }
                    break;
                case 'b':
                case 'B':
                {
                    int x,y;
#ifdef DBG
                    printf("BISHOP\n");
#endif
                    findKing(&x, &y, (chessMap[i][j] == 'b')? TRUE : FALSE);
#ifdef DBG
                    printf("[x,y][%d %d] king : %c, i,j [%d %d]\n",x,y,chessMap[x][y],i,j);
#endif
                    result = isCheckWithBishop(x, y , i, j ,(chessMap[i][j] == 'b')? TRUE : FALSE);
                    if ( result.isCheck == 1){
                        return result;
                    }
                    
                }
                    break;
                case 'k':
                case 'K':
                    /*todo but no posibility in this case */
                default:;
                    
            }
            
            
            
        }
    }
    return result;
}


int main(){
    
    
    printf("Start Check the Check\n");
    
    
    while(1){
        
        initChessMap();
        receiveChessMap();
        //for DBG
        printChessMap();
        if ( isMapEmpty() == TRUE ){
            printf("map is empty terminate program.\n");
            return 0;
        }

        result=checkTheCheckMate();
        ++gameCount;
        printResult(result);
 
    }
    return 0;
}
