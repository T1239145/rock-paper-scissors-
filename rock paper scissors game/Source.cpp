/*
Stone Paper Scissor or Rock Paper Scissor is a game that is played between two people,
Each player in this game forms one of three shapes. The winner will be decided as per the given rules:

Rock vs Scissor -> Rock wins
Rock vs Paper -> Paper wins
Paper vs Scissor -> Scissor wins
In this game, the user is asked to make choices based on both computer and user choices and the results are displayed showing both computer and user choices.

Technologies Required: C++ programming language, I/O Streams, Standard Library Functions.
*/

#include <iostream>
#include <string>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()
#include <cctype> // for toupper
#include <algorithm> // for transform

using namespace std;



// Function prototypes
string userInput();
string cpuInput();
void logic(const string& userChoice, const string& cpuChoice);




int main() {
	srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

	//syntax of a value returning function
	//datatype identifier, datatype idenitfier
	string userChoice = userInput();//calls function userinput and passes the string choice along
	string cpuChoice = cpuInput();
	//syntax function call functionName(paramter list)
	logic(userChoice, cpuChoice);
	return 0;

}
//user input will return the answer to other functions
string userInput() {

	string userChoice;
	cout << "This is a game of ROCK PAPER SCISSORS" << endl;
	cout << "RULES" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
		cout << "ROCK > SCISSORS " << endl;
		cout << "SCISSORS > PAPER " << endl;
		cout << "PAPER > ROCK " << endl;
		cout << "\n";
		cout << "\n";
	cout << "-------------------------------------------------------------------------------" << endl;
		cout << " ENTER CHOICE " <<  "\n";
		cin >> userChoice;
		cout << "\n";
		transform(userChoice.begin(), userChoice.end(), userChoice.begin(), ::toupper);
		return userChoice;
}

string cpuInput(){
	const string ROCK = "ROCK";
	const string PAPER = "PAPER";
	const string SCISSORS = "SCISSORS";
	int randomNum = rand() % 3;//creates a random number between 0-2
	//based on the random num will select a choice
	if (randomNum == 0) {
		return "ROCK";
	}
	else if (randomNum == 1) {
		return "SCISSORS";
	}
	else {
		return "PAPER";
	}
}
//prints result and has game rules
/*userChoice 
* cpu choice
* check to see if user/cpu input is valid and declare winner
*/
void  logic(const string& userChoice, const string& cpuChoice) {
	//user logic
	cout << "YOU CHOSE :" << userChoice << endl;
	if (userChoice != "ROCK" && userChoice != "PAPER" && userChoice != "SCISSORS"){
		cout << "USER Invalid choice." << endl;
	}
	cout << "CPU CHOSE :" << cpuChoice << endl;
	if (cpuChoice != "ROCK" && cpuChoice != "PAPER" && cpuChoice != "SCISSORS") {
		cout << "CPU Invalid choice." << endl;
	}
	
	cout << "-------------------------------------------------------------------------------" << endl;
	//rules to win && both conditions must be true to prompt
	if (userChoice == cpuChoice) {
		cout << "NO CONTEST/DRAW" << endl;
	}
	//win/lose condition for 
	//rock vs paper
	else if (userChoice == "ROCK" && cpuChoice == "PAPER") {
		cout << "THE WINNER IS CPU: PAPER BEATS ROCK" << endl;
	}
	else if (userChoice == "PAPER" && cpuChoice == "ROCK") {
		cout << "THE WINNER IS USER: PAPER BEATS ROCK" << endl;
	}
	// rock vs scissors
	else if (userChoice == "SCISSORS" && cpuChoice == "ROCK") {
		cout << "THE WINNER IS CPU: ROCK BEATS SCISSORS" << endl;
	}
	else if (userChoice == "ROCK" && cpuChoice == "SCISSORS") {
		cout << "THE WINNER IS USER: ROCK BEATS SCIRRORS" << endl;
	}
	// scissors vs paper
	else if (userChoice == "SCISSORS" && cpuChoice == "PAPER") {
		cout << "THE WINNER IS USER: SCISSORS BEATS PAPER" << endl;
	}
	else if (userChoice == "PAPER" && cpuChoice == "SCISSORS") {
		cout << "THE WINNER IS CPU: SCISSORS BEATS PAPER" << endl;
	}
}


