// Adam vanWestrienen

#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

class Node {
	private:
	  int coefficient, exponent;
      Node *next, *previous;
		
	public:
      // constructors
	  Node();
	  Node(int c, int e);
	   
      // getters
	  int getExponent() {return exponent;}
      int getCoefficient() {return coefficient;}
      Node* getNext() {return next;}
      Node* getPrevious() {return previous;}

      // setters
      void setPrevious(Node* p) {previous = p;}	
      void setNext(Node* p) {next = p;}
      void setCoefficient(int c) {coefficient = c;}
	  void setExponent(int e) {exponent = e;}
	   
	};

    //constructors
    Node::Node() {   
			coefficient = 0;
			exponent = 0;
			next = 0; 
			previous = 0; 
		}	
		
	Node::Node(int c, int e){  
			coefficient = c;
			exponent = e;
			next = 0; 
			previous = 0; 
		}

#endif

