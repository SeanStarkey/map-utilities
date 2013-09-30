
#ifndef GPXTEST_H
#define GPXTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>
#include "GPXUnknownElementException.h"

class GPXTest : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(GPXTest);
    CPPUNIT_TEST(testParseGarminActivity);
    CPPUNIT_TEST_SUITE_END();

public:
    void testParseGarminActivity();
};

#endif
