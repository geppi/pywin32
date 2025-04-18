// This file implements the IDocHostUIHandler Interface and Gateway for Python.
// Generated by makegw.py

#include "internet_pch.h"
#include "MsHtmHst.h"
#include "PyIDocHostUIHandler.h"

// @doc - This file contains autoduck documentation
// ---------------------------------------------------
//
// Interface Implementation

PyIDocHostUIHandler::PyIDocHostUIHandler(IUnknown *pdisp) : PyIUnknown(pdisp) { ob_type = &type; }

PyIDocHostUIHandler::~PyIDocHostUIHandler() {}

/* static */ IDocHostUIHandler *PyIDocHostUIHandler::GetI(PyObject *self)
{
    return (IDocHostUIHandler *)PyIUnknown::GetI(self);
}

// @pymethod |PyIDocHostUIHandler|ShowContextMenu|Description of ShowContextMenu.
PyObject *PyIDocHostUIHandler::ShowContextMenu(PyObject *self, PyObject *args)
{
    IDocHostUIHandler *pIDHUIH = GetI(self);
    if (pIDHUIH == NULL)
        return NULL;
    // @pyparm int|dwID||Description for dwID
    POINT pt;
    // @pyparm (int, int)|pt||Description for ppt
    // @pyparm <o PyIUnknown>|pcmdtReserved||Description for pcmdtReserved
    // @pyparm <o PyIDispatch>|pdispReserved||Description for pdispReserved
    PyObject *obpcmdtReserved;
    PyObject *obpdispReserved;
    DWORD dwID;
    IUnknown *pcmdtReserved;
    IDispatch *pdispReserved;
    if (!PyArg_ParseTuple(args, "l(ii)OO:ShowContextMenu", &dwID, &pt.x, &pt.y, &obpcmdtReserved, &obpdispReserved))
        return NULL;
    BOOL bPythonIsHappy = TRUE;
    if (!PyCom_InterfaceFromPyInstanceOrObject(obpcmdtReserved, IID_IUnknown, (void **)&pcmdtReserved,
                                               TRUE /* bNoneOK */))
        return NULL;
    if (!PyCom_InterfaceFromPyInstanceOrObject(obpdispReserved, IID_IDispatch, (void **)&pdispReserved,
                                               TRUE /* bNoneOK */)) {
        if (pcmdtReserved)
            pcmdtReserved->Release();
        return NULL;
    }
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIDHUIH->ShowContextMenu(dwID, &pt, pcmdtReserved, pdispReserved);
    if (pcmdtReserved)
        pcmdtReserved->Release();
    if (pdispReserved)
        pdispReserved->Release();
    PY_INTERFACE_POSTCALL;
    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pIDHUIH, IID_IDocHostUIHandler);
    return PyLong_FromLong(hr);
}

// @pymethod |PyIDocHostUIHandler|GetHostInfo|Description of GetHostInfo.
PyObject *PyIDocHostUIHandler::GetHostInfo(PyObject *self, PyObject *args)
{
    IDocHostUIHandler *pIDHUIH = GetI(self);
    if (pIDHUIH == NULL)
        return NULL;
    DOCHOSTUIINFO info;
    memset(&info, 0, sizeof(info));
    info.cbSize = sizeof(info);
    if (!PyArg_ParseTuple(args, ":GetHostInfo"))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIDHUIH->GetHostInfo(&info);
    PY_INTERFACE_POSTCALL;
    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pIDHUIH, IID_IDocHostUIHandler);
    return Py_BuildValue("iiNN", info.dwFlags, info.dwDoubleClick, MakeOLECHARToObj(info.pchHostCss),
                         MakeOLECHARToObj(info.pchHostNS));
}

