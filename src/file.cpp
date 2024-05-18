/**********************************************\
*
*  Andrey A. Ugolnik
*  https://www.ugolnik.info
*  andrey@ugolnik.info
*
\**********************************************/

#include "file.h"

#include <cstdio>

cFile::cFile()
{
}

cFile::~cFile()
{
    close();
}

bool cFile::open(const char* path, const char* mode)
{
    auto file = fopen(path, mode);
    if (file != nullptr)
    {
        m_file = file;

        (void)fseek(file, 0, SEEK_END);
        m_size = static_cast<size_t>(ftell(file));
        (void)fseek(file, 0, SEEK_SET);

        return true;
    }

    return false;
}

void cFile::close()
{
    if (m_file != nullptr)
    {
        fclose((FILE*)m_file);
        m_file = nullptr;
    }
}

bool cFile::seek(size_t offset, int whence) const
{
    return fseek((FILE*)m_file, static_cast<long>(offset), whence) == 0;
}

size_t cFile::read(void* ptr, size_t size) const
{
    if (m_file != nullptr)
    {
        return fread(ptr, 1, size, (FILE*)m_file);
    }

    return 0;
}

size_t cFile::write(void* ptr, size_t size) const
{
    if (m_file != nullptr)
    {
        return fwrite(ptr, 1, size, (FILE*)m_file);
    }

    return 0;
}

size_t cFile::getOffset() const
{
    if (m_file != nullptr)
    {
        return static_cast<size_t>(ftell((FILE*)m_file));
    }

    return 0;
}
