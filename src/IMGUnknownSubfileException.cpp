
#include "IMGUnknownSubfileException.h"

IMGUnknownSubfileException::IMGUnknownSubfileException(const std::string message_in) : message(message_in) {
}

IMGUnknownSubfileException::~IMGUnknownSubfileException() throw() {
}

const char* IMGUnknownSubfileException::what() const throw() {
    std::string ret = std::string("Unknown subfile: ") + message;
    return ret.c_str();
}