// @pymethod |PyIDocHostUIHandler|ShowUI|Description of ShowUI.
PyObject *PyIDocHostUIHandler::ShowUI(PyObject *self, PyObject *args)
{
    IDocHostUIHandler *pIDHUIH = GetI(self);
    if (pIDHUIH == NULL)
        return NULL;
    // @pyparm int|dwID||Description for dwID
    // @pyparm <o PyIOleInPlaceActiveObject>|pActiveObject||Description for pActiveObject
    // @pyparm <o PyIOleCommandTarget>|pCommandTarget||Description for pCommandTarget
    // @pyparm <o PyIOleInPlaceFrame>|pFrame||Description for pFrame
    // @pyparm <o PyIOleInPlaceUIWindow>|pDoc||Description for pDoc
    PyObject *obpActiveObject;
    PyObject *obpCommandTarget;
    PyObject *obpFrame;
    PyObject *obpDoc;
    DWORD dwID;
    if (!PyArg_ParseTuple(args, "lOOOO:ShowUI", &dwID, &obpActiveObject, &obpCommandTarget, &obpFrame, &obpDoc))
        return NULL;
    IOleInPlaceActiveObject *pActiveObject;
    IOleCommandTarget *pCommandTarget;
    IOleInPlaceFrame *pFrame;
    IOleInPlaceUIWindow *pDoc;
    BOOL bPythonIsHappy = TRUE;
    if (bPythonIsHappy && !PyCom_InterfaceFromPyInstanceOrObject(obpActiveObject, IID_IOleInPlaceActiveObject,
                                                                 (void **)&pActiveObject, TRUE /* bNoneOK */))
        bPythonIsHappy = FALSE;
    if (bPythonIsHappy && !PyCom_InterfaceFromPyInstanceOrObject(obpCommandTarget, IID_IOleCommandTarget,
                                                                 (void **)&pCommandTarget, TRUE /* bNoneOK */))
        bPythonIsHappy = FALSE;
    if (bPythonIsHappy &&
        !PyCom_InterfaceFromPyInstanceOrObject(obpFrame, IID_IOleInPlaceFrame, (void **)&pFrame, TRUE /* bNoneOK */))
        bPythonIsHappy = FALSE;
    if (bPythonIsHappy &&
        !PyCom_InterfaceFromPyInstanceOrObject(obpDoc, IID_IOleInPlaceUIWindow, (void **)&pDoc, TRUE /* bNoneOK */))
        bPythonIsHappy = FALSE;
    if (!bPythonIsHappy)
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIDHUIH->ShowUI(dwID, pActiveObject, pCommandTarget, pFrame, pDoc);
    if (pActiveObject)
        pActiveObject->Release();
    if (pCommandTarget)
        pCommandTarget->Release();
    if (pFrame)
        pFrame->Release();
    if (pDoc)
        pDoc->Release();
    PY_INTERFACE_POSTCALL;
    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pIDHUIH, IID_IDocHostUIHandler);
    return PyLong_FromLong(hr);
}

// @pymethod |PyIDocHostUIHandler|HideUI|Description of HideUI.
PyObject *PyIDocHostUIHandler::HideUI(PyObject *self, PyObject *args)
{
    IDocHostUIHandler *pIDHUIH = GetI(self);
    if (pIDHUIH == NULL)
        return NULL;
    if (!PyArg_ParseTuple(args, ":HideUI"))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIDHUIH->HideUI();
    PY_INTERFACE_POSTCALL;
    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pIDHUIH, IID_IDocHostUIHandler);
    return PyLong_FromLong(hr);
}

// @pymethod |PyIDocHostUIHandler|UpdateUI|Description of UpdateUI.
PyObject *PyIDocHostUIHandler::UpdateUI(PyObject *self, PyObject *args)
{
    IDocHostUIHandler *pIDHUIH = GetI(self);
    if (pIDHUIH == NULL)
        return NULL;
    if (!PyArg_ParseTuple(args, ":UpdateUI"))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIDHUIH->UpdateUI();
    PY_INTERFACE_POSTCALL;
    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pIDHUIH, IID_IDocHostUIHandler);
    return PyLong_FromLong(hr);
}

