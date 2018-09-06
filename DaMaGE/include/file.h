#ifndef _FILEUTIL_H_
#define _FILEUTIL_H_

#include <cstdio>
#include <cstring>
#include <assert.h> 

#define TERM_CHAR 1

namespace dmg { namespace util {

    const char* read_file(const char* path);

}}
#endif //_FILEUTIL_H_

