
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/CompilerOutputter.h>

#include <iostream>

int main()
{
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    CppUnit::TextTestRunner runner;
    runner.addTest(registry.makeTest());
    bool wasSucessful = runner.run("", false);
    return wasSucessful ? 0 : 1;
}
