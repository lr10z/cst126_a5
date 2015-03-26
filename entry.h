//
// CST 126 - Assignment #5
//
// Author: Leander Rodriguez
//
// File: entry.h
//
// Due date:  Sunday, March 17th by 11:59pm
//



#ifndef  ENTRY_H
#define  ENTRY_H


#include <string>


//
// Class Declaration
//
class  Entry
{

  public  :

	//
	// Contructor
	//
	Entry();

	Entry( std::string w, std::string d );

	//
	// Method
	//
	static int compareMYentries( const void  *vp1, const void *vp2 );

	//
	// Accessors
	//
	const std::string &getWord() const { return m_word; }
	const std::string &getDef() const { return m_def; }


  private  :

	//
	// Strings that represent the word and definition entries
	// in the dictionary
	//
    std::string m_word;
	std::string m_def;

};


#endif
