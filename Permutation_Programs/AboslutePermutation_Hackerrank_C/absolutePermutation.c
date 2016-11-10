#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int t; 
    scanf("%d",&t);
    while(t--){
        int n; 
        int k; 
        scanf("%d %d",&n,&k);
        
        // if absolute difference is 0 then the absolute permutation will be the n natural natural numbers
        if(k==0){
            for(int i =1; i<=n; i++){
                printf("%d ",i);
            }
                printf("\n");
        }
        // else if the length of the input (n) is a multiple of 2*k, only then it will have absolute permutation
        // just replace consecutive group if k values for absolute permutation
        // test run for n=8 and k=2
        else if(n%(k*2)==0){
            int i=1;
            while(i<=n){
                for(int x =0; x<k; x++,i++)
                    printf("%d ",i+k);
                for(int x =0; x<k; x++,i++)
                    printf("%d ",i-k);
            }
            printf("\n");
        }
        // else absolute permutation is not possible
        else{
            printf("-1\n");
        }
    }
    return 0;
}

