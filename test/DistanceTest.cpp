
#include <cppunit/TestAssert.h>

#include "DistanceTest.h"

#include "LocationDegMinSec.h"
#include "Distance.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DistanceTest);

void DistanceTest::testDistance() {
    LocationDegMinSec c1(38, 50, 0, -104, 49, 0);
    LocationDegMinSec c2(39, 45, 0, -104, 59, 0);

    double dist = distance(&c1, &c2);

    CPPUNIT_ASSERT_DOUBLES_EQUAL(102.9, dist, 0.1);
}
