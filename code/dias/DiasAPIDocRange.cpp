#include "stdafx.h"
#include "dias.h"
#include "DiasAPIDocRange.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDiasAPIDocs

CDiasAPIDocRange::CDiasAPIDocRange () {
	CaImAPIRange<CStorageDoc>::CaImAPIRange<CStorageDoc> ();
}

CDiasAPIDocRange::~CDiasAPIDocRange () {                           
	CaImAPIRange<CStorageDoc>::~CaImAPIRange<CStorageDoc> ();
}

