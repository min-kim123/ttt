#include <iomanip>
#include <iostream>
using namespace std;
void printBoard();
bool checkTie();
bool checkWin();
int board[2][2];
int blank = 0;
int xmove = 1;
int omove = 2;
int xturn = 0;
int oturn = 1;
int turn = xturn;
char input[2];
int inputlength = 0;
int xwin;
int owin;

int main() {  
  bool stillplaying = true;
  while (stillplaying == true) {
    //while (checkWin(xmove) == false && checkWin(omove) == false && checkTie() == false) {
      printBoard();
      cin.getline(input, 3);
      //incorrect input
      //input is not a length of 2
      for (int i = 0; input[i] != '\0'; i++) {
	inputlength += 1;
      }
      if (inputlength != 2) {
	cout << "Enter a letter followed by a number." << endl;
      }
      //row does not exist
      else if (input[0] != 'a'
	       && input[0] != 'b'
	       && input[0] != 'c') {
	cout << "Row must be an a, b, or c." << endl;
      }
      //column does not exist
      else if (input[1] != '1' &&
	       input[1] != '2' &&
	       input[1] != '3') {
	cout << input[1] << endl;
	cout << "Column must be a 1, 2, or 3." << endl;
      }
      //correct input
      else {
	cout << "correct input" << endl;
      }
      stillplaying = false;
      //    }
  }


}

void printBoard() {
  cout << "\t1\t2\t3" << endl;
  
  
}

bool checkWin(int player) {
  if (board[0][0] == player && board[0][1] == player && board[0][2] == player){
    return true;
  }
  if (board[1][0] == player && board[1][1] == player && board[1][2] == player){
    return true;
  }
  if (board[2][0] == player && board[2][1] == player && board[2][2] == player){
    return true;
  }
  if (board[0][0] == player && board[1][0] == player && board[2][0] == player){
    return true;
  }
  if (board[0][1] == player && board[1][1] == player && board[2][1] == player){
    return true;
  }
  if (board[0][2] == player && board[1][2] == player && board[2][2]== player){
    return true;
  }
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player){
    return true;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player){
    return true;
  }

  return false;
}

bool checkTie() {
  for(int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {
      if (board[row][column] == blank) {
	return false;
      }
    }
    return true;
  }
}
