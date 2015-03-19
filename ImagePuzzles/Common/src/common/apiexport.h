#ifndef LIBRARY_H
#define LIBRARY_H

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32)
    #define API_EXPORT __declspec(dllexport)
#else
    #define API_EXPORT
#endif

#endif // LIBRARY_H

