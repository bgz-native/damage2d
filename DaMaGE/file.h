#ifndef _FILE_H_
#define _FILE_H_

#include <cstdio>
#include <cstring>
#include <assert.h> 

#define TERM_CHAR 1

namespace dmg
{
    const char* read_file(const char* path)
    {
        FILE* fi = fopen(path, "rt");
        assert(fi);

        fseek(fi, 0, SEEK_END);
        unsigned long len = ftell(fi);

        char* buff = new char[len + TERM_CHAR];
        memset(buff, 0, len + TERM_CHAR);

        fseek(fi, 0, SEEK_SET);
        fread(buff, 1, len, fi);
        fclose(fi);

        return buff;
    }

}

#endif //_FILE_H_

