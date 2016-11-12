//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ClearingProvidForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIChild"
#pragma link "RzButton"
#pragma link "RzGrids"
#pragma link "RzLabel"
#pragma link "RzPanel"
#pragma link "DBGridEh"
#pragma link "GridsEh"
#pragma resource "*.dfm"
TfrmClearingProvid *frmClearingProvid;
//---------------------------------------------------------------------------
__fastcall TfrmClearingProvid::TfrmClearingProvid(TComponent* Owner)
	: TfrmMDIChild(Owner)
{        m_module = MTData;
	dtp1->Date= Date();
	dtp2->Date= Date();
	dtp3->Date= Date();
	dtp4->Date= Date();
	dtp5->Date= Date();
	dtp6->Date= Date();
	this->WindowState = wsMaximized ;
}
//---------------------------------------------------------------------------

void TfrmClearingProvid::Init(TApplication* app, TADOConnection* con)
{          TfrmMDIChild::Init(app, con);

	fcon = con;
	/*	  if (dsCUS->Active) {
				dsCUS->Active=false;
		  }
		  String sql="select ID,Name from CUST_CustomerInfo where Type= 1 order by name" ;

		 dsCUS->CommandText=sql;
		 dsCUS->Active=true;

		 dsCUS->First();
		 while (!dsCUS->Eof) {
		 cbbType->AddItem(dsCUS->FieldByName("Name")->AsString ,(TObject*)dsCUS->FieldByName("ID")->AsInteger );
		 dsCUS->Next();
		 } */
	query->Connection = fcon;
	TADOQuery * aq;
	aq = new TADOQuery(this);
	aq->Connection = con;
	AnsiString sql;
	sql = "select ID,Name from CUST_CustomerInfo where Type= 1 order by name ";
    aq->Close();
	aq->SQL->Clear();
	aq->SQL->Add(sql);
	aq->Open();
	while (!aq->Eof) {
		 cbbType->AddItem(aq->FieldByName("Name")->AsString ,(TObject*)aq->FieldByName("ID")->AsInteger );
		 aq->Next();
	}

	aq->Close();
	aq->SQL->Clear();
	aq->SQL->Add("select * from sys_bsset where name ='xiaoshudian'");
	aq->Open();
	storageformat =  "￥" + aq->FieldByName("bk")->AsAnsiString ;
	aq->Close();
	aq->SQL->Clear();
	aq->SQL->Add("select * from sys_bsset where name ='retailxiaoshudian'");
	aq->Open();
	retaiformat =  "￥" + aq->FieldByName("bk")->AsAnsiString ;
	aq->Close();
	aq->SQL->Clear();
	aq->SQL->Add("select * from sys_bsset where name ='salexiaoshudian'");
	aq->Open();
	saleformat =  "￥" + aq->FieldByName("bk")->AsAnsiString ;

	sql = "select ID,Name from SYS_StorageInfo ";
	aq->Close();
	aq->SQL->Clear();
	aq->SQL->Add(sql);
	aq->Open();
	while (!aq->Eof )
	{
		cbstorage->AddItem(aq->FieldByName("Name")->AsString ,(TObject*)aq->FieldByName("ID")->AsInteger );
		aq->Next();
	}
	cbstorage->ItemIndex = cbstorage->Items->IndexOfObject((TObject*)stgid);
	sql = "select Master from SYS_StorageInfo where id = " + IntToStr(stgid);
	aq->Close();
	aq->SQL->Clear();
	aq->SQL->Add(sql);
	aq->Open();
	if (aq->FieldByName("Master")->AsBoolean ) {
		chstorage->Enabled = true;
		cbstorage->Enabled = true;
	}
	else
	{
		chstorage->Enabled = false;
		cbstorage->Enabled = false;
	}

	delete aq;
	/*DBGridEh1->Columns->Items[3]->DisplayFormat =  storageformat;
	DBGridEh1->Columns->Items[4]->DisplayFormat =  storageformat;
	DBGridEh1->Columns->Items[6]->DisplayFormat =  storageformat;
	DBGridEh1->Columns->Items[7]->DisplayFormat =  storageformat;
	DBGridEh1->Columns->Items[9]->DisplayFormat =  retaiformat;
	DBGridEh1->Columns->Items[10]->DisplayFormat =  retaiformat;
	DBGridEh1->Columns->Items[12]->DisplayFormat =  saleformat;
	DBGridEh1->Columns->Items[13]->DisplayFormat =  saleformat;
	DBGridEh1->Columns->Items[14]->DisplayFormat =  storageformat;
	DBGridEh1->Columns->Items[15]->DisplayFormat =  storageformat;
	DBGridEh1->Columns->Items[3]->Footer->DisplayFormat =  storageformat;
	DBGridEh1->Columns->Items[4]->Footer->DisplayFormat =  storageformat;
	DBGridEh1->Columns->Items[6]->Footer->DisplayFormat =  storageformat;
	DBGridEh1->Columns->Items[7]->Footer->DisplayFormat =  storageformat;
	DBGridEh1->Columns->Items[9]->Footer->DisplayFormat =  retaiformat;
	DBGridEh1->Columns->Items[10]->Footer->DisplayFormat =  retaiformat;
	DBGridEh1->Columns->Items[12]->Footer->DisplayFormat =  saleformat;
	DBGridEh1->Columns->Items[13]->Footer->DisplayFormat =  saleformat;
	DBGridEh1->Columns->Items[14]->Footer->DisplayFormat =  storageformat;
	DBGridEh1->Columns->Items[15]->Footer->DisplayFormat =  storageformat;  */
}

