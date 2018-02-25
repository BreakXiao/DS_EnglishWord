; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLexSet
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DS_English.h"
LastPage=0

ClassCount=10
Class1=CDS_EnglishApp
Class2=CDS_EnglishDoc
Class3=CDS_EnglishView
Class4=CMainFrame

ResourceCount=7
Resource1=IDD_FORMVIEW (English (U.S.))
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Class6=CInformation
Resource3=IDD_LexSet
Class7=CWordDo
Resource4=IDD_ABOUTBOX
Class8=CWordAdd
Resource5=IDD_DIALWordAdd
Class9=CLexSet
Resource6=IDD_DIALWordDo
Class10=CMODELSET
Resource7=IDD_DIALOG1

[CLS:CDS_EnglishApp]
Type=0
HeaderFile=DS_English.h
ImplementationFile=DS_English.cpp
Filter=N

[CLS:CDS_EnglishDoc]
Type=0
HeaderFile=DS_EnglishDoc.h
ImplementationFile=DS_EnglishDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=CDS_EnglishDoc

[CLS:CDS_EnglishView]
Type=0
HeaderFile=DS_EnglishView.h
ImplementationFile=DS_EnglishView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CDS_EnglishView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=ID_FILE_SAVE




[CLS:CAboutDlg]
Type=0
HeaderFile=DS_English.cpp
ImplementationFile=DS_English.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_FILE_OPEN
Command11=ID_FILE_SAVE
Command12=ID_ADD_WORD
Command13=ID_ADDMANY
Command14=ID_Change
Command15=ID_VIEW_TOOLBAR
Command16=ID_VIEW_STATUS_BAR
Command17=ID_WINDOW_SPLIT
Command18=ID_APP_ABOUT
CommandCount=18

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_FORMVIEW (English (U.S.))]
Type=1
Class=CInformation
ControlCount=9
Control1=IDC_FalseBUTTON,button,1342242816
Control2=IDC_RightBUTTON,button,1342242816
Control3=IDC_BUTTON3,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_WordID,edit,1350633600
Control8=IDC_FalseNum,edit,1350633600
Control9=IDC_RightNum,edit,1350633600

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[CLS:CInformation]
Type=0
HeaderFile=Information.h
ImplementationFile=Information.cpp
BaseClass=CFormView
Filter=D
LastObject=CInformation
VirtualFilter=VWC

[CLS:CWordDo]
Type=0
HeaderFile=WordDo.h
ImplementationFile=WordDo.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_ADD_WORD
VirtualFilter=dWC

[DLG:IDD_DIALWordDo]
Type=1
Class=CWordDo
ControlCount=17
Control1=IDCANCEL,button,1342242816
Control2=IDC_STATIC,static,1342308352
Control3=IDC_LIST1,listbox,1352728833
Control4=IDC_STATIC,button,1342177287
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_ENGMEAN,edit,1350631552
Control10=IDC_CHIMEAN,edit,1350631552
Control11=IDC_FALSE_NUM,edit,1350633600
Control12=IDC_RIGHT_NUM,edit,1350633600
Control13=IDC_ADD_WORD,button,1342242816
Control14=IDC_DELETE_WORD,button,1342242816
Control15=IDC_STATIC,static,1342308352
Control16=IDC_WordID,edit,1350633600
Control17=IDC_LexName,edit,1350633600

[DLG:IDD_DIALWordAdd]
Type=1
Class=CWordAdd
ControlCount=3
Control1=IDCANCEL,button,1342242816
Control2=IDC_EDIT2,edit,1352728708
Control3=IDC_ADD,button,1342242816

[CLS:CWordAdd]
Type=0
HeaderFile=WordAdd.h
ImplementationFile=WordAdd.cpp
BaseClass=CDialog
Filter=D
LastObject=CWordAdd
VirtualFilter=dWC

[DLG:IDD_LexSet]
Type=1
Class=CLexSet
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_LexName,edit,1350631552
Control5=IDC_UPSET_ID,button,1342242816

[CLS:CLexSet]
Type=0
HeaderFile=LexSet.h
ImplementationFile=LexSet.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_UPSET_ID
VirtualFilter=dWC

[DLG:IDD_DIALOG1]
Type=1
Class=CMODELSET
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_COMBO1,combobox,1344339970
Control6=IDC_STATIC,static,1342308352
Control7=IDC_COMBO2,combobox,1344339970

[CLS:CMODELSET]
Type=0
HeaderFile=MODELSET.h
ImplementationFile=MODELSET.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_COMBO2
VirtualFilter=dWC

