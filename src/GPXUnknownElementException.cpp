
#include "GPXUnknownElementException.h"

GPXUnknownElementException::GPXUnknownElementException(const std::string message_in) : message(message_in) {
}

GPXUnknownElementException::~GPXUnknownElementException() throw() {
}

const char* GPXUnknownElementException::what() const throw() {
    std::string ret = std::string("Unknown Element: ") + message;
    return ret.c_str();
}
