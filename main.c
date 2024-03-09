//===============================================================================================================================================================================
//===============================================================================================================================================================================
//===============================================================================================================================================================================
//=======NOTE : LOTS OF COMMENTS ARE CONSIDERED A BAD PRACTICE "not clean code" SO ALWAYS AVOID THEM , LOTS OF THEM ARE HERE FOR EDUCATIONAL AND VIEWING PURPOSES PURPOSES=======
//===============================================================================================================================================================================
//=================================================================BY Mohammad Sameh Ayaad=======================================================================================
//===============================================================================================================================================================================



#include <stdio.h>

char getFirstDuplicateChar(char str[]) // a string of ASCII lower-case characters ONLY
{
	//declare the variables
	const int ENGLISH_CHARACTERS_COUNT = 26; //just for a cleaner code , nothing with performance , arguably slightly better memory usage (ignoring the compiler optimization)
	bool english_characters_tracker[ENGLISH_CHARACTERS_COUNT];

	//initializing the "english" array
	for (int i = 0; i < ENGLISH_CHARACTERS_COUNT; i++) english_characters_tracker[i] = false; //

	//declaration of an INT variable to track the index at the target string also ...
	//... we can get away with a single byte sense it doesn't take us more than 26 characters to encounter our first repeated one
	int index = 0;
	
	//a loop going through all characters of the string while the string has not ended yet
	while (str[index] != NULL)
	{
		int character_index = str[index] - 'a'; //just for a bit more cleaner code , nothing with performance , arguably slightly worse (ignoring the compiler optimization)

		if (english_characters_tracker[character_index] == true)
		{
			//we have encountered that character before so we return it
			return str[index];
		}
		else {
			//we have NOT encountered that character before so we say YES (yes we did encounter it)
			english_characters_tracker[character_index] = true;
		}

		index++;
	}

	//NOTE: code execution should be impossible to reach HERE if the input is guaranteed to have duplicate characters , ...
	//...S if not just return some "error" state where it means it found no duplicate characters (maybe NULL)
	//warning C4715: 'getFirstRepeatedChar': not all control paths return a value 
}

int main(int argc,char** argv)
{
	printf("RESULT: '%c'",getFirstDuplicateChar(argv[1])); //the first parameter after the "filename" is what we read as our input string
}
