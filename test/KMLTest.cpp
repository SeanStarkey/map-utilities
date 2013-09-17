
#include <cppunit/TestAssert.h>

#include <fstream>
#include "KMLTest.h"
#include "KML.h"

CPPUNIT_TEST_SUITE_REGISTRATION(KMLTest);

void KMLTest::testParseGarminActivity() {
    std::ifstream f("test/activity_366057463.kml");

    KML kml = KML(f);
}

void KMLTest::testParseGoogleKMLSample() {
    std::ifstream f("test/KML_Samples.kml");

    KML kml = KML(f);
}
