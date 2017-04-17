#include "BooleanCharacter.h"
#include <stdint.h>

BooleanCharacter::BooleanCharacter(unsigned char character) noexcept {
	for (uint8_t i = 0; i < 8; ++i)
	{
		bits[i] = character & 128;
		character <<= 1;
	}
}

unsigned char BooleanCharacter::asChar() const noexcept {
	unsigned char character = 0;
	for (uint8_t i = 0; i < 7; ++i)
	{
		character |= bits[i];
		character <<= 1;
	}
	character |= bits[7];
	return character;
}