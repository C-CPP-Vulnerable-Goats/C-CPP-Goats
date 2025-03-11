/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__wchar_t_environment_ofstream_83_bad.cpp
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-83_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * BadSource: environment Read input from an environment variable
 * GoodSource: Full path and file name
 * Sinks: ofstream
 *    BadSink : Open the file named in data using ofstream::open()
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITBAD

#include "std_testcase.h"
#include "CWE36_Absolute_Path_Traversal__wchar_t_environment_ofstream_83.h"

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
#define GETENV _wgetenv
#else
#define GETENV getenv
#endif

#include <fstream>
using namespace std;

namespace CWE36_Absolute_Path_Traversal__wchar_t_environment_ofstream_83
{
CWE36_Absolute_Path_Traversal__wchar_t_environment_ofstream_83_bad::CWE36_Absolute_Path_Traversal__wchar_t_environment_ofstream_83_bad(wchar_t * dataCopy)
{
    data = dataCopy;
    {
        /* Append input from an environment variable to data */
        size_t dataLen = wcslen(data);
        wchar_t * environment = GETENV(ENV_VARIABLE);
        /* If there is data in the environment variable */
        if (environment != NULL)
        {
            /* POTENTIAL FLAW: Read data from an environment variable */
            wcsncat(data+dataLen, environment, FILENAME_MAX-dataLen-1);
        }
    }
}

CWE36_Absolute_Path_Traversal__wchar_t_environment_ofstream_83_bad::~CWE36_Absolute_Path_Traversal__wchar_t_environment_ofstream_83_bad()
{
    {
        ofstream outputFile;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        outputFile.open((char *)data);
        outputFile.close();
    }
}
}
#endif /* OMITBAD */
