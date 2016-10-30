// this is back tracking solution in which we try to place queens in one column at a time

#include<stdio.h>

int board[100][100]={0};

int isOK(int row, int col, int size){
	int ld, ud, currRow = row;	//variables for row index of lower diagonal, upper diagonal and curret row
	
	ld = row+1;
	ud = row-1;
	col -= 1;
	for(col; col >= 0; col--, ud--, ld++){
		
		if(ld < size){
			if( board[ld][col] == 1)
				return 0;
		}
		
		if(ud >= 0){
			if( board[ud][col] == 1 )
				return 0;
		}
		
		if( board[currRow][col] == 1)
			return 0;
	}
	
	return 1;
}

int placeQueens(int column, int size){
	
	int i;
	
	if(column >= size)
		return 1;
		
	for(i=0; i < size; i++){
		board[i][column] = 1;
		// check if placing queen in the current position causes any conflicts
		if(isOK(i, column, size)){
			if(placeQueens(column+1, size)){
				return 1;
			}else{
				board[i][column] = 0;
			}
		}else{
			board[i][column] = 0;	
		}
	}
	return 0;
}

int main(void){
	int size_of_board;
	int i, j;
	printf("enter the size of chess board: ");
	scanf("%d", &size_of_board);
	
	
	if( placeQueens(0, size_of_board)){
		printf("\nSolution is:\n\n");
		for(i = 0; i < size_of_board; i++){
			for(j = 0; j < size_of_board; j++){
				printf("%d  ", board[i][j]);
			}
			printf("\n");
		}
	}
	else{
		printf("\nSolution is not possible");
	}
	
}
