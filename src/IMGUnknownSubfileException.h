#ifndef IMGUNKNOWNSUBFILEEXCEPTION_H
#define IMGUNKNOWNSUBFILEEXCEPTION_H

#include <exception>
#include <string>

class IMGUnknownSubfileException : public std::exception {
public:
    IMGUnknownSubfileException(const std::string message);
    virtual const char* what() const throw();
    virtual ~IMGUnknownSubfileException() throw();

private:
    std::string message;
};

#endif
