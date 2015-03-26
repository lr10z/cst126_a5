//
// CST 126 - Assignment #5
//
// Author: Leander Rodriguez
//
// File: entry.cpp
//
// Due date:  Sunday, March 17th by 11:59pm
//



#include  "entry.h"


using  namespace  std;


//
// Constructor
//
Entry::Entry()
{
	
}

Entry::Entry( string w, string d )
{
	m_word = w;

	m_def = d;
}



//
// Member function that compares dictionary entries and returns
// the one with the lesser value for sorting purposes
//
int Entry::compareMYentries( const void  *vp1, const void *vp2 )
{

	Entry *p1 = (Entry *) vp1;
	Entry *p2 = (Entry *) vp2;

	return p1->getWord().compare( p2->getWord() );

}