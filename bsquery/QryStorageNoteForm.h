//---------------------------------------------------------------------------

#ifndef QryStorageNoteFormH
#define QryStorageNoteFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MDIChild.h"
#include <ADODB.hpp>
#include <DB.hpp>
#include "RzButton.hpp"
#include "RzPanel.hpp"
#include <ExtCtrls.hpp>
#include "RzEdit.hpp"
#include "RzRadChk.hpp"
#include <Mask.hpp>
#include "RzDBCmbo.hpp"
#include "RzLine.hpp"
#include <DBCtrls.hpp>
#include "RzTabs.hpp"
#include "RzDBGrid.hpp"
#include <DBGrids.hpp>
#include <Grids.hpp>
#include "RzCmboBx.hpp"
#include <Buttons.hpp>
#include <ImgList.hpp>
#include <Dialogs.hpp>
#include "DBGridEh.hpp"
#include "GridsEh.hpp"
#include "RzDTP.hpp"
#include <ComCtrls.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TfrmQryStorageNote : public TfrmMDIChild
{
__published:	// IDE-managed Components
	TRzToolbar *rztlbr1;
	TRzToolButton *tlbtnQry;
	TRzToolButton *tlbtnExport;
	TRzToolButton *tlbtnExit;
	TADODataSet *dsetByNtHeader;
	TDataSource *dsrcByNtHeader;
	TADODataSet *dsetByNote;
	TDataSource *dsrcByNote;
	TADODataSet *dsetByCustomer;
	TDataSource *dsrcByCustomer;
	TADODataSet *dsetByBktype;
	TDataSource *dsrcByBktype;
	TDataSource *dsrcByPress;
	TADOStoredProc *spQryNote;
	TADODataSet *dsetCustomer;
	TDataSource *dsrcCustomer;
	TDataSource *dsrcPress;
	TADODataSet *dsetBookType;
	TDataSource *dsrcBookType;
	TDataSource *dsrcStorage;
	TADODataSet *dsetStorage;
	TDataSource *dsrcBookstack;
	TADODataSet *dsetBookstack;

	TADOQuery *qryItems;
	TImageList *ImageList1;
	TADODataSet *dsetPress;
	TADODataSet *dsetByPress;
	TDataSource *dsrcSupplier;
	TADODataSet *dsetSupplier;
	TRzToolButton *BtnAlignBottom;
	TSaveDialog *savedlg;
	TRzGroupBox *grpbx1;
	TLabel *lbl1;
	TLabel *lbl2;
	TLabel *lbl3;
	TLabel *lbl4;
	TLabel *Label36;
	TLabel *Label37;
	TRzCheckBox *chckbxStartTime;
	TRzCheckBox *chckbxEndTime;
	TRzCheckBox *chckbxBookName;
	TRzCheckBox *chckbxISBN;
	TRzCheckBox *chckbxCustomer;
	TRzCheckBox *chckbxBkstack;
	TRzCheckBox *chckbxUserDefNum;
	TRzCheckBox *chckbxPrice;
	TRzCheckBox *chckbxAuthor;
	TRzCheckBox *chckbxAmount;
	TRzCheckBox *chckbxPress;
	TRzCheckBox *chckbxType;
	TRzCheckBox *chckbxRemarks;
	TRzCheckBox *chckbxStorage;
	TRzEdit *edtBookName;
	TRzEdit *edtISBN;
	TRzEdit *edtUserDefNum;
	TRzEdit *edtAuthor;
	TRzEdit *edtPress;
	TRzEdit *edtRemarks;
	TRzEdit *edtCustomer;
	TRzNumericEdit *numedtMinPrice;
	TRzNumericEdit *numedtMinAmount;
	TRzNumericEdit *numedtMaxPrice;
	TRzNumericEdit *numedtMaxAmount;
	TRzDBLookupComboBox *dblkpcbbCustomer;
	TRzDBLookupComboBox *dblkpcbbStorage;
	TRzDBLookupComboBox *dblkpcbbBookstack;
	TRzCheckBox *cboutstorage;
	TCheckBox *cbreturnstorage;
	TRzCheckBox *cbinstorage;
	TCheckBox *cblost;
	TCheckBox *cbdamage;
	TCheckBox *chdiscount;
	TEdit *edmaxdiscount;
	TCheckBox *chstaff;
	TComboBox *cbstaff;
	TCheckBox *chnocheck;
	TCheckBox *chcheckpart;
	TCheckBox *chchecked;
	TEdit *edmindiscount;
	TCheckBox *chjytype;
	TComboBox *cbjytype;
	TRzDBLookupComboBox *dblkpcbbPress;
	TRzDateTimePicker *dtedtStart;
	TRzDateTimePicker *dtedtEnd;
	TRzCheckBox *chdanhao;
	TRzEdit *eddanhao;
	TRzPageControl *pgcntrlResult;
	TRzTabSheet *tbshtByNtHeader;
	TDBGridEh *dbgrdByNtHeader;
	TRzTabSheet *tbshtByNote;
	TDBGridEh *dbgrdByNote;
	TRzTabSheet *tbshtByCustomer;
	TDBGridEh *dbgrdByCustomer;
	TRzTabSheet *tbshtByBktype;
	TDBGridEh *dbgrdByBktype;
	TRzTabSheet *tbshtByPress;
	TDBGridEh *dbgrdByPress;
	TCheckBox *chrktype;
	TComboBox *cbrktype;
	TCheckBox *chsuptype;
	TComboBox *cbsuptype;
	TSpeedButton *SpeedButton1;
	TEdit *edtyname;
	TEdit *edpyquery;
	TCheckBox *cbcaigou;
	TPopupMenu *PopupMenu2;
	TMenuItem *N2;
	TRzCheckBox *cbghuo;
	TRzEdit *Ed_ghbh;
	void __fastcall tlbtnQryClick(TObject *Sender);
	void __fastcall chckbxBkstackClick(TObject *Sender);
	void __fastcall tlbtnExportClick(TObject *Sender);
	void __fastcall tlbtnExitClick(TObject *Sender);
	void __fastcall edtPressKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall edtBookNameChange(TObject *Sender);
	void __fastcall edtUserDefNumChange(TObject *Sender);
	void __fastcall edtISBNChange(TObject *Sender);
	void __fastcall numedtMinPriceChange(TObject *Sender);
	void __fastcall numedtMaxPriceChange(TObject *Sender);
	void __fastcall numedtMinAmountChange(TObject *Sender);
	void __fastcall numedtMaxAmountChange(TObject *Sender);
	void __fastcall edtAuthorChange(TObject *Sender);
	void __fastcall edtRemarksChange(TObject *Sender);
	void __fastcall dblkpcbbBookstackClick(TObject *Sender);
	void __fastcall dblkpcbbStorageClick(TObject *Sender);
	void __fastcall dblkpcbbCustomerClick(TObject *Sender);
	void __fastcall cbstaffClick(TObject *Sender);
	void __fastcall edmindiscountChange(TObject *Sender);
	void __fastcall edmaxdiscountChange(TObject *Sender);
	void __fastcall cbjytypeClick(TObject *Sender);
	void __fastcall BtnAlignBottomClick(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall dbgrdByNtHeaderDblClick(TObject *Sender);
	void __fastcall dbgrdByNtHeaderTitleClick(TColumnEh *Column);
	void __fastcall dbgrdByNoteTitleClick(TColumnEh *Column);
	void __fastcall dbgrdByCustomerTitleClick(TColumnEh *Column);
	void __fastcall dbgrdByBktypeTitleClick(TColumnEh *Column);
	void __fastcall dbgrdByPressTitleClick(TColumnEh *Column);
	void __fastcall dblkpcbbPressClick(TObject *Sender);
	void __fastcall eddanhaoChange(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall edpyqueryKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall cbsuptypeClick(TObject *Sender);
	void __fastcall cbrktypeClick(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall chcheckedClick(TObject *Sender);
	void __fastcall chcheckpartClick(TObject *Sender);
	void __fastcall chnocheckClick(TObject *Sender);
	void __fastcall Ed_ghbhChange(TObject *Sender);


private:	// User declarations
	void Query();
	String QueryDesic();
	String Desic,Desic1;
	void View();
public:		// User declarations
	__fastcall TfrmQryStorageNote(TComponent* Owner);
	bool __fastcall DbgridToExcel(TDBGridEh* dbg);
	virtual void Init(LandInfo* li);
	int totaldmage ,totallost ;
	long double totalchecked,totalunchecked;
	TADOConnection *fcon;
	bool danhaodisplay;
	bool discountqry,finca;
        bool master;
    int TypeID;
        bool qfsupplier;
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmQryStorageNote *frmQryStorageNote;
//---------------------------------------------------------------------------
#endif
