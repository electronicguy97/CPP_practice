/*********************************************************************
 * @file   Dx11_Renderer2D.h
 * @brief  DirectX11 ���� ���Ǵ� ���ҽ� ���� ���� Ŭ����
 *
 * @author FuJiGraphics
 * @date   2024/03/12
 *********************************************************************/

#pragma once
#ifndef __FZ_LIBRARY_RESOURCE_GENERATOR_DIRECTX11__
#define	__FZ_LIBRARY_RESOURCE_GENERATOR_DIRECTX11__

#include "../CoreRef.h"
#include "../../../gcr.h"
#include "../Device.h"

namespace FZLib {
	namespace DirectX11 {
		namespace Helpers {
			/**
			 * @brief		DirectX11 ���ҽ��� �����ϴ� ���� Ŭ����
			 * @details		����ϱ� ���ؼ��� �ν��Ͻ� ���� �� device �� device context�� �����ؾ� �մϴ�.
			 */
			class FZLIB_API ResourceGenerator
			{
				//-----------------------------------------------------------------------------
				// Static functions
			public:
				/**
				 * @brief		ResourceGenerator�� �ν��Ͻ��� ��ȯ
				 * @param[in]	device	: device�� ��ü
				 * @return		ResourceGenerator&	: ResourceGenerator�� ��ü ���۷���
				 */
				static ResourceGenerator&	GetInstance(Device& device);
				//-----------------------------------------------------------------------------


				//-----------------------------------------------------------------------------
				// Constructor and destructor
			public:
				ResourceGenerator() = default;
				~ResourceGenerator() = default;
				//-----------------------------------------------------------------------------


				//-----------------------------------------------------------------------------
				// Export Interfaces
			public:
				/**
				 * @brief	Vertex Buffer�� �����մϴ�.
				 * @param[in]	size		: ������ ������ ����Ʈ ũ��
				 * @param[in]	dynamic		: CPU���� �������� �� �� �ִ� ���� Ÿ������ ����
				 * @param[in]	pData		: ���� ������
				 * @return	ID3D11Buffer	: ������ ���� ���� (���� ��, nullptr�� ��ȯ)
				 */
				ID3D11Buffer*		CreateVertexBuffer(FZuint size, FZbool dynamic, FZbool streamout, D3D11_SUBRESOURCE_DATA* pData);
				/**
				 * @brief	Static Vertex Buffer�� �����մϴ�.
				 * @details	
				 * - static �Ӽ����� �ش� ���۴� �Ҵ� ���� ������ �Ұ��մϴ�.
				 * @param[in]	vertices	: ���ۿ� ���� float ���� ������ �迭
				 * @param[in]	size		: vertices�� �� ����Ʈ ũ��
				 * @param[in]	streamOut	: ��Ʈ�� ��� Ȱ��ȭ ����
				 * @return	ID3D11Buffer	: ������ ���� ���� (���� ��, nullptr�� ��ȯ)
				 */
				ID3D11Buffer*		CreateStaticVertexBuffer(FZfloat* vertices, FZuint size, FZbool streamOut = false);
				/**
				 * @brief	Dynamic Vertex Buffer�� �����մϴ�.
				 * @details	
				 * - dynamic �Ӽ����� �ش� ���۴� �Ҵ� �� ���� �����մϴ�.
				 * @param[in]	size		: ������ ������ ����Ʈ ũ��
				 * @param[in]	streamout	: ��Ʈ�� ��� Ȱ��ȭ ����
				 * @return	ID3D11Buffer	: ������ ���� ���� (���� ��, nullptr�� ��ȯ)
				 */
				ID3D11Buffer*		CreateDynamicVertexBuffer(FZuint size, FZbool streamOut = false);



				/**
				 * @brief	Index Buffer�� �����մϴ�.
				 * @param[in]	size		: ������ ������ ����Ʈ ũ��
				 * @param[in]	dynamic		: CPU���� �������� �� �� �ִ� ���� Ÿ������ ����
				 * @param[in]	pData		: �ε��� ������
				 * @return	ID3D11Buffer	: ������ �ε��� ���� (���� ��, nullptr�� ��ȯ)
				 */
				ID3D11Buffer*		CreateIndexBuffer(FZuint size, FZbool dynamic, D3D11_SUBRESOURCE_DATA* pData = nullptr);
				/**
				 * @brief	Static Index Buffer�� �����մϴ�.
				 * @details
				 * - static �Ӽ����� �ش� ���۴� �Ҵ� ���� ������ �Ұ��մϴ�.
				 * @param[in]	indices		: ���ۿ� ���� unsigned int index ������ �迭
				 * @param[in]	size		: index�� �� ����Ʈ ũ��
				 * @return	ID3D11Buffer	: ������ �ε��� ���� (���� ��, nullptr�� ��ȯ)
				 */
				ID3D11Buffer*		CreateStaticIndexBuffer(FZuint* indices, FZuint size);
				/**
				 * @brief	Dynamic Index Buffer�� �����մϴ�.
				 * @details
				 * - dynamic �Ӽ����� �ش� ���۴� �Ҵ� �� ���� �����մϴ�.
				 * @param[in]	size		: ������ ������ ����Ʈ ũ��
				 * @return	ID3D11Buffer	: ������ �ε��� ���� (���� ��, nullptr�� ��ȯ)
				 */
				ID3D11Buffer*		CreateDynamicIndexBuffer(FZuint size);



				/**
				 * @brief	��� ���۸� ����
				 * @param[in]	size		: ������ ������ ����Ʈ ũ��
				 * @param[in]	dynamic		: CPU���� �������� �� �� �ִ� ���� Ÿ������ ����
				 * @param[in]	CPUupdates	: CPU ���� Ȱ��ȭ ����
				 * @return	ID3D11Buffer	: ������ ��� ���� (���� ��, nullptr�� ��ȯ)
				 */
				ID3D11Buffer*		CreateConstantBuffer(FZuint size, FZbool dynamic, FZbool CPUupdates, D3D11_SUBRESOURCE_DATA* pData = nullptr);
				/**
				 * @brief	������ ���۸� ����
				 * @param[in]	size		: ������ ������ ����Ʈ ũ��
				 * @param[in]	dynamic		: CPU���� �������� �� �� �ִ� ���� Ÿ������ ����
				 * @param[in]	CPUupdates	: CPU ���� Ȱ��ȭ ����
				 * @return	ID3D11Buffer	: ������ ��� ���� (���� ��, nullptr�� ��ȯ)
				 */
				ID3D11Buffer*		CreateStructuredBuffer(FZuint count, FZuint structSize, FZbool CPUwritable, FZbool GPUwritable, D3D11_SUBRESOURCE_DATA* pData = nullptr);

				ID3D11ShaderResourceView*	CreateBufferShaderResourceView(ID3D11Resource* pResource);
				ID3D11UnorderedAccessView*	CreateBufferUnorderedAccessView(ID3D11Resource* pResource);
				//-----------------------------------------------------------------------------




				//-----------------------------------------------------------------------------
				// static variables
			private:
				static std::unique_ptr<ResourceGenerator>		s_pInstance;
				static ID3D11Device*							s_pCurrUsedDevice;
				static ID3D11DeviceContext*						s_pCurrUsedContext;

				//-----------------------------------------------------------------------------
			}; // class ResourceGenerator

		} // namespace Helper
	} // namespace DirectX11
} // namespace FZLib

#endif
