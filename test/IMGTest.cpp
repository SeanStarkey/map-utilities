
#include <cppunit/TestAssert.h>

#include "IMGTest.h"
#include "IMG.h"

CPPUNIT_TEST_SUITE_REGISTRATION(IMGTest);

void IMGTest::testPikesPeakNFS() {
    std::ifstream f("test/stelprdb5350805.img", std::ifstream::binary);

    IMG img = IMG(f);
}

void IMGTest::testColo24k() {
    std::ifstream f("test/Colorado 24K Topos.img", std::ifstream::binary);

    IMG img = IMG(f);
}
