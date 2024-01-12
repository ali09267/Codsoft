#include<iostream> //This program is based on simple basic calculator
#include<limits>   //Asks user to input two numbers with operation between them (+,-,*,/)
 using namespace std;     //Performs calculation based on input operand
                    //Then ask user if he/she want to continue
class Calculator {
	//To keep following data members hidden from public
private:
    float inputNum1;
    float inputNum2;
    char operand;

public:
    Calculator() : inputNum1(0), inputNum2(0), operand('+') {}//Constructor to initialize variables

    void getInput()//Prompt user to input 
	{ 
        while (true)
		{
            cout << "Enter a number: ";//to input first number
            
            if (cin >> inputNum1) 
			{
                break;
            } 
            
		else
		{
            cout << "Invalid input, please enter a number" << endl;//input validation
            cin.clear();
            cin.ignore();
        }
    }

        while (true) 
		{
            cout << "Enter second number: ";//Ask to input second number
            
            if (cin >> inputNum2)
			{
                break;
            } 
            
			else 
			{
                cout << "Invalid input, please enter a number" << endl;//input validation
                cin.clear();
                cin.ignore();
            }
        }

        while (true) 
		{
            cout << "Enter operation between them (+,-,*,/): ";//Ask for operator
            cin >> operand;

            if (operand == '+' || operand == '-' || operand == '*' || operand == '/')
			{
                break;
            } 
            
			else
			{
                cout << "Invalid operator. Please enter +, -, *, or /." << endl;//operator validation 
                cin.clear();
                cin.ignore();
            }
        }
    }

    void calculate() //To perform calculation
	{
        switch (operand) 
		{
            case '+':
                cout << "Result: " << inputNum1 + inputNum2;//in case '+' performs addition
                break;
            case '-':
                cout << "Result: " << inputNum1 - inputNum2;//in case '-' performs subtraction
                break;
            case '*':
                cout << "Result: " << inputNum1 * inputNum2;//in case '*' performs multiplication
                break;
            case '/':
                if (inputNum2 == 0)
				{
                cout << "MATH ERROR (Division by zero)\n";//division validation by checking denominator in case 0
                } 
				
				else
				{
                    cout << "Result: " << inputNum1 / inputNum2;//in case '/' performs division
                }
                break;
            default:
                cout << "\nUnexpected error occurred. Please try again." << endl;
        }
    }
};

int main() {
    string choice;
    Calculator calc;  //Creating object of class calculator(Constructor automatically invoked)

    do 
	{//usng do-while loop to execute program atleast once 
        calc.getInput();//Calling functions to perform their respective jobs
        calc.calculate();

    cout << "\nDo you wish to perform another calculation (Yes or No): ";
    cin >> choice;//Asks whether user wants to continue by yes or no

    }
	while (choice == "yes" || choice == "YES" || choice == "Yes");//while user enter yes , program will 
//execute again
    return 0;
}
