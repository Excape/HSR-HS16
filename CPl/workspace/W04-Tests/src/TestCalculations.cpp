#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "calculations.h"
#include "counting.h"
#include "sum.h"
#include "table.h"

#include <sstream>

void testZeroDigit() {
	std::ostringstream out{};
	printLargeDigit(0, out);
	std::string expected = " - \n"
						   "| |\n"
						   "   \n"
			    		   "| |\n"
						   " - \n";
	ASSERT_EQUAL(expected, out.str());
}

void testOneDigit() {
	std::ostringstream out{};
	printLargeDigit(1, out);
	std::string expected = "   \n"
						   "  |\n"
						   "   \n"
			    		   "  |\n"
						   "   \n";
	ASSERT_EQUAL(expected, out.str());
}

void testTwoDigit() {
	std::ostringstream out{};
	printLargeDigit(2, out);
	std::string expected = " - \n"
						   "  |\n"
						   " - \n"
			    		   "|  \n"
						   " - \n";
	ASSERT_EQUAL(expected, out.str());
}


void testThreeDigit() {
	std::ostringstream out{};
	printLargeDigit(3, out);
	std::string expected = " - \n"
						   "  |\n"
						   " - \n"
			    		   "  |\n"
						   " - \n";
	ASSERT_EQUAL(expected, out.str());
}

void testFourDigit() {
	std::ostringstream out{};
	printLargeDigit(4, out);
	std::string expected = "   \n"
						   "| |\n"
						   " - \n"
			    		   "  |\n"
						   "   \n";
	ASSERT_EQUAL(expected, out.str());
}

void testFiveDigit() {
	std::ostringstream out{};
	printLargeDigit(5, out);
	std::string expected = " - \n"
						   "|  \n"
						   " - \n"
			    		   "  |\n"
						   " - \n";
	ASSERT_EQUAL(expected, out.str());
}

void testSixDigit() {
	std::ostringstream out{};
	printLargeDigit(6, out);
	std::string expected = " - \n"
						   "|  \n"
						   " - \n"
			    		   "| |\n"
						   " - \n";
	ASSERT_EQUAL(expected, out.str());
}

void testSevenDigit() {
	std::ostringstream out{};
	printLargeDigit(7, out);
	std::string expected = " - \n"
						   "  |\n"
						   "   \n"
			    		   "  |\n"
						   "   \n";
	ASSERT_EQUAL(expected, out.str());
}

void testEightDigit() {
	std::ostringstream out{};
	printLargeDigit(8, out);
	std::string expected = " - \n"
						   "| |\n"
						   " - \n"
			    		   "| |\n"
						   " - \n";
	ASSERT_EQUAL(expected, out.str());
}

void testNineDigit() {
	std::ostringstream out{};
	printLargeDigit(9, out);
	std::string expected = " - \n"
						   "| |\n"
						   " - \n"
			    		   "  |\n"
						   " - \n";
	ASSERT_EQUAL(expected, out.str());
}

void tes134Number() {
	std::ostringstream out{};
	printLargeNumber(1234, out);
	std::string expected = "    -  -    \n"
						   "  |  |  || |\n"
						   "    -  -  - \n"
					 	   "  ||    |  |\n"
						   "    -  -    \n";
	ASSERT_EQUAL(expected, out.str());
}

void test42Number() {
	std::ostringstream out{};
	printLargeNumber(42, out);
	std::string expected = "    - \n"
						   "| |  |\n"
						   " -  - \n"
					 	   "  ||  \n"
						   "    - \n";
	ASSERT_EQUAL(expected, out.str());
}

void testScaled42Number() {
	std::ostringstream out{};
	printLargeNumber(42, out, 3);
	std::string expected = "    - \n"
						   "| |  |\n"
						   "| |  |\n"
						   "| |  |\n"
						   " -  - \n"
					 	   "  ||  \n"
						   "  ||  \n"
						   "  ||  \n"
						   "    - \n";
	ASSERT_EQUAL(expected, out.str());
}

// Tests for A2

void testCountNonWhiteSpace() {
	std::istringstream in {"The world is beautiful"};
	ASSERT_EQUAL(19, chcount(in));
}

void testCountAllCharacters() {
	std::istringstream in {"The world is beautiful"};
	ASSERT_EQUAL(22, chacount(in));
}

void testCountWords() {
	std::istringstream in {"The world is beautiful"};
	ASSERT_EQUAL(4, wcount(in));
}

void testACount() {
	std::istringstream in {"all apes are awesome!"};
	ASSERT_EQUAL(4, acount(in));
}
void testLineCount() {
	std::istringstream in {"all apes\n are \n\n\n awesome!\n"};
	ASSERT_EQUAL(5, lcount(in));
}

// Self study
void testSumi() {
	std::istringstream in {"1 22 9412"};
	ASSERT_EQUAL(9435, sumi(in));
}

void testSumd() {
	std::istringstream in {"1.12 22.73 9412.1122"};
	ASSERT_EQUAL_DELTA(9435.9622, sumd(in), 0.0005);
}

void testTable() {
	std::ostringstream os {};
	multab(os);
	ASSERT_EQUAL("NEVER", os.str());
}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };

	s.push_back(CUTE(testZeroDigit));
	s.push_back(CUTE(testOneDigit));
	s.push_back(CUTE(testTwoDigit));
	s.push_back(CUTE(testThreeDigit));
	s.push_back(CUTE(testFourDigit));
	s.push_back(CUTE(testFiveDigit));
	s.push_back(CUTE(testSixDigit));
	s.push_back(CUTE(testSevenDigit));
	s.push_back(CUTE(testNineDigit));
	s.push_back(CUTE(testEightDigit));
	s.push_back(CUTE(tes134Number));
	s.push_back(CUTE(test42Number));
	s.push_back(CUTE(testCountNonWhiteSpace));
	s.push_back(CUTE(testCountAllCharacters));
	s.push_back(CUTE(testCountWords));
	s.push_back(CUTE(testACount));
	s.push_back(CUTE(testLineCount));
	s.push_back(CUTE(testScaled42Number));
	s.push_back(CUTE(testSumi));
	s.push_back(CUTE(testSumd));
	s.push_back(CUTE(testTable));

	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner { cute::makeRunner(lis, argc, argv) };
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}