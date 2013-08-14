//
//  sb_color.cpp
//  sr-osx
//
//  Created by Andrey Kunitsyn on 5/20/13.
//  Copyright (c) 2013 Andrey Kunitsyn. All rights reserved.
//

#include "sb_color.h"
#include <cstring>

namespace Sandbox {
    
    
    static inline int conv_hex_char(int c) {
        if ( (c>='0')&&(c<='9')) return c-'0';
        if ( (c>='a')&&(c<='f')) return (c-'a')+0xa;
        if ( (c>='A')&&(c<='F')) return (c-'A')+0xa;
        return 0;
    }
    
    static inline GHL::Byte conv_hex(const char* str) {
        return static_cast<GHL::Byte>((conv_hex_char(*str++)<<4) | conv_hex_char(*str));
    }
    
    Color Color::FromString( const char* str ) {
        if (!str) return Color(0,0,0,1);
        size_t len = ::strlen(str);
        GHL::Byte c[4];
        if (len>=6) {
            c[0]=conv_hex(str);
            c[1]=conv_hex(str+2);
            c[2]=conv_hex(str+4);
            if (len>=8) {
                c[3]=conv_hex(str+6);
            } else {
                c[3]=0xff;
            }
        }
        return from_bytes(c);
    }

}