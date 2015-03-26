//
// CST 126 - Assignment #5
//
// Author: Leander Rodriguez
//
// File: main.cpp
//
// Due date:  Sunday, March 17th by 11:59pm
//



#include  <iostream>
#include  <iomanip>
#include  "dict.h"


using  namespace  std;


//
// Column header
//
void columnHeader()
{

	cout  <<  endl	  
		  <<  setw(4)  <<  ""  
		  <<  setw(17) <<  left  
		  <<  "Word"  
		  <<  "Definition"  
		  <<  endl  

		  <<  setw(4)   <<  ""		
		  <<  "----"   
		  <<  setw(13)  <<  ""		
		  <<  "----------"  
		  <<  endl;

}



//
// A function that will display a word and it's definition.
//
static void  displayEntry( const string  &word, const string &def )
{

	cout  <<  setw(4)  <<  ""  
		  <<  setw(17) <<  left	  
		  <<  word
		  <<  def
		  <<  endl; 

}



//
// Main program
//
int main( int argc, char *argv[] )
{

	//
	// Command line argument initialized and checked
	//
	char *programName = argv[0];
	char *argumentName = argv[1];


	if (argc != 2)
    {

      std::cerr <<  "Invalid command line." 
		        <<  std::endl
				<<  '\t'
				<<  "Usage: "
				<<  programName
				<<  std::endl;

      exit(EXIT_FAILURE);

    }
   

	//
	// Dictionary object created
	// 
	Dictionary dict( argumentName );


	//
	// User prompted for word and word is looked-up in dictionary
	//
	string word;


	do
	{

		cout  <<  endl  <<  "Enter a word: ";
		getline( cin, word );


		if( word == "" )
		{
			//
			// Blank word entered, therefore, exit program
			//
			return 0;
		}

		if( dict.lookupDefinition( word ) == "" )
		{
			//
			// Word does not exist in dictionary
			//
			cout  <<  '\t'
				  <<  "*** '"  
				  <<  word  
				  <<  "' not found in dictionary"
				  <<  endl;  

		}

		else if( word == "+" )
		{

			//
			// Display entries in forward order
			//
			columnHeader();

			dict.forEach( displayEntry, true );

		}

		else if( word == "-" )
		{

			//
			// Display entries in reverse order
			//
			columnHeader();

			dict.forEach( displayEntry, false );

		}

		else
		{

			//
			// Displays definition
			//
			cout <<  '\t'  
				 <<  "Definition: "
				 <<  dict.lookupDefinition( word )
				 <<  endl;

		}


	}while( word != "" );

	
	return 0;
}