/*********************************************************************
 * @file   Renderer2D.h
 * @brief  2D �������� ���� ������
 * 
 * @author FuJiGraphics
 * @date   2024/03/08
 *********************************************************************/

#pragma once
#ifndef __FZ_LIBRARY_RENDERER2D__
#define __FZ_LIBRARY_RENDERER2D__

#include "../gcr.h"

namespace FZLib {

	class FZLIB_API Renderer2D
	{
	public: // Create 2D Renderer Instance
		static Renderer2D* Create(const std::string& name);

	public: // Setup Devices in 2D Renderer
		virtual bool	StartUp(const HWND& hwnd, int width, int height) = 0;
		virtual bool	Shutdown() = 0;

	public: // Getting metadata and Setting Metadata
		virtual std::string GetDeviceInfo() = 0;

	public: // Generic Interface
		virtual void	Begin() = 0;
		virtual void	End() = 0;
	};

} // namespace FZLib

#endif
