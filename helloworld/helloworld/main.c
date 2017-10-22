//
//  main.c
//  helloworld
//
//  Created by 이지현 on 2017. 10. 21..
//  Copyright © 2017년 이지현. All rights reserved.
//

#include <stdio.h>

int isEven( int number ){
    if ( number % 2 ) return 1;
    else return 0;
    
}

int process3N1 ( int number ){
    
    int n = number;
    /*lenth start from 1*/
    int cycle = 1;
    //printf("process3N1 : ");
    while ( n != 1 ){

   //     printf( "%d ", n );
        ++cycle;
        if ( isEven ( n ) )
            n= (n*3) + 1;
        else
            n= n/2;
        
    }
    //printf( "%d ", n );
    
    return cycle;
}

int findMaxCycleAmong(int numberA , int numberB){
    
    int tMaxCycle=0;
    int tCycle;
    int n=numberA;
    while ( n <= numberB ){
        tCycle=process3N1( n );
        if ( tMaxCycle < tCycle)
            tMaxCycle = tCycle;
        
        ++n;
    }
    return tMaxCycle;
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("start program\n");
    
#if 0//test
{
    int cycle;
    lenth = process3N1(22);
    printf ("lenth : %d \n",lenth);
}
#endif

#if 1
{
    int maxCycle;
    int numberA=201;
    int numberB=210;
    maxCycle = findMaxCycleAmong(numberA,numberB);
    printf ("%d %d %d\n",numberA,numberB,maxCycle);
}
#endif
    printf("finish with program\n");
    
    
    
    return 0;
}
