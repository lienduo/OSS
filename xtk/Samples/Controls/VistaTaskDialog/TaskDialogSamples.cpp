#include "stdafx.h"
#include "Resource.h"

#include "TaskDialogSamples.h"

///////////////// TEST CODE ///////////////////

enum { IDC_BUTTON_STATE = 101, IDC_BUTTON_MODE, };

CProgressEffectsDialog::CProgressEffectsDialog(CWnd* pWndParent)
: CXTPTaskDialog(pWndParent)
, m_eState(PBST_NORMAL)
, m_bMarquee(TRUE)
{
	SetWindowTitle(_T("Progress Effects"));

	AddButton(_T("Cycle State"), IDC_BUTTON_STATE);
	AddButton(_T("Toggle Mode"), IDC_BUTTON_MODE);
	AddButton(_T("Change password"), IDOK);

	m_config.dwFlags |= TDF_ALLOW_DIALOG_CANCELLATION | TDF_SHOW_PROGRESS_BAR;
}

void CProgressEffectsDialog::OnDialogConstructed()
{
	UpdateMainInstruction();

	SetButtonElevationRequired(IDOK, TRUE);

}

void CProgressEffectsDialog::OnButtonClicked(int nButtonID, BOOL& bCloseDialog)
{
	switch (nButtonID)
	{
		case IDC_BUTTON_STATE: CycleState(); bCloseDialog = FALSE; break;
		case IDC_BUTTON_MODE:  ToggleMode(); bCloseDialog = FALSE; break;
	}
}

void CProgressEffectsDialog::UpdateMainInstruction()
{
	CString strText;

	switch (m_eState)
	{
	case PBST_NORMAL: strText += _T("State: Normal\n"); break;
	case PBST_PAUSED: strText += _T("State: Paused\n"); break;
	case PBST_ERROR:  strText += _T("State: Error\n");  break;
	}

	CString strTemp;
	strTemp.Format(_T("Marquee: %s"), m_bMarquee ? _T("True") : _T("False"));
	strText += strTemp;

	SetMainInstruction(strText);

	if (m_bMarquee) {
		SetMarqueeProgressBar(m_bMarquee);
		StartProgressBarMarquee(TRUE, 10);
	}
	else {
		SetProgressBarRange(0, 50);
		SetProgressBarPos(25);
	}
}

void CProgressEffectsDialog::CycleState()
{
	switch (m_eState)
	{
	case PBST_NORMAL: m_eState = PBST_PAUSED; break;
	case PBST_PAUSED: m_eState = PBST_ERROR;  break;
	case PBST_ERROR:  m_eState = PBST_NORMAL; break;
	}

	SetProgressBarState(m_eState);
	UpdateMainInstruction();
}

void CProgressEffectsDialog::ToggleMode()
{
	m_bMarquee = !m_bMarquee;
	SetMarqueeProgressBar(m_bMarquee);
	UpdateMainInstruction();
}

//////////////////////////////////////////////////////////////////////////
// CDynamicTextDialog

CDynamicTextDialog::CDynamicTextDialog(CWnd* pWndParent)
	: CXTPTaskDialog(pWndParent)
{
	SetWindowTitle(_T("Dynamic Text"));
	SetFooter(_T("Click Button to change text"));

	SetContent(_T("<a href=\"click\">Some text!</a>"));    


	AddButton(_T("Change Main text"), 100);
	AddButton(_T("Change Content text"), 101);
	AddButton(_T("Change Footer text"), 102);
	EnableMessageBoxStyle(); // Only for our Codejock Implementation

	EnableCancellation();
	EnableHyperlinks();
	SetCommonButtons(TDCBF_OK_BUTTON);
}

void CDynamicTextDialog::OnDialogConstructed()
{
}

