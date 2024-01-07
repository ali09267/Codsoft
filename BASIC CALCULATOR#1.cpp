#include<iostream>  //This program is based on simple basic calculator
#include<limits> //Asks user to input two numbers with operation between them (+,-,*,/)
using namespace std;     //Performs calculation based on input operand
int main(){        //Then ask user if he/she want to continue
	              
	float inputNum1,inputNum2;
	char operand;
	string choice;
	
do{
	while(true){
	cout<<"Enter a number: ";   //Ask user to input first number
	
	if(cin>>inputNum1){
		break;
	}
	
	else                        //Checking user's input
	{cout<<"Invalid input , please enter a number"<<endl;
	
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	}
	}
	
	while(true){
		
	cout<<"Enter second number: ";    //Ask user to input second number
	if(cin>>inputNum2)
	{
		break;
	}
	else{                            //Checking user's input
		cout<<"Invalid input , please enter a number"<<endl;
		
		cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
		}
}
	cout<<"Enter operation between them (+,-,*,/): ";  //Ask for operation
	cin>>operand;
	
	switch (operand){
	case '+':{           //Performs addition if operation is '+'
		cout<<"Result: "<<inputNum1+inputNum2;
		break;
	}
		case '-':{	   //Performs subtraction if operation is '-'
		cout<<"Result: "<<inputNum1-inputNum2;
			break;
		}	
		case '*':{      //Performs multiplition if operation is '*'
	 	cout<<"Result: "<<inputNum1*inputNum2;
			break;
		}
		case '/':{      //Performs division if operation is '/'
		
			if(num2==0){
cout<<"MATH ERROR (Division by zero)";//Checking for denominator in case if it is '0'
			}
			
			cout<<"Result: "<<inputNum1/inputNum2;
			break;
		}
		
		 default:
		 {//Give error if operation does not belong to (+,-,*,/)
			cout<<"\nYour operation does not belong to (+,-,*,/) .Try again "<<endl;
			break;
		}
	}
	cout<<"\nDo you wish to perform another calculation(Yes or No): ";
	cin>>choice;     //Ask user if he/she want to continue
	
	
}
while(choice=="yes" || choice=="YES" || choice=="Yes");}/*Ignoring case
sensitivity*/
