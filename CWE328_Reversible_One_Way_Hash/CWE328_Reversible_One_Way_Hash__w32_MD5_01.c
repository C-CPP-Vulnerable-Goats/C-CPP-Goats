/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE328_Reversible_One_Way_Hash__w32_MD5_01.c
Label Definition File: CWE328_Reversible_One_Way_Hash__w32.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 328 Reversible One Way Hash
 * Sinks: MD5
 *    GoodSink: Use SHA-512 as a hashing algorithm
 *    BadSink : Use MD5 as a hashing algorithm
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <wincrypt.h>
#pragma comment(lib, "advapi32.lib")

#define PASSWORD_INPUT_SIZE 128
#define SHA512_SUM_SIZE (512 / 8)

#define MD5_SUM_SIZE (128 / 8)

#ifndef OMITBAD

void CWE328_Reversible_One_Way_Hash__w32_MD5_01_bad()
{
    {
        HCRYPTPROV hCryptProv;
        HCRYPTHASH hHash;
        FILE *pFile = NULL;
        char password[PASSWORD_INPUT_SIZE];
        UCHAR savedHash[MD5_SUM_SIZE], calcHash[MD5_SUM_SIZE];
        DWORD hashSize;
        char *replace;
        size_t i;
        pFile = fopen("password.txt", "r");
        if (pFile == NULL)
        {
            exit(1);
        }
        for (i = 0; i < MD5_SUM_SIZE; i++)
        {
            ULONG val;
            if (fscanf(pFile, "%02x", &val) != 1)
            {
                fclose(pFile);
                exit(1);
            }
            if (val > 0xff) /* EXPECTED INCIDENTAL: Reliance on data memory layout, we assume char is at least 8 bits */
            {
                fclose(pFile);
                exit(1);
            }
            savedHash[i] = (UCHAR)val;
        }
        if (pFile)
        {
            fclose(pFile);
        }
        if (fgets(password, PASSWORD_INPUT_SIZE, stdin) == NULL)
        {
            exit(1);
        }
        replace = strchr(password, '\r');
        if (replace)
        {
            *replace = '\0';
        }
        replace = strchr(password, '\n');
        if (replace)
        {
            *replace = '\0';
        }
        if (!CryptAcquireContextW(&hCryptProv, 0, 0, PROV_RSA_FULL, 0))
        {
            exit(1);
        }
        /* FLAW: Use a reversible hash (MD5) */
        if (!CryptCreateHash(hCryptProv, CALG_MD5, 0, 0, &hHash))
        {
            CryptReleaseContext(hCryptProv, 0);
            exit(1);
        }
        /* EXPECTED INCIDENTAL: We did not salt the password, that may raise flags,
         * the password hash was not securely transmitted (via one form or another),
         * that may raise flags
         */
        if (!CryptHashData(hHash, (BYTE*)password, strlen(password), 0))
        {
            CryptDestroyHash(hHash);
            CryptReleaseContext(hCryptProv, 0);
            exit(1);
        }
        hashSize = MD5_SUM_SIZE;
        if (!CryptGetHashParam(hHash, HP_HASHVAL, (BYTE*)calcHash, &hashSize, 0))
        {
            CryptDestroyHash(hHash);
            CryptReleaseContext(hCryptProv, 0);
            exit(1);
        }
        if (memcmp(savedHash, calcHash, MD5_SUM_SIZE * sizeof(UCHAR)) == 0)
        {
            printLine("Access granted");
        }
        else
        {
            printLine("Access denied");
        }
        if (hHash)
        {
            CryptDestroyHash(hHash);
        }
        if (hCryptProv)
        {
            CryptReleaseContext(hCryptProv, 0);
        }
    }
}

#endif /* OMITBAD */
