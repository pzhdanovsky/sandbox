/*
 *  sb_color.h
 *  SR
 *
 *  Created by Андрей Куницын on 07.02.11.
 *  Copyright 2011 andryblack. All rights reserved.
 *
 */

#ifndef SB_COLOR_H
#define SB_COLOR_H

#include <ghl_types.h>

namespace Sandbox {

	/**
	 Color object
	 */
    struct Color {
        float r;    ///< red component
        float g;    ///< green component
        float b;    ///< blue component
        float a;    ///< alpha component
        /// default ctor ( white )
        Color() : r(1.0f),g(1.0f),b(1.0f),a(1.0f) {}
        /// per component ctor
        Color(float r_,float g_,float b_,float a_=1.0f) : r(r_),g(g_),b(b_),a(a_) {}
        /// from UIn32 ctor
        explicit Color(GHL::UInt32 clr) :
		r(conv_byte((clr>>16)&0xff)),
		g(conv_byte((clr>>8)&0xff)),
		b(conv_byte((clr)&0xff)),
		a(conv_byte((clr>>24)&0xff)) {}
        /// convert component from byte to float
        static float conv_byte(GHL::Byte comp) { return float(comp)/255.0f; }
        /// convert component from float to byte
        static GHL::Byte conv_float(float comp) { return static_cast<GHL::Byte>(comp*255);}
		
        GHL::Byte red() const { return conv_float(r);}
        GHL::Byte green() const { return conv_float(g);}
        GHL::Byte blue() const { return conv_float(b);}
        GHL::Byte alpha() const { return conv_float(a);}
		
		/// clamp all components to [0.0-1.0] range
		void clamp() { 
			r = (r<0.0f) ? 0.0f : ( (r>1.0f) ? 1.0f : r );
			g = (g<0.0f) ? 0.0f : ( (g>1.0f) ? 1.0f : g );
			b = (b<0.0f) ? 0.0f : ( (b>1.0f) ? 1.0f : b );
			a = (a<0.0f) ? 0.0f : ( (a>1.0f) ? 1.0f : a );
		}
		
        static Color from_bytes(const GHL::Byte c[4] ) { return Color(conv_byte(c[0]),conv_byte(c[1]),conv_byte(c[2]),conv_byte(c[3])); }
		
        GHL::UInt32 hw() const { return
			(alpha() << 24) |
			(red()) |
			(green()<<8) |
			(blue()<<16);}
		
        /// operators
        Color operator * (const Color& other) const {
            return Color(r*other.r,g*other.g,b*other.b,a*other.a);
        }
		Color operator * (float k) const {
			return Color(r*k,g*k,b*k,a*k);
		}
		Color operator + (const Color& other) const {
			return Color(r+other.r,g+other.g,b+other.b,a+other.a);
		}
		Color& operator += (const Color& other) {
			r+=other.r;g+=other.g;b+=other.b;a+=other.a;
			return *this;
		}
    };
	
}

#endif /*SB_COLOR_H*/