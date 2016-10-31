#include <stdio.h>


void reverse(char a[], int start, int end){
    if(start==end)
        return;
    char temp;
    while(start<end){
        temp = a[start];
        a[start]=a[end];
        a[end]= temp;
        start++;
        end--;
    }
}

int main() {

    int t, len;
    char word[101];
    int possible;
    int k,l;
    scanf("%d", &t);
    while(t--){
        scanf("%s",word);
        len = strlen(word);
        possible = 0; // 0 means no answer
        //step 1: Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is the last permutation.
        for(int i = len-2; i>=0; i--){
            if(word[i]<word[i+1]){
                k = i;
                possible = 1;
                break;
            }
        }
        
        if(!possible)
            printf("no answer\n");
        else{
            //step 2 : Find the largest index l greater than k such that a[k] < a[l].
            for(int i = len-1; i>k; i--){
                if(word[k]<word[i]){
                    l = i;
                    break;
                }
            }
            
            //step 3: Swap the value of a[k] with that of a[l].
            char temp = word[k];
            word[k]=word[l];
            word[l]=temp;
            
            //step4: Reverse the sequence from a[k + 1] up to and including the final element a[n].
            reverse(word, k+1, len-1);
            
            printf("%s\n",word);
        }
    } 
    return 0;
}

