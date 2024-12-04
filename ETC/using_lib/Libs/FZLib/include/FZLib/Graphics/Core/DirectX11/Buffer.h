/*********************************************************************
 * @file   Dx11_Buffer.h
 * @brief  ���������� ���Ǵ� ���� ����
 *
 * @author FuJiGraphics
 * @date   2024/03/08
 *********************************************************************/

#pragma once
#ifndef __FZ_LIBRARY_BUFFER_DIRECTX11__
#define __FZ_LIBRARY_BUFFER_DIRECTX11__

#include "CoreRef.h"
#include "../Buffer.h"

namespace FZLib {
	namespace DirectX11 {
		/*********************************************************************
		 * @brief		Vertex Buffer class
		 * @details		�������� �����ϴ� ���� Ŭ����
		 *********************************************************************/
		class FZLIB_API VertexBuffer : public FZLib::VertexBuffer
		{
			using SubResource = std::shared_ptr<D3D11_MAPPED_SUBRESOURCE>;
		public:
			/**
			 * @brief		���� ������ ������
			 * @param[in]	size : ���� ������ ����Ʈ ũ��
			 */
			VertexBuffer(unsigned int size);
			virtual ~VertexBuffer();

		public: // Vertex Buffer Interface
			/**
			 * @brief	���� ���۸� ���ε��մϴ�.
			 * @return	bool : ���ε��� ���
			 */
			virtual bool Bind() final;
			/**
			 * @brief	���� ������ ���ε��� �����մϴ�.
			 * @return	bool : ���ε� ���� ���
			 */
			virtual bool UnBind() final;
			/**
			 * @brief	���� �����͸� ���ۿ� �߰��մϴ�.
			 * @return	bool : ��� (true/false)
			 */
			virtual bool AddVertices(float* vertices) final;

		public:
			void ResetSubResource(SubResource& subres);

		private:
			ID3D11Buffer*			m_VertexBuffer;
			SubResource				m_MappedResource;
		};

		/*********************************************************************
		 * @brief		Index Buffer class
		 * @details		������ ���� �ε������� �����ϴ� ���� Ŭ����
		 *********************************************************************/
		class FZLIB_API IndexBuffer : public FZLib::IndexBuffer
		{
			using SubResource = std::shared_ptr<D3D11_MAPPED_SUBRESOURCE>;
		public: // Create Index Buffer Instance
			IndexBuffer(unsigned int size);
			virtual ~IndexBuffer();

		public: // Index Buffer Interface
			/**
			 * @brief	�ε��� ���۸� ���ε��մϴ�.
			 * @return	bool : ���ε��� ���
			 */
			virtual bool Bind() final;
			/**
			 * @brief	�ε��� ������ ���ε��� �����մϴ�.
			 * @return	bool : ���ε� ���� ���
			 */
			virtual bool UnBind() final;
			/**
			 * @brief	�ε��� �����͸� ���ۿ� �߰��մϴ�.
			 * @return	bool : ��� (true/false)
			 */
			virtual bool AddIndices(unsigned int* indices) final;

		public:
			void ResetSubResource(SubResource& subres);

		private:
			ID3D11Buffer*		m_IndexBuffer;
			SubResource			m_MappedResource;

		};
	} // namespace DirectX11
} // namespace FZLib

#endif