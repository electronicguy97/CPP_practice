/*********************************************************************
 * @file   gcr.h
 * @brief  �׷��Ƚ� ���̺귯������ ���������� ���Ǵ� ���ҽ� ����
 *
 * @author FuJiGraphics
 * @date   2024/03/08
 *********************************************************************/

#pragma once
#ifndef __FZ_LIBRARY_GRAPHICS_COMMON_RESOURCES_H_
#define __FZ_LIBRARY_GRAPHICS_COMMON_RESOURCES_H_

 // standard library headers
#include <iostream>
#include <string>
#include <vector>
#include <map>

// DLL Export Macros
#ifdef FZLIB_USAGE_DLL
	#ifdef FZLIB_EXPORTS
		#define FZLIB_API __declspec(dllexport)
	#else
		#define FZLIB_API __declspec(dllimport)
	#endif
#else
	#define FZLIB_API
#endif

namespace FZLib {

	// Custom type info
	using	FZuint		= std::uint32_t;
	using	FZint		= std::int32_t;
	using	FZfloat		= std::float_t;
	using	FZbool		= bool;
	enum {  FZtrue		= true
		 ,	FZfalse		= false
	}; 

	/**
	 * @brief	�������� ���� RGB ����ü
	 * @details	����� ��� float Ÿ��
	 */
	struct RGB {
		float R, G, B;
	};

	/**
	 * @brief	�������� ���� RGBA ����ü
	 * @details ����� ��� float Ÿ��
	 */
	struct RGBA {
		float R, G, B, A;
	};

	/**
	 * @brief	���� ��ü�� ��缭
	 * @details GraphicsAPIŸ�� ��	
	 */
	struct Specification
	{
		// Graphics API Types
		inline static const std::string&&
			OpenGL		= "OpenGL",
			Vulkan		= "Vulkan",
			DirectX11	= "DirectX11",
			DirectX12	= "DirectX12",
			WebGPU		= "WebGPU",
			None		= "None";
	};
}

#endif
