//---------------------------------------------------------------------------

#ifndef QryMemberOrderH
#define QryMemberOrderH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "QryStorageNoteForm.h"
#include "RzButton.hpp"
#include "RzDBCmbo.hpp"
#include "RzDBGrid.hpp"
#include "RzEdit.hpp"
#include "RzLine.hpp"
#include "RzPanel.hpp"
#include "RzRadChk.hpp"
#include "RzTabs.hpp"
#include <ADODB.hpp>
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
#include <ImgList.hpp>
#include <Dialogs.hpp>
#include "DBGridEh.hpp"
#include "GridsEh.hpp"
#include "RzDTP.hpp"
#include <ComCtrls.hpp>
#include <Buttons.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TfrmQryMemberOrder : public TfrmQryStorageNote
{
__published:	// IDE-managed Components
	TRzCheckBox *chckbx1;
	TRzDBLookupComboBox *dblkpcbbSupplierID;
	TEdit *edsuplier;
	void __fastcall tlbtnQryClick(TObject *Sender);
	void __fastcall edtPressKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall tlbtnExportClick(TObject *Sender);
	void __fastcall edsuplierKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall edtCustomerKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall dbgrdByNtHeaderTitleClick(TColumnEh *Column);
	void __fastcall dbgrdByNoteTitleClick(TColumnEh *Column);
	void __fastcall dbgrdByCustomerTitleClick(TColumnEh *Column);
	void __fastcall dbgrdByBktypeTitleClick(TColumnEh *Column);
	void __fastcall dbgrdByPressTitleClick(TColumnEh *Column);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall edpyqueryKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall dblkpcbbSupplierIDClick(TObject *Sender);
	void __fastcall dbgrdByNtHeaderDblClick(TObject *Sender);

private:	// User declarations
	void Query();
	String QueryDesic();
	String Desic,Desic1;
public:		// User declarations
	__fastcall TfrmQryMemberOrder(TComponent* Owner);
	bool __fastcall DbgridToExcel(TDBGridEh* dbg);
	void Init(LandInfo* li);
	void View();
	bool cbpr,prf;
	int TypeID;
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmQryMemberOrder *frmQryMemberOrder;
//---------------------------------------------------------------------------
#endif
