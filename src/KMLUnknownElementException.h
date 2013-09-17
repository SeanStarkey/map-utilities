#ifndef KMLUNKNOWNELEMENTEXCEPTION_H
#define KMLUNKNOWNELEMENTEXCEPTION_H

#include <exception>
#include <string>

class KMLUnknownElementException : public std::exception {
public:
    KMLUnknownElementException(const std::string message);
    virtual const char* what() const throw();
    virtual ~KMLUnknownElementException() throw();

private:
    std::string message;
};

#endif
