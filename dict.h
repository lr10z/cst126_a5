//
// CST 126 - Assignment #5
//
// Author: Leander Rodriguez
//
// File: dict.h
//
// Due date:  Sunday, March 17th by 11:59pm
//


#ifndef  DICT_H
#define  DICT_H


#include "entry.h"


using  namespace  std;


#define  INPUT_LINE_MAX_LEN  256


//
// Class Declaration
//
class  Dictionary
{

  public  :

    typedef void  (*WordDefFunc)( const string  &word, const string  &definition );

    Dictionary( const string  &filename );

    ~Dictionary();

    string  lookupDefinition( const string  &word );

    void  forEach( WordDefFunc  func, bool  forward );


  private  :
	
	//
	// Variable that holds the # of entries in the dictionary
	//
	int m_numEntries;

	//
	// An array of type Entry to hold dictionary data
	//
	Entry *m_dictionary;

	//
	// Array that holds a line of text read in from file
	//
	char text[INPUT_LINE_MAX_LEN];
	

};


#endif