// @pymethod |PyIDocHostUIHandler|EnableModeless|Description of EnableModeless.
PyObject *PyIDocHostUIHandler::EnableModeless(PyObject *self, PyObject *args)
{
    IDocHostUIHandler *pIDHUIH = GetI(self);
    if (pIDHUIH == NULL)
        return NULL;
    // @pyparm int|fEnable||Description for fEnable
    BOOL fEnable;
    if (!PyArg_ParseTuple(args, "i:EnableModeless", &fEnable))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIDHUIH->EnableModeless(fEnable);
    PY_INTERFACE_POSTCALL;
    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pIDHUIH, IID_IDocHostUIHandler);
    return PyLong_FromLong(hr);
}

// @pymethod |PyIDocHostUIHandler|OnDocWindowActivate|Description of OnDocWindowActivate.
PyObject *PyIDocHostUIHandler::OnDocWindowActivate(PyObject *self, PyObject *args)
{
    IDocHostUIHandler *pIDHUIH = GetI(self);
    if (pIDHUIH == NULL)
        return NULL;
    // @pyparm int|fActivate||Description for fActivate
    BOOL fActivate;
    if (!PyArg_ParseTuple(args, "i:OnDocWindowActivate", &fActivate))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIDHUIH->OnDocWindowActivate(fActivate);
    PY_INTERFACE_POSTCALL;
    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pIDHUIH, IID_IDocHostUIHandler);
    return PyLong_FromLong(hr);
}

// @pymethod |PyIDocHostUIHandler|OnFrameWindowActivate|Description of OnFrameWindowActivate.
PyObject *PyIDocHostUIHandler::OnFrameWindowActivate(PyObject *self, PyObject *args)
{
    IDocHostUIHandler *pIDHUIH = GetI(self);
    if (pIDHUIH == NULL)
        return NULL;
    // @pyparm int|fActivate||Description for fActivate
    BOOL fActivate;
    if (!PyArg_ParseTuple(args, "i:OnFrameWindowActivate", &fActivate))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIDHUIH->OnFrameWindowActivate(fActivate);
    PY_INTERFACE_POSTCALL;
    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pIDHUIH, IID_IDocHostUIHandler);
    return PyLong_FromLong(hr);
}

// @pymethod |PyIDocHostUIHandler|ResizeBorder|Description of ResizeBorder.
PyObject *PyIDocHostUIHandler::ResizeBorder(PyObject *self, PyObject *args)
{
    IDocHostUIHandler *pIDHUIH = GetI(self);
    if (pIDHUIH == NULL)
        return NULL;
    RECT border;
    // @pyparm (int, int, int, int)|prcBorder||Description for prcBorder
    // @pyparm <o PyIOleInPlaceUIWindow>|pUIWindow||Description for pUIWindow
    // @pyparm int|fRameWindow||Description for fRameWindow
    PyObject *obpUIWindow;
    IOleInPlaceUIWindow *pUIWindow;
    BOOL fRameWindow;
    if (!PyArg_ParseTuple(args, "(iiii)Oi:ResizeBorder", &border.left, &border.top, &border.right, &border.bottom,
                          &obpUIWindow, &fRameWindow))
        return NULL;
    if (!PyCom_InterfaceFromPyInstanceOrObject(obpUIWindow, IID_IOleInPlaceUIWindow, (void **)&pUIWindow,
                                               TRUE /* bNoneOK */))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIDHUIH->ResizeBorder(&border, pUIWindow, fRameWindow);
    if (pUIWindow)
        pUIWindow->Release();
    PY_INTERFACE_POSTCALL;
    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pIDHUIH, IID_IDocHostUIHandler);
    return PyLong_FromLong(hr);
}

