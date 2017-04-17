#define _SCL_SECURE_NO_WARNINGS

#include "BooleanString.h"

#include <iostream>
#include <cstring>

#include "BooleanCharacter.h"

void BooleanString::copyString(const char* string)
{
	this->length = strlen(string);
	this->booleanString = new BooleanCharacter[this->length];
	for (auto i = decltype(this->length){0}; i < this->length; ++i)
	{
		this->booleanString[i] = BooleanCharacter(string[i]);
	}
}

BooleanString::BooleanString() noexcept
{
	this->length = 0;
	this->booleanString = nullptr;
}

BooleanString::~BooleanString() noexcept
{
	delete[] this->booleanString; // Deleting nullptr is a no-op.
	this->booleanString = nullptr;
}

BooleanString::BooleanString(const char* string)
{
	copyString(string);
}

BooleanString::BooleanString(const std::string& string)
{
	copyString(string.c_str());
}

BooleanString::BooleanString(const BooleanString& copy) noexcept
	: length(copy.length),
	  booleanString(copy.length ? new BooleanCharacter[copy.length] : nullptr)
{
	std::copy(copy.booleanString, copy.booleanString + copy.length, booleanString);
}

BooleanString& BooleanString::operator=(BooleanString rightHandSide) noexcept
{
	swap(*this, rightHandSide);
	return *this;
}

BooleanString::BooleanString(BooleanString&& move) noexcept
	: BooleanString() // Initialize via default constructor to make swap valid.
{
	swap(*this, move);
}

std::iostream& operator<<(std::iostream& stream, const BooleanString& string)
{
	// stream >> string.asCppString() gives warning C4239.
	std::string cppString = string.asCppString();
	stream >> cppString;
	return stream;
}

void swap(BooleanString& first, BooleanString& second) noexcept
{
	using std::swap; // Enable argument-dependent lookup.
	swap(first.length, second.length);
	swap(first.booleanString, second.booleanString);
}

std::string BooleanString::asCppString() const
{
	std::string cppString;
	cppString.reserve(this->length);
	for (auto i = decltype(this->length){0}; i < this->length; ++i)
	{
		cppString += this->booleanString[i].asChar();
	}
	return cppString;
}
