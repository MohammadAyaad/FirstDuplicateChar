# FirstRepeatedChar
Certenly! this is one of the questions that has alot of answers.
However i liked to interoduce my answer to the compitiion.

my code focuses on effeciency rather than simplicity, However it is pretty simple if understood correctly!

The question is "If you were givin a string of English lower-case letters , find the First Repeated Character in that string"

and my answer to this question is the following code : 
```C
char getFirstRepeatedChar(char str[]) 
{
	const int ENGLISH_CHARACTERS_COUNT = 26;
	bool english_characters_tracker[ENGLISH_CHARACTERS_COUNT];

	for (int i = 0; i < ENGLISH_CHARACTERS_COUNT; i++) english_characters_tracker[i] = false;

	int index = 0;
	
	while (str[index] != NULL)
	{
		int character_index = str[index] - 'a'; 
		if (english_characters_tracker[character_index] == true)
		{
			return str[index];
		}
		else {
			english_characters_tracker[character_index] = true;
		}

		index++;
	}
}
```

now to a fresh eye in programming , this looks like a mess , what is going on ? and how does this work ? 

Iam going to explain this code line by line so hopefully you come out with better understanding of how it works and maybe give you more ideas to how should you solve your algorithems in a better and more effecient way.

first lets start with the easiest, *function signature*
```char getFirstRepeatedChar(char str[])```
the function returns a character (```char```) which is supposedly the first repeated character in the string
the function name is ```getFirstRepeatedChar``` which is a unique identifier for this function,
and it takes a single parameter with type of "character array" and is identified with the name ```str```

```{```
i don't think this needs much explaination , its the begining of the function's *code block* aka *the body of the function*

```const int ENGLISH_CHARACTERS_COUNT = 26;```
just declaring a constant of type ```int``` and it holds the value ```26``` with the variable name being ```ENGLISH_CHARACTERS_COUNT``` all caps with underscores because its a *constant*

we can get rid of the constant and just replace all the appearences of it with the value it was decaled to (```26```) , however it is not the best practice as it makes the code less clear and sometimes less effecient specially in memory usage

```bool english_characters_tracker[ENGLISH_CHARACTERS_COUNT];``` 
here we are creating a variable which holds an array of "bool" which is an array of booleans and it has ```ENGLISH_CHARACTERS_COUNT``` elements or ```26``` elements

and before we continue lets understand the algorithm i'm trying to apply here.
##First lets understand the inputs!
we have a single array that holds a string or "an array of characters" but can they hold ANY characters ?
in our example we are expecting a specific number of characters which are any character in the english alphabet BUT lowercase and in the ASCII encoding



so if we look at the array in a low level , we are expecting an array of bytes (the size of ```char``` type in ```C``` is ```1```) and looking back at the ASCII table ![ASCII Table](https://static.wikia.nocookie.net/the-martian/images/3/30/ASCII_TABLE.JPG/revision/latest?cb=20170213161702)
each byte of our expected string can hold a value between ```[96 < x < 123]```

so knowing that , and also knowing that we have only 26 characters in the english alphabet which is not much , we can create an array with each element represents the amount of occurances of that character so our algorithm can expand beyond the single first repeated character too just with minor changes

anyways so now that we know what we could do , we can create our own algorithm 

there are million ways to solve the same problem but some of them can be really difficult , some of them are really ineffecient , and some of them are just both!

but the unique thing about our algorithm is that it is pretty simple and effecient

so going back to our code.

```for (int i = 0; i < ENGLISH_CHARACTERS_COUNT; i++) english_characters_tracker[i] = false;```

here we are initializing the array to be all "false"

why ? because "true" means we have seen that character before while "false" means we havn't and by default we didn't scan the target string yet so we do not know the weather we have seen any of the characters or not

next is to create a loop going through the string so that we can see which character has appeared twice

```int index = 0;```

here we are just declaring a variable to keep track of the index at our string which is just like a pointer "literally like your finger pointing at something" to the character we are looking at in our string

```while (str[index] != NULL)```
just creating a loop that goes on forever while the "character" we are looking at is not `NULL` which means the end of our char array

> **NOTE:** `NULL` is a constant defined with value `0`


```{```

doesn't need much explaination either , just the begining of the "while loop's body"

```int character_index = str[index] - 'a'; ```

here we are declaring a variable called ```character_index``` of type ```int``` and givin the value of ```str[index] - 'a'```

wait what ? 

how can that be ? subtracting characters ?

YES

as it turns out under the hood the C compiler deals with character the exact same as numbers except they are a special type of numbers that represent some special form of data called "char" which is basically delt with diffrently depending on the function's signature you are calling and not so much diffrent as "char + char" or "char - char" from a regular number and it has the size of a singular byte

so what we are actually doing is subtracting the code of `'a'` from that character in our string "for example `'a'` and we get the result being the same as calculating `97 - 97` which is `0`

so essentially we have created a mapping from our character to an index in our array! yay

also it doesn't mean that we can't give our function a character it doesn't expect like an upper case character which is going to give us a negative index OR  a character after the `z` like `{` which both are going to give us an "index out of range" , "segmentation fault" or an "exception" depending on what environment , code and language you are using this function in

but remember it is AN UNEXPECTED VALUE so we should never get these values as inputs in the first place and if it is possible it should be the job of another function calling our function to check for that 

for example :

```C
char callfunc(char a[])
{
    //check if it is a valid string
    return getFirstRepeatedChar(a);
}
```


now that we finally reached here , we can look at the most important peace of our code

```C
if (english_characters_tracker[character_index] == true)
{
	return str[index];
}
else {
	english_characters_tracker[character_index] = true;
}
```

first we are checking if 
```english_characters_tracker[character_index] == true```

which is basically asking if we have "encountered" this character before

if we did we return that character :
```return str[index];```

however if we didn't :
```else {...}```
we keep in mind "our array" that we did see it :
```english_characters_tracker[character_index] = true;```

and finally we ```index++;``` to make sure we are not stuck at the same character checking it over and over again forever 
>_its just going to return the first character in the second iteration thinking we have encountered it twice_

```}``` we end the body of the "while loop"

BUT WAIT
doesn't all paths of the code return a value ?

if we are garenteed that we are going to get a lower-case small caps character with at least one character repeating then YES we are garenteed to return a value

however if there wasn't any character repeating repeating then we can detect that simply with the code continueing execution AFTER the "while loop"

so basically after the end of the while loop's body and before the end of the function

```}``` then we end the body of the function


**and here we go :D**

i hope that was simple enough.
 
also let me know if there is a faster or more effient algorithm :D!

***Thanks for reading!*** - By Mohammad Ayaad

# My links : 

## [twitter.com/mohammad_ayaad](https://twitter.com/mohammad_ayaad 'Twitter')

## [github.com/MohammadAyaad](https://github.com/MohammadAyaad 'Github')

## [linkedin.com/in/mohammad-ayaad](https://www.linkedin.com/in/mohammad-ayaad/ 'Linked in')
