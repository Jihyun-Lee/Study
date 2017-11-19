//
//  JollyJumpers.c
//  helloworld
//
//  Created by 이지현 on 2017. 11. 19..
//  Copyright © 2017년 이지현. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_DATA_LENGTH         3000
int array[MAX_DATA_LENGTH];
int diffArray[MAX_DATA_LENGTH];
int numOfInput;

#define TRUE    1
#define FALSE   0


int compareInt(const void * a, const void * b){
    
    return (*(int*)a == *(int*)b) ? 0 : (int)(*(int*)a-*(int*)b);
}

int isJollyJump(){
    
    
    int i;
    int isJolly=TRUE;

    
    //fill diff array
    for ( i = 0 ; i < numOfInput - 1 ; ++i){
        
        diffArray[i] = abs(array[i+1] - array[i]);
        
    }
    /*
    //dbg array
    printf("numofInput : %d\n", numOfInput);
    for (i = 0 ; i < numOfInput ; ++i){
        
        printf("%d ", array[i]);
        
    }
    printf("\n");
     //dbg diffarray
    for (i = 0 ; i < numOfInput-1 ; ++i){
     
        printf("%d ", diffArray[i]);
     
    }
    printf("\n");
    */
    
    //qsort
    qsort(diffArray, numOfInput-1, sizeof(int), compareInt);
    
    //check jolly or not from diff Array
    
    for ( i = 0 ; i < numOfInput - 1 ; ++i )
    {
        if ( i+1 == diffArray [i]){
            //printf(">>> %d same!\n",i+1);
        } else {
            //printf("@@@ [%d:%d] diff!\n", i+1, diffArray[i]);
            isJolly=FALSE;
        }
    }
    

    return isJolly;
}


int main (){
    
    
    char ch;
    int i=0;
    printf("start Jolly jumpers!\n");
    
    
    
    while(1){
        scanf("%d", &numOfInput);
        printf("numofinput %d\n",numOfInput);
       
        while( (ch = getchar()) != '\n' ){
            if( ch == ' '){
                //printf("ignore space\n");
                continue;
            }
            if ( ch == '-'){
                ch = getchar();
                array[i++] = -(ch - '0');
                continue;
            }
            array[i++] = ch - '0';
        }
        if( isJollyJump() == TRUE){
            printf("Jolly\n");
        }else{
            printf("Not Jolly\n");
        }
        
        //printf("new line break\n");
        memset(array, 0x00, MAX_DATA_LENGTH*sizeof(int));
        memset(diffArray, 0x00, MAX_DATA_LENGTH*sizeof(int));
        numOfInput=0;
        i=0;
        
    }
    
    return 0;
}
