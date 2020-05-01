#include "pch.h"
#include <iostream>
#include<vector>
#include<string>
using namespace std;


class TicTacToe {
private:
	string players = { 'X', 'O' };
	char player1, player2;
	vector <int> available_moves = {};
	vector <int> moves = {};
	vector <int> player1_moves = {}, player2_moves = {};
	char winner;

public:
	TicTacToe() {
		// Wlecome to the game
		cout << "Wlecome to the tic-toc-toe game!\n";
		// assigning the players
		player1 = players[0];
		player2 = players[1];
		cout << "Player 1 " << player1 << endl;
		cout << "Player 2 " << player2 << endl;
		available_moves = { 1,2,3,4,5,6,7,8,9 };
	}

	int getMoves() {
		return moves.size();
	}

	bool isMoveValid(int pos) {
		if (pos < 10 && pos>0) {
			for (int a : moves) {
				if (pos == a) {
					return false;
				}
			}
		}
		else if (pos > 9 && pos <= 0) {
			return false;
		}
		return true;
	}

	bool isMoveExists(int pos, vector <int> arr) {
		for (int a : arr) {
			if (a == pos) {
				return true;
			}
		}
		return false;
	}

	bool isWinning(char this_player) {
		if (this_player == player1) {
			vector <int> playerx_moves = player1_moves;
			if (isMoveExists(1, playerx_moves) && isMoveExists(2, playerx_moves) && isMoveExists(3, playerx_moves)) {
				return true;
			}
			else if (isMoveExists(4, playerx_moves) && isMoveExists(5, playerx_moves) && isMoveExists(6, playerx_moves)) {
				return true;
			}
			else if (isMoveExists(7, playerx_moves) && isMoveExists(8, playerx_moves) && isMoveExists(9, playerx_moves)) {
				return true;
			}

			else if (isMoveExists(1, playerx_moves) && isMoveExists(4, playerx_moves) && isMoveExists(7, playerx_moves)) {
				return true;
			}
			else if (isMoveExists(2, playerx_moves) && isMoveExists(5, playerx_moves) && isMoveExists(8, playerx_moves)) {
				return true;
			}
			else if (isMoveExists(3, playerx_moves) && isMoveExists(6, playerx_moves) && isMoveExists(9, playerx_moves)) {
				return true;
			}

			else if (isMoveExists(1, playerx_moves) && isMoveExists(5, playerx_moves) && isMoveExists(9, playerx_moves)) {
				return true;
			}
			else if (isMoveExists(3, playerx_moves) && isMoveExists(5, playerx_moves) && isMoveExists(7, playerx_moves)) {
				return true;
			}
			
		}
		else {
			vector <int> playerx_moves = player2_moves;
			if (isMoveExists(1, playerx_moves) && isMoveExists(2, playerx_moves) && isMoveExists(3, playerx_moves)) {
				return true;
			}
			else if (isMoveExists(4, playerx_moves) && isMoveExists(5, playerx_moves) && isMoveExists(6, playerx_moves)) {
				return true;
			}
			else if (isMoveExists(7, playerx_moves) && isMoveExists(8, playerx_moves) && isMoveExists(9, playerx_moves)) {
				return true;
			}

			else if (isMoveExists(1, playerx_moves) && isMoveExists(4, playerx_moves) && isMoveExists(7, playerx_moves)) {
				return true;
			}
			else if (isMoveExists(2, playerx_moves) && isMoveExists(5, playerx_moves) && isMoveExists(8, playerx_moves)) {
				return true;
			}
			else if (isMoveExists(3, playerx_moves) && isMoveExists(6, playerx_moves) && isMoveExists(9, playerx_moves)) {
				return true;
			}

			else if (isMoveExists(1, playerx_moves) && isMoveExists(5, playerx_moves) && isMoveExists(9, playerx_moves)) {
				return true;
			}
			else if (isMoveExists(3, playerx_moves) && isMoveExists(5, playerx_moves) && isMoveExists(7, playerx_moves)) {
				return true;
			}
		}
		return false;
	}

	void play(int pos, char player) {
		if (isMoveValid(pos)) {
			if (player == player1) {
				// this means that the this is player 1 --> X
				moves.push_back(pos);
				player1_moves.push_back(pos);
				for (int i = 0; i < available_moves.size(); i++) {
					if (available_moves[i]==pos) {
						available_moves[i]= 0;
					}
				}
				
			}
			else {
				moves.push_back(pos);
				player2_moves.push_back(pos);
				for (int i = 0; i < available_moves.size(); i++) {
					if (available_moves[i] == pos) {
						available_moves[i] = 0;
					}
				}
			}
			if (isWinning(player)) {
				printGride();
				cout << "******* Player " << player << " is the winner *******" << endl;
			}
		}
		else if (!isMoveValid(pos)) {
			cout << "!!!!!! This move is not valid !!!!!!!" << endl;
		}
	}
	
	void printGride() {
		cout << "\n";
		for (int i = 0; i < 9; i++) {
			if (isMoveExists(i + 1, player1_moves)) {
				cout << player1 << "\t";
			}
			else if (isMoveExists(i + 1, player2_moves)) {
				cout << player2 << "\t";
			}
			else {
				cout << available_moves[i] << "\t";
			}

			if ((i+1)% 3 == 0) {
				cout << endl;
			}
		}
	}

};




int main()
{
	TicTacToe game;
	int move;
	game.printGride();
	char curr_player = 'X';
	while (!game.isWinning(curr_player)) {
		cout << "Player: " << curr_player << endl;
		cout << "choose your move!" << endl;
		cin >> move;
		game.play(move, curr_player);

		if (game.isWinning(curr_player)) {
			break;
		}
		else if (game.getMoves() == 9) {
			cout << "******* TIE *******" << endl;
			break;
		}
		game.printGride();

		if (curr_player == 'X') { 
			curr_player = 'O';
		}
		else { curr_player='X';}
	}
	
	return 0;
}

