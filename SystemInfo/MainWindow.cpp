#include "stdafx.h"
#include "MainWindow.h"
#include <string>

#define INFO_BUFFER_SIZE 512

static TCHAR const* OS_WINXP = L"Windows XP Or Greater version %u.%u";


MainWindow::MainWindow()
{
	
}

LRESULT MainWindow::OnInit(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	m_EditControl.Attach(GetDlgItem(IDC_EDIT1));
	m_EditControl2.Attach(GetDlgItem(IDC_EDIT2));
	m_ListBox.Attach(GetDlgItem(IDC_LIST1));
	m_ComboBox.Attach(GetDlgItem(IDC_COMBO1));

	m_ComboBox.InsertString(0, L" + ");
	m_ComboBox.InsertString(1, L" - ");
	m_ComboBox.InsertString(2, L" x ");
	m_ComboBox.InsertString(3, L" : ");

	return 0;
}

LRESULT MainWindow::OnInputConfirm(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
	WCHAR windowText1[1024];
	WCHAR windowText2[1024];
	GetDlgItemText(IDC_EDIT1, windowText1, 1024);
	GetDlgItemText(IDC_EDIT2, windowText2, 1024);
	
	//Convert string to double
	numbers_arr.push_back(std::stod(windowText1));
	numbers_arr.push_back(std::stod(windowText2));	
	
	//----------------------
	int operand_index = m_ComboBox.GetCurSel(); //get current selection of operands
	if (operand_index == 0) {
		double result = numbers_arr[0] + numbers_arr[1];
		numbers_arr.push_back(result);

		//Convert double to TCHAR
		std::string d_str1 = std::to_string(numbers_arr[0]) + " + " + std::to_string(numbers_arr[1]); //a  & b
		std::string d_str2 = " = " + std::to_string(numbers_arr[2]); //= c

		TCHAR char_input1[1024]; //a  & b
		TCHAR char_input2[1024]; //= c
		_tcscpy_s(char_input1, CA2T(d_str1.c_str()));
		_tcscpy_s(char_input2, CA2T(d_str2.c_str()));

		m_ListBox.InsertString(0, char_input1);
		m_ListBox.InsertString(1, char_input2);
	}
	if (operand_index == 1) {
		double result = numbers_arr[0] - numbers_arr[1];
		numbers_arr.push_back(result);

		//Convert double to TCHAR
		std::string d_str1 = std::to_string(numbers_arr[0]) + " - " + std::to_string(numbers_arr[1]); //a  & b
		std::string d_str2 = " = " + std::to_string(numbers_arr[2]); //= c

		TCHAR char_input1[1024]; //a  & b
		TCHAR char_input2[1024]; //= c
		_tcscpy_s(char_input1, CA2T(d_str1.c_str()));
		_tcscpy_s(char_input2, CA2T(d_str2.c_str()));

		m_ListBox.InsertString(0, char_input1);
		m_ListBox.InsertString(1, char_input2);
	}
	if (operand_index == 2) {
		double result = numbers_arr[0] * numbers_arr[1];
		numbers_arr.push_back(result);

		//Convert double to TCHAR
		std::string d_str1 = std::to_string(numbers_arr[0]) + " x " + std::to_string(numbers_arr[1]); //a  & b
		std::string d_str2 = " = " + std::to_string(numbers_arr[2]); //= c

		TCHAR char_input1[1024]; //a  & b
		TCHAR char_input2[1024]; //= c
		_tcscpy_s(char_input1, CA2T(d_str1.c_str()));
		_tcscpy_s(char_input2, CA2T(d_str2.c_str()));

		m_ListBox.InsertString(0, char_input1);
		m_ListBox.InsertString(1, char_input2);
	}
	if (operand_index == 3) {
		double result = numbers_arr[0] / numbers_arr[1];
		numbers_arr.push_back(result);

		//Convert double to TCHAR
		std::string d_str1 = std::to_string(numbers_arr[0]) + " : " + std::to_string(numbers_arr[1]); //a  & b
		std::string d_str2 = " = " + std::to_string(numbers_arr[2]); //= c

		TCHAR char_input1[1024]; //a  & b
		TCHAR char_input2[1024]; //= c
		_tcscpy_s(char_input1, CA2T(d_str1.c_str()));
		_tcscpy_s(char_input2, CA2T(d_str2.c_str()));

		m_ListBox.InsertString(0, char_input1);
		m_ListBox.InsertString(1, char_input2);
	}

	return 0;
}

LRESULT MainWindow::OnResetClick(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
	numbers_arr.clear();

	m_EditControl.SetSel(0, 100);
	m_EditControl.ReplaceSel(L"");
	m_EditControl2.SetSel(0, 100);
	m_EditControl2.ReplaceSel(L"");

	m_ComboBox.ShowDropDown(FALSE);//reset to 1st item of combo box

	m_ListBox.DeleteString(0);
	m_ListBox.DeleteString(0);
	m_ListBox.DeleteString(0);

	return 0;
}


LRESULT MainWindow::OnClose(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	DestroyWindow();
	return 0;
}

LRESULT MainWindow::OnCloseButtonClick(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
	DestroyWindow();
	return 0;
}


LRESULT MainWindow::OnDestroy(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	PostQuitMessage(0);
	return 0;
}