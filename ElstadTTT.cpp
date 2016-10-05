#include<iostream>
#include<cstring>
using namespace std;

//John Elstad TicTacToe Game - 9/29/16

void printboard(char(*board)[3]);
void resetboard(char(*board)[3]);
				     
int main(){
  char board[3][3];
  int test = 5;
  resetboard(board);
  printboard(board);
  
}

		

void printboard(char(*board)[3]){
  cout<<"\tA\tB\tC"<<endl;
  cout<< "1\t"<< board[0][0] << "\t"<<board[0][1]<<"\t"<<board[0][2]<<endl;
  cout<< "2\t"<< board[1][0] << "\t"<<board[1][1]<<"\t"<<board[1][2]<<endl;
  cout<< "3\t"<< board[2][0] << "\t"<<board[2][1]<<"\t"<<board[2][2]<<endl;
      
}

void resetboard(char(*board)[3]){

    for(int x=0;x<3;x++){
      for(int y=0;y<3;y++){
	board[x][y]='t';
	
      }
    }
}
