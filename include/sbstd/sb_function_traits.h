/**
 * Copyright (C) 2010-2010, by Andrey AndryBlack Kunitsyn
 * (support.andryblack@gmail.com)
 */

#ifndef SB_FUNCTION_TRAITS_H
#define SB_FUNCTION_TRAITS_H

#include "sb_meta_utils.h"
#include "sb_traits.h"

namespace sb {

    template <typename T> struct base_function_traits {
        enum { is_valid = false};
        enum { is_member = sb::type_traits<T>::is_member_function_pointer };
    };

    template <typename T> struct function_traits;

    /// free functions
    template <typename T> struct function_traits<T(*)()> : public base_function_traits<T(*)()>{
        typedef T result_type;
        typedef null_type object_type;
        enum { is_const = false };
        typedef null_type arg1_type;
        typedef null_type arg2_type;
        typedef null_type arg3_type;
        typedef null_type arg4_type;
        typedef null_type arg5_type;
        typedef T(function_proto)();
    };
    template <typename T,typename P1> struct function_traits<T(*)(P1)> : public base_function_traits<T(*)()>{
        typedef T result_type;
        typedef null_type object_type;
        enum { is_const = false };
        typedef P1 arg1_type;
        typedef null_type arg2_type;
        typedef null_type arg3_type;
        typedef null_type arg4_type;
        typedef null_type arg5_type;
        typedef T(function_proto)(P1);
    };
    template <typename T,typename P1,typename P2> struct function_traits<T(*)(P1,P2)> : public base_function_traits<T(*)()>{
        typedef T result_type;
        typedef null_type object_type;
        enum { is_const = false };
        typedef P1 arg1_type;
        typedef P2 arg2_type;
        typedef null_type arg3_type;
        typedef null_type arg4_type;
        typedef null_type arg5_type;
        typedef T(function_proto)(P1,P2);
    };
    template <typename T,typename P1,typename P2,typename P3> struct function_traits<T(*)(P1,P2,P3)> : public base_function_traits<T(*)()>{
        typedef T result_type;
        typedef null_type object_type;
        enum { is_const = false };
        typedef P1 arg1_type;
        typedef P2 arg2_type;
        typedef P3 arg3_type;
        typedef null_type arg4_type;
        typedef null_type arg5_type;
        typedef T(function_proto)(P1,P2,P3);
    };
    template <typename T,typename P1,typename P2,typename P3,typename P4> struct function_traits<T(*)(P1,P2,P3,P4)> : public base_function_traits<T(*)()>{
        typedef T result_type;
        typedef null_type object_type;
        enum { is_const = false };
        typedef P1 arg1_type;
        typedef P2 arg2_type;
        typedef P3 arg3_type;
        typedef P4 arg4_type;
        typedef null_type arg5_type;
        typedef T(function_proto)(P1,P2,P3,P4);
    };
    template <typename T,typename P1,typename P2,typename P3,typename P4,typename P5> struct function_traits<T(*)(P1,P2,P3,P4,P5)> : public base_function_traits<T(*)()>{
        typedef T result_type;
        typedef null_type object_type;
        enum { is_const = false };
        typedef P1 arg1_type;
        typedef P2 arg2_type;
        typedef P3 arg3_type;
        typedef P4 arg4_type;
        typedef P5 arg5_type;
        typedef T(function_proto)(P1,P2,P3,P4,P5);
    };

    /// member function
    template <typename T,class U> struct function_traits<T(U::*)()> : public base_function_traits<T(*)()>{
        typedef T result_type;
        typedef U object_type;
        enum { is_const = false };
        typedef null_type arg1_type;
        typedef null_type arg2_type;
        typedef null_type arg3_type;
        typedef null_type arg4_type;
        typedef null_type arg5_type;
        typedef T(function_proto)(U*);
    };
    template <typename T,class U,typename P1> struct function_traits<T(U::*)(P1)> : public base_function_traits<T(*)()>{
        typedef T result_type;
        typedef U object_type;
        enum { is_const = false };
        typedef P1 arg1_type;
        typedef null_type arg2_type;
        typedef null_type arg3_type;
        typedef null_type arg4_type;
        typedef null_type arg5_type;
        typedef T(function_proto)(U*,P1);
    };
    template <typename T,class U,typename P1,typename P2> struct function_traits<T(U::*)(P1,P2)> : public base_function_traits<T(*)()>{
        typedef T result_type;
        typedef U object_type;
        enum { is_const = false };
        typedef P1 arg1_type;
        typedef P2 arg2_type;
        typedef null_type arg3_type;
        typedef null_type arg4_type;
        typedef null_type arg5_type;
        typedef T(function_proto)(U*,P1,P2);
    };
    template <typename T,class U,typename P1,typename P2,typename P3> struct function_traits<T(U::*)(P1,P2,P3)> : public base_function_traits<T(*)()>{
        typedef T result_type;
        typedef U object_type;
        enum { is_const = false };
        typedef P1 arg1_type;
        typedef P2 arg2_type;
        typedef P3 arg3_type;
        typedef null_type arg4_type;
        typedef null_type arg5_type;
        typedef T(function_proto)(U*,P1,P2,P3);
    };
    template <typename T,class U,typename P1,typename P2,typename P3,typename P4> struct function_traits<T(U::*)(P1,P2,P3,P4)> : public base_function_traits<T(*)()>{
        typedef T result_type;
        typedef U object_type;
        enum { is_const = false };
        typedef P1 arg1_type;
        typedef P2 arg2_type;
        typedef P3 arg3_type;
        typedef P4 arg4_type;
        typedef null_type arg5_type;
        typedef T(function_proto)(U*,P1,P2,P3,P4);
    };
    template <typename T,class U,typename P1,typename P2,typename P3,typename P4,typename P5> struct function_traits<T(U::*)(P1,P2,P3,P4,P5)> : public base_function_traits<T(*)()>{
        typedef T result_type;
        typedef U object_type;
        enum { is_const = false };
        typedef P1 arg1_type;
        typedef P2 arg2_type;
        typedef P3 arg3_type;
        typedef P4 arg4_type;
        typedef P5 arg5_type;
        typedef T(function_proto)(U*,P1,P2,P3,P4,P5);
    };

