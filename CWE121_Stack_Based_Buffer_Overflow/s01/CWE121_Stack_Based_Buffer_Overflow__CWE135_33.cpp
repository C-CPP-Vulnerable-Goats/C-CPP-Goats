/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE135_33.cpp
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE135.label.xml
Template File: sources-sinks-33.tmpl.cpp
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Void pointer to a wchar_t array
 * GoodSource: Void pointer to a char array
 * Sinks:
 *    GoodSink: Allocate memory using wcslen() and copy data
 *    BadSink : Allocate memory using strlen() and copy data
 * Flow Variant: 33 Data flow: use of a C++ reference to data within the same function
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define WIDE_STRING L"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
#define CHAR_STRING "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"

namespace CWE121_Stack_Based_Buffer_Overflow__CWE135_33
{

#ifndef OMITBAD

void bad() {
    char userInput[50];
    char buffer[100] = "User: ";

    printf("Enter your name: ");
    scanf("%49s", &userInput);  // 🚨 Unsafe: No bounds checking beyond 49 chars

    lstrcat(buffer, userInput);  // 🚨 Potential buffer overflow risk!
    std::cout << "Final string: " << buffer << std::endl;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    void * data;
    void * &dataRef = data;
    data = NULL;
    /* FIX: Set data to point to a char string */
    data = (void *)CHAR_STRING;
    {
        void * data = dataRef;
        {
            /* POTENTIAL FLAW: treating pointer as a char* when it may point to a wide string */
            size_t dataLen = strlen((char *)data);
            void * dest = (void *)ALLOCA((dataLen+1) * 1);
            (void)strcpy((char *)dest, (char *)data);
            printLine((char *)dest);
        }
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    void * data;
    void * &dataRef = data;
    data = NULL;
    /* POTENTIAL FLAW: Set data to point to a wide string */
    data = (void *)WIDE_STRING;
    {
        void * data = dataRef;
        {
            /* FIX: treating pointer like a wchar_t*  */
            size_t dataLen = wcslen((wchar_t *)data);
            void * dest = (void *)ALLOCA((dataLen+1) * sizeof(wchar_t));
            (void)wcscpy((wchar_t *)dest, (wchar_t *)data);
            printWLine((wchar_t *)dest);
        }
    }
}

void good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */
#ifdef INCLUDEMAIN

using namespace CWE121_Stack_Based_Buffer_Overflow__CWE135_33; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
