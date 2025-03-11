/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__class_32.cpp
Label Definition File: CWE476_NULL_Pointer_Dereference__class.label.xml
Template File: sources-sinks-32.tmpl.cpp
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    GoodSink: Check data for NULL before attempting to print data->a
 *    BadSink : Print data->a
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

namespace CWE476_NULL_Pointer_Dereference__class_32
{

#ifndef OMITBAD

void bad()
{
    TwoIntsClass * data;
    TwoIntsClass * *dataPtr1 = &data;
    TwoIntsClass * *dataPtr2 = &data;
    {
        TwoIntsClass * data = *dataPtr1;
        /* POTENTIAL FLAW: Set data to NULL */
        data = NULL;
        *dataPtr1 = data;
    }
    {
        TwoIntsClass * data = *dataPtr2;
        /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
        printIntLine(data->intOne);
        /* avoid memory leak - deleting a NULL pointer is a no-op in C++ so no need to check for NULL */
        delete data;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    TwoIntsClass * data;
    TwoIntsClass * *dataPtr1 = &data;
    TwoIntsClass * *dataPtr2 = &data;
    {
        TwoIntsClass * data = *dataPtr1;
        {
            TwoIntsClass * tmpData = new TwoIntsClass;
            tmpData->intOne = 0;
            tmpData->intTwo = 0;
            /* FIX: Initialize data */
            data = tmpData;
        }
        *dataPtr1 = data;
    }
    {
        TwoIntsClass * data = *dataPtr2;
        /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
        printIntLine(data->intOne);
        /* avoid memory leak - deleting a NULL pointer is a no-op in C++ so no need to check for NULL */
        delete data;
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    TwoIntsClass * data;
    TwoIntsClass * *dataPtr1 = &data;
    TwoIntsClass * *dataPtr2 = &data;
    {
        TwoIntsClass * data = *dataPtr1;
        /* POTENTIAL FLAW: Set data to NULL */
        data = NULL;
        *dataPtr1 = data;
    }
    {
        TwoIntsClass * data = *dataPtr2;
        /* FIX: Check for NULL before attempting to print data */
        if (data != NULL)
        {
            printIntLine(data->intOne);
            delete data;
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

using namespace CWE476_NULL_Pointer_Dereference__class_32; /* so that we can use good and bad easily */

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
