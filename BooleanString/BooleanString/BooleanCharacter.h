#pragma once

class BooleanCharacter
{
private:
	bool bits[8] = { 0 };

public:
	BooleanCharacter() = default;
	BooleanCharacter(unsigned char character) noexcept;

	unsigned char asChar() const noexcept;
};