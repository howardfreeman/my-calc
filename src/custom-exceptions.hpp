#include<exception>

class OpenBracketException : public std::exception {
public:
    const char* what() const noexcept override;
};

class CloseBracketException : public std::exception {
public:
    const char* what() const noexcept override;
};

