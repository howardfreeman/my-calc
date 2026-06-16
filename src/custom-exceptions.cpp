#include "custom-exceptions.hpp"

const char* OpenBracketException::what() const noexcept  {
    return "Expression contains redundant open bracket";
}

const char* CloseBracketException::what() const noexcept  {
    return "Expression contains redundant close bracket";
}