// DiasStatusBar.cpp : implementation file
//

#include "stdafx.h"
#include "dias.h"
#include "MainFrame.h"
#include "DiasStatusBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDiasStatusBar

CDiasStatusBar::CDiasStatusBar () {
}

CDiasStatusBar::~CDiasStatusBar () {
}


BEGIN_MESSAGE_MAP(CDiasStatusBar, CStatusBar)
	//{{AFX_MSG_MAP(CDiasStatusBar)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_COMMAND_EX_RANGE(ID_TOOLS_GEOMSCALE_1, ID_TOOLS_GEOMSCALE_999, OnSelectGeomScale)
	ON_COMMAND_EX_RANGE(ID_TOOLS_DENSSCALE_1, ID_TOOLS_DENSSCALE_999, OnSelectDensScale)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDiasStatusBar message handlers

void CDiasStatusBar::OnLButtonDown (UINT nFlags, CPoint point) {
}

void CDiasStatusBar::OnLButtonUp (UINT nFlags, CPoint point) {
}

void CDiasStatusBar::OnLButtonDblClk (UINT nFlags, CPoint point) {
	CRect rect1, rect2;
	GetItemRect (2, rect1);
	GetItemRect (3, rect2);
	if (rect1.PtInRect (point) || rect2.PtInRect (point))
		m_pMainFrame->OnEditGeomScales ();
	GetItemRect (4, rect1);
	GetItemRect (5, rect2);
	if (rect1.PtInRect (point) || rect2.PtInRect (point))
		m_pMainFrame->OnEditDensScales ();
}

void CDiasStatusBar::OnRButtonDown (UINT nFlags, CPoint point) {
	SetCapture();	
}

void CDiasStatusBar::OnRButtonUp (UINT nFlags, CPoint point) {
	if (GetCapture() != this) {
		ReleaseCapture ();
		return;
	}
	ReleaseCapture ();

	CRect rect1, rect2;
	GetItemRect (2, rect1);
	GetItemRect (3, rect2);
	CMenu menu;
	menu.CreatePopupMenu ();

	GetItemRect (2, rect1);
	GetItemRect (3, rect2);
	if (rect1.PtInRect (point) || rect2.PtInRect (point)) {
		for (uvar32_64 n = 0; n < theApp.GeomScales.GetCount (); ++n)
			menu.AppendMenu (MF_STRING | MF_ENABLED, ID_TOOLS_GEOMSCALE_1 + n, theApp.GeomScales[n].GetName() + 
			                 "\t(" + theApp.GeomScales[n].GetUnits () + ")");
		menu.CheckMenuRadioItem (0, n, theApp.GeomScales[aimActive].GetPos (), MF_BYPOSITION);
	}
	GetItemRect (4, rect1);
	GetItemRect (5, rect2);
	if (rect1.PtInRect (point) || rect2.PtInRect (point)) {
		for (uvar32_64 n = 0; n < theApp.DensScales.GetCount (); ++n)
			menu.AppendMenu (MF_STRING | MF_ENABLED, ID_TOOLS_DENSSCALE_1 + n, theApp.DensScales[n].GetName() + 
			                 "\t(" + theApp.DensScales[n].GetUnits () + ")");
		menu.CheckMenuRadioItem (0, n, theApp.DensScales[aimActive].GetPos (), MF_BYPOSITION);
	}

	GetWindowRect (rect2);
	menu.TrackPopupMenu (TPM_LEFTALIGN, point.x + rect2.left, point.y + rect2.top, this);
}

BOOL CDiasStatusBar::OnSelectGeomScale (UINT nID) { theApp.GeomScales[nID - ID_TOOLS_GEOMSCALE_1].Activate (); return (true); }
BOOL CDiasStatusBar::OnSelectDensScale (UINT nID) { theApp.DensScales[nID - ID_TOOLS_DENSSCALE_1].Activate (); return (true); }
