// Adam vanWEstrienen

#ifndef POLY_H_INCLUDED
#define POLY_H_INCLUDED

#include "Node.h"
#include <iostream>
#include <sstream>
using namespace std;

class Poly {
  
  private:
    Node *head, *tail;

  public:
    Poly();

    // getter method
    string getPoly();

    // setter methods
    void setPoly(int c, int e);
    void setCanonical(int c, int e);

    // helper methods
    void sort(Node *newNode);
    string numToString(int num);

};

// constructor
Poly::Poly() {
  Node *newNode = new Node(0,0);
  head = newNode;
  tail = newNode;
}


// convert int to string
string Poly::numToString(int num) {
  stringstream ss;
  ss << num;
  return ss.str();
}

// set polynomials
void Poly::setPoly(int c, int e) {
		if(c == 0) {
      e = 0;
    }

		Node *newNode = new Node(c, e);
		
		if(head == NULL || head == 0) { 
      head = newNode;
    }
		else {
		    newNode -> setPrevious(tail);
		    tail -> setNext(newNode);
		}
		
		tail = newNode;
	}

// print polynomials in string
string Poly::getPoly()
	{
	    string output = "", space = "", add = "+", x = "x", power = "x^";
		Node* p = head;

		while(p != NULL ||  p != 0)
		{
			if(p -> getCoefficient() == 0){ output += space; }
			else if(p -> getExponent() == 0)
			{ 
				    if (p -> getCoefficient() < 0){ output += space + numToString(p -> getCoefficient()); }
				    else output += add + numToString(p-> getCoefficient());
			}
			else if(p -> getExponent() == 1)
			{
				if(p -> getCoefficient() < 0) { output += space + numToString(p -> getCoefficient()) + x; }
				else output += add + numToString(p -> getCoefficient()) + x;
			}
			else 
			{
    			if(p -> getCoefficient() < 0) { output += space + numToString( p -> getCoefficient() ) + power + numToString (p -> getExponent());}
    			else output += add + numToString( p -> getCoefficient() ) + power + numToString(p -> getExponent());
		    }
			p = p -> getNext();
		}

		return output;
	}


// sort list
void Poly:: sort(Node *newNode) {

  Node *p = head;

  if (p -> getExponent() < newNode -> getExponent()) {
    newNode -> setNext(p);
    head = newNode;
    return;
  }
  while (p -> getNext() != NULL || p -> getNext() != 0) {
    if (p -> getNext() -> getExponent() < newNode -> getExponent()) {
      p -> setCoefficient(p -> getCoefficient() + newNode -> getExponent());
      return;
    }
    else if (p -> getNext() -> getExponent() < newNode -> getExponent()) {
      newNode -> setNext(p -> getNext());
      p -> setNext(newNode);
    return;
    }
    p = p -> getNext();
  }
  if (p -> getExponent() == newNode -> getExponent()) {
    p -> setCoefficient(p -> getCoefficient() + newNode -> getCoefficient());
    return;
  }
  else {
    p -> setNext(newNode);
  }
}

// set in canonical form
void Poly::setCanonical(int c, int e) {
  if (c == 0) {
    e = 0;
  }
  Node* newNode = new Node(c, e);
    if (head == NULL || head == 0) {
      head = newNode;
    }
    else {
      sort(newNode);
    }
  
}


ostringstream os;
// output list
void printList(string line1, string line2) {
  Poly lineAsIs1, lineAsIs2, canonical1, canonical2, add, sub, mult;
  int coefficient1, coefficient2, exponent1, exponent2;

  stringstream ss1(line1);
  while (ss1 >> coefficient1 >> exponent1) {
    lineAsIs1.setPoly(coefficient1, exponent1);
    canonical1.setCanonical(coefficient1, exponent1);
    add.setCanonical(coefficient1, exponent1);
    sub.setCanonical(coefficient1, exponent1);
  }
  stringstream ss2(line2);
  while (ss2 >> coefficient2 >> exponent2) {
    lineAsIs2.setPoly(coefficient2, exponent2);
    canonical2.setCanonical(coefficient2, exponent2);
    add.setCanonical(coefficient2, exponent2);
    sub.setCanonical(-coefficient2, exponent2);
  }

  os << "Line 1: " << lineAsIs1.getPoly() << endl;
  os << "Canonicalized: " << canonical1.getPoly() << endl;
  os << endl;
  os << "Line 2: " << lineAsIs2.getPoly() << endl;
  os << "Canonicalized: " << canonical2.getPoly() << endl;
  os << endl;
  os << "Addition: " << add.getPoly() << endl;
  os << "Subtraction: " << sub.getPoly() << endl;
  os << endl;



};

#endif
 