// @pymethod |PyIDocHostUIHandler|TranslateAccelerator|Description of TranslateAccelerator.
PyObject *PyIDocHostUIHandler::TranslateAccelerator(PyObject *self, PyObject *args)
{
    IDocHostUIHandler *pIDHUIH = GetI(self);
    if (pIDHUIH == NULL)
        return NULL;
    MSG msg;
    PyObject *oblpMsg;
    // @pyparm <o PyLPMSG>|lpMsg||Description for lpMsg
    // @pyparm <o PyIID>|pguidCmdGroup||Description for pguidCmdGroup
    // @pyparm int|nCmdID||Description for nCmdID
    PyObject *obpguidCmdGroup;
    IID guidCmdGroup;
    DWORD nCmdID;
    if (!PyArg_ParseTuple(args, "OOl:TranslateAccelerator", &oblpMsg, &obpguidCmdGroup, &nCmdID))
        return NULL;
    BOOL bPythonIsHappy = TRUE;
    if (bPythonIsHappy && !PyWinObject_AsMSG(oblpMsg, &msg))
        bPythonIsHappy = FALSE;
    if (!PyWinObject_AsIID(obpguidCmdGroup, &guidCmdGroup))
        bPythonIsHappy = FALSE;
    if (!bPythonIsHappy)
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIDHUIH->TranslateAccelerator(&msg, &guidCmdGroup, nCmdID);
    PY_INTERFACE_POSTCALL;
    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pIDHUIH, IID_IDocHostUIHandler);
    return PyLong_FromLong(hr);
}

// @pymethod |PyIDocHostUIHandler|GetOptionKeyPath|Description of GetOptionKeyPath.
PyObject *PyIDocHostUIHandler::GetOptionKeyPath(PyObject *self, PyObject *args)
{
    IDocHostUIHandler *pIDHUIH = GetI(self);
    if (pIDHUIH == NULL)
        return NULL;
    // @pyparm int|dw||Description for dw
    LPOLESTR pchKey;
    DWORD dw;
    if (!PyArg_ParseTuple(args, "l:GetOptionKeyPath", &dw))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIDHUIH->GetOptionKeyPath(&pchKey, dw);
    PY_INTERFACE_POSTCALL;
    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pIDHUIH, IID_IDocHostUIHandler);
    PyObject *pyretval = MakeOLECHARToObj(pchKey);
    CoTaskMemFree(pchKey);
    return pyretval;
}

// @pymethod |PyIDocHostUIHandler|GetDropTarget|Description of GetDropTarget.
PyObject *PyIDocHostUIHandler::GetDropTarget(PyObject *self, PyObject *args)
{
    IDocHostUIHandler *pIDHUIH = GetI(self);
    if (pIDHUIH == NULL)
        return NULL;
    // @pyparm <o PyIDropTarget>|pDropTarget||Description for pDropTarget
    PyObject *obpDropTarget;
    IDropTarget *pDropTarget;
    IDropTarget *ppDropTarget;
    if (!PyArg_ParseTuple(args, "O:GetDropTarget", &obpDropTarget))
        return NULL;
    BOOL bPythonIsHappy = TRUE;
    if (bPythonIsHappy && !PyCom_InterfaceFromPyInstanceOrObject(obpDropTarget, IID_IDropTarget, (void **)&pDropTarget,
                                                                 TRUE /* bNoneOK */))
        bPythonIsHappy = FALSE;
    if (!bPythonIsHappy)
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIDHUIH->GetDropTarget(pDropTarget, &ppDropTarget);
    if (pDropTarget)
        pDropTarget->Release();
    PY_INTERFACE_POSTCALL;
    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pIDHUIH, IID_IDocHostUIHandler);
    return PyCom_PyObjectFromIUnknown(ppDropTarget, IID_IDropTarget, FALSE);
}

