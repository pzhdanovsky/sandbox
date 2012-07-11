#ifndef SB_LUABIND_METHOD_H_INCLUDED
#define SB_LUABIND_METHOD_H_INCLUDED

/**
	generated by ./gen_sb_luabind_method.sh at Tue Jul 10 02:21:47 MSK 2012
*/
#include "sb_luabind_stack.h"
namespace Sandbox {
	namespace luabind {
		template <typename FuncPtr,int base=1> struct method_helper;
		template <typename Proto,int base=1> struct constructor_helper;
		// implementation for 0 args
		// constructor
		template<int base>
		struct constructor_helper<void(),base>{
			template <class T> static T* raw( lua_State * /*L*/) {
				return new T();
			}
			template <class T> static void inplace( lua_State * /*L*/,void *data) {
				new (data) T();
			}
		};
		// free method void
		template<int base>
		struct method_helper<void(*)(),base>{
			typedef void (*Func)();
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				(*func)();
				return 0;
			}
		};
		// free method with result
		template<class R,int base>
		struct method_helper<R(*)(),base>{
			typedef R (*Func)();
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				stack<R>::push(L,(*func)());
				return 1;
			}
		};
		// member method void
		template<class T,int base>
		struct method_helper<void(T::*)(),base>{
			typedef void (T::*Func)();
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				(&stack<T>::get(L,base+0)->*func)();
				return 0;
			}
		};
		// member method void const
		template<class T,int base>
		struct method_helper<void(T::*)()const,base>{
			typedef void (T::*Func)()const;
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				(&stack<const T>::get(L,base+0)->*func)();
				return 0;
			}
		};
		// member method with result
		template<class T,class R,int base>
		struct method_helper<R(T::*)(),base>{
			typedef R (T::*Func)();
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				stack<R>::push(L,(&stack<T>::get(L,base+0)->*func)());
				return 1;
			}
		};
		// member method with result const
		template<class T,class R,int base>
		struct method_helper<R(T::*)()const,base>{
			typedef R (T::*Func)()const;
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				stack<R>::push(L,(&stack<const T>::get(L,base+0)->*func)());
				return 1;
			}
		};
		// implementation for 1 args
		// constructor
		template<typename A1,
			 int base>
		struct constructor_helper<void(A1),base>{
			template <class T> static T* raw( lua_State * L) {
				return new T(stack<A1>::get(L,base+1-1));
			}
			template <class T> static void inplace( lua_State * L,void *data) {
				new (data) T(stack<A1>::get(L,base+1-1));
			}
		};
		// free method void
		template<typename A1,
			 int base>
		struct method_helper<void(*)(A1),base>{
			typedef void (*Func)(A1);
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				(*func)(stack<A1>::get(L,base+1-1));
				return 0;
			}
		};
		// free method with result
		template<class R,typename A1,
			 int base>
		struct method_helper<R(*)(A1),base>{
			typedef R (*Func)(A1);
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				stack<R>::push(L,(*func)(stack<A1>::get(L,base+1-1)));
				return 1;
			}
		};
		// member method void
		template<class T,typename A1,
			 int base>
		struct method_helper<void(T::*)(A1),base>{
			typedef void (T::*Func)(A1);
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				(&stack<T>::get(L,base+0)->*func)(stack<A1>::get(L,base+1));
				return 0;
			}
		};
		// member method void const
		template<class T,typename A1,
			 int base>
		struct method_helper<void(T::*)(A1)const,base>{
			typedef void (T::*Func)(A1)const;
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				(&stack<const T>::get(L,base+0)->*func)(stack<A1>::get(L,base+1));
				return 0;
			}
		};
		// member method with result
		template<class T,class R,typename A1,
			 int base>
		struct method_helper<R(T::*)(A1),base>{
			typedef R (T::*Func)(A1);
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				stack<R>::push(L,(&stack<T>::get(L,base+0)->*func)(stack<A1>::get(L,base+1)));
				return 1;
			}
		};
		// member method with result const
		template<class T,class R,typename A1,
			 int base>
		struct method_helper<R(T::*)(A1)const,base>{
			typedef R (T::*Func)(A1)const;
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				stack<R>::push(L,(&stack<const T>::get(L,base+0)->*func)(stack<A1>::get(L,base+1)));
				return 1;
			}
		};
		// implementation for 2 args
		// constructor
		template<typename A1,
			 typename A2,
			 int base>
		struct constructor_helper<void(A1,A2),base>{
			template <class T> static T* raw( lua_State * L) {
				return new T(stack<A1>::get(L,base+1-1),
					stack<A2>::get(L,base+2-1));
			}
			template <class T> static void inplace( lua_State * L,void *data) {
				new (data) T(stack<A1>::get(L,base+1-1),
					stack<A2>::get(L,base+2-1));
			}
		};
		// free method void
		template<typename A1,
			 typename A2,
			 int base>
		struct method_helper<void(*)(A1,A2),base>{
			typedef void (*Func)(A1,A2);
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				(*func)(stack<A1>::get(L,base+1-1),
					stack<A2>::get(L,base+2-1));
				return 0;
			}
		};
		// free method with result
		template<class R,typename A1,
			 typename A2,
			 int base>
		struct method_helper<R(*)(A1,A2),base>{
			typedef R (*Func)(A1,A2);
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				stack<R>::push(L,(*func)(stack<A1>::get(L,base+1-1),
					stack<A2>::get(L,base+2-1)));
				return 1;
			}
		};
		// member method void
		template<class T,typename A1,
			 typename A2,
			 int base>
		struct method_helper<void(T::*)(A1,A2),base>{
			typedef void (T::*Func)(A1,A2);
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				(&stack<T>::get(L,base+0)->*func)(stack<A1>::get(L,base+1),
					stack<A2>::get(L,base+2));
				return 0;
			}
		};
		// member method void const
		template<class T,typename A1,
			 typename A2,
			 int base>
		struct method_helper<void(T::*)(A1,A2)const,base>{
			typedef void (T::*Func)(A1,A2)const;
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				(&stack<const T>::get(L,base+0)->*func)(stack<A1>::get(L,base+1),
					stack<A2>::get(L,base+2));
				return 0;
			}
		};
		// member method with result
		template<class T,class R,typename A1,
			 typename A2,
			 int base>
		struct method_helper<R(T::*)(A1,A2),base>{
			typedef R (T::*Func)(A1,A2);
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				stack<R>::push(L,(&stack<T>::get(L,base+0)->*func)(stack<A1>::get(L,base+1),
					stack<A2>::get(L,base+2)));
				return 1;
			}
		};
		// member method with result const
		template<class T,class R,typename A1,
			 typename A2,
			 int base>
		struct method_helper<R(T::*)(A1,A2)const,base>{
			typedef R (T::*Func)(A1,A2)const;
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				stack<R>::push(L,(&stack<const T>::get(L,base+0)->*func)(stack<A1>::get(L,base+1),
					stack<A2>::get(L,base+2)));
				return 1;
			}
		};
		// implementation for 3 args
		// constructor
		template<typename A1,
			 typename A2,
			 typename A3,
			 int base>
		struct constructor_helper<void(A1,A2,A3),base>{
			template <class T> static T* raw( lua_State * L) {
				return new T(stack<A1>::get(L,base+1-1),
					stack<A2>::get(L,base+2-1),
					stack<A3>::get(L,base+3-1));
			}
			template <class T> static void inplace( lua_State * L,void *data) {
				new (data) T(stack<A1>::get(L,base+1-1),
					stack<A2>::get(L,base+2-1),
					stack<A3>::get(L,base+3-1));
			}
		};
		// free method void
		template<typename A1,
			 typename A2,
			 typename A3,
			 int base>
		struct method_helper<void(*)(A1,A2,A3),base>{
			typedef void (*Func)(A1,A2,A3);
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				(*func)(stack<A1>::get(L,base+1-1),
					stack<A2>::get(L,base+2-1),
					stack<A3>::get(L,base+3-1));
				return 0;
			}
		};
		// free method with result
		template<class R,typename A1,
			 typename A2,
			 typename A3,
			 int base>
		struct method_helper<R(*)(A1,A2,A3),base>{
			typedef R (*Func)(A1,A2,A3);
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				stack<R>::push(L,(*func)(stack<A1>::get(L,base+1-1),
					stack<A2>::get(L,base+2-1),
					stack<A3>::get(L,base+3-1)));
				return 1;
			}
		};
		// member method void
		template<class T,typename A1,
			 typename A2,
			 typename A3,
			 int base>
		struct method_helper<void(T::*)(A1,A2,A3),base>{
			typedef void (T::*Func)(A1,A2,A3);
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				(&stack<T>::get(L,base+0)->*func)(stack<A1>::get(L,base+1),
					stack<A2>::get(L,base+2),
					stack<A3>::get(L,base+3));
				return 0;
			}
		};
		// member method void const
		template<class T,typename A1,
			 typename A2,
			 typename A3,
			 int base>
		struct method_helper<void(T::*)(A1,A2,A3)const,base>{
			typedef void (T::*Func)(A1,A2,A3)const;
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				(&stack<const T>::get(L,base+0)->*func)(stack<A1>::get(L,base+1),
					stack<A2>::get(L,base+2),
					stack<A3>::get(L,base+3));
				return 0;
			}
		};
		// member method with result
		template<class T,class R,typename A1,
			 typename A2,
			 typename A3,
			 int base>
		struct method_helper<R(T::*)(A1,A2,A3),base>{
			typedef R (T::*Func)(A1,A2,A3);
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				stack<R>::push(L,(&stack<T>::get(L,base+0)->*func)(stack<A1>::get(L,base+1),
					stack<A2>::get(L,base+2),
					stack<A3>::get(L,base+3)));
				return 1;
			}
		};
		// member method with result const
		template<class T,class R,typename A1,
			 typename A2,
			 typename A3,
			 int base>
		struct method_helper<R(T::*)(A1,A2,A3)const,base>{
			typedef R (T::*Func)(A1,A2,A3)const;
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				stack<R>::push(L,(&stack<const T>::get(L,base+0)->*func)(stack<A1>::get(L,base+1),
					stack<A2>::get(L,base+2),
					stack<A3>::get(L,base+3)));
				return 1;
			}
		};
		// implementation for 4 args
		// constructor
		template<typename A1,
			 typename A2,
			 typename A3,
			 typename A4,
			 int base>
		struct constructor_helper<void(A1,A2,A3,A4),base>{
			template <class T> static T* raw( lua_State * L) {
				return new T(stack<A1>::get(L,base+1-1),
					stack<A2>::get(L,base+2-1),
					stack<A3>::get(L,base+3-1),
					stack<A4>::get(L,base+4-1));
			}
			template <class T> static void inplace( lua_State * L,void *data) {
				new (data) T(stack<A1>::get(L,base+1-1),
					stack<A2>::get(L,base+2-1),
					stack<A3>::get(L,base+3-1),
					stack<A4>::get(L,base+4-1));
			}
		};
		// free method void
		template<typename A1,
			 typename A2,
			 typename A3,
			 typename A4,
			 int base>
		struct method_helper<void(*)(A1,A2,A3,A4),base>{
			typedef void (*Func)(A1,A2,A3,A4);
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				(*func)(stack<A1>::get(L,base+1-1),
					stack<A2>::get(L,base+2-1),
					stack<A3>::get(L,base+3-1),
					stack<A4>::get(L,base+4-1));
				return 0;
			}
		};
		// free method with result
		template<class R,typename A1,
			 typename A2,
			 typename A3,
			 typename A4,
			 int base>
		struct method_helper<R(*)(A1,A2,A3,A4),base>{
			typedef R (*Func)(A1,A2,A3,A4);
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				stack<R>::push(L,(*func)(stack<A1>::get(L,base+1-1),
					stack<A2>::get(L,base+2-1),
					stack<A3>::get(L,base+3-1),
					stack<A4>::get(L,base+4-1)));
				return 1;
			}
		};
		// member method void
		template<class T,typename A1,
			 typename A2,
			 typename A3,
			 typename A4,
			 int base>
		struct method_helper<void(T::*)(A1,A2,A3,A4),base>{
			typedef void (T::*Func)(A1,A2,A3,A4);
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				(&stack<T>::get(L,base+0)->*func)(stack<A1>::get(L,base+1),
					stack<A2>::get(L,base+2),
					stack<A3>::get(L,base+3),
					stack<A4>::get(L,base+4));
				return 0;
			}
		};
		// member method void const
		template<class T,typename A1,
			 typename A2,
			 typename A3,
			 typename A4,
			 int base>
		struct method_helper<void(T::*)(A1,A2,A3,A4)const,base>{
			typedef void (T::*Func)(A1,A2,A3,A4)const;
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				(&stack<const T>::get(L,base+0)->*func)(stack<A1>::get(L,base+1),
					stack<A2>::get(L,base+2),
					stack<A3>::get(L,base+3),
					stack<A4>::get(L,base+4));
				return 0;
			}
		};
		// member method with result
		template<class T,class R,typename A1,
			 typename A2,
			 typename A3,
			 typename A4,
			 int base>
		struct method_helper<R(T::*)(A1,A2,A3,A4),base>{
			typedef R (T::*Func)(A1,A2,A3,A4);
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				stack<R>::push(L,(&stack<T>::get(L,base+0)->*func)(stack<A1>::get(L,base+1),
					stack<A2>::get(L,base+2),
					stack<A3>::get(L,base+3),
					stack<A4>::get(L,base+4)));
				return 1;
			}
		};
		// member method with result const
		template<class T,class R,typename A1,
			 typename A2,
			 typename A3,
			 typename A4,
			 int base>
		struct method_helper<R(T::*)(A1,A2,A3,A4)const,base>{
			typedef R (T::*Func)(A1,A2,A3,A4)const;
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				stack<R>::push(L,(&stack<const T>::get(L,base+0)->*func)(stack<A1>::get(L,base+1),
					stack<A2>::get(L,base+2),
					stack<A3>::get(L,base+3),
					stack<A4>::get(L,base+4)));
				return 1;
			}
		};
		// implementation for 5 args
		// constructor
		template<typename A1,
			 typename A2,
			 typename A3,
			 typename A4,
			 typename A5,
			 int base>
		struct constructor_helper<void(A1,A2,A3,A4,A5),base>{
			template <class T> static T* raw( lua_State * L) {
				return new T(stack<A1>::get(L,base+1-1),
					stack<A2>::get(L,base+2-1),
					stack<A3>::get(L,base+3-1),
					stack<A4>::get(L,base+4-1),
					stack<A5>::get(L,base+5-1));
			}
			template <class T> static void inplace( lua_State * L,void *data) {
				new (data) T(stack<A1>::get(L,base+1-1),
					stack<A2>::get(L,base+2-1),
					stack<A3>::get(L,base+3-1),
					stack<A4>::get(L,base+4-1),
					stack<A5>::get(L,base+5-1));
			}
		};
		// free method void
		template<typename A1,
			 typename A2,
			 typename A3,
			 typename A4,
			 typename A5,
			 int base>
		struct method_helper<void(*)(A1,A2,A3,A4,A5),base>{
			typedef void (*Func)(A1,A2,A3,A4,A5);
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				(*func)(stack<A1>::get(L,base+1-1),
					stack<A2>::get(L,base+2-1),
					stack<A3>::get(L,base+3-1),
					stack<A4>::get(L,base+4-1),
					stack<A5>::get(L,base+5-1));
				return 0;
			}
		};
		// free method with result
		template<class R,typename A1,
			 typename A2,
			 typename A3,
			 typename A4,
			 typename A5,
			 int base>
		struct method_helper<R(*)(A1,A2,A3,A4,A5),base>{
			typedef R (*Func)(A1,A2,A3,A4,A5);
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				stack<R>::push(L,(*func)(stack<A1>::get(L,base+1-1),
					stack<A2>::get(L,base+2-1),
					stack<A3>::get(L,base+3-1),
					stack<A4>::get(L,base+4-1),
					stack<A5>::get(L,base+5-1)));
				return 1;
			}
		};
		// member method void
		template<class T,typename A1,
			 typename A2,
			 typename A3,
			 typename A4,
			 typename A5,
			 int base>
		struct method_helper<void(T::*)(A1,A2,A3,A4,A5),base>{
			typedef void (T::*Func)(A1,A2,A3,A4,A5);
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				(&stack<T>::get(L,base+0)->*func)(stack<A1>::get(L,base+1),
					stack<A2>::get(L,base+2),
					stack<A3>::get(L,base+3),
					stack<A4>::get(L,base+4),
					stack<A5>::get(L,base+5));
				return 0;
			}
		};
		// member method void const
		template<class T,typename A1,
			 typename A2,
			 typename A3,
			 typename A4,
			 typename A5,
			 int base>
		struct method_helper<void(T::*)(A1,A2,A3,A4,A5)const,base>{
			typedef void (T::*Func)(A1,A2,A3,A4,A5)const;
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				(&stack<const T>::get(L,base+0)->*func)(stack<A1>::get(L,base+1),
					stack<A2>::get(L,base+2),
					stack<A3>::get(L,base+3),
					stack<A4>::get(L,base+4),
					stack<A5>::get(L,base+5));
				return 0;
			}
		};
		// member method with result
		template<class T,class R,typename A1,
			 typename A2,
			 typename A3,
			 typename A4,
			 typename A5,
			 int base>
		struct method_helper<R(T::*)(A1,A2,A3,A4,A5),base>{
			typedef R (T::*Func)(A1,A2,A3,A4,A5);
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				stack<R>::push(L,(&stack<T>::get(L,base+0)->*func)(stack<A1>::get(L,base+1),
					stack<A2>::get(L,base+2),
					stack<A3>::get(L,base+3),
					stack<A4>::get(L,base+4),
					stack<A5>::get(L,base+5)));
				return 1;
			}
		};
		// member method with result const
		template<class T,class R,typename A1,
			 typename A2,
			 typename A3,
			 typename A4,
			 typename A5,
			 int base>
		struct method_helper<R(T::*)(A1,A2,A3,A4,A5)const,base>{
			typedef R (T::*Func)(A1,A2,A3,A4,A5)const;
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				stack<R>::push(L,(&stack<const T>::get(L,base+0)->*func)(stack<A1>::get(L,base+1),
					stack<A2>::get(L,base+2),
					stack<A3>::get(L,base+3),
					stack<A4>::get(L,base+4),
					stack<A5>::get(L,base+5)));
				return 1;
			}
		};
		// implementation for 6 args
		// constructor
		template<typename A1,
			 typename A2,
			 typename A3,
			 typename A4,
			 typename A5,
			 typename A6,
			 int base>
		struct constructor_helper<void(A1,A2,A3,A4,A5,A6),base>{
			template <class T> static T* raw( lua_State * L) {
				return new T(stack<A1>::get(L,base+1-1),
					stack<A2>::get(L,base+2-1),
					stack<A3>::get(L,base+3-1),
					stack<A4>::get(L,base+4-1),
					stack<A5>::get(L,base+5-1),
					stack<A6>::get(L,base+6-1));
			}
			template <class T> static void inplace( lua_State * L,void *data) {
				new (data) T(stack<A1>::get(L,base+1-1),
					stack<A2>::get(L,base+2-1),
					stack<A3>::get(L,base+3-1),
					stack<A4>::get(L,base+4-1),
					stack<A5>::get(L,base+5-1),
					stack<A6>::get(L,base+6-1));
			}
		};
		// free method void
		template<typename A1,
			 typename A2,
			 typename A3,
			 typename A4,
			 typename A5,
			 typename A6,
			 int base>
		struct method_helper<void(*)(A1,A2,A3,A4,A5,A6),base>{
			typedef void (*Func)(A1,A2,A3,A4,A5,A6);
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				(*func)(stack<A1>::get(L,base+1-1),
					stack<A2>::get(L,base+2-1),
					stack<A3>::get(L,base+3-1),
					stack<A4>::get(L,base+4-1),
					stack<A5>::get(L,base+5-1),
					stack<A6>::get(L,base+6-1));
				return 0;
			}
		};
		// free method with result
		template<class R,typename A1,
			 typename A2,
			 typename A3,
			 typename A4,
			 typename A5,
			 typename A6,
			 int base>
		struct method_helper<R(*)(A1,A2,A3,A4,A5,A6),base>{
			typedef R (*Func)(A1,A2,A3,A4,A5,A6);
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				stack<R>::push(L,(*func)(stack<A1>::get(L,base+1-1),
					stack<A2>::get(L,base+2-1),
					stack<A3>::get(L,base+3-1),
					stack<A4>::get(L,base+4-1),
					stack<A5>::get(L,base+5-1),
					stack<A6>::get(L,base+6-1)));
				return 1;
			}
		};
		// member method void
		template<class T,typename A1,
			 typename A2,
			 typename A3,
			 typename A4,
			 typename A5,
			 typename A6,
			 int base>
		struct method_helper<void(T::*)(A1,A2,A3,A4,A5,A6),base>{
			typedef void (T::*Func)(A1,A2,A3,A4,A5,A6);
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				(&stack<T>::get(L,base+0)->*func)(stack<A1>::get(L,base+1),
					stack<A2>::get(L,base+2),
					stack<A3>::get(L,base+3),
					stack<A4>::get(L,base+4),
					stack<A5>::get(L,base+5),
					stack<A6>::get(L,base+6));
				return 0;
			}
		};
		// member method void const
		template<class T,typename A1,
			 typename A2,
			 typename A3,
			 typename A4,
			 typename A5,
			 typename A6,
			 int base>
		struct method_helper<void(T::*)(A1,A2,A3,A4,A5,A6)const,base>{
			typedef void (T::*Func)(A1,A2,A3,A4,A5,A6)const;
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				(&stack<const T>::get(L,base+0)->*func)(stack<A1>::get(L,base+1),
					stack<A2>::get(L,base+2),
					stack<A3>::get(L,base+3),
					stack<A4>::get(L,base+4),
					stack<A5>::get(L,base+5),
					stack<A6>::get(L,base+6));
				return 0;
			}
		};
		// member method with result
		template<class T,class R,typename A1,
			 typename A2,
			 typename A3,
			 typename A4,
			 typename A5,
			 typename A6,
			 int base>
		struct method_helper<R(T::*)(A1,A2,A3,A4,A5,A6),base>{
			typedef R (T::*Func)(A1,A2,A3,A4,A5,A6);
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				stack<R>::push(L,(&stack<T>::get(L,base+0)->*func)(stack<A1>::get(L,base+1),
					stack<A2>::get(L,base+2),
					stack<A3>::get(L,base+3),
					stack<A4>::get(L,base+4),
					stack<A5>::get(L,base+5),
					stack<A6>::get(L,base+6)));
				return 1;
			}
		};
		// member method with result const
		template<class T,class R,typename A1,
			 typename A2,
			 typename A3,
			 typename A4,
			 typename A5,
			 typename A6,
			 int base>
		struct method_helper<R(T::*)(A1,A2,A3,A4,A5,A6)const,base>{
			typedef R (T::*Func)(A1,A2,A3,A4,A5,A6)const;
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				stack<R>::push(L,(&stack<const T>::get(L,base+0)->*func)(stack<A1>::get(L,base+1),
					stack<A2>::get(L,base+2),
					stack<A3>::get(L,base+3),
					stack<A4>::get(L,base+4),
					stack<A5>::get(L,base+5),
					stack<A6>::get(L,base+6)));
				return 1;
			}
		};
		// implementation for 7 args
		// constructor
		template<typename A1,
			 typename A2,
			 typename A3,
			 typename A4,
			 typename A5,
			 typename A6,
			 typename A7,
			 int base>
		struct constructor_helper<void(A1,A2,A3,A4,A5,A6,A7),base>{
			template <class T> static T* raw( lua_State * L) {
				return new T(stack<A1>::get(L,base+1-1),
					stack<A2>::get(L,base+2-1),
					stack<A3>::get(L,base+3-1),
					stack<A4>::get(L,base+4-1),
					stack<A5>::get(L,base+5-1),
					stack<A6>::get(L,base+6-1),
					stack<A7>::get(L,base+7-1));
			}
			template <class T> static void inplace( lua_State * L,void *data) {
				new (data) T(stack<A1>::get(L,base+1-1),
					stack<A2>::get(L,base+2-1),
					stack<A3>::get(L,base+3-1),
					stack<A4>::get(L,base+4-1),
					stack<A5>::get(L,base+5-1),
					stack<A6>::get(L,base+6-1),
					stack<A7>::get(L,base+7-1));
			}
		};
		// free method void
		template<typename A1,
			 typename A2,
			 typename A3,
			 typename A4,
			 typename A5,
			 typename A6,
			 typename A7,
			 int base>
		struct method_helper<void(*)(A1,A2,A3,A4,A5,A6,A7),base>{
			typedef void (*Func)(A1,A2,A3,A4,A5,A6,A7);
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				(*func)(stack<A1>::get(L,base+1-1),
					stack<A2>::get(L,base+2-1),
					stack<A3>::get(L,base+3-1),
					stack<A4>::get(L,base+4-1),
					stack<A5>::get(L,base+5-1),
					stack<A6>::get(L,base+6-1),
					stack<A7>::get(L,base+7-1));
				return 0;
			}
		};
		// free method with result
		template<class R,typename A1,
			 typename A2,
			 typename A3,
			 typename A4,
			 typename A5,
			 typename A6,
			 typename A7,
			 int base>
		struct method_helper<R(*)(A1,A2,A3,A4,A5,A6,A7),base>{
			typedef R (*Func)(A1,A2,A3,A4,A5,A6,A7);
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				stack<R>::push(L,(*func)(stack<A1>::get(L,base+1-1),
					stack<A2>::get(L,base+2-1),
					stack<A3>::get(L,base+3-1),
					stack<A4>::get(L,base+4-1),
					stack<A5>::get(L,base+5-1),
					stack<A6>::get(L,base+6-1),
					stack<A7>::get(L,base+7-1)));
				return 1;
			}
		};
		// member method void
		template<class T,typename A1,
			 typename A2,
			 typename A3,
			 typename A4,
			 typename A5,
			 typename A6,
			 typename A7,
			 int base>
		struct method_helper<void(T::*)(A1,A2,A3,A4,A5,A6,A7),base>{
			typedef void (T::*Func)(A1,A2,A3,A4,A5,A6,A7);
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				(&stack<T>::get(L,base+0)->*func)(stack<A1>::get(L,base+1),
					stack<A2>::get(L,base+2),
					stack<A3>::get(L,base+3),
					stack<A4>::get(L,base+4),
					stack<A5>::get(L,base+5),
					stack<A6>::get(L,base+6),
					stack<A7>::get(L,base+7));
				return 0;
			}
		};
		// member method void const
		template<class T,typename A1,
			 typename A2,
			 typename A3,
			 typename A4,
			 typename A5,
			 typename A6,
			 typename A7,
			 int base>
		struct method_helper<void(T::*)(A1,A2,A3,A4,A5,A6,A7)const,base>{
			typedef void (T::*Func)(A1,A2,A3,A4,A5,A6,A7)const;
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				(&stack<const T>::get(L,base+0)->*func)(stack<A1>::get(L,base+1),
					stack<A2>::get(L,base+2),
					stack<A3>::get(L,base+3),
					stack<A4>::get(L,base+4),
					stack<A5>::get(L,base+5),
					stack<A6>::get(L,base+6),
					stack<A7>::get(L,base+7));
				return 0;
			}
		};
		// member method with result
		template<class T,class R,typename A1,
			 typename A2,
			 typename A3,
			 typename A4,
			 typename A5,
			 typename A6,
			 typename A7,
			 int base>
		struct method_helper<R(T::*)(A1,A2,A3,A4,A5,A6,A7),base>{
			typedef R (T::*Func)(A1,A2,A3,A4,A5,A6,A7);
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				stack<R>::push(L,(&stack<T>::get(L,base+0)->*func)(stack<A1>::get(L,base+1),
					stack<A2>::get(L,base+2),
					stack<A3>::get(L,base+3),
					stack<A4>::get(L,base+4),
					stack<A5>::get(L,base+5),
					stack<A6>::get(L,base+6),
					stack<A7>::get(L,base+7)));
				return 1;
			}
		};
		// member method with result const
		template<class T,class R,typename A1,
			 typename A2,
			 typename A3,
			 typename A4,
			 typename A5,
			 typename A6,
			 typename A7,
			 int base>
		struct method_helper<R(T::*)(A1,A2,A3,A4,A5,A6,A7)const,base>{
			typedef R (T::*Func)(A1,A2,A3,A4,A5,A6,A7)const;
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				stack<R>::push(L,(&stack<const T>::get(L,base+0)->*func)(stack<A1>::get(L,base+1),
					stack<A2>::get(L,base+2),
					stack<A3>::get(L,base+3),
					stack<A4>::get(L,base+4),
					stack<A5>::get(L,base+5),
					stack<A6>::get(L,base+6),
					stack<A7>::get(L,base+7)));
				return 1;
			}
		};
		// implementation for 8 args
		// constructor
		template<typename A1,
			 typename A2,
			 typename A3,
			 typename A4,
			 typename A5,
			 typename A6,
			 typename A7,
			 typename A8,
			 int base>
		struct constructor_helper<void(A1,A2,A3,A4,A5,A6,A7,A8),base>{
			template <class T> static T* raw( lua_State * L) {
				return new T(stack<A1>::get(L,base+1-1),
					stack<A2>::get(L,base+2-1),
					stack<A3>::get(L,base+3-1),
					stack<A4>::get(L,base+4-1),
					stack<A5>::get(L,base+5-1),
					stack<A6>::get(L,base+6-1),
					stack<A7>::get(L,base+7-1),
					stack<A8>::get(L,base+8-1));
			}
			template <class T> static void inplace( lua_State * L,void *data) {
				new (data) T(stack<A1>::get(L,base+1-1),
					stack<A2>::get(L,base+2-1),
					stack<A3>::get(L,base+3-1),
					stack<A4>::get(L,base+4-1),
					stack<A5>::get(L,base+5-1),
					stack<A6>::get(L,base+6-1),
					stack<A7>::get(L,base+7-1),
					stack<A8>::get(L,base+8-1));
			}
		};
		// free method void
		template<typename A1,
			 typename A2,
			 typename A3,
			 typename A4,
			 typename A5,
			 typename A6,
			 typename A7,
			 typename A8,
			 int base>
		struct method_helper<void(*)(A1,A2,A3,A4,A5,A6,A7,A8),base>{
			typedef void (*Func)(A1,A2,A3,A4,A5,A6,A7,A8);
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				(*func)(stack<A1>::get(L,base+1-1),
					stack<A2>::get(L,base+2-1),
					stack<A3>::get(L,base+3-1),
					stack<A4>::get(L,base+4-1),
					stack<A5>::get(L,base+5-1),
					stack<A6>::get(L,base+6-1),
					stack<A7>::get(L,base+7-1),
					stack<A8>::get(L,base+8-1));
				return 0;
			}
		};
		// free method with result
		template<class R,typename A1,
			 typename A2,
			 typename A3,
			 typename A4,
			 typename A5,
			 typename A6,
			 typename A7,
			 typename A8,
			 int base>
		struct method_helper<R(*)(A1,A2,A3,A4,A5,A6,A7,A8),base>{
			typedef R (*Func)(A1,A2,A3,A4,A5,A6,A7,A8);
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				stack<R>::push(L,(*func)(stack<A1>::get(L,base+1-1),
					stack<A2>::get(L,base+2-1),
					stack<A3>::get(L,base+3-1),
					stack<A4>::get(L,base+4-1),
					stack<A5>::get(L,base+5-1),
					stack<A6>::get(L,base+6-1),
					stack<A7>::get(L,base+7-1),
					stack<A8>::get(L,base+8-1)));
				return 1;
			}
		};
		// member method void
		template<class T,typename A1,
			 typename A2,
			 typename A3,
			 typename A4,
			 typename A5,
			 typename A6,
			 typename A7,
			 typename A8,
			 int base>
		struct method_helper<void(T::*)(A1,A2,A3,A4,A5,A6,A7,A8),base>{
			typedef void (T::*Func)(A1,A2,A3,A4,A5,A6,A7,A8);
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				(&stack<T>::get(L,base+0)->*func)(stack<A1>::get(L,base+1),
					stack<A2>::get(L,base+2),
					stack<A3>::get(L,base+3),
					stack<A4>::get(L,base+4),
					stack<A5>::get(L,base+5),
					stack<A6>::get(L,base+6),
					stack<A7>::get(L,base+7),
					stack<A8>::get(L,base+8));
				return 0;
			}
		};
		// member method void const
		template<class T,typename A1,
			 typename A2,
			 typename A3,
			 typename A4,
			 typename A5,
			 typename A6,
			 typename A7,
			 typename A8,
			 int base>
		struct method_helper<void(T::*)(A1,A2,A3,A4,A5,A6,A7,A8)const,base>{
			typedef void (T::*Func)(A1,A2,A3,A4,A5,A6,A7,A8)const;
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				(&stack<const T>::get(L,base+0)->*func)(stack<A1>::get(L,base+1),
					stack<A2>::get(L,base+2),
					stack<A3>::get(L,base+3),
					stack<A4>::get(L,base+4),
					stack<A5>::get(L,base+5),
					stack<A6>::get(L,base+6),
					stack<A7>::get(L,base+7),
					stack<A8>::get(L,base+8));
				return 0;
			}
		};
		// member method with result
		template<class T,class R,typename A1,
			 typename A2,
			 typename A3,
			 typename A4,
			 typename A5,
			 typename A6,
			 typename A7,
			 typename A8,
			 int base>
		struct method_helper<R(T::*)(A1,A2,A3,A4,A5,A6,A7,A8),base>{
			typedef R (T::*Func)(A1,A2,A3,A4,A5,A6,A7,A8);
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				stack<R>::push(L,(&stack<T>::get(L,base+0)->*func)(stack<A1>::get(L,base+1),
					stack<A2>::get(L,base+2),
					stack<A3>::get(L,base+3),
					stack<A4>::get(L,base+4),
					stack<A5>::get(L,base+5),
					stack<A6>::get(L,base+6),
					stack<A7>::get(L,base+7),
					stack<A8>::get(L,base+8)));
				return 1;
			}
		};
		// member method with result const
		template<class T,class R,typename A1,
			 typename A2,
			 typename A3,
			 typename A4,
			 typename A5,
			 typename A6,
			 typename A7,
			 typename A8,
			 int base>
		struct method_helper<R(T::*)(A1,A2,A3,A4,A5,A6,A7,A8)const,base>{
			typedef R (T::*Func)(A1,A2,A3,A4,A5,A6,A7,A8)const;
			static int call( lua_State* L ) {
				Func func = *reinterpret_cast<Func*>(lua_touserdata(L, lua_upvalueindex(1)));
				stack<R>::push(L,(&stack<const T>::get(L,base+0)->*func)(stack<A1>::get(L,base+1),
					stack<A2>::get(L,base+2),
					stack<A3>::get(L,base+3),
					stack<A4>::get(L,base+4),
					stack<A5>::get(L,base+5),
					stack<A6>::get(L,base+6),
					stack<A7>::get(L,base+7),
					stack<A8>::get(L,base+8)));
				return 1;
			}
		};
	}
}
#endif /*SB_LUABIND_METHOD_H_INCLUDED*/
