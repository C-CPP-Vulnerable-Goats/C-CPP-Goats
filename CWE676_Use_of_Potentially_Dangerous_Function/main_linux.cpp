/* NOTE - eventually this file will be automatically updated using a Perl script that understand
 * the naming of test case files, functions, and namespaces.
 */

#include <time.h>   /* for time() */
#include <stdlib.h> /* for srand() */

#include "std_testcase.h"
#include "testcases.h"

int main(int argc, char * argv[]) {

	/* seed randomness */

	srand( (unsigned)time(NULL) );

	globalArgc = argc;
	globalArgv = argv;

#ifndef OMITGOOD

	/* Calling C good functions */
	/* BEGIN-AUTOGENERATED-C-GOOD-FUNCTION-CALLS */

	/* END-AUTOGENERATED-C-GOOD-FUNCTION-CALLS */





#ifdef __cplusplus
	/* Calling C++ good functions */
	/* BEGIN-AUTOGENERATED-CPP-GOOD-FUNCTION-CALLS */
	printLine("Calling CWE676_Use_of_Potentially_Dangerous_Function__basic_04::good();");
	CWE676_Use_of_Potentially_Dangerous_Function__basic_04::good();

	printLine("Calling CWE676_Use_of_Potentially_Dangerous_Function__basic_13::good();");
	CWE676_Use_of_Potentially_Dangerous_Function__basic_13::good();

	printLine("Calling CWE676_Use_of_Potentially_Dangerous_Function__basic_02::good();");
	CWE676_Use_of_Potentially_Dangerous_Function__basic_02::good();

	printLine("Calling CWE676_Use_of_Potentially_Dangerous_Function__basic_15::good();");
	CWE676_Use_of_Potentially_Dangerous_Function__basic_15::good();

	printLine("Calling CWE676_Use_of_Potentially_Dangerous_Function__basic_06::good();");
	CWE676_Use_of_Potentially_Dangerous_Function__basic_06::good();

	printLine("Calling CWE676_Use_of_Potentially_Dangerous_Function__basic_16::good();");
	CWE676_Use_of_Potentially_Dangerous_Function__basic_16::good();

	printLine("Calling CWE676_Use_of_Potentially_Dangerous_Function__basic_12::good();");
	CWE676_Use_of_Potentially_Dangerous_Function__basic_12::good();

	printLine("Calling CWE676_Use_of_Potentially_Dangerous_Function__basic_09::good();");
	CWE676_Use_of_Potentially_Dangerous_Function__basic_09::good();

	printLine("Calling CWE676_Use_of_Potentially_Dangerous_Function__basic_08::good();");
	CWE676_Use_of_Potentially_Dangerous_Function__basic_08::good();

	printLine("Calling CWE676_Use_of_Potentially_Dangerous_Function__basic_14::good();");
	CWE676_Use_of_Potentially_Dangerous_Function__basic_14::good();

	printLine("Calling CWE676_Use_of_Potentially_Dangerous_Function__basic_17::good();");
	CWE676_Use_of_Potentially_Dangerous_Function__basic_17::good();

	printLine("Calling CWE676_Use_of_Potentially_Dangerous_Function__basic_01::good();");
	CWE676_Use_of_Potentially_Dangerous_Function__basic_01::good();

	printLine("Calling CWE676_Use_of_Potentially_Dangerous_Function__basic_11::good();");
	CWE676_Use_of_Potentially_Dangerous_Function__basic_11::good();

	printLine("Calling CWE676_Use_of_Potentially_Dangerous_Function__basic_10::good();");
	CWE676_Use_of_Potentially_Dangerous_Function__basic_10::good();

	printLine("Calling CWE676_Use_of_Potentially_Dangerous_Function__basic_18::good();");
	CWE676_Use_of_Potentially_Dangerous_Function__basic_18::good();

	printLine("Calling CWE676_Use_of_Potentially_Dangerous_Function__basic_03::good();");
	CWE676_Use_of_Potentially_Dangerous_Function__basic_03::good();

	printLine("Calling CWE676_Use_of_Potentially_Dangerous_Function__basic_07::good();");
	CWE676_Use_of_Potentially_Dangerous_Function__basic_07::good();

	printLine("Calling CWE676_Use_of_Potentially_Dangerous_Function__basic_05::good();");
	CWE676_Use_of_Potentially_Dangerous_Function__basic_05::good();

	/* END-AUTOGENERATED-CPP-GOOD-FUNCTION-CALLS */

#endif /* __cplusplus */

#endif /* OMITGOOD */

#ifndef OMITBAD

	/* Calling C bad functions */
	/* BEGIN-AUTOGENERATED-C-BAD-FUNCTION-CALLS */

	/* END-AUTOGENERATED-C-BAD-FUNCTION-CALLS */




	
#ifdef __cplusplus
	/* Calling C++ bad functions */
	/* BEGIN-AUTOGENERATED-CPP-BAD-FUNCTION-CALLS */
	printLine("Calling CWE676_Use_of_Potentially_Dangerous_Function__basic_04::bad();");
	CWE676_Use_of_Potentially_Dangerous_Function__basic_04::bad();

	printLine("Calling CWE676_Use_of_Potentially_Dangerous_Function__basic_13::bad();");
	CWE676_Use_of_Potentially_Dangerous_Function__basic_13::bad();

	printLine("Calling CWE676_Use_of_Potentially_Dangerous_Function__basic_02::bad();");
	CWE676_Use_of_Potentially_Dangerous_Function__basic_02::bad();

	printLine("Calling CWE676_Use_of_Potentially_Dangerous_Function__basic_15::bad();");
	CWE676_Use_of_Potentially_Dangerous_Function__basic_15::bad();

	printLine("Calling CWE676_Use_of_Potentially_Dangerous_Function__basic_06::bad();");
	CWE676_Use_of_Potentially_Dangerous_Function__basic_06::bad();

	printLine("Calling CWE676_Use_of_Potentially_Dangerous_Function__basic_16::bad();");
	CWE676_Use_of_Potentially_Dangerous_Function__basic_16::bad();

	printLine("Calling CWE676_Use_of_Potentially_Dangerous_Function__basic_12::bad();");
	CWE676_Use_of_Potentially_Dangerous_Function__basic_12::bad();

	printLine("Calling CWE676_Use_of_Potentially_Dangerous_Function__basic_09::bad();");
	CWE676_Use_of_Potentially_Dangerous_Function__basic_09::bad();

	printLine("Calling CWE676_Use_of_Potentially_Dangerous_Function__basic_08::bad();");
	CWE676_Use_of_Potentially_Dangerous_Function__basic_08::bad();

	printLine("Calling CWE676_Use_of_Potentially_Dangerous_Function__basic_14::bad();");
	CWE676_Use_of_Potentially_Dangerous_Function__basic_14::bad();

	printLine("Calling CWE676_Use_of_Potentially_Dangerous_Function__basic_17::bad();");
	CWE676_Use_of_Potentially_Dangerous_Function__basic_17::bad();

	printLine("Calling CWE676_Use_of_Potentially_Dangerous_Function__basic_01::bad();");
	CWE676_Use_of_Potentially_Dangerous_Function__basic_01::bad();

	printLine("Calling CWE676_Use_of_Potentially_Dangerous_Function__basic_11::bad();");
	CWE676_Use_of_Potentially_Dangerous_Function__basic_11::bad();

	printLine("Calling CWE676_Use_of_Potentially_Dangerous_Function__basic_10::bad();");
	CWE676_Use_of_Potentially_Dangerous_Function__basic_10::bad();

	printLine("Calling CWE676_Use_of_Potentially_Dangerous_Function__basic_18::bad();");
	CWE676_Use_of_Potentially_Dangerous_Function__basic_18::bad();

	printLine("Calling CWE676_Use_of_Potentially_Dangerous_Function__basic_03::bad();");
	CWE676_Use_of_Potentially_Dangerous_Function__basic_03::bad();

	printLine("Calling CWE676_Use_of_Potentially_Dangerous_Function__basic_07::bad();");
	CWE676_Use_of_Potentially_Dangerous_Function__basic_07::bad();

	printLine("Calling CWE676_Use_of_Potentially_Dangerous_Function__basic_05::bad();");
	CWE676_Use_of_Potentially_Dangerous_Function__basic_05::bad();

	/* END-AUTOGENERATED-CPP-BAD-FUNCTION-CALLS */
	
#endif /* __cplusplus */

#endif /* OMITBAD */

	return 0;

} 