    /// const member function
    template <typename T,class U> struct function_traits<T(U::*)()const> : public base_function_traits<T(*)()>{
        typedef T result_type;
        typedef U object_type;
        enum { is_const = true };
        typedef null_type arg1_type;
        typedef null_type arg2_type;
        typedef null_type arg3_type;
        typedef null_type arg4_type;
        typedef null_type arg5_type;
        typedef T(function_proto)();
    };
    template <typename T,class U,typename P1> struct function_traits<T(U::*)(P1)const> : public base_function_traits<T(*)()>{
        typedef T result_type;
        typedef U object_type;
        enum { is_const = true };
        typedef P1 arg1_type;
        typedef null_type arg2_type;
        typedef null_type arg3_type;
        typedef null_type arg4_type;
        typedef null_type arg5_type;
        typedef T(function_proto)(U*,P1);
    };
    template <typename T,class U,typename P1,typename P2> struct function_traits<T(U::*)(P1,P2)const> : public base_function_traits<T(*)()>{
        typedef T result_type;
        typedef U object_type;
        enum { is_const = true };
        typedef P1 arg1_type;
        typedef P2 arg2_type;
        typedef null_type arg3_type;
        typedef null_type arg4_type;
        typedef null_type arg5_type;
        typedef T(function_proto)(U*,P1,P2);
    };
    template <typename T,class U,typename P1,typename P2,typename P3> struct function_traits<T(U::*)(P1,P2,P3)const> : public base_function_traits<T(*)()>{
        typedef T result_type;
        typedef U object_type;
        enum { is_const = true };
        typedef P1 arg1_type;
        typedef P2 arg2_type;
        typedef P3 arg3_type;
        typedef null_type arg4_type;
        typedef null_type arg5_type;
        typedef T(function_proto)(U*,P1,P2,P3);
    };
    template <typename T,class U,typename P1,typename P2,typename P3,typename P4> struct function_traits<T(U::*)(P1,P2,P3,P4)const> : public base_function_traits<T(*)()>{
        typedef T result_type;
        typedef U object_type;
        enum { is_const = true };
        typedef P1 arg1_type;
        typedef P2 arg2_type;
        typedef P3 arg3_type;
        typedef P4 arg4_type;
        typedef null_type arg5_type;
        typedef T(function_proto)(U*,P1,P2,P3,P4);
    };
    template <typename T,class U,typename P1,typename P2,typename P3,typename P4,typename P5> struct function_traits<T(U::*)(P1,P2,P3,P4,P5)const> : public base_function_traits<T(*)()>{
        typedef T result_type;
        typedef U object_type;
        enum { is_const = true };
        typedef P1 arg1_type;
        typedef P2 arg2_type;
        typedef P3 arg3_type;
        typedef P4 arg4_type;
        typedef P5 arg5_type;
        typedef T(function_proto)(U*,P1,P2,P3,P4,P5);
    };


    template <typename Res,typename Arg1=null_type,typename Arg2=null_type,typename Arg3=null_type,typename Arg4=null_type,typename Arg5=null_type> struct proto_build {
        typedef Res (result)(Arg1,Arg2,Arg3,Arg4,Arg5);
    };
    template <typename Res,typename Arg1,typename Arg2,typename Arg3,typename Arg4> struct proto_build<Res,Arg1,Arg2,Arg3,Arg4,null_type> {
        typedef Res (result)(Arg1,Arg2,Arg3,Arg4);
    };
    template <typename Res,typename Arg1,typename Arg2,typename Arg3> struct proto_build<Res,Arg1,Arg2,Arg3,null_type,null_type> {
        typedef Res (result)(Arg1,Arg2,Arg3);
    };
    template <typename Res,typename Arg1,typename Arg2> struct proto_build<Res,Arg1,Arg2,null_type,null_type,null_type> {
        typedef Res (result)(Arg1,Arg2);
    };
    template <typename Res,typename Arg1> struct proto_build<Res,Arg1,null_type,null_type,null_type,null_type> {
        typedef Res (result)(Arg1);
    };
    template <typename Res> struct proto_build<Res,null_type,null_type,null_type,null_type,null_type> {
        typedef Res (result)();
    };
}

#endif // SB_FUNCTION_TRAITS_H
