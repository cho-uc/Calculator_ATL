#pragma once

#include "stdafx.h"
#include "Resource.h"

/**
* This class is the GUI part of the program. It contains a MSG
* map, a DDX map and handles for Buttons, ListViewControls, etc.
*
*/

class MainWindow : public CDialogImpl<MainWindow, CEdit>
{
protected:
	CEditT m_EditControl;
	CEditT m_EditControl2;
	CListBox m_ListBox;
	CComboBox m_ComboBox;

	std::vector<double> numbers_arr;

public:
    MainWindow();

    enum {IDD = IDD_MAIN_DIALOG};

    BEGIN_MSG_MAP(MainWindow)
        MESSAGE_HANDLER(WM_INITDIALOG, OnInit);
        MESSAGE_HANDLER(WM_CLOSE, OnClose);
        MESSAGE_HANDLER(WM_DESTROY, OnDestroy);
		COMMAND_ID_HANDLER(IDD_LIST_OF_SERVICES_DLG2, OnInputConfirm);
		COMMAND_ID_HANDLER(IDD_LIST_RESET, OnResetClick);
        COMMAND_HANDLER(IDC_CLOSE, BN_CLICKED, OnCloseButtonClick);
    END_MSG_MAP()

    LRESULT OnInit(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnClose(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnDestroy(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnCloseButtonClick(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
	LRESULT OnInputConfirm(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
	LRESULT OnResetClick(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);

};