void __fastcall TfrmClearingProvid::RzToolButton1Click(TObject *Sender)
{
	if (cbbType->Text == "") {
		Query();
	}
	else
	{
		int supplierid;
		try {
			supplierid = int(cbbType->Items->Objects[cbbType->ItemIndex]);
		} catch (...) {
			return ;
		}
		Query(supplierid);
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmClearingProvid::FormClose(TObject *Sender, TCloseAction &Action)

{
	Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TfrmClearingProvid::RzToolButton3Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmClearingProvid::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if (Shift.Contains(ssCtrl)&& Key == 70 ) {    //查询
		RzToolButton1->Click();
	}
	if (Shift.Contains(ssCtrl)&& Key == 78 ) {    //最小化
		BtnAlignBottom->Click();
	}
	if (Shift.Contains(ssCtrl)&& Key == 81 ) {    //退出
		RzToolButton3->Click();
	}
	if (Shift.Contains(ssCtrl)&& Key ==90) {   //恢复窗口
		WindowState = wsNormal  ;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmClearingProvid::BtnAlignBottomClick(TObject *Sender)
{
	WindowState = wsMinimized ;
}
//---------------------------------------------------------------------------


void __fastcall TfrmClearingProvid::SpeedButton1Click(TObject *Sender)
{
	Query();
}
//---------------------------------------------------------------------------
void TfrmClearingProvid::Query(int supplierid)

{
	AnsiString sql;
	sql = "EXEC USP_jisuan_analysis 0,";
	sql = sql + IntToStr(supplierid) + ",";
	if (cbstart->Checked) {
		sql = sql + "'" + DateToStr(dtp1->Date) + "',";
		sql = sql + "'" + DateToStr(dtp2->Date) + "',";
	}
	else
	{
		sql = sql + "null,null,";
	}
	if (cb1->Checked) {
		sql = sql + "'" + DateToStr(dtp3->Date) + "',";
		sql = sql + "'" + DateToStr(dtp4->Date) + "',";
	}
	else
	{
		sql = sql + "null,null,";
	}
	if (cb2->Checked) {
		sql = sql + "'" + DateToStr(dtp5->Date) + "',";
		sql = sql + "'" + DateToStr(dtp6->Date) + "',";
	}
	else
	{
		sql = sql + "null,null,";
	}

	if (chstorage->Checked) {
    	int fstgid;
		try {
			fstgid = (int)cbstorage->Items->Objects[cbstorage->ItemIndex];
		} catch (...) {
                        ShowMsg(Handle ,"请选择正确的店号！",3);
			return;
		}
		sql = sql + IntToStr(fstgid);
	}
	else
	{
    	sql = sql + "null";
	}

	query->Close();
	query->SQL->Clear();
	query->SQL->Add(sql);
	try {
		query->Open() ;
	} catch (Exception &E) {
		//ShowMessage(E.Message);
	}
}
//---------------------------------------------------------------------------
void TfrmClearingProvid::Query()

{
	AnsiString sql;
	sql = "EXEC USP_jisuan_analysis 0,null,";
	if (cbstart->Checked) {
		sql = sql + "'" + DateToStr(dtp1->Date) + "',";
		sql = sql + "'" + DateToStr(dtp2->Date) + "',";
	}
	else
	{
		sql = sql + "null,null,";
	}
	if (cb1->Checked) {
		sql = sql + "'" + DateToStr(dtp3->Date) + "',";
		sql = sql + "'" + DateToStr(dtp4->Date) + "',";
	}
	else
	{
		sql = sql + "null,null,";
	}
	if (cb2->Checked) {
		sql = sql + "'" + DateToStr(dtp5->Date) + "',";
		sql = sql + "'" + DateToStr(dtp6->Date) + "',";
	}
	else
	{
		sql = sql + "null,null,";
	}

	if (chstorage->Checked) {
    	int fstgid;
		try {
			fstgid = (int)cbstorage->Items->Objects[cbstorage->ItemIndex];
		} catch (...) {
                        ShowMsg(Handle ,"请选择正确的店号！",3);
			return;
		}
		sql = sql + IntToStr(fstgid);
	}
	else
	{
    	sql = sql + "null";
	}

	query->Close();
	query->SQL->Clear();
	query->SQL->Add(sql);
	try {
		query->Open();
	} catch (Exception &E) {
		//ShowMessage(E.Message);
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmClearingProvid::DBGridEh1TitleClick(TColumnEh *Column)
{
	if (query->IsEmpty() ) {
    	return;
	}
	AnsiString qusort;
	qusort =  Column->FieldName + " ASC";
	if (query->Sort == "") {
		query->Sort =  Column->FieldName + " ASC";
	}
	else if (query->Sort == qusort) {
		query->Sort =  Column->FieldName + " DESC";
	}
	else
	{
		query->Sort =  Column->FieldName + " ASC";
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmClearingProvid::dtp1Change(TObject *Sender)
{
	cbstart->Checked = true;
}
//---------------------------------------------------------------------------


