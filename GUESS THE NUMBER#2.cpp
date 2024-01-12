#include<iostream> //Program asks user to guess a number
#include<ctime>   //If number greater or less then original number then
#include<cstdlib>//comment according to it until user guess correct number 
using namespace std;

class GuessNumber{//To keep following data members hidden from public
	private:
	int myGuess;
	int originalNum;
	int score;
	
	public:
	
GuessNumber(){ //constructor to set random number 
	srand(time(0));//Ensuring that Original number will be random
    originalNum=rand()%20+1;}//Original number will be from 1 to 20
    
void  setScore(int s){//Setters to set initial score to 0
	score=s;
}
	
void welcome(){//display a welcome message to player
	cout<<"\t\t******WELCOME TO NUMBER GUESSING GAME******"<<endl;//Start of the game
	
	cout<<"\nPress Enter to continue...";//Waiting for user to press enter
	
	cin.ignore();
	}
void takeInput(){
	cout<<"\n\nGuess the number (1 to 20): ";//Ask user to take a guess
	cin>>myGuess;
	
}
	
void check(){
	
	while(myGuess!=originalNum) //if guess number not equal to desired number
	{  
	if(myGuess<1 || myGuess>20)//if guessed number not in range (1-20)
	{
		cin.clear();
		cin.ignore();
		cout<<"Invalid input , enter a number from 1 to 20: ";
	}
	
    else if (myGuess<originalNum)//Feedback on if guessed number less then desired number
	{
		score++;
		cout<<"Your guess is low. Try again: ";
	}
    else if(myGuess>originalNum)//Feedback on if guessed number greater then desired number
	{
		score++;
		cout<<"Your guess is high. Try again: ";
	}
	cin>>myGuess;  //For chances 
}
cout<<"\nCORRECT , U GOT IT"<<endl;//comment on guessing original number correctly
}
int getScore(){
	return score;
}

void comment(){//Comments on user performance
	if(score<=3)
	{
	cout<<"CONGRATS! You solved it in "<<score+1<<" attempts.Impressive!";
}
	else if(score>3&&score<=5)
	{
		cout<<"Good effort! You demostrated good problem solving skills";
	}
	else if(score>5 && score<=7)
	{
		cout<<"Decent performance. It took you "<<score+1<<" attempts. Good Luck next time";
	}
	else if(score>7)
	{
		cout<<"Room for improvement. It take you "<<score+1<<" attempts.";
	}
}};

int main(){
	//Calling functions to perform their respective jobs
	GuessNumber game;
	game.setScore(0); //Setting no: of attempts to 0
	game.welcome();  //for displaying welcome message to user
	game.takeInput();//prompt user to enter his/her guess
	game.check();//check whether guess is correct and give clues according to it
	game.getScore();//return no: of attempts
	game.comment();//gives feedback 
}
