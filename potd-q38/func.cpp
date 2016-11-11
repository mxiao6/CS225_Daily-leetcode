#include "func.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

//prints the secret key to stdout, and returns the secret key as a string
//The secret key can be whatever you want with the restriction that it must 
//only be made up of upper and lowercase letters
string secretKey(){
	string nameArray[10] = { "budz", "pain", "konan", "nagato", 
								"itachi", "tobi", "madara", "naruto", 
								"danzou", "kakashi" };
	/* initialize random seed: */
  	srand (time(NULL));

  	/* generate secret number between 0 and 9: */
	int rand1 = rand() % 10;
	int rand2 = rand() % 10;

	string retVal = nameArray[rand1] + nameArray[rand2];

	cout << "The secret key is " << retVal << endl;

	return retVal;
}

//rot12 encryption
void encrypt(string str){
	char * list = new char[str.length()];

	for (size_t i = 0; i < str.length(); i++) 
		list[i] = char((int(str[i]) - 97 + 12) % 26 + 97);
	
	cout << "The encryption of the secret key is " << string(list) << endl;
}
