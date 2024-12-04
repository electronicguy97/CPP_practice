

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 12:14:07 2038
 */
/* Compiler settings for AutoProject.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __AutoProject_h_h__
#define __AutoProject_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAutoProject_FWD_DEFINED__
#define __IAutoProject_FWD_DEFINED__
typedef interface IAutoProject IAutoProject;

#endif 	/* __IAutoProject_FWD_DEFINED__ */


#ifndef __AutoProject_FWD_DEFINED__
#define __AutoProject_FWD_DEFINED__

#ifdef __cplusplus
typedef class AutoProject AutoProject;
#else
typedef struct AutoProject AutoProject;
#endif /* __cplusplus */

#endif 	/* __AutoProject_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __AutoProject_LIBRARY_DEFINED__
#define __AutoProject_LIBRARY_DEFINED__

/* library AutoProject */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_AutoProject;

#ifndef __IAutoProject_DISPINTERFACE_DEFINED__
#define __IAutoProject_DISPINTERFACE_DEFINED__

/* dispinterface IAutoProject */
/* [uuid] */ 


EXTERN_C const IID DIID_IAutoProject;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("7ae1e71b-bee9-49f2-a419-103d44597bc5")
    IAutoProject : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IAutoProjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAutoProject * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAutoProject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAutoProject * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAutoProject * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAutoProject * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAutoProject * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAutoProject * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IAutoProjectVtbl;

    interface IAutoProject
    {
        CONST_VTBL struct IAutoProjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAutoProject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAutoProject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAutoProject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAutoProject_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAutoProject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAutoProject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAutoProject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IAutoProject_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_AutoProject;

#ifdef __cplusplus

class DECLSPEC_UUID("65dd58cb-fae8-4653-8db8-b777e9ca8a93")
AutoProject;
#endif
#endif /* __AutoProject_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


