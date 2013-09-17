
#ifndef KMLTEST_H
#define KMLTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>
#include "KMLUnknownElementException.h"

class KMLTest : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(KMLTest);
    CPPUNIT_TEST(testParseGarminActivity);
    CPPUNIT_TEST_EXCEPTION(testParseGoogleKMLSample, KMLUnknownElementException);
    CPPUNIT_TEST_SUITE_END();

public:
    void testParseGarminActivity();
    void testParseGoogleKMLSample();
};

#endif
