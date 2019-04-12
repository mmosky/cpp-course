/* macOS (OS X) */
#ifdef __APPLE__
#define USE_UNISTD
#endif

/* OS 9 */
#ifdef macintosh
#define USE_UNISTD
#endif

/* linux kernel */
#ifdef __linux__
#define USE_UNISTD
#endif

/* Windows */
#ifdef _WIN32
#define USE_WINDOWS
#endif
#ifdef _WIN64
#define USE_WINDOWS
#endif

#ifdef USE_WINDOWS
#ifdef USE_UNISTD
#define IMPOSSIBLE_ERROR
#endif
#endif

#ifdef USE_UNISTD
#include <unistd.h>
#endif

#ifdef USE_WINDOWS
#include <Windows.h>
#endif

#include "MySleep.h"
#include <iostream>
using namespace std;

void MySleep::mSleep(unsigned int ms)
{
#ifdef IMPOSSIBLE_ERROR
    cout << "Impossible error: Your environment is both Unix-Like and Windows?" << endl;
#else

#ifdef USE_UNISTD
    usleep(ms * 1000);
    return;
#endif

#ifdef USE_WINDOWS
    Sleep(ms);
    return;
#endif

    cerr << "Error: Your platform is not supported for Sleep::mSleep() yet" << endl;
#endif
}
