// Dynamic Problem
// time - O(n)
// space - O(1)

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main() {
    
    int t, n, num;	// test cases, number of elements in input array, to scan present element in array 
    long cont; 		// to store the max continuous sum till now
	long prevcont; 	// to store prev max continuous sum
	long noncont;	// to store the maximum non continuous sum
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        
        // scanning first element of array
		scanf("%d", &num);
        cont = prevcont = noncont = num;
              
        // scanning rest of the array
        for(int i=0; i<n-1; i++){
            scanf("%d", &num);
                        
            // if prev continuous sum was negative and current input no. is greater(+ve or -ve)
            // then it will be new max cont sum
            if(prevcont<0){
                if(num>prevcont)
                    prevcont=cont=num;
            }
            // if prev cont sum is was +ve, then calculate new cuurent cont sum
            // if it is greater than prev cont then update prev cont
            // and if new cont became less than prev cont tehn it means that the cuurent cont array segment has ended
            // so reset the cont sum
            else{
                cont += num;
                if(prevcont < cont)
                   prevcont = cont;
                if(cont<0)
                    cont=0;
            }
            
            // if noncont sum was negative and current input no. is greater(+ve or -ve)
            // then it will be new max noncont sum
            if(noncont < 0){
                if(num>noncont)
                    noncont = num;
            }
            // once it is positive, just add any non -ve number to non cont sum
            else{
                if(num>0)
                    noncont+=num;
            }
                
            
        }
        
        printf("%ld %ld\n", prevcont, noncont);
        
    }
    
    
    
    return 0;
}

