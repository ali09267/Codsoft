#include<iostream>//Program asks user to guess a number
#include<conio.h>//If number greater or less then original number then
#include<cstdlib>//comment according to it until user guess correct number
#include<ctime>
using namespace std;
int main(){
	int myGuess;
	
	srand(time(0));//Ensuring that Original number will be random
	int originalNum=rand()%20+1;//Original number will be from 1 to 20
	
	cout<<"\t\t******WELCOME TO NUMBER GUESSING GAME******"<<endl;//Start of the game
	
	cout<<"\nPress Enter to continue...";
	
	getch();
	
	cout<<"\n\nGuess the number (1 to 20): ";//Ask user to take a guess
	cin>>myGuess;  //Taking guess as an input
	
	while(myGuess!=originalNum) //if guess number not equal to desired number
	{  
		
		if(myGuess>20 || myGuess<0) //input validation
		{
cout<<"Your guessed number is not in desired range , please enter from 1 to 20"<<endl;
		}
	
else if (myGuess<originalNum)//Feedback on if guessed number less then desired number
	{
		cout<<"Your guess is low , Try again: ";
	}
else if(myGuess>originalNum)//Feedback on if guessed number greater then desired number
	{
		cout<<"Your guess is high , Try again: ";
	}
	cin>>myGuess;  //For chances 
}
cout<<"\nCORRECT , U GOT IT :)";//comment on guessing original number correctly
}
