// Author: Bernadette Kornberger
// Date:   2/2021
// Purpose: PolyStack class

#ifndef _POLYSTACK_HPP_
#define _POLYSTACK_HPP_

#include <list>
#include "Polynomial.hpp"

template <class L>
class PolyStack : std::list<L>
{
public:
	//returns a bool if stack is empty
	bool isEmpty() const;
	
	//removes the top polynoimal on stack 
	void pop();

	//removes all polynomials on stack
	void clear();

	//adds a new polynomial to front of stack
	void push();
	void push(const L& val);

	//returns top polynomial 
	const L& top() const;

};


#endif
