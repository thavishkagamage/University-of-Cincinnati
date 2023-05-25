#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <cstring>
char* strcpy(char* to, const char* from);

#define MAX_PLAYERS 10

using namespace std;

/*
	N-sided die-representing class
*/
class Dice {
private:
	int numberofsides;
	void generator() {
		srand((unsigned)time(0));
	}
public:
	// Perform a single die roll.	
	int roll() {
		//The result of a dice throw can range from 1 to n.
		return (rand() % numberofsides) + 1;
	}
	Dice(int nS) {
		numberofsides = nS;
		generator();
	}
};

/*
	Class denoting a player in a game
*/
class Player {
private:
	string name;
	int score;
public:
	// Getter : Player Name
	// Using a parametrized constructor, initialize the variables.
	Player(string a, int b) {
		name = a;
		score = b;
	}
	//return the constructor's name.
	string getName() {
		return name;
	}
	// Getter : Score
	//return the constructor's score.
	int getScore() {
		return score;
	}
	// raises the player's score by a certain amount.
	//expanding the value of the scores.
	void addToScore(int val) {
		score += val;
	}
};

/*
	Abstract class DiceGame
*/
class DiceGame {

public:
	Player* players[MAX_PLAYERS];
	Dice* dice;
	int number_players, Dice_Amount;
	//	an entirely virtual function	
	virtual void play() = 0;

	DiceGame(Dice dice, int number_players, int Dice_Amount)
	{
		this->dice = &dice;
		this->number_players = number_players;
		this->Dice_Amount = Dice_Amount;

	}

	void initPlayers() {
		//Re-take the name and score of a player.
		string name;
		int score;
		//Put to an array
		for (int i = 0; i < number_players; i++) {
			//Player name and score are entered..
			cout << "Player Name: ";
			cin >> name;
			cout << "Player Score: ";
			cin >> score;
			//Pointer players -> put to an array.
			players[i] = new Player(name, score);
		}
	}
	//Show each player's name and score.
	void displayScores() {
		for (int i = 0; i < number_players; i++) {
			cout << players[i]->getName() << ":" << players[i]->getScore() << endl;
		}
	}

	void writeScoresToFile() {
		ofstream myfile("Game.txt");
		if (myfile.is_open()) {
			for (int i = 0; i < number_players; i++) {
				myfile << "Player's name: " << players[i]->getName() << ":"
					<< "Player's score: " << players[i]->getScore() << endl;
			}
			myfile.close();
		}
		else {
			cout << "Unable to open file";
		}
		return;
	}

	void getHighestScore() {
		string line;
		ifstream myfile("Game.txt");
		if (myfile.is_open()) {
			string max_player;
			int max_score = 0;
			while (getline(myfile, line)) {
				string deli = ":";
				int sequence_counter = 0;
				int cur_score;
				string cur_player;
				int start = 0;
				int end = line.find(deli);
				while (end != -1) {
					if (sequence_counter == 1)
					{
						cur_player = line.substr(start, end - start);
					}
					start = end + deli.size();
					end = line.find(deli, start);
					sequence_counter++;
				}
				string str_cur_score = line.substr(start, end - start);
				int  n = str_cur_score.length();
				char char_array[]{ n + 1 };
				strcpy(char_array, str_cur_score.c_str());
				cur_score = atoi(char_array);

				if (cur_score > max_score)
				{
					max_score = cur_score;
					max_player = cur_player;
				}
			}
			myfile.close();
			cout << "Player with Highest Score = " << max_player << endl;
			cout << "Highest Score = " << max_score << endl;

		}
		else {
			cout << "Unable to open file";
		}
		return;
	}

};

class KnockOut : public DiceGame {
public:
	KnockOut(Dice dice, int number_players, int Dice_Amount) : DiceGame(dice, number_players, Dice_Amount) {};
	void play() {
		initPlayers();
		cout << "Play start";

		int dice_roll, winner = -1, KO_score = 0;
		//Create an array of players with a value of 0 for each player.
		int player_eliminated_check[MAX_PLAYERS] = { 0 };
		int current_no_of_players = number_players;
		KO_score = 0;
		for (int i = 0; i < Dice_Amount; i++) {
			KO_score += dice->roll();
		}

		//Repeat while we are still unsure about the outcome.
		while (current_no_of_players > 1) {
			for (int i = 0; i < number_players; i++) {

				//Whether the players are still engaged.
				if (player_eliminated_check[i] == 0) {
					int player_score = 0;
					for (int j = 0; j < Dice_Amount; j++) {
						int dice_roll = dice->roll();
						//Increasing player score with the use of dice.
						for (int k = 0; k < Dice_Amount; k++) {
							player_score += dice_roll;
						}
					}
					//Eliminate a player whose score is equal to the KO score.
					if (player_score == KO_score) {
						current_no_of_players -= 1;
						//Put the specific element in array 1 after that to prevent program overflow.
						player_eliminated_check[i] = 1;
					}
					//If there is just one player, then they have won!
					if (current_no_of_players == 1) {
						winner = i;
					}
				}
			}


		}
		//Reward the winner based on their score!
		players[winner]->addToScore(10);
	}
};

class Boston : public DiceGame {
public:
	Boston(Dice dice, int num_p, int num_dice) : DiceGame(dice, number_players, Dice_Amount) {};
	void play() {
		initPlayers();
		//No one is winning, therefore set the maximum player to -1.
		int max_player = -1;
		int max_player_score = 0;
		for (int i = 0; i < number_players; i++) {
			int cur_player_score = 0;
			for (int j = 0; j < Dice_Amount; j++) {
				//Each roll's largest number will be retained.. 
				int rollmax = 0;
				int currentroll;
				for (int k = 0; k < (Dice_Amount - j); k++) {
					currentroll = dice->roll();
					if (currentroll > rollmax) {
						rollmax = currentroll;
					}
				}
				cout << "Maximum roll: " << rollmax << endl;
				//Adding up each player's highest score after each roll of the die.
				cur_player_score += rollmax;
			}
			//If a player's current score is higher than their previous score, that score is kept..
			if (cur_player_score > max_player_score) {
				max_player_score = cur_player_score;
				max_player = i;//Winner is announced!
			}
			cout << "The winner is: "<< max_player << endl;
		}
	}

};


int main() {
	// Base class pointer
	DiceGame* game;

	//Count the number of sides, dice, and participants.
	int number_players, Dice_Amount, numberofsides;
	cout << "Players?";
	cin >> number_players;
	cout << "Sides?";
	cin >> numberofsides;
	cout << "Dice_Amounts?";
	cin >> Dice_Amount;

	int choice;
	cout << "enter your choce : 1 for knockout game, 2 for boston game";
	cin >> choice;

	Dice dice(numberofsides);

	//Call out the KnockOut class.
	if (choice == 1) {
		KnockOut objt(dice, number_players, Dice_Amount);
		game = &objt;
	}
	else {
		Boston objt(dice, number_players, Dice_Amount);
		game = &objt;
	}

	game->play();
	game->displayScores();
	game->getHighestScore();

}
