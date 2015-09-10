#include<stdio.h>
#include<stdlib.h>
#define N 9

int SolveSudoku(int grid[9][9]){
	int row,col,num;
	if(!Findunassigned(grid,row,col))
		return 1;
	
	for(num=1;num<=9;num++){
		
		if(issafe(grid,row,col,num)){
	
			grid[row][col]=num;
			
			if(SolveSudoku(grid))
				return 1;
			
			grid[row][col]=0;
		}
	}
	return 0;
}

int Findunassigned(int grid[9][9], int &row, int &col) //SEE THIS LINE CAREFULLY(&row,&col)
{
	for(row=0;row<=9;row++)
		for(col=0;col<=9;col++)
			if(grid[row][col]==0)
				return 1;
	return 0;
}

int issafe(int grid[9][9],int row, int col, int num)
{
	return (!usedinrow(grid,col,num) && !usedinrow(grid,col,num) && !usedingrid(grid,row-row%3,col-col%3,num));//row-row%3 gives the starting index to search in grid. same with column.
}

int usedinrow(int grid[9][9],int col,int num){
	int row;
	for(row=0;row<9;row++)
		if(grid[row][col]==num)
			return 1;
	return 0;
}

int usedincol(int grid[9][9],int row,int num){
	int col;
	for(col=0;col<9;col++)
		if(grid[row][col]==num)
			return 1;
	return 0;
}

int usedingrid(int grid[9][9],int row,int col,int num)
{
	int i,j;
	for(i=row;i<row+3;i++)
		for(j=col;j<col+3;col++)
			if(grid[row][col]==num)
				return 1;
	return 0;
}

void printGrid(int grid[9][9])
{
	int row,col;
    for (row = 0; row < 9; row++)
    {
       for (col = 0; col < 9; col++)
             printf("%2d", grid[row][col]);
        printf("\n");
    }
}



int main(void){
	
	int grid[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    if (SolveSudoku(grid))
          printGrid(grid);
    else
         printf("No solution exists");
 
    return 0;
}
