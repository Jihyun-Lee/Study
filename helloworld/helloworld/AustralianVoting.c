//
//  AustralianVoting.c
//  helloworld
//
//  Created by 이지현 on 2017. 11. 6..
//  Copyright © 2017년 이지현. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define DBG
#define MAX_CANDIDATES       20
#define MAX_NAME_LENGTH      80
#define MAX_CITIZEN          1000


int numOfCase;
int numOfCandidates;
int numOfCitizen;


char nameOfPeople[MAX_CANDIDATES][MAX_NAME_LENGTH];
int listOfVote[MAX_CITIZEN][MAX_CANDIDATES];
int voteResults[MAX_CANDIDATES];


/*

1

3
Jone Doe
Jane Smith
Sirhan Sirhan
1 2 3
2 1 3
2 3 1
1 2 3
3 1 2

1
 
3
Jone Doe
Jane Smith
Sirhan Sirhan
1 2 3
2 1 3
2 3 1
1 2 3
3 2 1
 
3
 
3
Jone Doe
Jane Smith
Sirhan Sirhan
3 2 1
2 1 3
2 3 1
1 3 2
3 2 1
 
 
 

*/
void initGlobalVariables(){
    int i;
    
    for ( i = 0 ; i < MAX_CANDIDATES ; ++i)
        memset(nameOfPeople,0x0, MAX_NAME_LENGTH);
    for ( i = 0 ; i < MAX_CITIZEN ; ++i)
        memset(listOfVote,0x0, MAX_CANDIDATES*sizeof(int));
    for ( i = 0 ; i < MAX_CANDIDATES ; ++i)
        memset(voteResults,0x0, MAX_CANDIDATES*sizeof(int));
    
}

void executeVote(){
    char str[MAX_CITIZEN*2];
    int i,j;
    
    /*init numof citizen*/
    numOfCitizen=0;
    
    while( numOfCitizen <= MAX_CITIZEN ){
        memset(str, 0x0, sizeof(char)*MAX_CITIZEN*2);

        scanf("%[^\n]s", str);
        getchar();
        if(str[0]=='\0'){
#ifdef DBG
            printf("end of input\n");
#endif
            break;
        }
#ifdef DBG
        printf("str : %s\n",str);
#endif
        
        for ( i = 0, j = 0 ; i < numOfCandidates; ++i , j+=2 ){
            /*parse input*/
            listOfVote[numOfCitizen][i]=str[j]-'0';
        }

        ++numOfCitizen;
    }
    
}
int whoIsPresident(){
    
    int i;
    /*important it manages dropped candidates for revote*/
    int dropped_candidates[MAX_CANDIDATES]={0};
    int drop_out_count=0;
    
    int drop_out_idx;
    int elected_idx;
    int elected_count=0;
    //count
    for ( i = 0 ; i < numOfCitizen; ++i){
       
        int tCandidateNumber = listOfVote[i][0];
        /* ignore 0th candidate */
        ++voteResults[ tCandidateNumber ];
    }


    /*is there lucky guy?*/
    for ( i = 0 ; i < numOfCandidates; ++i ){
        if ( voteResults[i]*2 >= numOfCitizen ){
#ifdef DBG
            printf("%d is elected\n",i);
#endif
            //terminate
            return i;
        }
    }
    
    while(1){

        
        //find drop-out boy's idx
        for ( i = 2, drop_out_idx=1 ; i < numOfCandidates + 1; ++i){
            
            if( voteResults[drop_out_idx] > voteResults[i] ){
                drop_out_idx=i;
            }
        }
        //drop-out same score boys
        for ( i = 1 ; i < numOfCitizen; ++i){
            
            if( voteResults[drop_out_idx] == voteResults[i] ){
                dropped_candidates[drop_out_count++]=i;
#ifdef DBG
                printf("[%d]dropped : drop out count = %d\n", i, drop_out_count);
#endif
            }
        }
    
        //re-vote
        for (i = 0 ; i < numOfCitizen ; ++i){
            int count=0;
            int needRevote=0;
            int tCandidateNumber = listOfVote[i][count];
            
            int j = 0;
            
            //chekc drop out candidate
            while (  j < drop_out_count ){
                
                if( tCandidateNumber == dropped_candidates[j] ){
                    tCandidateNumber = listOfVote[i][++count];
                    needRevote=1;
                    
                    //voted on dropped candidate check from first.
                    j=0;
                    continue;
                }
                ++j;
            }
            if ( needRevote == 1)
                ++voteResults[tCandidateNumber];
        }
        
    
        /*is there lucky guy?*/
        for ( i = 1 ,elected_idx = 0 ; i < numOfCandidates+1; ++i ){
            if ( voteResults[i]*2 >= numOfCitizen ){
                elected_idx=i;
            }
        }
        
        if (elected_idx == 0) {
            printf("no persion elected...\n");
            continue;
        }
        
        for ( i = 0, elected_count=0 ; i < numOfCandidates + 1; ++i ){
        
            if ( voteResults[elected_idx] == voteResults[i] ){
                ++elected_count;
            }
        }
        if ( elected_count > 2 ){
            printf("elected more than 2.. terminate..\n");
            return -1;
        } else if ( elected_count == 1){
#ifdef DBG
            printf("%d is elected... terminate\n",elected_idx);
#endif
            return elected_idx;
        }
    }
    return 1;
}

int main(void){
    
    int tnumOfCandidates;
    
    int president;
    printf("start Australian Voting problem\n");
   
#ifdef DBG
    printf("get the number of cases :");
#endif
    scanf("%d", &numOfCase);
    getchar();
    getchar();
    
    while( (numOfCase--) > 0){
        int i=0;
        initGlobalVariables();

#ifdef DBG
        printf("get the number of people :");
#endif
        scanf("%d", &numOfCandidates);
        getchar();
        tnumOfCandidates=numOfCandidates;
        
        while( (tnumOfCandidates--) > 0){
#ifdef DBG
            printf("get name of each people : ");
#endif
            gets( nameOfPeople[i++]);
            //getchar();
#ifdef DBG
            printf("[%d : %s]\n", i, nameOfPeople[i-1]);
#endif
        }
        
        executeVote();
        
        president=whoIsPresident();
        if( president == -1){
            printf("Error occurred terminated program\n");
        }
        printf("%s\n", nameOfPeople[president-1]);

    }
    
    getchar();
    
    return 0;
}