// @pymethod |PyIDocHostUIHandler|GetExternal|Description of GetExternal.
PyObject *PyIDocHostUIHandler::GetExternal(PyObject *self, PyObject *args)
{
    IDocHostUIHandler *pIDHUIH = GetI(self);
    if (pIDHUIH == NULL)
        return NULL;
    IDispatch *ppDispatch;
    if (!PyArg_ParseTuple(args, ":GetExternal"))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIDHUIH->GetExternal(&ppDispatch);
    PY_INTERFACE_POSTCALL;
    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pIDHUIH, IID_IDocHostUIHandler);
    return PyCom_PyObjectFromIUnknown(ppDispatch, IID_IDispatch, FALSE);
}

// @pymethod |PyIDocHostUIHandler|TranslateUrl|Description of TranslateUrl.
PyObject *PyIDocHostUIHandler::TranslateUrl(PyObject *self, PyObject *args)
{
    IDocHostUIHandler *pIDHUIH = GetI(self);
    if (pIDHUIH == NULL)
        return NULL;
    // @pyparm int|dwTranslate||Description for dwTranslate
    // @pyparm <o unicode>|pchURLIn||Description for pchURLIn
    PyObject *obpchURLIn;
    DWORD dwTranslate;
    OLECHAR *pchURLIn;
    OLECHAR *pchURLOut = 0;
    if (!PyArg_ParseTuple(args, "lO:TranslateUrl", &dwTranslate, &obpchURLIn))
        return NULL;
    if (!PyWinObject_AsWCHAR(obpchURLIn, &pchURLIn))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIDHUIH->TranslateUrl(dwTranslate, pchURLIn, &pchURLOut);
    PY_INTERFACE_POSTCALL;
    PyWinObject_FreeWCHAR(pchURLIn);
    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pIDHUIH, IID_IDocHostUIHandler);
    PyObject *pyretval = MakeOLECHARToObj(pchURLOut);
    CoTaskMemFree(pchURLOut);
    return pyretval;
}

// @pymethod |PyIDocHostUIHandler|FilterDataObject|Description of FilterDataObject.
PyObject *PyIDocHostUIHandler::FilterDataObject(PyObject *self, PyObject *args)
{
    IDocHostUIHandler *pIDHUIH = GetI(self);
    if (pIDHUIH == NULL)
        return NULL;
    // @pyparm <o PyIDataObject>|pDO||Description for pDO
    PyObject *obpDO;
    IDataObject *pDO;
    IDataObject *ppDORet;
    if (!PyArg_ParseTuple(args, "O:FilterDataObject", &obpDO))
        return NULL;
    if (!PyCom_InterfaceFromPyInstanceOrObject(obpDO, IID_IDataObject, (void **)&pDO, TRUE /* bNoneOK */))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIDHUIH->FilterDataObject(pDO, &ppDORet);
    if (pDO)
        pDO->Release();
    PY_INTERFACE_POSTCALL;
    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pIDHUIH, IID_IDocHostUIHandler);
    return PyCom_PyObjectFromIUnknown(ppDORet, IID_IDataObject, FALSE);
}

