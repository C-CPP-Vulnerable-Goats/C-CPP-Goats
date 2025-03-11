/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_rand_multiply_82_goodG2B.cpp
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-82_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an overflow before multiplying data by 2
 *    BadSink : If data is positive, multiply by 2, which can cause an overflow
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */
#ifndef OMITGOOD

#include "std_testcase.h"
#include "CWE190_Integer_Overflow__char_rand_multiply_82.h"

namespace CWE190_Integer_Overflow__char_rand_multiply_82
{

void CWE190_Integer_Overflow__char_rand_multiply_82_goodG2B::action(char data)
{
    if(data > 0) /* ensure we won't have an underflow */
    {
        /* POTENTIAL FLAW: if (data*2) > CHAR_MAX, this will overflow */
        char result = data * 2;
        printHexCharLine(result);
    }
}

}
#endif /* OMITGOOD */
