/**********************************************\
*
*  Andrey A. Ugolnik
*  https://www.ugolnik.info
*  andrey@ugolnik.info
*
\**********************************************/

#include "file_cache.h"
#include "file.h"

void cFileCache::append(size_t size)
{
    m_pos += size;
    if (m_pos >= m_buffer.size())
    {
        flush();
    }
}

void cFileCache::flush()
{
    m_file.write(m_buffer.data(), m_pos);
    m_pos = 0;
}
