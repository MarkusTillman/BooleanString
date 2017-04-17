#pragma once
#include <string>

class BooleanCharacter;

class BooleanString
{
private:
	BooleanCharacter* booleanString;
	unsigned int length;

private:
	void copyString(const char* string);

public:
	BooleanString()	noexcept;
	~BooleanString() noexcept;
	BooleanString(const char* string);
	BooleanString(const std::string& string);
	BooleanString(const BooleanString& copy) noexcept;
	BooleanString& operator=(BooleanString rhs) noexcept;
	BooleanString(BooleanString&& move) noexcept;

	std::string asCppString() const;

	friend std::iostream& operator<<(std::iostream& stream, const BooleanString& booleanString);
	friend void swap(BooleanString& first, BooleanString& second) noexcept;
};