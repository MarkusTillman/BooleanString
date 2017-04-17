
#define YES true
#define NOW YES
#define NO NOW

#include <iostream>
#include <cstdlib>
#include <cassert>

#include "BooleanString.h"
#include "BooleanCharacter.h"
#include "vld.h"


void testThatAllCharactersAreConvertedCorrectly() {
	BooleanCharacter booleanCharacter;
	
	for (uint16_t character = 0; character <= 255; ++character)
	{
		booleanCharacter = (char) character;
		assert(booleanCharacter.asChar() == character);
		//std::cout << booleanCharacter.asChar() << " -> " << (char)character << std::endl;
	}
}


int main(int argc, char** argv)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

#if NO
	testThatAllCharactersAreConvertedCorrectly();
#endif

	BooleanString defaultConstructed = BooleanString();
	std::string string = "test string";
	BooleanString cStringConstructed = BooleanString(string.c_str());
	BooleanString cppStringConstructed = BooleanString(string);
	BooleanString copyConstructed = BooleanString(cppStringConstructed);
	BooleanString assigned;
	assigned = copyConstructed;
	BooleanString moveConstructed = BooleanString(BooleanString(string));

	std::cout << "'" << defaultConstructed.asCppString() << "'" << std::endl;
	std::cout << "'" << cStringConstructed.asCppString() << "'" << std::endl;
	std::cout << "'" << cppStringConstructed.asCppString() << "'" << std::endl;
	std::cout << "'" << copyConstructed.asCppString() << "'" << std::endl;
	std::cout << "'" << assigned.asCppString() << "'" << std::endl;
	std::cout << "'" << moveConstructed.asCppString() << "'" << std::endl;

	system("PAUSE");
	return 0;
}