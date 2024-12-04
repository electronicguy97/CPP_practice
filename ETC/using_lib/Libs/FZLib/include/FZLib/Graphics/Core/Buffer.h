/*********************************************************************
 * @file   Buffer.h
 * @brief  ���������� ���Ǵ� ���� ����
 * 
 * @author FuJiGraphics
 * @date   2024/03/08
 *********************************************************************/

#pragma once
#ifndef __FZ_LIBRARY_BUFFER__
#define __FZ_LIBRARY_BUFFER__

#include "../gcr.h"

namespace FZLib {

	/*********************************************************************
	 * @brief		Vertex Buffer class 
	 * @details		�������� �����ϴ� ���� Ŭ����
	 *********************************************************************/
	class FZLIB_API VertexBuffer 
	{
	public: // Create Vertex Buffer Instance
		/**
		 * @brief		���� ���� ����
		 * @details	
		 * - �� ������ ���� ���۸� �����մϴ�.
		 * - ���ۿ� ���� �׷��� API ������ ������ Ÿ�ӿ� �����˴ϴ�.
		 * @param[in]	vertices : ������ ���� �迭
		 * @param[in]	size : ������ ���� �迭�� ����Ʈ ũ��
		 * @return		VertexBuffer* : ������ ���� ������ ��ü ������
		 */
		static VertexBuffer* Create(float* vertices, unsigned int size);
		/**
		 * @brief		�� ���� ���� ����
		 * @details		���ۿ� ���� �׷��� API ������ ������ Ÿ�ӿ� �����˴ϴ�.
		 * @param[in]	size : ���� ������ ����Ʈ ũ��
		 * @return		VertexBuffer* : ������ ���� ������ ��ü ������
		 */
		static VertexBuffer* Create(unsigned int size);

	public: // Vertex Buffer Interface
		/**
		 * @brief	���� ���۸� ���ε��մϴ�.
		 * @return	bool : ���ε��� ���
		 */
		virtual bool Bind() = 0;
		/**
		 * @brief	���� ������ ���ε��� �����մϴ�.
		 * @return	bool : ���ε� ���� ���
		 */
		virtual bool UnBind() = 0;
		/**
		 * @brief	���� �����͸� ���ۿ� �߰��մϴ�.
		 * @return	bool : ��� (true/false)
		 */
		virtual bool AddVertices(float* vertices) = 0;
	};

	/*********************************************************************
	 * @brief		Index Buffer class
	 * @details		������ ���� �ε������� �����ϴ� ���� Ŭ����
	 *********************************************************************/
	class FZLIB_API IndexBuffer
	{
	public: // Create Index Buffer Instance
		/**
		 * @brief		�ε��� ���� ����
		 * @details
		 * - �ε����� ���� ���۸� �����մϴ�.
		 * - �ε����� ���� �׷��� API ������ ������ Ÿ�ӿ� �����˴ϴ�.
		 * @param[in]	indices : ������ �ε��� �迭
		 * @param[in]	count : �ε����� ����
		 * @return		IndexBuffer* : ������ �ε��� ������ ��ü ������
		 */
		static IndexBuffer* Create(unsigned int* indices, unsigned int count);
		/**
		 * @brief		�� �ε��� ���� ����
		 * @details		���ۿ� ���� �׷��� API ������ ������ Ÿ�ӿ� �����˴ϴ�.
		 * @param[in]	size : �ε��� ������ ����Ʈ ũ��
		 * @return		IndexBuffer* : ������ ���� ������ ��ü ������
		 */
		static IndexBuffer* Create(unsigned int count);
		
	public: // Index Buffer Interface
		/**
		 * @brief	���� ���۸� ���ε��մϴ�.
		 * @return	bool : ���ε��� ���
		 */
		virtual bool Bind() = 0;
		/**
		 * @brief	���� ������ ���ε��� �����մϴ�.
		 * @return	bool : ���ε� ���� ���
		 */
		virtual bool UnBind() = 0;
		/**
		 * @brief	���� �����͸� ���ۿ� �߰��մϴ�.
		 * @return	bool : ��� (true/false)
		 */
		virtual bool AddIndices(unsigned int* indices) = 0;

	};

} // namespace FZLib

#endif
