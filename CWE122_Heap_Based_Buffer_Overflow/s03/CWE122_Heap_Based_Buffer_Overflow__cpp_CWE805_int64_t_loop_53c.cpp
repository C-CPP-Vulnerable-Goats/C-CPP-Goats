/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int64_t_loop_53c.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805.label.xml
Template File: sources-sink-53c.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using new[] and set data pointer to a small buffer
 * GoodSource: Allocate using new[] and set data pointer to a large buffer
 * Sink: loop
 *    BadSink : Copy int64_t array to data using a loop
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int64_t_loop_53
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void badSink_d(int64_t * data);

void badSink_c(int64_t * data)
{
    badSink_d(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink_d(int64_t * data);

void goodG2BSink_c(int64_t * data)
{
    goodG2BSink_d(data);
}

#endif /* OMITGOOD */

} /* close namespace */
