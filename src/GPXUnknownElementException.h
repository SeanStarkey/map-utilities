#ifndef GPXUNKNOWNELEMENTEXCEPTION_H
#define GPXUNKNOWNELEMENTEXCEPTION_H

#include <exception>
#include <string>

class GPXUnknownElementException : public std::exception {
public:
    GPXUnknownElementException(const std::string message);
    virtual const char* what() const throw();
    virtual ~GPXUnknownElementException() throw();

private:
    std::string message;
};

#endif