// @object PyIDocHostUIHandler|Description of the interface
static struct PyMethodDef PyIDocHostUIHandler_methods[] = {
    {"ShowContextMenu", PyIDocHostUIHandler::ShowContextMenu,
     1},                                                   // @pymeth ShowContextMenu|Description of ShowContextMenu
    {"GetHostInfo", PyIDocHostUIHandler::GetHostInfo, 1},  // @pymeth GetHostInfo|Description of GetHostInfo
    {"ShowUI", PyIDocHostUIHandler::ShowUI, 1},            // @pymeth ShowUI|Description of ShowUI
    {"HideUI", PyIDocHostUIHandler::HideUI, 1},            // @pymeth HideUI|Description of HideUI
    {"UpdateUI", PyIDocHostUIHandler::UpdateUI, 1},        // @pymeth UpdateUI|Description of UpdateUI
    {"EnableModeless", PyIDocHostUIHandler::EnableModeless, 1},  // @pymeth EnableModeless|Description of EnableModeless
    {"OnDocWindowActivate", PyIDocHostUIHandler::OnDocWindowActivate,
     1},  // @pymeth OnDocWindowActivate|Description of OnDocWindowActivate
    {"OnFrameWindowActivate", PyIDocHostUIHandler::OnFrameWindowActivate,
     1},  // @pymeth OnFrameWindowActivate|Description of OnFrameWindowActivate
    {"ResizeBorder", PyIDocHostUIHandler::ResizeBorder, 1},  // @pymeth ResizeBorder|Description of ResizeBorder
    {"TranslateAccelerator", PyIDocHostUIHandler::TranslateAccelerator,
     1},  // @pymeth TranslateAccelerator|Description of TranslateAccelerator
    {"GetOptionKeyPath", PyIDocHostUIHandler::GetOptionKeyPath,
     1},  // @pymeth GetOptionKeyPath|Description of GetOptionKeyPath
    {"GetDropTarget", PyIDocHostUIHandler::GetDropTarget, 1},  // @pymeth GetDropTarget|Description of GetDropTarget
    {"GetExternal", PyIDocHostUIHandler::GetExternal, 1},      // @pymeth GetExternal|Description of GetExternal
    {"TranslateUrl", PyIDocHostUIHandler::TranslateUrl, 1},    // @pymeth TranslateUrl|Description of TranslateUrl
    {"FilterDataObject", PyIDocHostUIHandler::FilterDataObject,
     1},  // @pymeth FilterDataObject|Description of FilterDataObject
    {NULL}};

PyComTypeObject PyIDocHostUIHandler::type("PyIDocHostUIHandler", &PyIUnknown::type, sizeof(PyIDocHostUIHandler),
                                          PyIDocHostUIHandler_methods, GET_PYCOM_CTOR(PyIDocHostUIHandler));
// ---------------------------------------------------
//
// Gateway Implementation
STDMETHODIMP PyGDocHostUIHandler::ShowContextMenu(
    /* [in] */ DWORD dwID,
    /* [in] */ POINT *ppt,
    /* [in] */ IUnknown *pcmdtReserved,
    /* [in] */ IDispatch *pdispReserved)
{
    PY_GATEWAY_METHOD;
    return InvokeViaPolicy("ShowContextMenu", NULL, "l(ii)NO", dwID, ppt->x, ppt->y,
                           PyCom_PyObjectFromIUnknown(pcmdtReserved, IID_IUnknown, TRUE),
                           PyCom_PyObjectFromIUnknown(pdispReserved, IID_IDispatch, TRUE));
}

STDMETHODIMP PyGDocHostUIHandler::GetHostInfo(
    /* [out][in] */ DOCHOSTUIINFO *pInfo)
{
    PY_GATEWAY_METHOD;
    PyObject *result;
    HRESULT hr = InvokeViaPolicy("GetHostInfo", &result, "");
    if (FAILED(hr))
        return hr;
    // Process the Python results, and convert back to the real params
    PyObject *obhostcss, *obhostns;
    if (!PyArg_ParseTuple(result, "iiOO", &pInfo->dwFlags, &pInfo->dwDoubleClick, &obhostcss, &obhostns) ||
        !PyWinObject_AsTaskAllocatedWCHAR(obhostcss, &pInfo->pchHostCss, TRUE) ||
        !PyWinObject_AsTaskAllocatedWCHAR(obhostns, &pInfo->pchHostNS, TRUE))
        hr = MAKE_PYCOM_GATEWAY_FAILURE_CODE("GetHostInfo");
    Py_DECREF(result);
    return hr;
}

