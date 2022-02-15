#include <bits/stdc++.h>
using namespace std;

int board[20][20];

bool isPossible(int maze[][20], int n,int row,int col){
	//The point should not be out of matrix,  also it should be the available path to go and last, it should not be covered earlier as path
    if( row <0 || row>=n || col <0 || col>=n || board[row][col] == 1 || maze[row][col] == 0){
        return false;
    }
  	return true;
}

void mazeHelper(int maze[][20], int n,int row, int col){
  	if(row == (n-1) && col == (n-1)){
        board[row][col] =1;
    // We have reached some solution.
    // Print the board and then return
		for(int i=0;i<n;i++){
      		for(int j=0;j<n;j++){
        		cout << board[i][j] << " ";
      		}
    	}
    	cout<<endl;
        board[row][col] = 0;
    	return;
  	}

  	// Place at all possible positions and move to smaller problem
  	//The rat can move in any of the four directions => upward, downward, left or right
    if(isPossible(maze, n , row+1, col)){
        board[row][col]=1;
        mazeHelper(maze, n, row+1, col);
        board[row][col]=0;
    }
    if(isPossible(maze, n , row-1, col)){
        board[row][col]=1;
        mazeHelper(maze, n, row-1, col);
        board[row][col]=0;
    }
    if(isPossible(maze, n , row, col-1)){
        board[row][col]=1;
        mazeHelper(maze, n, row, col-1);
        board[row][col]=0;
    }
    if(isPossible(maze, n , row, col+1)){
        board[row][col]=1;
        mazeHelper(maze, n, row, col+1);
        board[row][col]=0;
    }
    
  	return;
}

void ratInAMaze(int maze[][20], int n){
    memset(board,0,20*20*sizeof(int));
  	mazeHelper(maze, n, 0, 0);
}


int main(){

  int n; 
  cin >> n ;
  int maze[20][20];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> maze[i][j];
        }		
  }
  ratInAMaze(maze, n);
}