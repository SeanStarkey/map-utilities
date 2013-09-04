
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/CompilerOutputter.h>

#include <iostream>
#include "DistanceTest.h"
#include "LocationTest.h"

int main()
{
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    CppUnit::TextTestRunner runner;
    runner.addTest(registry.makeTest());
    bool wasSucessful = runner.run("", true);
    return wasSucessful ? 0 : 1;
}