STDMETHODIMP PyGDocHostUIHandler::ShowUI(
    /* [in] */ DWORD dwID,
    /* [in] */ IOleInPlaceActiveObject *pActiveObject,
    /* [in] */ IOleCommandTarget *pCommandTarget,
    /* [in] */ IOleInPlaceFrame *pFrame,
    /* [in] */ IOleInPlaceUIWindow *pDoc)
{
    PY_GATEWAY_METHOD;
    PyObject *obpActiveObject;
    PyObject *obpCommandTarget;
    PyObject *obpFrame;
    PyObject *obpDoc;
    obpActiveObject = PyCom_PyObjectFromIUnknown(pActiveObject, IID_IOleInPlaceActiveObject, TRUE);
    obpCommandTarget = PyCom_PyObjectFromIUnknown(pCommandTarget, IID_IOleCommandTarget, TRUE);
    obpFrame = PyCom_PyObjectFromIUnknown(pFrame, IID_IOleInPlaceFrame, TRUE);
    obpDoc = PyCom_PyObjectFromIUnknown(pDoc, IID_IOleInPlaceUIWindow, TRUE);
    HRESULT hr = InvokeViaPolicy("ShowUI", NULL, "lOOOO", dwID, obpActiveObject, obpCommandTarget, obpFrame, obpDoc);
    Py_XDECREF(obpActiveObject);
    Py_XDECREF(obpCommandTarget);
    Py_XDECREF(obpFrame);
    Py_XDECREF(obpDoc);
    return hr;
}

STDMETHODIMP PyGDocHostUIHandler::HideUI(void)
{
    PY_GATEWAY_METHOD;
    return InvokeViaPolicy("HideUI", NULL);
}

STDMETHODIMP PyGDocHostUIHandler::UpdateUI(void)
{
    PY_GATEWAY_METHOD;
    return InvokeViaPolicy("UpdateUI", NULL);
}

STDMETHODIMP PyGDocHostUIHandler::EnableModeless(
    /* [in] */ BOOL fEnable)
{
    PY_GATEWAY_METHOD;
    return InvokeViaPolicy("EnableModeless", NULL, "i", fEnable);
}

STDMETHODIMP PyGDocHostUIHandler::OnDocWindowActivate(
    /* [in] */ BOOL fActivate)
{
    PY_GATEWAY_METHOD;
    return InvokeViaPolicy("OnDocWindowActivate", NULL, "i", fActivate);
}

STDMETHODIMP PyGDocHostUIHandler::OnFrameWindowActivate(
    /* [in] */ BOOL fActivate)
{
    PY_GATEWAY_METHOD;
    return InvokeViaPolicy("OnFrameWindowActivate", NULL, "i", fActivate);
}

STDMETHODIMP PyGDocHostUIHandler::ResizeBorder(
    /* [in] */ LPCRECT prcBorder,
    /* [in] */ IOleInPlaceUIWindow *pUIWindow,
    /* [in] */ BOOL fRameWindow)
{
    PY_GATEWAY_METHOD;
    return InvokeViaPolicy("ResizeBorder", NULL, "(iiii)Ni", prcBorder->left, prcBorder->top, prcBorder->right,
                           prcBorder->bottom, PyCom_PyObjectFromIUnknown(pUIWindow, IID_IOleInPlaceUIWindow, TRUE),
                           fRameWindow);
}

STDMETHODIMP PyGDocHostUIHandler::TranslateAccelerator(
    /* [in] */ LPMSG lpMsg,
    /* [in] */ const GUID *pguidCmdGroup,
    /* [in] */ DWORD nCmdID)
{
    PY_GATEWAY_METHOD;
    return InvokeViaPolicy("TranslateAccelerator", NULL, "NNl", PyWinObject_FromMSG(lpMsg),
                           PyWinObject_FromIID(*pguidCmdGroup), nCmdID);
}

STDMETHODIMP PyGDocHostUIHandler::GetOptionKeyPath(
    /* [out] */ LPOLESTR *pchKey,
    /* [in] */ DWORD dw)
{
    PY_GATEWAY_METHOD;
    PyObject *result;
    HRESULT hr = InvokeViaPolicy("GetOptionKeyPath", &result, "l", dw);
    if (FAILED(hr))
        return hr;
    // Process the Python results, and convert back to the real params
    if (!PyWinObject_AsTaskAllocatedWCHAR(result, pchKey, FALSE))
        hr = MAKE_PYCOM_GATEWAY_FAILURE_CODE("GetOptionKeyPath");
    Py_DECREF(result);
    return hr;
}

