/*
 *  sb_container_shader.cpp
 *  SR
 *
 *  Created by Андрей Куницын on 13.02.11.
 *  Copyright 2011 andryblack. All rights reserved.
 *
 */

#include "sb_container_shader.h"
#include "sb_graphics.h"

SB_META_DECLARE_OBJECT(Sandbox::ContainerShader, Sandbox::Container)

namespace Sandbox {

	ContainerShader::ContainerShader() : m_enabled(true){
	}
	
	ContainerShader::~ContainerShader() {
	}
	
	void ContainerShader::Draw(Graphics& g) const {
		if (m_enabled) {
			ShaderPtr ss = g.GetShader();
			g.SetShader(m_shader);
            TexturePtr crnt_mask = g.GetMaskTexture();
            if (m_texture) {
                g.SetMaskTexture(m_texture);
            }
            Container::Draw(g);
			g.SetShader(ss);
            if (m_texture) {
                g.SetMaskTexture(crnt_mask);
            }
		} else {
			Container::Draw(g);
		}
	}
	
	
}
