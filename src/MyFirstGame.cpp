#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;
enum SPSc { Stone = 1, Paper = 2, Scissors = 3 };

int RandomNumber(int From, int To) {
	int num = From + rand() % (To - From + 1);
	return num;
}
void setScreen() {
	system("cls");
	system("color 0F");
}

void screenColor(string x) {
	if (x == "Player1")
		system("color 2F");
	else if (x == "Computer") {
		system("color 4F");
		cout << "\a";
	}
	else 
		system("color 6F");
		
	



}
string nameChoice(SPSc x) {
	if (x == 1)
		return "Stone";
	else if (x == 2)
		return "Paper";
	else
		return "Scissors";



}

string winner(int u, int c) {
	if (u > c)
		return "Player1";
	else if (c > u)
		return "Computer";
	else
		return "No Winner";


}

void finalResult(int rounds,int userC,int computerC,int drawC) {
	cout << "                 -----------------------------------------------------------\n\n";
	cout << "                                 ++ G a m e O v e r +++                    \n\n";
	cout << "                 -----------------------------------------------------------\n\n";
	cout << "                 --------------------[Game Results ]-------------------------\n\n";
	cout << "                 Game rounds          : " << rounds << endl;
	cout << "                 Player 1 won times   : " << userC << endl;
	cout << "                 Computer won times   : " << computerC << endl;
	cout << "                 Draw times           : " << drawC << endl;
	cout << "                 final winner         : " << winner(userC,computerC) << endl;
	cout << "                 -----------------------------------------------------------\n\n";



}

void aRoundResult(int round ,string winner,SPSc computerChoice,SPSc userChoice) {
	cout << "--------------Round[" << round << "] ------------------\n\n";
	cout << "Player1  Choice : " << nameChoice(userChoice) << "\n";
	cout << "Computer Choice : " << nameChoice(computerChoice) << "\n";
	cout << "Round Winner    : " << winner << "\n";
	cout << "--------------------------------------------------------\n\n\n";

}
SPSc Choice(int number) {
	if (number == 1)
		return SPSc::Stone;
	else if (number == 2)
		return SPSc::Paper;
	else
		return Scissors;
}

int ComputerChoice() {
	return RandomNumber(1, 3);
	
}

void Game(int round, SPSc user,int& userCounter,int& computerCounter,int& drawCounter) {
	SPSc computer = Choice(ComputerChoice());
	if (user == computer) {
		screenColor("Draw");
		drawCounter++;
		aRoundResult(round, "[No winner]", computer, user);
	}
	else if (user==Stone&&computer==Scissors||user==Paper&&computer==Stone||user==Scissors&&computer==Paper)//user win
	{
		screenColor("Player1");
		userCounter++;
		aRoundResult(round, "[Player1]", computer, user);
	
	}
	else {
		screenColor("Computer");
		computerCounter++;
		aRoundResult(round, "[Computer]", computer, user);
	}

}

void Rounds(int number) {
	int computerCounter = 0, userCounter = 0, drawCounter = 0;

	for (int i = 1; i <= number; i++) {
	
		cout << "Round[" << i << "] begins:\n\n";
	    cout << "Your Choice: [1]:Stone, [2]:Paper, [3]:Scissor ?\n\n";
		int userNum;
		cin >> userNum;
		SPSc userChoice = Choice(userNum);
		Game(i, userChoice, userCounter, computerCounter, drawCounter);
		
	}

	finalResult(number,userCounter, computerCounter, drawCounter);


}

void start() {
	string c = "y";
	do {
		setScreen();
		cout << "How Many Rounds 1 to 10 ?" << endl;
		int numberOfRound;
		cin >> numberOfRound;

		Rounds(numberOfRound);

		cout << "Do you want to play again? Y/N ?\n";
		cin >> c;
		
	} while ( c == "y" || c == "Y");
}

int main() {
	
	srand((unsigned) time(NULL));//for random function

	start();




}


