#ifndef STRINGS_H
#define STRINGS_H


typedef char* String;

// a cover function for malloc()
// malloc and return memory for a string of stringsize characters
// return (String)NULL on failure
String mallocString(int stringsize);

// just a cover function for free()
void freeString(String s);

// create a duplicate string of s
// return it
// return (String)NULL on failure
// should call mallocString(), and then strcpy()
String duplicateString(String s);

// create a duplicate of string list sl
// return it
// return (String*)NULL on failure
// uses other Strings module functions
//String* duplicateStringList(String* sl,int n);

// Return an allocated string from an open file,
// Stop reading when any character is in terminators list
// return allocated string or (String)NULL
String getfString(FILE* pFIn, String terminators);
String getString(String terminators);

int fputString(FILE* pFout, String s);

int compareStrings(const void* a, const void* b);

#endif