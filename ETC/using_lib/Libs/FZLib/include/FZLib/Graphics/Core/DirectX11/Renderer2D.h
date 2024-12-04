/*********************************************************************
 * @file   Dx11_Renderer2D.h
 * @brief  2D �������� ���� �׷��� ���̺귯��
 * 
 * @author FuJiGraphics
 * @date   2024/03/07
 *********************************************************************/

#pragma once
#ifndef __FZ_LIBRARY_RENDERER2D_DIRECTX11__
#define __FZ_LIBRARY_RENDERER2D_DIRECTX11__

#include "CoreRef.h"
#include "../Renderer2D.h"

namespace FZLib {
	namespace DirectX11 {

		class FZLIB_API Renderer2D : public FZLib::Renderer2D
		{
		public: // Constructor and Destructor
			Renderer2D(const std::string& name);
			Renderer2D(const std::string& name, const HWND& hwnd, int width, int height);
			virtual ~Renderer2D();

		public: // Setup Devices in 2D Renderer
			virtual bool			StartUp(const HWND& hwnd, int width, int height) final;
			virtual bool			Shutdown() final;

		public: // Getter Setter Interface
			virtual std::string		GetDeviceInfo() final;

		public: // Generic Interface
			virtual void			Begin() final;
			virtual void			End() final;


		public:
			inline std::string&		GetRendererID() { return m_RendererID; }

		private:
			static int				s_RendererCount;
			inline void				SetRendererID(const std::string& name, int index) { m_RendererID = name + std::to_string(index); }

		private:
			std::string				m_RendererID;
			HWND					m_Hwnd;
			int						m_Width, m_Height;
			bool					m_Initialized;
		};

	} // namespace DirectX11
} // namespace FZLib

#endif