void CDynamicTextDialog::OnButtonClicked(int nButtonID, BOOL& bCloseDialog)
{
	switch (nButtonID)
	{
		case 100: 
			SetMainInstruction(_T("New text"));   
			EnableButton(100, FALSE);
			bCloseDialog = FALSE;   
			break;

		case 101:
			SetContent(_T("<a href=\"click\">Some New text!</a>"));    
			EnableButton(101, FALSE);
			bCloseDialog = FALSE;   
			break;
		
		case 102:
			SetFooter(_T("New text"));    
			EnableButton(102, FALSE);
			bCloseDialog = FALSE;   
			break;
	}
}


class CSendFeedbackDialog : public CXTPTaskDialog
{
public:
	CSendFeedbackDialog();
	virtual ~CSendFeedbackDialog(void);

protected:
	virtual void OnNavigated();
	virtual void OnButtonClicked(int /*buttonId*/, bool& closeDialog);
	virtual void OnTimer(DWORD dwMilliSeconds, BOOL& bReset);

};

enum
{
	MaxRange = 5000
};


CSendFeedbackDialog::CSendFeedbackDialog()
{
	SetWindowTitle(_T("Error Sample (page 2)"));
	SetContent(_T("Copying your feedback"));

	EnableCancellation();
	ShowProgressBar(TRUE);
	EnableCallbackTimer();
}

CSendFeedbackDialog::~CSendFeedbackDialog(void)
{
}

void CSendFeedbackDialog::OnNavigated()
{
	SetProgressBarRange(0, MaxRange);
}

void CSendFeedbackDialog::OnButtonClicked(int /*buttonId*/, bool& closeDialog)
{
	closeDialog = true;
}

void CSendFeedbackDialog::OnTimer(DWORD dwMilliSeconds, BOOL& /*bReset*/)
{
	if (MaxRange >= dwMilliSeconds)
	{
		USES_CONVERSION;

		CString text;
		text.Format(_T("Sending... %i%%"), MulDiv(dwMilliSeconds, 100, MaxRange));
		SetMainInstruction(text);

		SetProgressBarPos(dwMilliSeconds);
		SetProgressBarRange(0, MaxRange);
	}
	else
	{
		SetMainInstruction(_T("Thanks for the feedback!"));
		SetContent(_T("Our developers will get right on that..."));
		SetProgressBarPos(MaxRange);
	}
}


//////////////////////////////////////////////////////////////////////////
//

CTimerDialog::CTimerDialog(CWnd* pWndParent)
: CXTPTaskDialog(pWndParent)
{
	SetWindowTitle(_T("Timer Sample"));
	SetMainInstruction(_T("Timer Sample"));
	SetMainIcon(TD_INFORMATION_ICON);
	AddButton(_T("Send Feedback"), 100);

	SetCommonButtons(TDCBF_OK_BUTTON | TDCBF_CANCEL_BUTTON);
	EnableCallbackTimer();
	EnableMessageBoxStyle(); // Only for our Codejock Implementation
	
	SetVerificationText(_T("Enable Timer"));
	SetVerifyCheckState();
	m_nIcon = 0;
}

void CTimerDialog::OnDialogConstructed()
{
}


void CTimerDialog::OnButtonClicked(int nButtonID, BOOL& bCloseDialog)
{
	if (nButtonID == 100)
	{
		CSendFeedbackDialog fd;
		fd.DoModal(FALSE);

		bCloseDialog = FALSE;
	}
	
}


void CTimerDialog::OnVerificationClicked(BOOL bChecked)
{
	m_bUpdateIcon = bChecked;
}


void CTimerDialog::OnTimer(DWORD dwMilliSeconds, BOOL& bReset)
{
	if (dwMilliSeconds > 700 && m_bUpdateIcon)
	{
		m_nIcon = (m_nIcon + 1) % 5;

		if (m_nIcon < 4)
		{
			SetMainIcon(m_nIcon == 0 ? TD_INFORMATION_ICON : 
				m_nIcon == 1 ? TD_WARNING_ICON : 
				m_nIcon == 2 ? TD_ERROR_ICON : TD_SHIELD_ICON);
		}
		else
		{
			SetMainIcon(AfxGetApp()->LoadIcon(IDR_MAINFRAME));
		}

		bReset = TRUE;
	}
}
