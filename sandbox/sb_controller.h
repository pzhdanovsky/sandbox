/*
 *  sb_controller.h
 *  SR
 *
 *  Created by Андрей Куницын on 15.02.11.
 *  Copyright 2011 andryblack. All rights reserved.
 *
 */

#ifndef SB_CONTROLLER_H
#define SB_CONTROLLER_H

#include "sb_shared_ptr.h"

namespace Sandbox {
	
	class Controller {
	public:
		virtual ~Controller() {}
		virtual void Set(float k) = 0;
	};
	typedef shared_ptr<Controller> ControllerPtr;
	
	template <class T,class Setter ,class Obj> class LinearController : public Controller {
	public:
		const T& GetBegin() const { return m_begin;}
		void SetBegin(const T& from) { m_begin = from;}
		const T& GetEnd() const { return m_end;}
		void SetEnd(const T& to) { m_end = to;}
		void Set(float k) {
			Setter::SetValue( m_obj, m_begin * (1.0f-k) + m_end * k );
		}
		explicit LinearController(const Obj& obj) : m_obj(obj),m_begin(),m_end() {}
	private:
		Obj	m_obj;
		T	m_begin;
		T	m_end;
	};
	
	template <class Setter ,class Obj> class LinearController<float,Setter,Obj> : public Controller {
	public:
		float GetBegin() const { return m_begin;}
		void SetBegin(float from) { m_begin = from;}
		float GetEnd() const { return m_end;}
		void SetEnd(float to) { m_end = to;}
		void Set(float k) {
			Setter::SetValue( m_obj, m_begin * (1.0f-k) + m_end * k );
		}
		explicit LinearController(const Obj& obj) : m_obj(obj),m_begin(),m_end() {}
	private:
		Obj	m_obj;
		float	m_begin;
		float	m_end;
	};
}

#endif /*SB_CONTROLLER_H*/