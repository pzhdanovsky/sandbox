/*
 *  sb_bind.h
 *  SR
 *
 *  Created by Андрей Куницын on 14.02.11.
 *  Copyright 2011 andryblack. All rights reserved.
 *
 */

#ifndef SB_BIND_H
#define SB_BIND_H

#include "sb_bind_class.h"
#include "sb_bind_enum.h"
#include "sb_lua.h"

#define SB_BIND_BEGIN_BIND { using namespace ::Sandbox::Bind::ClassDefaults;(void)constructorInfo;(void)methods;(void)propertys;
#define SB_BIND(lua) lua->Bind(&bind);
#define SB_BIND_END_BIND }

#endif /*SB_BIND_H*/