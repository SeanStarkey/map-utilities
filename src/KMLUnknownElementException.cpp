
#include "KMLUnknownElementException.h"

KMLUnknownElementException::KMLUnknownElementException(const std::string message_in) : message(message_in) {
}

KMLUnknownElementException::~KMLUnknownElementException() throw() {
}

const char* KMLUnknownElementException::what() const throw() {
    std::string ret = std::string("Unknown Element: ") + message;
    return ret.c_str();
}
