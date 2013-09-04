
#ifndef LOCATIONTEST_H
#define LOCATIONTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>

class LocationTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(LocationTest);
    CPPUNIT_TEST(testLocation);
    CPPUNIT_TEST_SUITE_END();

public:
    void testLocation();
};

#endif
