
#include <cppunit/TestAssert.h>

#include "GPXTest.h"
#include "GPX.h"

CPPUNIT_TEST_SUITE_REGISTRATION(GPXTest);

void GPXTest::testParseGarminActivity() {
    std::ifstream f("test/activity_376645834.gpx");

    GPX gpx = GPX(f);
}
