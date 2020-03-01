

#include <algorithm>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

class InvertedIndex {
    //implemented user defined compare method to sort map keys (strings).
	struct comparison
	{
	    public:
	    bool operator()(const string x, const string y)
	    {
	         return (x.compare(y) < 0);
	    }
	};
	
	private:

	typedef map <string, vector<pair <int,int>>, comparison> MapType;
	map <string, vector<pair <int,int>>, comparison> dictionary;
	map <string, vector<pair <int,int>>, comparison>::iterator it;
	int lineCount = 1;
	int wordPosition = 0;
	
	public:
	
	//default constructor
	InvertedIndex() {}
	
	//add word method
	void addWord(string x, int line){
		//helper method design to reset the word's position count (when line number changes). 
		checkLine(line);
		
	  	string temp = clean(x);
	  	//if the word is blank (empty) exit method
	  	if(temp.empty()) return;
	  	//incrememnet word's position count after validating the input is a valid word.  
	  	wordPosition++;
	  	/*
	  	  search to see if the word (key) is already in the map
	  	  if yes, update the value (vector) with location of the word (line and position).
	  	  Otherwise, insert the key/value to the map.
	  	*/
	  	it = dictionary.find(temp);
        if (it != dictionary.end())
        {
          it -> second.push_back(make_pair(line,wordPosition));
        } else {
          dictionary[temp].push_back(make_pair(line,wordPosition));
        }
	}
	

	string clean(string x){
		string result;
		for (int i = 0; i < x.length(); i++) 
		{
		     switch (x[i]) {
		        case ',':
		        case '!':
		        case '.':
		        case '-':
		        case ' ':
		        case '=':
		            break;
		        default:
		        //format the word to be lower case.
		        result += tolower(x[i]);
		     }
		}
		return result;
	}
	
	//output the map to text file. 
	void output() {
	 ofstream Print("output.txt");
	 ostringstream os;	
	 for(auto & a : dictionary) 
		{
		   os  << a.first << " " <<  a.second.size() << " [";
		   int count = 1;
		   for(auto & b : a.second) 
			   {
			   	if (count == a.second.size()) { os  <<  "(" << b.first << ", " << b.second << ")"; }
			   	else 
			   	{
			   		os  <<  "(" << b.first << ", " << b.second << "), ";
			   		count++;
			   	}
			   }
			   os << "]" << endl;
		}
		
		Print << os.str();
		Print.close();
	}
	
  void checkLine(int line){
  	if(lineCount != line) wordPosition = 0;
	lineCount = line;
  }

};

int main(){
	InvertedIndex temp;
	string line, word;
	int lineCount = 1;
	ifstream File;
	File.open("input.txt");
	if(File.is_open()){
		while(File.good())
		{
			getline(File, line);
			stringstream str(line);
			while(str >> word)
			{
				//add all the words within the line
				temp.addWord(word, lineCount);
			}
				//increment line count after line is completed.
				lineCount++;
		}
	}
	File.close();
	temp.output();
	return 0;
}
