
#ifndef IMGTEST_H
#define IMGTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>

class IMGTest : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(IMGTest);
    CPPUNIT_TEST(testPikesPeakNFS);
    CPPUNIT_TEST(testColo24k);
    CPPUNIT_TEST_SUITE_END();

public:
    void testPikesPeakNFS();
    void testColo24k();
};

#endif
