//
//  TheTrip.c
//  helloworld
//
//  Created by 이지현 on 2017. 10. 23..
//  Copyright © 2017년 이지현. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define MAXNUM_OF_GROUP 100

int main (void ){
    int numOfStudent;
    int i;
    int groupIndex = 0;
    int * arryOfCost;
    int * costPerPersion;
    int differenceList[MAXNUM_OF_GROUP]={0,};
    
    
    printf("The trip\n");
    
    while(1){
        
        printf("put the number of student : ");
        scanf("%d",&numOfStudent);
        if (numOfStudent == 0){
            printf("terminate program\n");
            break;
        } else if ( numOfStudent > 1000 ){
            printf("student number cannot over 1000.\n");
            continue;
        }
        arryOfCost = (int *)malloc(numOfStudent*sizeof(int));
        memset(arryOfCost,sizeof(arryOfCost), 0);
        costPerPersion = (int *)malloc(numOfStudent*sizeof(int));
        memset(costPerPersion,sizeof(costPerPersion), 0);
        
        
        double tCost;
        
        /* avoid to use double */
        for ( i = 0 ; i < numOfStudent ; i ++  ){
            scanf("%lf", &tCost );
            //arryOfCost[i] = (tCost * 100);
            arryOfCost[i] = (tCost * 100 + 0.5);//what the... half round;
        }
        
        
        
        int tSum=0;
        int tAverage=0;
        int tModulus=0;
        for ( i = 0 ; i < numOfStudent ; i++ ){
            tSum += arryOfCost[i];
        }
        
        tAverage = tSum/numOfStudent;
        tModulus = tSum%numOfStudent;
        
        printf("sum : %lf average : %lf\n",(double)tSum/100, (double)tAverage/100);
        
        for ( i = 0 ; i < numOfStudent ; i++ ){
            costPerPersion[i] = tAverage;
        }
        
        /* do not consider who will on modulus */
        for ( i = 0 ; i < tModulus ; i++ ){
            ++costPerPersion[i];
        }
        
        
        for ( i = 0 ; i < numOfStudent ; i++ ){
                differenceList[groupIndex] += abs((arryOfCost[i] - costPerPersion[i]));
        }
        differenceList[groupIndex]/=2;
        groupIndex++;
        
        fflush(stdin);
    }
    
    for ( i = 0 ; i < groupIndex ; ++ i) {
        printf("$%.2lf\n", (double)differenceList[i]/100);
    }
    
    free( arryOfCost );
    free( costPerPersion );
    
    return 0;
}
