#include <iostream>
#include "Coord.h"
#include "Distance.h"

#include <CUnit/Basic.h>


void test_Distance()
{
    Coord c1;
    Coord c2;

    c1.latitudeDegrees = 38;
    c1.latitudeMinutes = 50;
    c1.latitudeSeconds = 0;
    c1.northHemisphere = true;
    c1.longitudeDegrees = 104;
    c1.longitudeMinutes = 49;
    c1.longitudeSeconds = 0;
    c1.eastHemisphere = false;

    c2.latitudeDegrees = 39;
    c2.latitudeMinutes = 45;
    c2.latitudeSeconds = 0;
    c2.northHemisphere = true;
    c2.longitudeDegrees = 104;
    c2.longitudeMinutes = 59;
    c2.longitudeSeconds = 0;
    c2.eastHemisphere = false;

    double dist = distance(c1, c2);

    CU_ASSERT_DOUBLE_EQUAL(dist, 102.9, 0.1);
}


int distanceSuiteInit(void)
{
    return 0;
}

int distanceSuiteCleanup(void)
{
    return 0;
}

int setupDistanceSuite()
{
   CU_pSuite distanceSuite;

   distanceSuite = CU_add_suite("Distance Suite", distanceSuiteInit, NULL);
   if (NULL == distanceSuite) {
      return -1;
   }

   if ((NULL == CU_add_test(distanceSuite, "test of distance", test_Distance)))
   {
      return -1;
   }

   return 0;
}

int main()
{
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   if (setupDistanceSuite() != 0)
   {
       CU_cleanup_registry();
       return CU_get_error();
   }

   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}

