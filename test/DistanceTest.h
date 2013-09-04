
#ifndef DISTANCETEST_H
#define DISTANCETEST_H

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>

class DistanceTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(DistanceTest);
    CPPUNIT_TEST(testDistance);
    CPPUNIT_TEST_SUITE_END();

public:
    void testDistance();
};

#endif
