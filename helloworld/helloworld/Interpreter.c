//
//  Interpreter.c
//  helloworld
//
//  Created by 이지현 on 2017. 10. 29..
//  Copyright © 2017년 이지현. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_REGISTER      10
#define WORD_SIZE               16
#define RAM_SIZE                1000


int gRegister[NUMBER_OF_REGISTER];
/*don't consider data type of word*/
int gRam[RAM_SIZE];
int gNumberOfCommand;
int executedCommandsCount;
void initRegisterAndRam(){
    
    for ( int i = 0 ; i < NUMBER_OF_REGISTER ; ++ i )
        memset(gRegister, 0 , sizeof(int));
    
    for ( int i = 0 ; i < RAM_SIZE ; ++ i )
        memset(gRam, 0 , sizeof(int));
}

void dbgRam(){
    
    printf(">>>%s\n",__func__);
    for (int i = 0 ; i < gNumberOfCommand ; ++i )
        printf("%d, %d\n", i , gRam[i]);
    
}

void FillRamWithCommand(){
    
    char line[16]={0};
    char ch;
    int j;
    for ( int i = 0 ; i < RAM_SIZE ; ++ i )
    {
        //scanf("%d", &gRam[i]);
        j=0;
        memset(line, 0, 16);
        while ( (ch=getchar()) != '\n' ){
            line[j++]=ch;
        }
        line[j]='\n';
        
        if (line[0] == '\n'){
            printf("new line character received... the end of input i : %d\n", i);
            break;
        }
        sscanf(line,"%d", &gRam[i]);
        
        //for debug
        gNumberOfCommand = i+1;
        
        //printf("debug :%d\n",gRam[i]);
        
    }
    
}

void processCommandsInRam(){
    
    int cmd;
    int p1;
    int p2;
    int i=0;
    int done=0;
    //for ( int i = 0 ; i < gNumberOfCommand ; ++i){
    while(done != 1){
        
#if 0
        if(gRam[i] == 0){
            printf("terminate program\n");
            break;
        }
#endif
        cmd = gRam[i]/100;
        p1  = gRam[i]%100/10;
        p2  = gRam[i]%10;
        printf("[%d %d] cmd : %d p1 : %d p2 : %d\n", i, gRam[i], cmd, p1, p2);
        /* i should be increased here to prevent from infinite loop */
        ++i;
        executedCommandsCount++;
        switch(cmd){
            case 1:
            {
                printf("terminate program\n");
                done = 1;
            }
                break;
            case 2:/*set register p1 to p2*/
            {
                gRegister[p1]=p2;
            }
                break;
            case 3:/*add p2 to p1 regiter */
            {
               // gRegister[p1] += p2;
               // gRegister[p1] %= 1000;
                gRegister[p1] = (gRegister[p1] + p2) % 1000;
            }
                break;
            case 4:/*multiply p2 to p1 regiter */
            {
               // gRegister[p1] *= p2;
               // gRegister[p1] %= 1000;
                
                gRegister[p1] = ( gRegister[p1] * p2 ) % 1000;
            }
                break;
            case 5:/*set p1 register with p2 regisetr*/
            {
                gRegister[p1]=gRegister[p2];
            }
                break;
            case 6:/*add p2 register value to p1 regiter */
            {
               // gRegister[p1] += gRegister[p2];
               // gRegister[p1] %= 1000;
                
                gRegister[p1] = (gRegister[p1] + gRegister[p2]) % 1000;
            }
                break;
            case 7:/*multiply p2 register to p1 regiter */
            {
               // gRegister[p1] *= gRegister[p2];
               // gRegister[p1] %= 1000;
                gRegister[p1] =  ( gRegister[p1] *  gRegister[p2] ) % 1000;
            }
                break;
            case 8:/* set p1 register to value of ram at p2  */
            {
                gRegister[p1]=gRam[gRegister[p2]];
                
            }
                break;
            case 9:/* set p2 ram to value of register at p1  */
            {
                gRam[gRegister[p2]]=gRegister[p1];
            }
                break;
            case 0:
            {
                if ( gRegister[p2] != 0)
                    i=gRegister[p1];
            }
                break;
            default:;
        }
        
    }

}

int main(){

    
    
    int numOfCase;
    
    printf("start the interpreter problem\n");
    

    scanf("%d", &numOfCase);
    getchar();
    printf("\n");
    
    while( numOfCase-- > 0 ){
        
        initRegisterAndRam();
        FillRamWithCommand();
        //for debug
        //dbgRam();
        
        processCommandsInRam();
        printf("executedCommandsCount : %d\n",executedCommandsCount);
        printf("\n");
        
    }

    return 0;
}
