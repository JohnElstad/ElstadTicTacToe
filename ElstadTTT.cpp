#include<iostream>
#include<cstring>
using namespace std;

//John Elstad TicTacToe Game - 9/29/16

void printboard(char(*board)[3]);
void resetboard(char(*board)[3], char &turn);
bool checkWin(char(*board)[3],char player);
bool checkTie(char(*board)[3]);

				     
int main(){
  int owins =0;
  int xwins = 0;
  char turn = 'O';
  char board[3][3];
  int test = 5;
  
  char input[3];
  bool stillPlaying=true;
  //play again loop  
  while(stillPlaying==true){
    resetboard(board,turn);
    printboard(board);
    //loop runs while there are no winners/ tie games
    while(!(checkWin(board,turn)||checkTie(board))){
      if(turn =='X'){
	turn = 'O';
	cout<<"turn changes"<<endl;
      }
      else{
	turn = 'X';
      }

      bool hasMoved = false;
      //loop that checks input and sets the board to have player at place x,y
      while(hasMoved == false){

	cout<<"Type a capital letter and then a number in a blank space to make a move."<<endl;
	cin>>input;
	cout<<input<<endl;
	if(input[0]!='A'&& input[0]!='B'&& input[0]!='C'&& input[1]!= '1'&& input[1]!= '2'&& input[1] != '3'){
	  cout<<"Please Input a Capital letter then a number"<<endl;
	}
	//when the person moved what places there move on the board
	else if(board[input[0]-'A'][input[1]-'1']==' '){
	  board[input[0] -'A'][input[1]-'1']= turn;
	  printboard(board);
	  hasMoved=true;
	  	  
	}
	else{
	  cout<<"Make a legit move. The format of which is a capital letter followed by a number. Also it must be in a blank space."<<endl;
	}
	
      }
    }
    if(checkTie(board)){
      cout<<"Cat's game"<<endl;
    }
    //win counter
    else{
      cout<< turn << "Wins!"<<endl;
      if(turn== 'X'){
	  xwins++;
      }
      else{
	owins ++;
      }
    }
    cout<<"X has won this many times:"<<xwins<<endl;
    cout<<"O has won this many times:"<<owins<<endl;
    cout<<"Want to play again? Y/N"<<endl;
    char answer[2];
    cin>>answer;
      
    if(answer[0]=='N'){
      stillPlaying = false;
    }
  }
} 

//method that checks for wins
bool checkWin(char(*board)[3],char player){
  if(board[0][0] == player && board [1][1] ==player && board[2][2]==player){
    return true;
  }
  if(board[0][2] == player &&board[1][1] == player && board[2][0] == player){
    return true;
  }
  for(int z = 0; z<3; z++){
      if(board[0][z] == player && board[1][z] == player && board[2][z]==player){
	return true;
      }
      if(board[z][0] == player && board[z][1] == player && board[z][2] == player){
	return true;
      }
  }
  return false;
}
//method that checks for ties
bool checkTie(char(*board)[3]){
  bool tie = true;
  for(int i = 0; i <3; i++){
    for(int j = 0; j < 3; j++){
      if(board[i][j]==' '){
	 tie = false;
      }
    }  
  }
  return tie;
}		
//prints board
void printboard(char(*board)[3]){
  cout<<"\tA\tB\tC"<<endl;
  cout<< "1\t"<< board[0][0] << "\t"<<board[1][0]<<"\t"<<board[2][0]<<endl;
  cout<< "2\t"<< board[0][1] << "\t"<<board[1][1]<<"\t"<<board[2][1]<<endl;
  cout<< "3\t"<< board[0][2] << "\t"<<board[1][2]<<"\t"<<board[2][2]<<endl;
  
}
//resets board
void resetboard(char(*board)[3] , char &turn){

    for(int x=0;x<3;x++){
      for(int y=0;y<3;y++){
	board[x][y]=' ';
	
      }
    }
    turn = 'O';
}
