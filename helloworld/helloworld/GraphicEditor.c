//
//  GraphicEditor.c
//  helloworld
//
//  Created by 이지현 on 2017. 10. 28..
//  Copyright © 2017년 이지현. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int gCanvas[MAX_LENGTH][MAX_LENGTH];



void initCanvas (){
    int i;
    
    for ( i = 0 ; i < MAX_LENGTH ;  ++i )
    {
        memset ( gCanvas[i], 0x0 , MAX_LENGTH);
    }
}

void showCanvas( int M, int N ){
    
    
    //printf("[%d %s]\n", __LINE__, __func__);
    for ( int i = 0 ; i < M; ++i ){
        for( int j = 0 ; j < N ; ++j )
        {
            printf("%c", gCanvas[i][j]);
        }
        printf("\n");
    }
    
    
}
void processI(int row, int column ){
    
    for ( int i = 0 ; i < row; ++i ){
        for( int j = 0 ; j < column ; ++j )
        {
            //gCanvas[i][j] = 'O';
            gCanvas[i][j] = '-';
        }
    }
    showCanvas(row, column);
}

void clearCanvas (int row, int column){
    
    processI(row, column);
    
}

void drawApixel( int x, int y, char color ){
    gCanvas[y-1][x-1] = color;
}

void drawVerticalLine( int x, int y1, int y2, char color){
    
    for (int i = y1-1 ; i < y2 ; ++ i ){
        gCanvas[i][x-1] = color;
    }

}
void drawHorizontalLine( int x1, int x2, int y, char color){
    
    for (int i = x1-1 ; i < x2 ; ++ i ){
        gCanvas[y-1][i] = color;
    }
}
    
void drawRectangular( int x1, int y1, int x2, int y2, char color){

    drawHorizontalLine(x1, x2, y1, color);
    drawHorizontalLine(x1, x2, y2, color);
    
    drawVerticalLine(x1, y1 ,y2, color);
    drawVerticalLine(x2, y1 ,y2, color);
}



void FillTheColor( int x, int y , char color, int row, int column ){
    
    char posColor;

    if ( !(y-1 >= 0 && y-1 < row && x-1 >=0 && x-1 < column))
        return;

    //current [ y-1 , x-1 ]
    posColor = gCanvas[y-1][x-1];
    
    //check up
    gCanvas[y-1][x-1]=color;
    if ( y-2 >= 0 ){
        
        if ( gCanvas[y-2][x-1] == posColor ){
            FillTheColor(x, y-1, color, row, column );
            gCanvas[y-2][x-1]=color;
        }
    }
    
    //check down
    if ( y  < row ){
        if ( gCanvas[y][x-1] == posColor ){
            FillTheColor(x, y+1, color, row, column );
            gCanvas[y][x-1]=color;
        }
    }

    //check left
    if( x-2  >= 0 ){
        if ( gCanvas[y-1][x-2] == posColor ){
            FillTheColor(x-1, y, color, row, column );
            gCanvas[y-1][x-2]=color;
        }
    }

    //check right
    if ( x < column ){
        if ( gCanvas[y-1][x] == posColor ){
            FillTheColor(x+1, y, color, row, column );
            gCanvas[y-1][x]=color;
        }
    }

    
    
}

int main(){

    //1. receive command from user
    //2. process command accordding to first character.
    //3. go to step 1.
    char cmd;
    int isEnd=0;
    int row=0;
    int column=0;
    printf("Graphic Editor\n");
    initCanvas();
    
    
    while ( isEnd != 1 )
    {

        scanf("%c", &cmd);
        switch(cmd){
            case 'I':
            {
                scanf("%d %d", &column , &row);
                printf("raw, column [%d %d]\n", row, column);
                processI(row, column);
            }
                break;
            case 'C':
            {
                clearCanvas(row, column);
            }
                break;
            case 'L':
            {
                int x,y;
                char color;
                scanf("%d %d %c", &x, &y, &color);
                printf("L x y c [%d %d %c]\n", x, y, color);
                drawApixel( x, y , color);
                showCanvas( row, column );
            }
                break;
                
            case 'V':
            {
                int x,y1,y2;
                char color;
                scanf("%d %d %d %c", &x, &y1, &y2, &color);
                drawVerticalLine(x, y1, y2, color);
                //debug
                showCanvas( row, column );
            }
                break;
            case 'H':
            {
                int x1,x2,y;
                char color;
                scanf("%d %d %d %c", &x1, &x2, &y, &color);
                drawHorizontalLine(x1, x2, y, color);
                //debug
                showCanvas( row, column );
            }
                break;
            case 'K':
            {
                int x1,x2,y1 ,y2;
                char color;
                scanf("%d %d %d %d %c", &x1, &y1, &x2, &y2, &color);
                drawRectangular(x1, y1, x2, y2, color);
                //debug
                showCanvas( row, column );
            }
                break;
            case 'F':
            {
                int x,y;
                char color;
                scanf("%d %d %c", &x, &y, &color);
                printf("F x y c [%d %d %c]\n", x, y, color);
                FillTheColor( x, y , color , row, column);
                showCanvas( row, column );
                
            }
                break;
            case 'S':
            {
                char fileName[15]={0,};
                scanf("%s",fileName);
                showCanvas( row, column );
            }
                break;
            case 'X':
                isEnd=1;
            default:;
                printf("default\n");
        }
        
        getchar();
        
    }
    
    printf("terminate program\n");
    
    
    return 0;
}
