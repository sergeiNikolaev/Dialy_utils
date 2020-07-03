/**
 * This file describes library API information
 */

/* include files */
#pragma once

/*
 *  definition for dynamic libraries interfaces
 */
#if defined(_WIN32) || defined(WIN32)
    #ifdef LIBRARY_INTERNAL_API
        #define LIB_API __declspec(dllexport)
    #else // LIBRARY_INTERNAL_API
        #define LIB_API __declspec(dllimport)
    #endif // LIBRARY_INTERNAL_API
#else
    #define LIB_API
#endif // WIN32
