/**********************************************\
*
*  Andrey A. Ugolnik
*  https://www.ugolnik.info
*  andrey@ugolnik.info
*
\**********************************************/

#pragma once

#include <vector>

class cFile;

class cFileCache final
{
public:
    cFileCache(cFile& file, size_t bufferSize)
        : m_file(file)
        , m_buffer(bufferSize)
    {
    }

    ~cFileCache()
    {
        flush();
    }

    char* buffer()
    {
        return m_buffer.data() + m_pos;
    }

    size_t remain() const
    {
        return m_buffer.size() - m_pos;
    }

    void append(size_t size);

    void flush();

private:
    cFile& m_file;
    std::vector<char> m_buffer;
    size_t m_pos = 0;
};
