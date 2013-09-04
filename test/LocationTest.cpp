
#include <cppunit/TestAssert.h>

#include "LocationTest.h"

#include "LocationDeg.h"

CPPUNIT_TEST_SUITE_REGISTRATION(LocationTest);

void LocationTest::testLocation()
{
    LocationDeg l1(100.0, 100.0);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(100.0, l1.getLatitude(), 0.000001);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(100.0, l1.getLongitude(), 0.000001);
}
