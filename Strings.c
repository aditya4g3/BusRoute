#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "Strings.h"


#define SIZE 100



String getfc(FILE* pFIn, String terminators, int n);
int charInString(String t, char c);

// a cover function for malloc()
// malloc and return memory for a string of stringsize characters
// return (String)NULL on failure
String mallocString(int stringsize){
    return (String)malloc(sizeof(char)*(stringsize+1));
}

// just a cover function for free()
void freeString(String s){
    free(s);
}

// create a duplicate string of s
// return it
// return (String)NULL on failure
// should call mallocString(), and then strcpy()
String duplicateString(String s){
    String sCopy = mallocString(strlen(s));
    if(sCopy != (String)NULL){
        strcpy(sCopy,s);
    }
    return sCopy;
}

String* duplicateStringList(String* s,int n){
    String* slCopy;
    // Allocate the list
    slCopy = (String*)malloc(sizeof(String)*n);
    if(slCopy == (String*)NULL) return slCopy;

    // Allocate/duplicate the strings
    for(int i = 0; i<n; i++){
        slCopy[i] = duplicateString(s[i]);
        if(slCopy[i] == (String)NULL){
            // Bad stuff - clean up and return
            for(int j=0; j<i; j++){
                freeString(slCopy[j]);
            }
            free(slCopy);
            slCopy = (String*)NULL;
            break;
        }
    }
    return slCopy;
}

// Return an allocated string from an open file,
// Stop reading when any character is in terminators list
// return allocated string or (String)NULL
String getfString(FILE* pFIn, String terminators){
    String s = getfc(pFIn, terminators, 0);
    return s;
}

String getString(String terminators){
    String s;
    s = getfc(stdin, terminators, 0);
    return s;
}

String getfc(FILE* pFIn, String terminators, int n){

    String s;
    char c = fgetc(pFIn);
    //base case
    if(c == EOF || charInString(terminators, c)){
        // allocate a string
        s = mallocString(n);    
        if(s != (String)NULL){
            // terminate the string
            s[n+1] = '\0';
        }    
        return s;
    }
    s = getfc(pFIn, terminators, n+1);
    s[n] = c;
    return s;
}

int charInString(String t, char c){
    int i = 0;
    while(t[i] != '\0'){
        if(t[i] == c) return 1;
        i++;
    }
    return 0;
}

int fputString(FILE* pFout, String s){
    int len = strlen(s);
    char lenAsStr[SIZE];
    sprintf(lenAsStr,"%d",(len-1));
    len += strlen(lenAsStr);
    fputs(lenAsStr,pFout);
    String space = " ";
    len++;
    fputs(space,pFout);
    fputs(s,pFout);
    return len;
}

char* fgetString(FILE* pFIn){
    char c = fgetc(pFIn);
    char lenAsStr[SIZE];
    int i = 0;
    while(isdigit(c)){
        lenAsStr[i] = c;
        i++;
        c = fgetc(pFIn);
    }
    int len = atoi(lenAsStr);
    char * str = mallocString(len);
    i = 0;
    while(c != '\n'){
        c = fgetc(pFIn);
        str[i] = c;
        i++;
    }
    return str;
}

int compareStrings(const void* a, const void* b) {
    const String* str1 = (const String*)a;
    const String* str2 = (const String*)b;
    
    return strcmp(*str1, *str2);
}