STDMETHODIMP PyGDocHostUIHandler::GetDropTarget(
    /* [in] */ IDropTarget *pDropTarget,
    /* [out] */ IDropTarget **ppDropTarget)
{
    PY_GATEWAY_METHOD;
    if (ppDropTarget == NULL)
        return E_POINTER;
    PyObject *obpDropTarget;
    obpDropTarget = PyCom_PyObjectFromIUnknown(pDropTarget, IID_IDropTarget, TRUE);
    PyObject *result;
    HRESULT hr = InvokeViaPolicy("GetDropTarget", &result, "O", obpDropTarget);
    Py_XDECREF(obpDropTarget);
    if (FAILED(hr))
        return hr;
    // Process the Python results, and convert back to the real params
    if (!PyCom_InterfaceFromPyInstanceOrObject(result, IID_IDropTarget, (void **)ppDropTarget, TRUE /* bNoneOK */))
        hr = MAKE_PYCOM_GATEWAY_FAILURE_CODE("GetDropTarget");
    Py_DECREF(result);
    return hr;
}

STDMETHODIMP PyGDocHostUIHandler::GetExternal(
    /* [out] */ IDispatch **ppDispatch)
{
    PY_GATEWAY_METHOD;
    if (ppDispatch == NULL)
        return E_POINTER;
    PyObject *result;
    HRESULT hr = InvokeViaPolicy("GetExternal", &result);
    if (FAILED(hr))
        return hr;
    // Process the Python results, and convert back to the real params
    if (!PyCom_InterfaceFromPyInstanceOrObject(result, IID_IDispatch, (void **)ppDispatch, TRUE /* bNoneOK */))
        hr = MAKE_PYCOM_GATEWAY_FAILURE_CODE("GetExternal");
    Py_DECREF(result);
    return hr;
}

STDMETHODIMP PyGDocHostUIHandler::TranslateUrl(
    /* [in] */ DWORD dwTranslate,
    /* [in] */ OLECHAR *pchURLIn,
    /* [out] */ OLECHAR **ppchURLOut)
{
    PY_GATEWAY_METHOD;
    if (ppchURLOut == NULL)
        return E_POINTER;
    PyObject *obpchURLIn;
    obpchURLIn = MakeOLECHARToObj(pchURLIn);
    PyObject *result;
    HRESULT hr = InvokeViaPolicy("TranslateUrl", &result, "lO", dwTranslate, obpchURLIn);
    Py_XDECREF(obpchURLIn);
    if (FAILED(hr))
        return hr;
    // Process the Python results, and convert back to the real params
    if (!PyWinObject_AsTaskAllocatedWCHAR(result, ppchURLOut, FALSE))
        hr = MAKE_PYCOM_GATEWAY_FAILURE_CODE("TranslateUrl");
    Py_DECREF(result);
    return hr;
}

STDMETHODIMP PyGDocHostUIHandler::FilterDataObject(
    /* [in] */ IDataObject *pDO,
    /* [out] */ IDataObject **ppDORet)
{
    PY_GATEWAY_METHOD;
    if (ppDORet == NULL)
        return E_POINTER;
    PyObject *obpDO;
    obpDO = PyCom_PyObjectFromIUnknown(pDO, IID_IDataObject, TRUE);
    PyObject *result;
    HRESULT hr = InvokeViaPolicy("FilterDataObject", &result, "O", obpDO);
    Py_XDECREF(obpDO);
    if (FAILED(hr))
        return hr;
    if (!PyCom_InterfaceFromPyInstanceOrObject(result, IID_IDataObject, (void **)ppDORet, TRUE /* bNoneOK */))
        hr = MAKE_PYCOM_GATEWAY_FAILURE_CODE("FilterDataObject");
    Py_DECREF(result);
    return hr;
}
