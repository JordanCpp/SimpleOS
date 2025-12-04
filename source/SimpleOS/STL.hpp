
#pragma once

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <SimpleOS/ExtNew.hpp>

namespace OS 
{
    class String 
    {
    private:
        char*  _data;
        size_t _size;
        size_t _capacity;
    public:
        String() noexcept : 
            _data(nullptr),
            _size(0), 
            _capacity(0) 
        {
            reserve(1);
            _data[0] = '\0';
        }

        String(const char* c_str) : 
            _data(nullptr), 
            _size(0), 
            _capacity(0) 
        {
            size_t len = 0;

            while (c_str[len] != '\0') 
            {
                len++;
            }

            reserve(len + 1);
            memcpy(_data, c_str, len + 1);
            _size = len;
        }

        String(const String& other) : 
            _data(nullptr), 
            _size(0), 
            _capacity(0) 
        {
            reserve(other._capacity);
            memcpy(_data, other._data, other._size + 1);
            _size = other._size;
        }

        ~String() noexcept 
        {
            delete[] _data;
        }

        String& operator=(const String& other) 
        {
            if (this != &other) 
            {
                delete[] _data;
                _size = other._size;
                _capacity = other._capacity;
                _data = new char[_capacity];
                memcpy(_data, other._data, _size + 1);
            }

            return *this;
        }

        size_t size() const noexcept 
        { 
            return _size; 
        }

        bool empty() const noexcept 
        { 
            return _size == 0; 
        }

        size_t capacity() const noexcept 
        {
            return _capacity - 1;
        }

        const char* c_str() const noexcept
        {
            return _data; 
        }

        char* data() noexcept
        {
            return _data;
        }

        char& operator[](size_t index) noexcept 
        { 
            return _data[index]; 
        }

        const char& operator[](size_t index) const noexcept 
        { 
            return _data[index]; 
        }

        String& operator+=(const String& other) 
        {
            size_t new_size = _size + other._size;

            if (new_size >= _capacity) 
            {

                reserve(new_size + 1 + (new_size / 2));
            }

            memcpy(_data + _size, other._data, other._size + 1);
            _size = new_size;

            return *this;
        }

        String& operator+=(char c) 
        {
            if (_size + 1 >= _capacity) 
            {
                reserve(_capacity * 2);
            }

            _data[_size] = c;
            _data[_size + 1] = '\0';
            _size++;

            return *this;
        }

        void reserve(size_t new_capacity) 
        {
            if (new_capacity <= _capacity) 
            {
                return;
            }

            size_t required_capacity = new_capacity + 1;
            char* new_data = new char[required_capacity];

            if (_data)
            {
                memcpy(new_data, _data, _size + 1);
                delete[] _data;
            }

            _data = new_data;
            _capacity = required_capacity;
        }
    };

    inline bool operator==(const String& lhs, const String& rhs) noexcept 
    {
        if (lhs.size() != rhs.size())
        {
            return false;
        }

        return memcmp(lhs.c_str(), rhs.c_str(), lhs.size()) == 0;
    }
       
    inline bool operator!=(const String& lhs, const String& rhs) noexcept
    {
        return !(lhs == rhs);
    }
}
