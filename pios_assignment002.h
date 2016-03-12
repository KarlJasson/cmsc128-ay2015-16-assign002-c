/*
	CMSC 128 Assignment 002
	Author: PIOS, Karl Jasson
	Section: AB-6L
	Description: A C library containing 6 functions as specified for Assignment 2
		- getHammingDistance()
		- countSubstrPattern()
		- isValidString
		- getSkew
		- getMaxSkewN
		- getMinSkewN
*/


#include<string.h>
#include<stdio.h>

// FUNCTION 1 ////////////////////////////////////////////
int getHammingDistance(char str1[], char str2[]){
	
	if(strlen(str1) == strlen(str2)){// if str1 and str2 are of unequal length, this returns false 
		int length = strlen(str1);
	
		int numOfMismatches = 0;
		int i;
		
		for(i=0; i<length; i++){
			if(str1[i] != str2[i]){
				numOfMismatches = numOfMismatches + 1;
			}
		}
		return numOfMismatches;
	}
	else{
		return -1;
	}
}
// End of FUNCTION 1 //////////////////////////////////////


// FUNCTION 2 (FAULTY) ////////////////////////////////////////////
int countSubstrPattern(char original[], char pattern[]){
	int i, j;
	
	int numOfMatches = 0;
	
	for(i=0; i<strlen(original); i++){
		
		int patternmatched = 0; // to be used as a boolean value (0 = false, 1 = true)

		if(original[i] == pattern[0]){
		/*
			(for each char in original) 
			if character matches 1st char of pattern
			program checks the next chars for matching
		*/ 
			int count = 0;			
			for(j=i; j<strlen(pattern); j++){
				if(j < strlen(original)){
					if(original[j] == pattern[count]){
						patternmatched = 1;
					}
					else{
						patternmatched = 0;
						break;
					}
					count++;
				}
			}
		}
		
		if(patternmatched){
			numOfMatches = numOfMatches + 1;
		}
	}
	
	return numOfMatches;
}
// End of FUNCTION 2 //////////////////////////////////////


// FUNCTION 3 ////////////////////////////////////////////
int isValidString(char str[], char alphabet[]){
	int i, j;
	
	int matches_found = 0;
	
	for(i=0; i<strlen(str);i++){
		/*
			for each character in string, checks if char matches
			one char in alphabet
		*/

		for(j=0; j<strlen(alphabet); j++){

			if(str[i] == alphabet[j]){
				matches_found = matches_found + 1;
				break;
			}
		}
	}

	// if str matches alphabet, matches_found should be equal to strlen(str)
	if(matches_found < strlen(str)){
		return 0;	
	}else{
		return 1;
	}
}
// End of FUNCTION 3 //////////////////////////////////////


// FUNCTION 4 ////////////////////////////////////////////
int getSkew(char str[], int n){
	
	int count = 0;
	int i;
	
	for(i=1; i<=n; i++){
		if(str[i-1] == 'G'){
			count = count + 1;
		}
		if(str[i-1] == 'C'){
			count = count - 1;
		}
		// if char is neither 'G' or 'C' program does nothing
	}	
	
	return count;
}
// End of FUNCTION 4 //////////////////////////////////////


// FUNCTION 5 ////////////////////////////////////////////
int getMaxSkewN(char str[], int n){
	int count = 0;
	int i;
	int maxvalue = -30; // value -30 will be replaced by count eventually
	
	for(i=1; i<=n; i++){
		if(str[i-1] == 'G'){
			count = count + 1;
		}
		if(str[i-1] == 'C'){
			count = count - 1;
		}
				
		// checks if the produced count is maximum value
		if(count > maxvalue){
			maxvalue = count;
		}
	}	
	
	return maxvalue;
}
// End of FUNCTION 5 //////////////////////////////////////


// FUNCTION 6 ////////////////////////////////////////////
int getMinSkewN(char str[], int n){
	int count = 0;
	int i;
	int minvalue = 999; // value 999 will be replaced by count eventually
	
	for(i=1; i<=n; i++){
		if(str[i-1] == 'G'){
			count = count + 1;
		}
		if(str[i-1] == 'C'){
			count = count - 1;
		}
		
		// checks if the produced count is minimum value
		if(count < minvalue){
			minvalue = count;
		}
	}	
	
	return minvalue;
}
// End of FUNCTION 6 //////////////////////////////////////
