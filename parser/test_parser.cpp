#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

// #include "parser.h"
#include <iostream> 

class TestParser : CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE(TestParser);
	CPPUNIT_TEST(test_initialize);
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp();
		void tearDown();
	protected:
		// Check whether whole source code loading is completed.
		void test_initialize();
};


void TestParser::test_initialize()
{
	CPPUNIT_ASSERT( 1 == 1 );
	return ;
}

int main()
{

}
