/*
 * FILE: Source.cpp
 * AUTHOR: Bernadette Kornberger
 * DATE: 2/2021
 * PURPOSE: Polynomial Calculator that works with user input in a stack
 *          
 *          CSC36000 Project #2.
 */

#include "PolyStack.hpp"
#include "PolyStack.ctt"

#include <list>
#include <iostream>

using namespace std;

/*****************************************************************************/
//solves top polynomial for value input by user
void solve(const PolyStack <Polynomial> stack)
{
	float num,
		  total;
	Polynomial poly;

	cout << "Please enter what you would like to plug in for x: ";
	cin >> num;
	cout << endl;

	//gives us the Polynomial at the top of the stack
	poly = stack.top();

	total = poly.eval(num);

	cout << "when x = " << num << endl
		 << poly << " = " << total << endl;

}
/*****************************************************************************/
//combines top two polynomials
void combine(PolyStack <Polynomial> &stack)
{
	Polynomial first,
		       second,
		       Poly;

	//once we have them stored in a variable they are removed from stack
	first = stack.top();
	stack.pop();
	second = stack.top();
	stack.pop();

	//adds them and stores at the top of stack
	Poly = first + second;
	stack.push(Poly);

	cout << stack.top() << endl;
}
/*****************************************************************************/
//subtracts top two polynomials
void subtract(PolyStack <Polynomial>& stack)
{
	Polynomial first,
		second,
		Poly;

	//once we have them stored in a variable they are removed from stack
	first = stack.top();
	stack.pop();
	second = stack.top();
	stack.pop();

	//subtracts them and stores new polynomial at top of stack
	Poly = second - first;
	stack.push(Poly);

	cout << stack.top() << endl;
}
/*****************************************************************************/
//multiply top two polynomials
void multi(PolyStack <Polynomial>& stack)
{
	Polynomial first,
		second,
		Poly;

	//once we have them stored in a variable they are removed from stack
	first = stack.top();
	stack.pop();
	second = stack.top();
	stack.pop();

	//multiplies them and stores new polynomial at top of stack
	Poly = second * first;
	stack.push(Poly);

	cout << stack.top() << endl;
}
/*****************************************************************************/
//print polynomial at top of stack
void print(const PolyStack <Polynomial> stack)
{
	cout << stack.top() << endl;
}
/*****************************************************************************/
//prints error message
void error()
{
	cout << "I'm sorry that is not a correct command please try again"
		 << endl;
}
/*****************************************************************************/
//prints quit message
void quit()
{
	cout << "Thank you for using PolyCalc! Have a good day.";
}
/*****************************************************************************/
int main()
{
	PolyStack<Polynomial> MyStack; //creates the stack of polynomials
	char m = ' '; //Used for the menu loop

	cout << "Welcome to PolyCalc" << endl;
	MyStack.push(); // stores a polynoimal on stack
	print(MyStack);

	cout << "What would you like to do?" << endl
		<< "c - Clear top polynomial" << endl
		<< "d - Clear all polynomials" <<endl
		<< "s - Add a new polynomial" << endl
		<< "e - Evalute top polynomial" << endl
		<< "+ - Add top two polynomials" << endl
		<< "- - Subtract top two polynomials" << endl
		<< "* - Multiply top two polynomials" << endl
		<< "p - Print top polynomial" << endl
		<< "q - Quit" << endl;
	do
	{
		cout << ">>> ";
		cin >> m;
		//menu
		switch (m)
		{
		case 'c':
			//pops top polynomial
			MyStack.pop();
			break;

		case 'd':
			//clears the whole stack
			MyStack.clear();
			break;

		case 's':
			//pushes a new polynomial onto the stack
			MyStack.push();
			print(MyStack);
			break;

		case 'e':
			//solves top polynomial for value input by user
			solve(MyStack);
			break;

		case '+':
			//combines top two polynomials
			combine(MyStack);
			break;

		case '-':
			//subtracts top two polynomials
			subtract(MyStack);
			break;

		case '*':
			//multiply top two polynomials
			multi(MyStack);
			break;

		case 'p':
			//prints top polynomial
			print(MyStack);
			break;

		case 'q':
			//when users ready to quit
			break;

		default:
			//if user enters a command thats not valid 
			error();
		}
	} while (m != 'q');

	//Once out of the menu run the quit function
	quit(); 

	return 0;
}