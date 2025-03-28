/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__long_33.cpp
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sinks-33.tmpl.cpp
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    GoodSink: Check for NULL before attempting to print data
 *    BadSink : Print data
 * Flow Variant: 33 Data flow: use of a C++ reference to data within the same function
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE476_NULL_Pointer_Dereference__long_33
{

#ifndef OMITBAD

void bad()
{
    long * data = new long;
    long * &dataRef = data;
    /* POTENTIAL FLAW: Set data to NULL */
    delete data;
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    printLongLine(*data);
}

void good()
{
    long * data = new long;
    long * &dataRef = data;
    /* POTENTIAL FLAW: Set data to NULL */
    delete data;
    /* FIX: allocate new memory */
    data = new long;
    printLongLine(*data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    long * data;
    long tmpData = 5L;
    long * &dataRef = data;
    /* FIX: Initialize data */
    {
        data = &tmpData;
    }
    {
        long * data = dataRef;
        /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
        printLongLine(*data);
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    long * data;
    long * &dataRef = data;
    /* POTENTIAL FLAW: Set data to NULL */
    data = NULL;
    {
        long * data = dataRef;
        /* FIX: Check for NULL before attempting to print data */
        if (data != NULL)
        {
            printLongLine(*data);
        }
        else
        {
            printLine("data is NULL");
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

using namespace CWE476_NULL_Pointer_Dereference__long_33; /* so that we can use good and bad easily */

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
