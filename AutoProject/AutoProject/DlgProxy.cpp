
// DlgProxy.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "AutoProject.h"
#include "DlgProxy.h"
#include "AutoProjectDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAutoProjectDlgAutoProxy

IMPLEMENT_DYNCREATE(CAutoProjectDlgAutoProxy, CCmdTarget)

CAutoProjectDlgAutoProxy::CAutoProjectDlgAutoProxy()
{
	EnableAutomation();

	// 자동화 개체가 활성화되어 있는 동안 계속 응용 프로그램을 실행하기 위해
	//	생성자에서 AfxOleLockApp를 호출합니다.
	AfxOleLockApp();

	// 응용 프로그램의 주 창 포인터를 통해 대화 상자에 대한
	//  액세스를 가져옵니다.  프록시의 내부 포인터를 설정하여
	//  대화 상자를 가리키고 대화 상자의 후방 포인터를 이 프록시로
	//  설정합니다.
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(CAutoProjectDlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CAutoProjectDlg)))
		{
			m_pDialog = reinterpret_cast<CAutoProjectDlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CAutoProjectDlgAutoProxy::~CAutoProjectDlgAutoProxy()
{
	// 모든 개체가 OLE 자동화로 만들어졌을 때 응용 프로그램을 종료하기 위해
	// 	소멸자가 AfxOleUnlockApp를 호출합니다.
	//  이러한 호출로 주 대화 상자가 삭제될 수 있습니다.
	if (m_pDialog != nullptr)
		m_pDialog->m_pAutoProxy = nullptr;
	AfxOleUnlockApp();
}

void CAutoProjectDlgAutoProxy::OnFinalRelease()
{
	// 자동화 개체에 대한 마지막 참조가 해제되면
	// OnFinalRelease가 호출됩니다.  기본 클래스에서 자동으로 개체를 삭제합니다.
	// 기본 클래스를 호출하기 전에 개체에 필요한 추가 정리 작업을
	// 추가하세요.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CAutoProjectDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CAutoProjectDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// 참고: IID_IAutoProject에 대한 지원을 추가하여
//  VBA에서 형식 안전 바인딩을 지원합니다.
//  이 IID는 .IDL 파일에 있는 dispinterface의 GUID와 일치해야 합니다.

// {7ae1e71b-bee9-49f2-a419-103d44597bc5}
static const IID IID_IAutoProject =
{0x7ae1e71b,0xbee9,0x49f2,{0xa4,0x19,0x10,0x3d,0x44,0x59,0x7b,0xc5}};

BEGIN_INTERFACE_MAP(CAutoProjectDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CAutoProjectDlgAutoProxy, IID_IAutoProject, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in pch.h of this project
// {65dd58cb-fae8-4653-8db8-b777e9ca8a93}
IMPLEMENT_OLECREATE2(CAutoProjectDlgAutoProxy, "AutoProject.Application", 0x65dd58cb,0xfae8,0x4653,0x8d,0xb8,0xb7,0x77,0xe9,0xca,0x8a,0x93)


// CAutoProjectDlgAutoProxy 메시지 처리기
