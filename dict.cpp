//
// CST 126 - Assignment #5
//
// Author: Leander Rodriguez
//
// File: dict.cpp
//
// Due date:  Sunday, March 17th by 11:59pm
//



#include  <iostream>
#include  <fstream>
#include  "dict.h"


using  namespace  std;


//
// Constructor
//
Dictionary::Dictionary( const string  &filename )
{

	//
	// File is opened
	//
	ifstream in( filename );

	
	//
	// Check to see if file exists
	//
	if( !in )
	{

		cout <<  "Error opening file '"
				  <<  filename
				  <<  "'"
				  <<  endl; 

		exit( EXIT_FAILURE );

	}

	else
	{

		//
		// Number of entries is read in from file and
		// carriage return after said number is cleared 
		// to prep next input from file
		//
		in  >>  m_numEntries;

		in.getline( text, INPUT_LINE_MAX_LEN );
		


		//
		// Memory for dictionary data is allocated and checked
		//
		m_dictionary = new Entry[m_numEntries];
		

		if( m_dictionary == 0 )
		{
			cout  <<  "Error:  Memory was not allocated correctly"  <<  endl;
		}
		


		//
		// Text from file is read in and split into words and definitions
		//
		for( int idx = 0; idx < m_numEntries; ++idx )
		{

			//
			// String of text is read in from file
			//
			in.getline( text, INPUT_LINE_MAX_LEN );


			//
			// Delimiters for splitting are defined
			//
			char delim[] = ",\n";
			char *context = 0;


			//
			// String split into words and definitions
			//
			char *token = strtok_s( text, delim, &context );
			string word( token );

			token = strtok_s( 0, delim, &context );
			string def( token );


			//
			// Local entry created
			//
			Entry entry( word, def );


			//
			// Entry is added to the dictionary
			//
			m_dictionary[idx] = entry;
			
		}


		//
		// File is closed
		//
		in.close();

	}


	//
	// Dictionary is sorted in forward order
	//
	qsort( m_dictionary, m_numEntries, sizeof(Entry), Entry::compareMYentries );
	

}



//
// Destructor, allocated memory is cleared
//
Dictionary::~Dictionary()
{
	delete [] m_dictionary;
}



//
// Find definition of the word selected by user
//
string Dictionary::lookupDefinition( const string  &word )
{

	//
	// Word selected by user is set as the key for search
	// in dictionary
	//
	Entry key(word, "");


	//
	// Checks if user requests dictionary to be displayed
	// in forward (+) order or reverse (-) order
	//
	if( word == "+" )
	{
		return "+";
	}
	else if( word == "-" )
	{
		return "-";
	}


	//
	// User's chosen word is looked for in the existing dictionary
	//
	Entry *resultPtr;

	resultPtr = (Entry*) 
				bsearch( &key, 
						 m_dictionary, 
						 m_numEntries, 
						 sizeof(Entry), 
						 Entry::compareMYentries ); 


	
	//
	// If word is found, the definition is returned
	// Otherwise, it was not found in the dictionary
	//
	if( resultPtr ) 
	{
		string definition = resultPtr->getDef();

		return definition;
	}
	else
	{
		return "";
	}
	
}



//
// Returns each dictionary entry in forward or reverse order;
// dependent on user's preference
//
void Dictionary::forEach( WordDefFunc  func, bool  forward )
{

	int idx;

	if( ! forward)
	{

		//
		// Loop through dictionary in reverse order, get all words and their 
		// definitions respectively for displaying
		//
		for( idx = m_numEntries-1; idx >= 0; --idx )
		{
			func( m_dictionary[idx].getWord(), m_dictionary[idx].getDef() );	
		}

	}

	else
	{
		//
		// Loop through dictionary, get all words and their definitions respectively
		// for displaying
		//
		for( idx = 0; idx < m_numEntries; ++idx )
		{
			func( m_dictionary[idx].getWord(), m_dictionary[idx].getDef() );	
		}

	}

}


