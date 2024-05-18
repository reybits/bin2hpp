/**********************************************\
*
*  Andrey A. Ugolnik
*  https://www.ugolnik.info
*  andrey@ugolnik.info
*
\**********************************************/

#pragma once

#include <cstddef>

class cFile final
{
public:
    cFile();
    ~cFile();

    bool open(const char* path, const char* mode = "rb");
    void close();

    size_t getOffset() const;
    void* getHandle() const
    {
        return m_file;
    }

    virtual bool seek(size_t offset, int whence) const;
    virtual size_t read(void* ptr, size_t size) const;
    virtual size_t write(void* ptr, size_t size) const;
    virtual size_t getSize() const
    {
        return m_size;
    }

protected:
    void* m_file = nullptr;
    size_t m_size = 0;
};
