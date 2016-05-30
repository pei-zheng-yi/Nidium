/*
   Copyright 2016 Nidium Inc. All rights reserved.
   Use of this source code is governed by a MIT license
   that can be found in the LICENSE file.
*/
#ifndef core_args_h__
#define core_args_h__

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

namespace Nidium {
namespace Core {

class Args
{
public:
    class ArgsValue {
    public:
        ArgsValue() : m_Value(0LL), m_isSet(false) {
            m_ValuePtr = NULL;
        }

        void *toPtr() const {
            return m_ValuePtr;
        }
        int64_t toInt64() const {
            return m_Value;
        }
        int32_t toInt() const {
            return static_cast<int32_t>(m_Value);
        }

        bool toBool() const {
            return static_cast<bool>(m_Value);
        }

        bool isSet() const {
            return m_isSet;
        }

        void set(void *val) {
            m_isSet = true;
            m_ValuePtr = val;
        }
        void set(int64_t val) {
            m_isSet = true;
            m_Value = val;
        }
    private:
        union {
            uint64_t m_Value;
            void *m_ValuePtr;
        };

        bool m_isSet;
    };
    Args() : m_fillArgs(0) {
        m_numArgs = 10;
        m_Args = new ArgsValue[m_numArgs];
    }
    ~Args() {
        delete[] m_Args;
    }

    /*
        Overflow values are automatically allocated
    */
    ArgsValue& operator[] (int idx) {
        if (idx >= m_fillArgs) {
            m_fillArgs = idx+1;
        }

        if (idx >= m_numArgs) {

            m_numArgs = idx+1;
            printf("[Err] Args overflow\n");
            *(volatile int*)0 = 42;
        }

        return m_Args[idx];
    }

    /*
        const version doesn't protect against overflow
    */
    const ArgsValue& operator[] (int idx) const {
        if (idx >= m_numArgs) {
            printf("/!\\ Overflow in accessing Args value. Beggining of the array returned\n");
            return m_Args[0];
        }
        return m_Args[idx];
    }

    int size() const {
        return m_fillArgs;
    }
private:
    ArgsValue *m_Args;
    int m_numArgs;
    int m_fillArgs;
};

} // namespace Core
} // namespace Nidium

#endif
