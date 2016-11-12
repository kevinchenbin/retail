//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitDiaobo.h"
#include "QryNoteCodeForm.h"
#include "SetNotesForm.h"
#include "selectdiaobook.h"
#include "..\bsadmin\bookQuery.h"
#include "..\bsadmin\retailbookup.h"
#include "Unitpsquery.h"
#include "unitpsinorder.h"
//#include "bookprint.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RzButton"
#pragma link "RzPanel"
#pragma link "RzDBEdit"
#pragma link "RzEdit"
#pragma link "RpBase"
#pragma link "RpCon"
#pragma link "RpConDS"
#pragma link "RpDefine"
#pragma link "RpRave"
#pragma link "RpSystem"
#pragma link "frxClass"
#pragma link "frxDBSet"
#pragma resource "*.dfm"
#include "selectbook.h"
#include "mytrace.h"
#include "Addsyslog.h"
Tfrmdiaobo *frmdiaobo;
//---------------------------------------------------------------------------
__fastcall Tfrmdiaobo::Tfrmdiaobo(TComponent* Owner,TADOConnection *cn,int stgid,int userid,int type)
	:  TfrmMDIChild(Owner)
	, m_catalogSearchMode(0)
	, m_bsmode(BSUnknown)
	, m_opmode(OPUnknown)

{
	fstgid = stgid;
	aq->Connection = cn;
	aqprint->Connection = cn;
	fuserid = userid;
	aquery->Connection = cn;
	query->Connection = cn;
	spqryntheader1->Connection = cn;
	spqryntheader->Connection = cn;
	cmdaddnote->Connection = cn;
	cmdDelNote->Connection = cn;
	cmdBatchDelNote->Connection = cn;
	cmdUpdateNote->Connection = cn;
	cmdshenhe->Connection = cn;
	cmdBatchUpdateNote->Connection = cn;
	aqhd->Connection = cn;
	adospcopy->Connection = cn;
        spnewdanhao->Connection = cn;
	con = cn;
	AnsiString sql;
	sql = "select * from SYS_BSSET where name = 'peisongsametishi'";
	aq->Close();
	aq->SQL->Clear();
	aq->SQL->Add(sql);
	aq->Open();
	sametishi  = aq->FieldByName("value")->AsBoolean ;

	sql = "select name  from SYS_StorageInfo where id = " + IntToStr(fstgid);
	aq->Close();
	aq->SQL->Clear();
	aq->SQL->Add(sql);
	aq->Open();
	stogName = aq->FieldByName("name")->AsString ;
        operationstateA = 0;//是否点入库
        operationstateB = 0;//是否点出库
        labtitle->Caption = stogName;
	ftype = type;
	if (ftype == 1) {  //主动配送

		ReadData();
	}else if (ftype == 0)   //申请配送
	{
		Label18->Caption = "--申请配送";
		this->Caption = "申请配送";
		ReadData();

	}


	m_catalogSearchMode = 1;
	dtpdata->Date = Date();
	if (type !=2) {
		BtnNew->Click();
	}
	if (ftype == 1) {
		DBGrid1->Columns->Items[6]->Visible = false;
                DBGrid1->Columns->Items[7]->Visible = true;
		BtnOK->Visible = false;
		BtnBullets->Visible = true;
                Label11->Caption = "配送数量";
	}
	else
	{
		DBGrid1->Columns->Items[6]->Visible = true;
                DBGrid1->Columns->Items[7]->Visible = false;
		BtnOK->Visible = true;
		BtnBullets->Visible = false;
                Label11->Caption = "申请数量";

	}
}
//---------------------------------------------------------------------------
void Tfrmdiaobo::ReadData()
{
	AnsiString sql;
	if (ftype == 1) {          //主动配送
		sql = "select ID,Name from SYS_StorageInfo " ;
		aq->Close();
		aq->SQL ->Clear();
		aq->SQL->Add(sql);
		aq->Open();
		while (!aq->Eof )
		{
			cboutstorage->AddItem(aq->FieldByName("Name")->AsString ,(TObject*)aq->FieldByName("ID")->AsInteger );
			aq->Next();
		}

		cboutstorage->ItemIndex = cboutstorage->Items->IndexOfObject((TObject*)fstgid);

		sql = "select ID,Name from SYS_User where id = " + IntToStr(fuserid);
		aq->Close();
		aq->SQL ->Clear();
		aq->SQL->Add(sql);
		aq->Open();
		edopname->Text = aq->FieldByName("Name")->AsAnsiString ;

		sql = "select ID,Name from SYS_StorageInfo ";
		aq->Close();
		aq->SQL ->Clear();
		aq->SQL->Add(sql);
		aq->Open();
		while (!aq->Eof )
		{
			cbinstorage->AddItem(aq->FieldByName("Name")->AsString ,(TObject*)aq->FieldByName("ID")->AsInteger );
			aq->Next();
		}

		sql = "select * from BS_ZN_DiaoNoteHeader where (outstorage = " + IntToStr(fstgid) + " or instorage = " + IntToStr(fstgid) + ") and type = 1  ";

		aqhd->Close();
		aqhd->SQL ->Clear();
		aqhd->SQL ->Add(sql);
		aqhd->Open();

	} else
	{
		sql = "select ID,Name from SYS_StorageInfo " ;
		aq->Close();
		aq->SQL ->Clear();
		aq->SQL->Add(sql);
		aq->Open();
		while (!aq->Eof )
		{
			cboutstorage->AddItem(aq->FieldByName("Name")->AsString ,(TObject*)aq->FieldByName("ID")->AsInteger );
			aq->Next();
		}
		sql = "select ID,Name from SYS_User where id = " + IntToStr(fuserid);
		aq->Close();
		aq->SQL ->Clear();
		aq->SQL->Add(sql);
		aq->Open();
		edopname->Text = aq->FieldByName("Name")->AsAnsiString ;

		sql = "select ID,Name from SYS_StorageInfo " ;
		aq->Close();
		aq->SQL ->Clear();
		aq->SQL->Add(sql);
		aq->Open();
		while (!aq->Eof )
		{
			cbinstorage->AddItem(aq->FieldByName("Name")->AsString ,(TObject*)aq->FieldByName("ID")->AsInteger );
			aq->Next();
		}

		cbinstorage->ItemIndex = cbinstorage->Items->IndexOfObject((TObject*)fstgid);
		instorage = fstgid;
   //		instorage = aq->FieldByName("ID")->AsInteger ;
		sql = "select ID,Name from STK_BookstackInfo where StgID = " + IntToStr(fstgid);
		aq->Close();
		aq->SQL->Clear();
		aq->SQL->Add(sql);
		aq->Open();
		while (!aq->Eof )
		{
			cbinbkstack->AddItem(aq->FieldByName("Name")->AsString ,(TObject*)aq->FieldByName("ID")->AsInteger );
			aq->Next();
		}
		aq->First();
		cbinbkstack->ItemIndex = 0;//cbinbkstack->Items->IndexOfObject((TObject*)aq->FieldByName("ID")->AsInteger );

		sql = "select * from BS_ZN_DiaoNoteHeader where (instorage = " + IntToStr(fstgid) + " or outstorage = " + IntToStr(fstgid) + ") and type = 0";

		aqhd->Close();
		aqhd->SQL ->Clear();
		aqhd->SQL ->Add(sql);
		aqhd->Open();
	}
}
//---------------------------------------------------------------------------
void Tfrmdiaobo::ReadDateWhenClick(int ins , int outs)    //当单击调拨单时
{
	AnsiString sql;
		sql = "select ID,Name from dbo.STK_BookstackInfo  where stgID = " + IntToStr(ins);
		aq->Close();
		aq->SQL->Clear();
		aq->SQL->Add(sql);
		aq->Open();
		cbinbkstack->Clear();
		while (!aq->Eof )
		{
			cbinbkstack->AddItem(aq->FieldByName("Name")->AsString ,(TObject*)aq->FieldByName("ID")->AsInteger );
			aq->Next();
		}

		sql = "select ID,Name from SYS_StorageInfo ";
		aq->Close();
		aq->SQL ->Clear();
		aq->SQL->Add(sql);
		aq->Open();
		cboutstorage->Items->Clear();
		cbinstorage->Items->Clear();
		while (!aq->Eof )
		{
			cboutstorage->AddItem(aq->FieldByName("Name")->AsString ,(TObject*)aq->FieldByName("ID")->AsInteger );
			cbinstorage->AddItem(aq->FieldByName("Name")->AsString ,(TObject*)aq->FieldByName("ID")->AsInteger );
			aq->Next();
		}



	if (ftype == 2) {


	return;
	}
	  if (ftype == 1) {   //主动


	  }else
	  {

	  }
}
//---------------------------------------------------------------------------
void Tfrmdiaobo::ReadinData()
{
	AnsiString sql;
	if (ftype == 2) {    //界面点击进入
		ftype = 1;
		return;
	}
	if(ftype==1)      //主动配送
	{
	    sql = "select ID,Name from dbo.STK_BookstackInfo  where stgID = " + IntToStr(instorage);
		aq->Close();
		aq->SQL->Clear();
		aq->SQL->Add(sql);
		aq->Open();
		cbinbkstack->Clear();
		while (!aq->Eof )
		{
			cbinbkstack->AddItem(aq->FieldByName("Name")->AsString ,(TObject*)aq->FieldByName("ID")->AsInteger );
			aq->Next();
		}
		aq->First();
		cbinbkstack->ItemIndex = cbinbkstack->Items->IndexOfObject((TObject*)aq->FieldByName("ID")->AsInteger );
	}else    //申请配送
	{
		sql = "select ID,Name from STK_BookstackInfo where StgID = " + IntToStr(instorage);
		aq->Close();
		aq->SQL->Clear();
		aq->SQL->Add(sql);
		aq->Open();
		cbinbkstack->Clear();
		while (!aq->Eof )
		{
			cbinbkstack->AddItem(aq->FieldByName("Name")->AsString ,(TObject*)aq->FieldByName("ID")->AsInteger );
			aq->Next();
		}
		aq->First();
		cbinbkstack->ItemIndex = cbinbkstack->Items->IndexOfObject((TObject*)aq->FieldByName("ID")->AsInteger );
	}
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdiaobo::BtnSaveAllClick(TObject *Sender)
{
	if (cbinstorage->Text == "") {
		ShowMsg(Handle ,"调入店不能为空！",3);
		return;
	}

	if (cboutstorage->Text == "") {
		ShowMsg(Handle ,"调出店不能为空！",3);
		return;
	}

	int outstackid,instackid,inuserid;
	instorage = int(cbinstorage->Items->Objects[cbinstorage->ItemIndex]);
	outstorage = int(cboutstorage->Items->Objects[cboutstorage->ItemIndex]);
	if (instorage == outstorage) {
		ShowMsg(Handle ,"调入店调出店不能为同一店，请确认！",3);
		return;
	}

	AnsiString Code;
	Code = NoteCode::BuildCode(aq, GetDBTime(aq), fstgid, "BS_ZN_DiaoNoteHeader", "ZNDiaoNtCode");
       //	diaobocode->Text = Code;
	AnsiString sql;
       /*
	sql = "insert into BS_ZN_DiaoNoteHeader(ZNDiaoNtCode,HdTime,StgID,Remarks,OperatorID,state,outstorage,instorage,type) values(" + Code + ",'"
	  + DateTimeToStr(dtpdata->DateTime) + "'," + IntToStr(fstgid) +",'" + membk->Text
	   + "'," + IntToStr(fuserid) + ",0," + IntToStr(outstorage) + "," + IntToStr(instorage) + "," + IntToStr(ftype) + ")";
	aq->Close();
	aq->SQL->Clear();
	aq->SQL->Add(sql);
	aq->ExecSQL();  */

        spnewdanhao->Parameters->ParamByName("@type")->Value = ftype;
        spnewdanhao->Parameters->ParamByName("@StgID")->Value = fstgid;
        spnewdanhao->Parameters->ParamByName("@Remarks")->Value =  membk->Text.Trim();
        spnewdanhao->Parameters->ParamByName("@OperatorID")->Value = fuserid;
        spnewdanhao->Parameters->ParamByName("@state")->Value = 1;
        spnewdanhao->Parameters->ParamByName("@outstorage")->Value = outstorage;
        spnewdanhao->Parameters->ParamByName("@instorage")->Value = instorage;
        spnewdanhao->Parameters->ParamByName("@ZNDiaoNtCode")->Value = Code;
        spnewdanhao->Parameters->ParamByName("@Danhao")->Value=0;
        spnewdanhao->ExecProc();
        diaobocode->Text = spnewdanhao->Parameters->ParamByName("@Danhao")->Value ;

	QryNtHeader(Code);
	logmessage = "添加配送单" + Code;
	AddEvent(1,"配送窗口",fuserid,fstgid,logmessage,con);
	cbinstorage->Enabled = false;
	cboutstorage->Enabled = false;

	BtnSaveAll->Enabled = false;
	edcatalog->SetFocus();
}
//---------------------------------------------------------------------------

void Tfrmdiaobo::QryNtHeader(String code)
{
	spqryntheader1->Active = false;
	spqryntheader1->Parameters->ParamByName("@NtCode")->Value = code;
	spqryntheader1->Parameters->ParamByName("@Bsmode")->Value = 7;
	MYTRACEF(_T("query note header @NtCode=%S"), code.c_str());
	try
	{
		spqryntheader1->Active = true;
		//spqryntheader1->ExecProc();
		dsetNtHeader->Recordset = spqryntheader1->Recordset;
		dsetNtHeader->Last();
		int count = 0;
		ds->DataSet = NULL;
		//ds->AfterScroll = NULL;
		aquery->Recordset = spqryntheader1->NextRecordset(count);
		ds->DataSet = aquery;
		aquery->Last();
		if (dsetNtHeader->Active && dsetNtHeader->RecordCount >= 1) {
			BtnSaveAll->Enabled = false;
			if (ftype == 2) {
				ftype = dsetNtHeader->FieldByName("type")->AsInteger;
				if (ftype == 1) {
					DBGrid1->Columns->Items[5]->Visible = false;
					BtnOK->Visible = false;
					BtnBullets->Visible = true;
				}
				else
				{
					DBGrid1->Columns->Items[5]->Visible = true;
					BtnOK->Visible = true;
					Label18->Caption = "--申请配送";
					this->Caption = "申请配送";
					BtnBullets->Visible = false;
				}
			}
			cbinstorage->Enabled = false;
			cboutstorage->Enabled = false;

				diaobocode->Text =  dsetNtHeader->FieldByName("ZNDiaoNtCode")->AsString ;
		       //	diaobocode->Text =  dsetNtHeader->FieldByName("StgNtCodeStr")->AsString ;


			instorage = dsetNtHeader->FieldByName("instorage")->AsInteger;
			ReadinData();
			outstorage = dsetNtHeader->FieldByName("outstorage")->AsInteger ;
			//ReadDateWhenClick(instorage,outstorage);
			cbinstorage->ItemIndex = cbinstorage->Items->IndexOfObject((TObject*)dsetNtHeader->FieldByName("instorage")->AsInteger );

			cboutstorage->ItemIndex = cboutstorage->Items->IndexOfObject((TObject*)dsetNtHeader->FieldByName("outstorage")->AsInteger );
			membk->Text =  dsetNtHeader->FieldByName("Remarks")->AsString ;
			edopname->Text = dsetNtHeader->FieldByName("opname")->AsString ;
			edcheckuser->Text = dsetNtHeader->FieldByName("checkname")->AsString ;
			if (ftype == 1) {
				DBGrid1->Columns->Items[5]->Visible = false;
			}
			else
			{
				DBGrid1->Columns->Items[5]->Visible = true;
			}
			Label11->Caption = "配送数量";
			switch (dsetNtHeader->FieldByName("state")->AsInteger) {
				case 0:
					if (ftype == 1) {  //主动配送
						edstate->Text = "待出库";
					}
					else    //请求配送
					{
						edstate->Text = "待审核";
					}

					Btn1->Enabled = false;
					BtnCancel->Enabled = false;
					BtnCancel1->Enabled = false;
					DBGrid1->Columns->Items[12]->Visible = true;
					if (ftype == 1) {     //主动
					Btn1->Enabled = false;
					BtnCancel->Enabled = false;
					BtnCancel1->Enabled = false;

						if (instorage == fstgid) {       //当前店为调入店
							GroupBox1->Enabled = false;
							BtnFinish->Enabled = false;
							BtnJumptoLine->Enabled = false;
							BtnDelete->Enabled = false;
							Btn->Enabled = false;
							BtnBullets->Enabled = false;
							edcatalog->Enabled = false;
							dbnumamount->Enabled = false;
							dbnumdiscount->Enabled = false;
						}
						else
						{
							GroupBox1->Enabled = true;
							edcatalog->Enabled = true;
							dbnumamount->Enabled = true;
							dbnumdiscount->Enabled = true;
							dbamountbk->Enabled = false;
							BtnFinish->Enabled = true;
							BtnJumptoLine->Enabled = true;
							BtnDelete->Enabled = true;
							Btn->Enabled = true;
							BtnBullets->Enabled = true;
						}
					}
					else
					{          //申请
						if (instorage == fstgid)        //当前店为调入店
						{
							Label11->Caption = "申请数量";
							Btn->Enabled = false;
							GroupBox1->Enabled = true;
							edcatalog->Enabled = true;
							dbnumamount->Enabled = true;
							dbnumdiscount->Enabled = true;
							dbamountbk->Enabled = false;
							BtnFinish->Enabled = true;
							BtnJumptoLine->Enabled = true;
							BtnDelete->Enabled = true;
							BtnOK->Enabled = true;
						}
						else
						{
							Btn->Enabled = false;
							GroupBox1->Enabled = false;
							dbamountbk->Enabled = false;
							BtnFinish->Enabled = false;
							BtnJumptoLine->Enabled = false;
							BtnDelete->Enabled = false;
							BtnOK->Enabled = false;
							edcatalog->Enabled = false;
							dbnumamount->Enabled = false;
							dbnumdiscount->Enabled = false;
						}
					}

				break;
				case 1:
					edstate->Text = "待出库";
					BtnOK->Enabled = false;
					if (instorage == fstgid) {        //当前店为调入店
						Btn->Enabled = false;
						GroupBox1->Enabled = false;
						dbamountbk->Enabled = false;
						BtnFinish->Enabled = false;
						BtnJumptoLine->Enabled = false;
						BtnDelete->Enabled = false;
						Btn1->Enabled = false;
						BtnCancel->Enabled = false;
						BtnCancel1->Enabled = false;
						edcatalog->Enabled = false;
						dbnumamount->Enabled = false;
						dbnumdiscount->Enabled = false;
					}
					else
					{
						Btn->Enabled = true;
						GroupBox1->Enabled = true;
						dbamountbk->Enabled = false;
						BtnFinish->Enabled = false;
						BtnJumptoLine->Enabled = true;
						dbnumamount->Enabled = true;
						dbnumdiscount->Enabled = true;
						edcatalog->Enabled = false;
						BtnDelete->Enabled = false;
						Btn1->Enabled = false;
						BtnCancel->Enabled = false;
						BtnCancel1->Enabled = false;
					}

				break;
				case 2:
					edstate->Text = "待入库";
					BtnOK->Enabled = false;
					Btn->Enabled = false;
					BtnCancel1->Enabled = false;
					BtnBullets->Enabled = false;
					edcatalog->Enabled = false;
					dbnumamount->Enabled = false;
					dbnumdiscount->Enabled = false;
					DBGrid1->Columns->Items[12]->Visible = false;
					if (instorage == fstgid) {
						GroupBox1->Enabled = true;
						dbamountbk->Enabled = true;
						BtnFinish->Enabled = false;
						BtnJumptoLine->Enabled = false;
						BtnDelete->Enabled = false;
						Btn1->Enabled = true;
						BtnCancel->Enabled = false;
					}
					else
					{
						GroupBox1->Enabled = false;
						BtnFinish->Enabled = false;
						BtnJumptoLine->Enabled = false;
						BtnDelete->Enabled = false;
						Btn1->Enabled = false;
						BtnCancel->Enabled = true;
					}
				break;
				case 3:
					edstate->Text = "已入库";
					BtnOK->Enabled = false;
					BtnBullets->Enabled = false;
					DBGrid1->Columns->Items[12]->Visible = false;
					Btn->Enabled = false;
					Btn1->Enabled = false;
					GroupBox1->Enabled = false;
					BtnFinish->Enabled = false;
					BtnJumptoLine->Enabled = false;
					BtnDelete->Enabled = false;
					BtnCancel->Enabled = false;
					edcatalog->Enabled = false;
					dbnumamount->Enabled = false;
					dbnumdiscount->Enabled = false;
					if (instorage == fstgid) {
						BtnCancel1->Enabled = true;
					}
					else
					{
                    	BtnCancel1->Enabled = false;
					}
				break;
            default:
                ;
			}

			cbinstorage->Enabled = false;

			dtpdata->Enabled = false;
			dtpdata->Date = dsetNtHeader->FieldByName("HdTime")->AsDateTime ;
			((TFloatField *)aquery->FieldByName("FixedPrice"))->DisplayFormat =  "￥0.00" ;
			((TFloatField *)aquery->FieldByName("DiscountedPrice"))->DisplayFormat =  "￥0.00" ;
			((TFloatField *)aquery->FieldByName("Discount"))->DisplayFormat =  "##0%" ;
		}
	}

	catch(Exception *E)
	{

	}
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdiaobo::N1Click(TObject *Sender)
{
	Label10->Caption = "书  号";
	m_catalogSearchMode=1;
	edcatalog->MaxLength = 20;
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdiaobo::N3Click(TObject *Sender)
{
	Label10->Caption = "书  名";
	m_catalogSearchMode=2;
	edcatalog->MaxLength = 0;
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdiaobo::N2Click(TObject *Sender)
{
	Label10->Caption = "自编码";
	m_catalogSearchMode=3;
	edcatalog->MaxLength = 0;
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdiaobo::N4Click(TObject *Sender)
{
	Label10->Caption = "定  价";
	m_catalogSearchMode=4;
	edcatalog->MaxLength = 0;
}
//---------------------------------------------------------------------------
void Tfrmdiaobo::ChangeCatalogSearchMode()
{
	m_catalogSearchMode++;
	if (m_catalogSearchMode >= 5)
	{
		m_catalogSearchMode = 1;
	}

	switch (m_catalogSearchMode)
	{
	case 1:
		edcatalog->MaxLength = 20;
		Label10->Caption = "书号";
		break;
    case 2:
		edcatalog->MaxLength = 0;
		Label10->Caption = "书名";
		break;
	case 3:
		edcatalog->MaxLength = 0;
		Label10->Caption = "自编码";
		break;
	case 4:
		edcatalog->MaxLength = 0;
		Label10->Caption = "定价";
		break;
    default:
        break;
	}
}
//---------------------------------------------------------------------------
void __fastcall Tfrmdiaobo::edcatalogKeyPress(TObject *Sender, wchar_t &Key)
{
	if (m_catalogSearchMode == 4) {
		if ((Key < '0' || Key > '9') && (Key != '\b') && (Key != '.') && (Key != '\r') ) {
            Key = NULL;
		}
	}

	if (Key == '\r') {
		if (diaobocode->Text == "") {
			ShowMsg(Handle ,"请先保存单号！",3);
			return;
		}
		if (edcatalog->Text == "") {
			ChangeCatalogSearchMode();
		}
		else
		{
			AnsiString sql;
			int outstackid;
                        AnsiString presscount;
			AnsiString SearchCont = edcatalog->Text.Trim() ;
			int storage,storagebk;
			storage = int(cboutstorage->Items->Objects[cboutstorage->ItemIndex]);

			sql = " select BS_BookCatalog.ID,BS_BookCatalog.Author,STK_BookInfo.ID as bkinfoid,STK_BookInfo.SupplierID,BS_BookCatalog.Name,BS_BookCatalog.Barcode,BS_BookCatalog.UserDefCode,BS_BookCatalog.ISBN,CUST_CustomerInfo.Name as SupplierName,STK_BookInfo.Amount,STK_BookstackInfo.Name as BkstackName,BS_BookCatalog.Price ,BS_PressInfo.fullname,STK_BookstackInfo.Name as BKStName,STK_BookstackInfo.ID as BSKID "
			  " from BS_BookCatalog  join STK_BookInfo on STK_BookInfo.BkcatalogID=BS_BookCatalog.ID "
			  " left join CUST_CustomerInfo on STK_BookInfo.SupplierID=CUST_CustomerInfo.ID "
			  " left join STK_BookstackInfo on STK_BookInfo.BkstackID=STK_BookstackInfo.ID "
			  " left join BS_PressInfo ON BS_BookCatalog.PressID = BS_PressInfo.ID "
			  " where   BS_BookCatalog.Unavailable=1 and STK_BookInfo.StgID = " + IntToStr(storage);
			switch (m_catalogSearchMode)
			{
				case 1://条码
                                       if (edcatalog->Text.Trim().Length()>13) {
                                          presscount = SearchCont.SubString(14,SearchCont.Length()-13);
                                         SearchCont =   SearchCont.SubString(0,13);

                                        sql = sql + " and (BS_BookCatalog.PressCount like '%" + presscount + "%' and BS_BookCatalog.type = 1) ";
                                       }
					sql = sql + "  and (BS_BookCatalog.Barcode like '%" + SearchCont + "%' or BS_BookCatalog.isbn like '%" + SearchCont + "%') ";
				break;
				case 2://书名
					sql = sql +  " and  BS_BookCatalog.Name like '%" + SearchCont + "%'";
				break;
				case 3://自编码
					sql = sql + " and BS_BookCatalog.UserDefCode like '%" + SearchCont + "%'";
				break;
				case 4://定价
					sql = sql +  " and BS_BookCatalog.price=" + SearchCont;
				break;
				default:
				break;
			}
			query->Close();
			query->SQL->Clear();
			query->SQL->Add(sql);
			query->Open();
			TLocateOptions   Opts;
			Opts.Clear();
			Opts   <<   loPartialKey;
			if (query->RecordCount == 1) {
				AnsiString   str   = query->FieldByName("bkinfoid")->AsString;
				if (!aquery->Locate("Bkinfoid",str,Opts)) {
					if (AddNote(query->FieldByName("bkinfoid")->AsInteger))
					{
						edcatalog->Text = "";
						dbnumamount->SetFocus();
					}
					else
					{
					}
				}
				else
				{
					if (sametishi) {
						ShowMsg(Handle ,"有相同记录请核实！",3);
					}

					DBGrid1->SelectedRows->CurrentRowSelected = true;
					DBGrid1->SetFocus();
					edcatalog->Text = "";
					dbnumamount->SetFocus();
				}
			}
			else if (query->RecordCount > 1) {
				Tfrmfinddiaobook *frm = new Tfrmfinddiaobook(Application,query);
				frm->frmdiaobo = this;
				frm->DoModalType = 1;
				if (mrOk == frm->ShowModal()) {
					if (frm->SelectAll ) {
						query->First();
						while (!query->Eof)
						{
							if (AddNote(query->FieldByName("bkinfoid")->AsInteger))
							{
								//dbnumamount->SetFocus();
							}
							else
							{
							}
							query->Next();
						}
					}
					else
					{
						String   str   = query->FieldByName("bkinfoid")->AsString;
						if (!aquery->Locate("Bkinfoid",str,Opts)) {
							if (AddNote(query->FieldByName("bkinfoid")->AsInteger))
							{
								edcatalog->Text = "";
								if (chfoceset->Checked) {
									if (chfsamount->Checked ) {
										dbnumamount->SetFocus();
									}
									else if (chfsdiscount->Checked ) {
										dbnumdiscount->SetFocus();
									}
									else if (chfsluru->Checked) {
										edcatalog->SetFocus();
									}
								}
								else
								{
									dbnumamount->SetFocus();
								}
							}
							else
							{
							}
						}
						else
						{
							if (sametishi) {
                            	ShowMsg(Handle ,"有相同记录请核实！",3);
							       //	MessageBox(0,"有相同记录请核实！","提示" ,MB_ICONEXCLAMATION);
							}
							DBGrid1->SelectedRows->CurrentRowSelected = true;
							DBGrid1->SetFocus();
							edcatalog->Text = "";
							dbnumamount->SetFocus();
						}
					}
				}
			}
			else
			{
			}
		}
	}
}
//---------------------------------------------------------------------------
bool Tfrmdiaobo::AddNote(int bkinfoid)
{
	bool result = false;
	if (dsetNtHeader->Active && dsetNtHeader->RecordCount >= 1)
	{
		cmdaddnote->Parameters->ParamByName("@NtHeaderID")->Value
			= dsetNtHeader->FieldByName("ID")->AsInteger;
		cmdaddnote->Parameters->ParamByName("@STKinfoID")->Value
			= bkinfoid;
		//cmdaddnote->Parameters->ParamByName("@SupplierID")->Value = supplierID;
		cmdaddnote->Parameters->ParamByName("@Bsmode")->Value = 7;
		cmdaddnote->Parameters->ParamByName("@NoteMode")->Value = -1;
		int  instackid;
		try {
			instackid = int(cbinbkstack->Items->Objects[cbinbkstack->ItemIndex]) ;
		} catch (...) {
			ShowMsg(Handle ,"请选择正确的调入库位！",3);
			return false;
		}
		cmdaddnote->Parameters->ParamByName("@bkstackID")->Value = instackid;
		cmdaddnote->ExecProc();
		int ret = cmdaddnote->Parameters->ParamByName("@RETURN_VALUE")->Value;
		if (ret > 0)//插入成功
		{
			try
			{
				QryNtHeader(dsetNtHeader->FieldByName("ID")->AsInteger);
			}
			__finally
			{
				//LockWindowUpdate(NULL);
			}
			result = true;
		}
		else if (ret == 0)//查无此书
		{

		}
		else if (ret == -1)//库存出错了
		{

		}
		else if (ret == -2) {

                        ShowMsg(Handle ,"不能添加相同目录的书！",3);
			result = true;
		}
	}
	return result;
}
//---------------------------------------------------------------------------
bool Tfrmdiaobo::AddNote(int catalogID,int supplierid)
{
	bool result = false;
        int stk_bookinfoid;
	if (dsetNtHeader->Active && dsetNtHeader->RecordCount >= 1)
	{
        AnsiString sql;
        sql = "select * from stk_bookinfo where bkcatalogid = " + IntToStr(catalogID) + " and supplierid = " + IntToStr(supplierid)
			+ " and stgid = " + IntToStr(outstorage) + " order by amount desc ";
		aq->Close();
		aq->SQL->Clear();
		aq->SQL->Add(sql);
		aq->Open();
		if (aq->IsEmpty() ) {
			return false;
		}
		stk_bookinfoid = aq->FieldByName("id")->AsInteger ;

		cmdaddnote->Parameters->ParamByName("@NtHeaderID")->Value
			= dsetNtHeader->FieldByName("ID")->AsInteger;
		cmdaddnote->Parameters->ParamByName("@BkcatalogID")->Value
			= catalogID;
                cmdaddnote->Parameters->ParamByName("@STKinfoID")->Value
                        =  stk_bookinfoid;

                   cmdaddnote->Parameters->ParamByName("@SupplierID")->Value
                        =  supplierid;
		cmdaddnote->Parameters->ParamByName("@Bsmode")->Value = 7;
		cmdaddnote->Parameters->ParamByName("@NoteMode")->Value = -1;
		int  instackid;
		try {
			instackid = int(cbinbkstack->Items->Objects[cbinbkstack->ItemIndex]) ;
		} catch (...) {

                                  ShowMsg(Handle ,"请选择正确的调入库位！",3);
			return false;
		}
		cmdaddnote->Parameters->ParamByName("@bkstackID")->Value = instackid;
		cmdaddnote->ExecProc();
		int ret = cmdaddnote->Parameters->ParamByName("@RETURN_VALUE")->Value;
		if (ret > 0)//插入成功
		{
			try
			{
				QryNtHeader(dsetNtHeader->FieldByName("ID")->AsInteger);
			}
			__finally
			{
				//LockWindowUpdate(NULL);
			}
			result = true;
		}
		else if (ret == 0)//查无此书
		{

		}
		else if (ret == -1)//库存出错了
		{

		}
		else if (ret == -2) {

                             ShowMsg(Handle ,"不能添加相同目录的书！",3);
			result = true;
		}
	}
	return result;
}
//---------------------------------------------------------------------------
void Tfrmdiaobo::QryNtHeader(int id)
{
	spqryntheader->Active = false;
	spqryntheader->Parameters->ParamByName("@ID")->Value = id;
	spqryntheader->Parameters->ParamByName("@Bsmode")->Value = 7;
	try
	{
		spqryntheader->Active = true;
		dsetNtHeader->Recordset = spqryntheader->Recordset;
		dsetNtHeader->Last();
		int count = 0;
		ds->DataSet = NULL;
		//ds->AfterScroll = NULL;
		aquery->Recordset = spqryntheader->NextRecordset(count);
		ds->DataSet = aquery;
		aquery->Last();
		if (dsetNtHeader->Active && dsetNtHeader->RecordCount >= 1) {
        	BtnSaveAll->Enabled = false;

                //单号                                                              //ZNDiaoNtCode
		       //	diaobocode->Text =  dsetNtHeader->FieldByName("StgNtCodeStr")->AsString ;
                        diaobocode->Text =  dsetNtHeader->FieldByName("ZNDiaoNtCode")->AsString ;
                        cbinstorage->Enabled = false;
			cboutstorage->Enabled = false;

			instorage = dsetNtHeader->FieldByName("instorage")->AsInteger;
			ReadinData();
			outstorage = dsetNtHeader->FieldByName("outstorage")->AsInteger ;
			//ReadDateWhenClick(instorage,outstorage);
			cbinstorage->ItemIndex = cbinstorage->Items->IndexOfObject((TObject*)dsetNtHeader->FieldByName("instorage")->AsInteger );

			cboutstorage->ItemIndex = cboutstorage->Items->IndexOfObject((TObject*)dsetNtHeader->FieldByName("outstorage")->AsInteger );
			membk->Text =  dsetNtHeader->FieldByName("Remarks")->AsString ;
			edopname->Text = dsetNtHeader->FieldByName("opname")->AsString ;
			edcheckuser->Text = dsetNtHeader->FieldByName("checkname")->AsString ;
			if (ftype == 1) {
				DBGrid1->Columns->Items[5]->Visible = false;
			}
			else
			{
				DBGrid1->Columns->Items[5]->Visible = true;
			}
			Label11->Caption = "配送数量";
			switch (dsetNtHeader->FieldByName("state")->AsInteger  ) {
				case 0:
					if (ftype == 1) {  //主动配送
						edstate->Text = "待出库";
					}
					else   //请求配送
					{
						edstate->Text = "待审核";
					}

					Btn1->Enabled = false;
					BtnCancel->Enabled = false;
					BtnCancel1->Enabled = false;
					DBGrid1->Columns->Items[12]->Visible = true;
					if (ftype == 1) {
					Btn1->Enabled = false;
					BtnCancel->Enabled = false;
					BtnCancel1->Enabled = false;

						if (instorage == fstgid) {       //当前店为调入店
							GroupBox1->Enabled = false;
							BtnFinish->Enabled = false;
							BtnJumptoLine->Enabled = false;
							BtnDelete->Enabled = false;
							Btn->Enabled = false;
							edcatalog->Enabled = false;
							dbnumamount->Enabled = false;
							dbnumdiscount->Enabled = false;
						}
						else
						{
							GroupBox1->Enabled = true;
                            edcatalog->Enabled = true;
							dbnumamount->Enabled = true;
							dbnumdiscount->Enabled = true;
							dbamountbk->Enabled = false;
							BtnFinish->Enabled = true;
							BtnJumptoLine->Enabled = true;
							BtnDelete->Enabled = true;
							Btn->Enabled = true;
						}
					}
					else
					{
						if (instorage == fstgid)        //当前店为调入店
						{
							Label11->Caption = "申请数量";
							Btn->Enabled = false;
							GroupBox1->Enabled = true;
							edcatalog->Enabled = true;
							dbnumamount->Enabled = true;
							dbnumdiscount->Enabled = true;
							dbamountbk->Enabled = false;
							BtnFinish->Enabled = true;
							BtnJumptoLine->Enabled = true;
							BtnDelete->Enabled = true;
							BtnOK->Enabled = true;
						}
						else
						{
							Btn->Enabled = false;
							GroupBox1->Enabled = false;
							dbamountbk->Enabled = false;
							BtnFinish->Enabled = false;
							BtnJumptoLine->Enabled = false;
							BtnDelete->Enabled = false;
							BtnOK->Enabled = false;
							edcatalog->Enabled = false;
							dbnumamount->Enabled = false;
							dbnumdiscount->Enabled = false;
						}
					}

				break;
				case 1:
					edstate->Text = "待出库";
					BtnOK->Enabled = false;
					if (instorage == fstgid) {        //当前店为调入店
						Btn->Enabled = false;
						GroupBox1->Enabled = false;
						dbamountbk->Enabled = false;
						BtnFinish->Enabled = false;
						BtnJumptoLine->Enabled = false;
						BtnDelete->Enabled = false;
						Btn1->Enabled = false;
						BtnCancel->Enabled = false;
						BtnCancel1->Enabled = false;
						edcatalog->Enabled = false;
						dbnumamount->Enabled = false;
						dbnumdiscount->Enabled = false;
					}
					else
					{
						Btn->Enabled = false;
						GroupBox1->Enabled = true;
						dbamountbk->Enabled = false;
						BtnFinish->Enabled = true;
						BtnJumptoLine->Enabled = true;
						dbnumamount->Enabled = true;
						dbnumdiscount->Enabled = true;
						edcatalog->Enabled = false;
						BtnDelete->Enabled = false;
						Btn1->Enabled = false;
						BtnCancel->Enabled = false;
						BtnCancel1->Enabled = false;
					}

				break;
				case 2:
					edstate->Text = "待入库";
					BtnOK->Enabled = false;
					Btn->Enabled = false;
					BtnCancel1->Enabled = false;
					edcatalog->Enabled = false;
					dbnumamount->Enabled = false;
					dbnumdiscount->Enabled = false;
					DBGrid1->Columns->Items[12]->Visible = false;
					if (instorage == fstgid) {
						GroupBox1->Enabled = true;
						dbamountbk->Enabled = true;
						BtnFinish->Enabled = false;
						BtnJumptoLine->Enabled = false;
						BtnDelete->Enabled = false;
						Btn1->Enabled = true;
						BtnCancel->Enabled = false;
					}
					else
					{
						GroupBox1->Enabled = false;
						BtnFinish->Enabled = false;
						BtnJumptoLine->Enabled = false;
						BtnDelete->Enabled = false;
						Btn1->Enabled = false;
						BtnCancel->Enabled = true;
					}
				break;
				case 3:
					edstate->Text = "已入库";
					BtnOK->Enabled = false;
					DBGrid1->Columns->Items[12]->Visible = false;
					Btn->Enabled = false;
					Btn1->Enabled = false;
					GroupBox1->Enabled = false;
					BtnFinish->Enabled = false;
					BtnJumptoLine->Enabled = false;
					BtnDelete->Enabled = false;
					BtnCancel->Enabled = false;
					edcatalog->Enabled = false;
					dbnumamount->Enabled = false;
					dbnumdiscount->Enabled = false;
					if (instorage == fstgid) {
						BtnCancel1->Enabled = true;
					}
					else
					{
                    	BtnCancel1->Enabled = false;
					}
				break;
            default:
                ;
			}

			cbinstorage->Enabled = false;

			dtpdata->Enabled = false;
			dtpdata->Date = dsetNtHeader->FieldByName("HdTime")->AsDateTime ;
			((TFloatField *)aquery->FieldByName("FixedPrice"))->DisplayFormat =  "￥0.00" ;
			((TFloatField *)aquery->FieldByName("DiscountedPrice"))->DisplayFormat =  "￥0.00" ;
			((TFloatField *)aquery->FieldByName("Discount"))->DisplayFormat =  "##0%" ;
		}
	}
	catch(...)
	{
		//ShowMessage("该单不存在！");
	}
}

//---------------------------------------------------------------------------
void __fastcall Tfrmdiaobo::BtnExitClick(TObject *Sender)
{
      //	this->;
    // WindowState = wsMinimized ;
  //   Sleep(2000);
      Application->ProcessMessages();
      Close();
      HANDLE hWindow = FindWindow("TfrmMain",NULL);
        SendMessage(hWindow ,WM_MYMESSAGE,0,0);
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdiaobo::cbinstorageChange(TObject *Sender)
{
	instorage = int(cbinstorage->Items->Objects[cbinstorage->ItemIndex]);
	ReadinData();
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdiaobo::BtnNewClick(TObject *Sender)
{
    GroupBox1->Enabled = true;
	dbamountbk->Enabled = false;
	if (!ftype) {         //请配
		cboutstorage->Enabled = true;
		cbinstorage->ItemIndex = cbinstorage->Items->IndexOfObject((TObject*)fstgid);
		cbinstorage->Enabled = false;
		cbinbkstack->Enabled = true;
	}else       //主动配送
	{
		cboutstorage->ItemIndex = cboutstorage->Items->IndexOfObject((TObject*)fstgid);
		cboutstorage->Enabled = false;
		cbinstorage->Enabled = true;
		cbinstorage->Text = "";
		cbinbkstack->Enabled = true;
	  	cbinbkstack->Text = "";
	}

	DBGrid1->DataSource->DataSet->Close();

	//cbcheckuser->Enabled = true;
	BtnSaveAll->Enabled = true;
	BtnDelete->Enabled = false;
	BtnJumptoLine->Enabled = false;
	BtnCancel->Enabled = false;
	Btn1->Enabled = false;
	BtnCancel1->Enabled = false;
	Btn->Enabled = false;
	membk->Text = "";

	//cbcheckuser->Text = "";
	diaobocode->Text = "";
	edopname->Text = "";
	edcheckuser->Text = "";
	edcatalog->Text = "";

	dtpdata->Date = Date();
	dtpdata->Enabled = true;
	DBNavigator1->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdiaobo::BtnViewClick(TObject *Sender)
{
	Tfrmpsquery *frm = new Tfrmpsquery(Application,con,fstgid,ftype);
	if (mrOk == frm->ShowModal() ) {
		AnsiString Codestr =  frm->GetNoteCode();
		AnsiString sqlwhere = frm->Getsqlwhere();
		delete frm;
		try {
			QryNtHeader(Codestr);
			cbinstorage->Enabled = false;
			AnsiString sql ;
			sql = "select * from BS_ZN_DiaoNoteHeader " + sqlwhere;
			aqhd->Close();
			aqhd->SQL->Clear();
			aqhd->SQL->Add(sql);
			aqhd->Open();
			TLocateOptions Opts;
			Opts.Clear();
			Opts << loPartialKey;
			aqhd->Locate("ZNDiaoNtCode", Codestr, Opts);
			//cbinbkstack->Enabled = false;
			//cbcheckuser->Enabled = false;
			BtnSaveAll->Enabled = false;
			DBNavigator1->Enabled = true;
		} catch (...) {
		}
	}
}

//---------------------------------------------------------------------------
void Tfrmdiaobo::Query(AnsiString Code)
{

	QryNtHeader(Code);
	cbinstorage->Enabled = false;
	//cbinbkstack->Enabled = false;
	//cbcheckuser->Enabled = false;
	BtnSaveAll->Enabled = false;
}
//---------------------------------------------------------------------------
void Tfrmdiaobo::DelNote()
{
	if (aquery->Active && aquery->RecordCount >= 1)
	{
		if (DBGrid1->SelectedRows->Count == 0)
		{
			cmdDelNote->Parameters->ParamByName("@ID")->Value
				= aquery->FieldByName("ID")->AsInteger;
			cmdDelNote->Parameters->ParamByName("@Bsmode")->Value = 7;
			logmessage = "删除配送单" + dsetNtHeader->FieldByName("ZNDiaoNtCode")->AsString + "的书目《" + aquery->FieldByName("Name")->AsString + "》";
			AddEvent(1,"调拨窗口",fuserid,fstgid,logmessage,con);
			cmdDelNote->Execute();
		}
		else if (DBGrid1->SelectedRows->Count > 0)
		{
			String ids = "";
			aquery->Bookmark = DBGrid1->SelectedRows->Items[0];
			ids = ids + aquery->FieldByName("ID")->AsString;
			logmessage = "删除配送单" + dsetNtHeader->FieldByName("ZNDiaoNtCode")->AsString + "的书目《" + aquery->FieldByName("Name")->AsString + "》";
			AddEvent(1,"调拨窗口",fuserid,fstgid,logmessage,con);
			for (int i=1; i < DBGrid1->SelectedRows->Count; i++)
			{
				aquery->Bookmark = DBGrid1->SelectedRows->Items[i];
				ids = ids + "," + aquery->FieldByName("ID")->AsString;
				logmessage = "删除配送单" + dsetNtHeader->FieldByName("ZNDiaoNtCode")->AsString + "的书目《" + aquery->FieldByName("Name")->AsString + "》";
				AddEvent(1,"配送窗口",fuserid,fstgid,logmessage,con);
			}
			cmdBatchDelNote->Parameters->ParamByName("@IDS")->Value = ids;
			cmdBatchDelNote->Parameters->ParamByName("@Bsmode")->Value = 7;
			cmdBatchDelNote->Execute();
		}
		try
		{
			//LockWindowUpdate(dbgrdNote->Handle);//锁定指定窗口，禁止它更新。
			QryNtHeader();
		}
		__finally
		{
			//LockWindowUpdate(NULL);
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdiaobo::BtnDeleteClick(TObject *Sender)
{
	DelNote();
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdiaobo::dbnumamountKeyPress(TObject *Sender, wchar_t &Key)
{
	if (Key == '\r') {



        if (aquery->IsEmpty() ) {
		return;
	}
       if (aquery->IsEmpty() ) {
			return;
		}
		try {
			aquery->UpdateBatch(arCurrent);
        } catch (...) {
		}

	if (dbnumamount->Value > aquery->FieldByName("bkamount")->AsInteger && dsetNtHeader->FieldByName("state")->AsInteger == 0 ) {

              if(ShowMsg(Handle ,"配送数量大于当前库存数量,是否继续?",1)==1)
              {
                 UpdateNote();

              }else
              {
		dbnumamount->SetFocus();
		return;
              }
	}else
        {
          UpdateNote();
        }
    	if (chfoceset->Checked) {
			if (chfsdiscount->Checked) {
				dbnumdiscount->SetFocus();
			}
			else if (chfsluru->Checked) {
				edcatalog->SetFocus();
			}
			else if (chfsamount->Checked) {
				if (!aquery->Eof) {
					DBGrid1->SetFocus();
					aquery->Next();
					DBGrid1->SelectedRows->CurrentRowSelected = true;
					dbnumamount->SetFocus();
				}
			}
		}
		else
		{
			dbnumdiscount->SetFocus();
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdiaobo::dbnumdiscountKeyPress(TObject *Sender, wchar_t &Key)
{
	if (Key == '\r') {
    	if (chfoceset->Checked) {
			if (chfsluru->Checked) {
				edcatalog->SetFocus();
			}
			else if (chfsamount->Checked) {
				if (!aquery->Eof) {
					DBGrid1->SetFocus();
					aquery->Next();
					DBGrid1->SelectedRows->CurrentRowSelected = true;
					dbnumamount->SetFocus();
				}
			}
			else if (chfsdiscount->Checked) {
				if (!aquery->Eof) {
					DBGrid1->SetFocus();
					aquery->Next();
					DBGrid1->SelectedRows->CurrentRowSelected = true;
					dbnumdiscount->SetFocus();
				}
			}
		}
		else
		{
                          if (edcatalog->Enabled) {
                            edcatalog->SetFocus();
                          }

		}
	}
}
//---------------------------------------------------------------------------
void Tfrmdiaobo::UpdateNote()
{
	if (aquery->Active && aquery->RecordCount >= 1)
	{
		cmdUpdateNote->Parameters->ParamByName("@ID")->Value
			= aquery->FieldByName("ID")->AsInteger;
		cmdUpdateNote->Parameters->ParamByName("@Amount")->Value
			= abs(aquery->FieldByName("Amount")->AsInteger);
		cmdUpdateNote->Parameters->ParamByName("@Discount")->Value
			= abs(aquery->FieldByName("Discount")->AsFloat);
		cmdUpdateNote->Parameters->ParamByName("@Bsmode")->Value = 7;

		int  instackid;
		try {
			instackid = int(cbinbkstack->Items->Objects[cbinbkstack->ItemIndex]) ;
		} catch (...) {

                        ShowMsg(Handle ,"请选择正确的调入库位！",3);
			return ;
		}
		cmdUpdateNote->Parameters->ParamByName("@bkstackID")->Value = instackid;
		cmdUpdateNote->Parameters->ParamByName("@bkchange")->Value = bkchange;
		if (ftype == 0 && instorage == fstgid && edstate->Text == "待审核") {
			cmdUpdateNote->Parameters->ParamByName("@bkamount")->Value = 1;
		}
		cmdUpdateNote->Execute();
	}
	try
	{
		//LockWindowUpdate(dbgrdNote->Handle);//锁定指定窗口，禁止它更新。
		QryNtHeader();
	}
	__finally
	{
		//LockWindowUpdate(NULL);
	}
}
//---------------------------------------------------------------------------
void Tfrmdiaobo::UpdateNote1()
{
	if (aquery->Active && aquery->RecordCount >= 1)
	{
		cmdUpdateNote->Parameters->ParamByName("@ID")->Value
			= aquery->FieldByName("ID")->AsInteger;
		cmdUpdateNote->Parameters->ParamByName("@Amount")->Value
			= abs(aquery->FieldByName("Amount")->AsInteger);
		cmdUpdateNote->Parameters->ParamByName("@Discount")->Value
			= abs(aquery->FieldByName("Discount")->AsFloat);
		cmdUpdateNote->Parameters->ParamByName("@Bsmode")->Value = 7;

		int  instackid;
		try {
			instackid = int(cbinbkstack->Items->Objects[cbinbkstack->ItemIndex]) ;
		} catch (...) {

                            ShowMsg(Handle ,"请选择正确的调入库位！",3);
			return ;
		}
		cmdUpdateNote->Parameters->ParamByName("@bkstackID")->Value = instackid;
		cmdUpdateNote->Parameters->ParamByName("@bkchange")->Value = bkchange;
		cmdUpdateNote->Execute();
	}

}
//---------------------------------------------------------------------------

void Tfrmdiaobo::QryNtHeader()
{
    //保存查询之前的当前活动记录ID
	int noteID = 0;
	if (aquery->Active && aquery->RecordCount >= 1)
	{
		noteID = aquery->FieldByName("ID")->AsInteger;
	}
	spqryntheader->Active = false;
	spqryntheader->Parameters->ParamByName("@ID")->Value = dsetNtHeader->FieldByName("ID")->AsInteger;
	spqryntheader->Parameters->ParamByName("@Bsmode")->Value = 7;
	try
	{
		spqryntheader->Active = true;
		dsetNtHeader->Recordset = spqryntheader->Recordset;
		dsetNtHeader->Last();
		int count = 0;
		ds->DataSet = NULL;
		//ds->AfterScroll = NULL;
		aquery->Recordset = spqryntheader->NextRecordset(count);
		ds->DataSet = aquery;
		if (noteID > 0)//将当前记录的ID重新调整至noteID
		{
			TLocateOptions Opts;
			Opts.Clear();
			Opts << loPartialKey;
			if (!aquery->Locate("ID", noteID, Opts))
				aquery->Last();
		}
		else
		{
			aquery->Last();
		}
		((TFloatField *)aquery->FieldByName("FixedPrice"))->DisplayFormat =  "￥0.00" ;
		((TFloatField *)aquery->FieldByName("DiscountedPrice"))->DisplayFormat =  "￥0.00" ;
		((TFloatField *)aquery->FieldByName("Discount"))->DisplayFormat =  "##0%" ;
		//ds->AfterScroll = dsetNoteAfterScroll;
	}
	catch(...)
	{
		//ShowMessage("该单不存在！");
	}
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdiaobo::BtnClick(TObject *Sender)
{
	if (aquery->IsEmpty() ) {
		return;
	}
	try
	{
        cmdshenhe->Parameters->ParamByName("@NtHeaderID")->Value
			= dsetNtHeader->FieldByName("ID")->AsInteger;
		cmdshenhe->Parameters->ParamByName("@Bsmode")->Value = 1;   //出库
		cmdshenhe->Parameters->ParamByName("@stgid")->Value = fstgid;
		cmdshenhe->Parameters->ParamByName("@userid")->Value = fuserid;
		cmdshenhe->Execute();
		QryNtHeader(dsetNtHeader->FieldByName("ZNDiaoNtCode")->AsString);
                operationstateA = 1;
	}
	__finally
	{
	}
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdiaobo::Btn1Click(TObject *Sender)
{
	if (aquery->IsEmpty() ) {
		return;
	}
	try
	{
        cmdshenhe->Parameters->ParamByName("@NtHeaderID")->Value
			= dsetNtHeader->FieldByName("ID")->AsInteger;
		cmdshenhe->Parameters->ParamByName("@Bsmode")->Value = 2;   //入库
		cmdshenhe->Parameters->ParamByName("@stgid")->Value = fstgid;
		cmdshenhe->Parameters->ParamByName("@userid")->Value = fuserid;
		cmdshenhe->Execute();
		QryNtHeader(dsetNtHeader->FieldByName("ZNDiaoNtCode")->AsString);
                operationstateA = 1;
                dbamountbk->Enabled = false;
	}
	__finally
	{
	}
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdiaobo::BtnJumptoLineClick(TObject *Sender)
{
	if (aquery->IsEmpty() ) {
        return;
	}
	if (DBGrid1->SelectedRows->Count == 0 || DBGrid1->SelectedRows->Count == 1) {
		for (int i = 1; i <= aquery->RecordCount ; i++) {
			aquery->RecNo = i;
			DBGrid1->SelectedRows->CurrentRowSelected = true;
		}
	}
	TfrmSetNotes* frm = new TfrmSetNotes(this);
	frm->ChangeBsmode(1);
	if (frm->ShowModal() == mrOk)
	{
		int amount = 0;
		float discount = 0;
		bool bsetAmount = frm->GetAmount(amount);
		bool bsetDiscount = frm->GetDiscount(discount);
		if (bsetAmount && bsetDiscount)
		{
			BatchSetNotes(amount, discount, 1);
		}
		else if (bsetAmount && !bsetDiscount)
		{
			BatchSetNotes(amount, discount, 2);
		}
		else if (!bsetAmount && bsetDiscount)
		{
			BatchSetNotes(amount, discount, 3);
		}
		else
		{
		}
	}
	delete frm;
}
//---------------------------------------------------------------------------

void Tfrmdiaobo::BatchSetNotes(int amount, float discount, int mode)
{
	if (aquery->Active && aquery->RecordCount >= 1)
	{
		String ids = "";
		if (DBGrid1->SelectedRows->Count == 0)
		{
			if (aquery->FieldByName("bkamount")->AsInteger >= amount ) {
				ids = ids + aquery->FieldByName("ID")->AsString;
			}
		}
		else if (DBGrid1->SelectedRows->Count > 0)
		{
			aquery->Bookmark = DBGrid1->SelectedRows->Items[0];
			if (aquery->FieldByName("bkamount")->AsInteger >= amount ) {
				ids = aquery->FieldByName("ID")->AsString;
			}
			for (int i=1; i < DBGrid1->SelectedRows->Count; i++)
			{
				aquery->Bookmark = DBGrid1->SelectedRows->Items[i];
				if (aquery->FieldByName("bkamount")->AsInteger >= amount) {
					if (ids == "") {
						ids = ids + aquery->FieldByName("ID")->AsString;
					}
					else
					{
						ids = ids + "," + aquery->FieldByName("ID")->AsString;
					}
				}
			}
		}
		else
			return;
		if (ids == "") {
            return;
		}

		switch(mode)
		{
		case 1://两者均更新
			cmdBatchUpdateNote->Parameters->ParamByName("@IDS")->Value = ids;
			cmdBatchUpdateNote->Parameters->ParamByName("@Amount")->Value = amount;
			cmdBatchUpdateNote->Parameters->ParamByName("@Discount")->Value = discount;
			cmdBatchUpdateNote->Parameters->ParamByName("@Bsmode")->Value = 7;
			if (BtnOK->Visible && BtnOK->Enabled) {
				cmdBatchUpdateNote->Parameters->ParamByName("@Type")->Value = 0;
			}
			else if (Btn->Enabled ) {
				cmdBatchUpdateNote->Parameters->ParamByName("@Type")->Value = 1;
			}
			else if (Btn1->Enabled ) {
				cmdBatchUpdateNote->Parameters->ParamByName("@Type")->Value = 2;
			}
			cmdBatchUpdateNote->Execute();
			try
			{
				//LockWindowUpdate(dbgrdNote->Handle);//锁定指定窗口，禁止它更新。
				QryNtHeader();
			}
			__finally
			{
				//LockWindowUpdate(NULL);
			}
			break;
		case 2://只更新Amount
			cmdBatchUpdateNote->Parameters->ParamByName("@IDS")->Value = ids;
			cmdBatchUpdateNote->Parameters->ParamByName("@Amount")->Value = amount;
			cmdBatchUpdateNote->Parameters->ParamByName("@Discount")->Value = "";
			cmdBatchUpdateNote->Parameters->ParamByName("@Bsmode")->Value = 7;
			if (BtnOK->Visible && BtnOK->Enabled) {
				cmdBatchUpdateNote->Parameters->ParamByName("@Type")->Value = 0;
			}
			else if (Btn->Enabled ) {
				cmdBatchUpdateNote->Parameters->ParamByName("@Type")->Value = 1;
			}
			else if (Btn1->Enabled ) {
				cmdBatchUpdateNote->Parameters->ParamByName("@Type")->Value = 2;
			}
			cmdBatchUpdateNote->Execute();
			try
			{
				//LockWindowUpdate(dbgrdNote->Handle);//锁定指定窗口，禁止它更新。
				QryNtHeader();
			}
			__finally
			{
				//LockWindowUpdate(NULL);
			}
			break;
		case 3://只更新Discount
			cmdBatchUpdateNote->Parameters->ParamByName("@IDS")->Value = ids;
			cmdBatchUpdateNote->Parameters->ParamByName("@Discount")->Value = discount;
			cmdBatchUpdateNote->Parameters->ParamByName("@Amount")->Value = "";
			cmdBatchUpdateNote->Parameters->ParamByName("@Bsmode")->Value = 7;
			if (BtnOK->Visible && BtnOK->Enabled) {
				cmdBatchUpdateNote->Parameters->ParamByName("@Type")->Value = 0;
			}
			else if (Btn->Enabled ) {
				cmdBatchUpdateNote->Parameters->ParamByName("@Type")->Value = 1;
			}
			else if (Btn1->Enabled ) {
				cmdBatchUpdateNote->Parameters->ParamByName("@Type")->Value = 2;
			}
			cmdBatchUpdateNote->Execute();
			try
			{
				//LockWindowUpdate(dbgrdNote->Handle);//锁定指定窗口，禁止它更新。
				QryNtHeader();
			}
			__finally
			{
				//LockWindowUpdate(NULL);
			}
			break;
		default:
			break;
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall Tfrmdiaobo::N6Click(TObject *Sender)
{
	for (int i = 1; i <= aquery->RecordCount; i++) {
		DBGrid1->DataSource->DataSet->RecNo = i;
		DBGrid1->SelectedRows->CurrentRowSelected = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdiaobo::Label10MouseDown(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y)
{
	if (Button == mbLeft ) {
		TPoint  pt;
		GetCursorPos(&pt);
		pm->Popup(pt.x,pt.y);
	}
}
//---------------------------------------------------------------------------


void __fastcall Tfrmdiaobo::BtnPrintPreviewClick(TObject *Sender)
{
   	PrintPreview(1);
}
//---------------------------------------------------------------------------
void Tfrmdiaobo::PrintPreview(int mode)
{
	/*if (diaobocode->Text == "") {
		return;
	}

   //	Tfrmbookprint *frm = new Tfrmbookprint(this,con);
	//::ShowWindow(frm->Handle, SW_HIDE);
	RvSystem1->SystemSetups >>ssAllowSetup;
	RvSystem1->SystemSetups >>ssAllowDestPreview;
	RvSystem1->SystemSetups >>ssAllowDestPrinter;
	RvSystem1->SystemSetups >>ssAllowPrinterSetup;
	RvSystem1->SystemSetups >>ssAllowDestFile;
	RvSystem1->SystemSetups<<ssAllowDestPrinter;
   	if (mode == 1) {
		RvSystem1->DefaultDest  = rdPreview ;
	}
	else
	{
		RvSystem1->DefaultDest  = rdPrinter ;
	}

	aqprint->Active = false;
	aqprint->Parameters->ParamByName("Code")->Value = diaobocode->Text;

   //	rvdatacondiaobo->DataSet->Close();
	aqprint->Active = true;
   //	rvdatacondiaobo->ExecOpen()  ;

	RvProject1->ProjectFile = ExtractFilePath(Application->ExeName) + "diaobo.rav";
	RvProject1->Close();
	RvProject1->Open();
	if (ftype == 0) {
		stogName = stogName + "配送申请单";
	}else
	{
		stogName = stogName + "配送单";
	}
	// /SetPrint(diaobocode->Text);

	RvProject1->SetParam("title",stogName);
	RvProject1->SetParam("user",username);
	RvProject1->SetParam("danhao",diaobocode->Text);
	RvProject1->SetParam("inuser",edopname->Text);
	RvProject1->SetParam("outstorage",cboutstorage->Text);
	RvProject1->SetParam("data",DateToStr(dtpdata->Date));
	RvProject1->SetParam("instorage",cbinstorage->Text);
	RvProject1->SetParam("instack",cbinbkstack->Text);
	//RvProject1->SetParam("checkuser",cbcheckuser->Text);
	RvProject1->SetParam("totalamount",dbtotalamount->Text);
	RvProject1->SetParam("totalfixprice",dbtotalmayang->Text);
	RvProject1->SetParam("totaldisprice",dntotalshiyang->Text);
	RvProject1->SetParam("bk",membk->Text);
	RvProject1->Execute();
	 */
	//frm->SetPrint(diaobocode->Text);
   //	frm->Print();
   //	delete frm;

    aqprint->Active = false;
	aqprint->Parameters->ParamByName("Code")->Value = diaobocode->Text;
	aqprint->Active = true;


	frxdiaobo->LoadFromFile(Sysutils::ExtractFilePath(Application->ExeName) + "diaobo.fr3");
	frxdiaobo->PrepareReport(true);
	if (mode == 1) {
		frxdiaobo->ShowPreparedReport();
	}
	else
	{
		frxdiaobo->PrintOptions->ShowDialog = false;
		frxdiaobo->Print();
	}
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdiaobo::BtnPrintClick(TObject *Sender)
{
	PrintPreview(2);
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdiaobo::DBNavigator1Click(TObject *Sender, TNavigateBtn Button)

{
	QryNtHeader(aqhd->FieldByName("ZNDiaoNtCode")->AsString);
}
//---------------------------------------------------------------------------


void __fastcall Tfrmdiaobo::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if (Key == VK_F1) {   //查单
		if (!BtnView->Enabled ) {
			return;
		}
		BtnView->Click();
	}
	if (Key == VK_F2) {   //添单
		if (!BtnNew->Enabled ) {
			return;
		}
		BtnNew->Click();
	}
	if (Key == VK_F3) {   //保存
		if (!BtnSaveAll->Enabled ) {
			return;
		}
		BtnSaveAll->Click();
	}
	if (Key == VK_F4) {   //删行
		if (!BtnDelete->Enabled ) {
			return;
		}
		BtnDelete->Click();
	}
	if (Key == VK_F6) {   //统一
		if (!BtnJumptoLine->Enabled ) {
			return;
		}
		BtnJumptoLine->Click();
	}
	if (Key == VK_F7) {   //审核
		if (!Btn->Enabled ) {
			return;
		}
		Btn->Click();
	}
	if (Key == VK_F8) {   //入库
		if (!Btn1->Enabled ) {
			return;
		}
		Btn1->Click();
	}
	if (Key == VK_F10) {   //打印
		if (!BtnPrint->Enabled ) {
			return;
		}
		BtnPrint->Click();
	}
	if (Key == VK_F11) {   //预览
		if (!BtnPrintPreview->Enabled ) {
			return;
		}
		BtnPrintPreview->Click();
	}
	if (Key == VK_F5) {   //反出库
		if (!BtnCancel->Enabled ) {
			return;
		}
		BtnCancel->Click();
	}
	if (Key == VK_F9) {   //反入库
		if (!BtnCancel1->Enabled ) {
			return;
		}
		BtnCancel1->Click();
	}
	if (Key == VK_F12) {   //审核
		if (!BtnOK->Enabled || !BtnOK->Visible  ) {
			return;
		}
		BtnOK->Click();
	}
	if (Shift.Contains(ssAlt)&& Key == 67) {    //定位
		SpeedButton1->Click();
	}
	if (Shift.Contains(ssCtrl)&& Key == 78 ) {    //最小化
		BtnAlignBottom->Click();
	}
	if (Shift.Contains(ssCtrl)&& Key == 81 ) {    //退出
		BtnExit->Click();
	}
	if (Shift.Contains(ssCtrl)&& Key ==90) {   //恢复窗口
		WindowState = wsNormal  ;
	}
	if (Shift.Contains(ssCtrl)&& Key ==70  ) {    //查书
		BtnView1->Click();
	}
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdiaobo::BtnAlignBottomClick(TObject *Sender)
{
	WindowState = wsMinimized ;

}
//---------------------------------------------------------------------------

void __fastcall Tfrmdiaobo::BtnView1Click(TObject *Sender)
{
	Tfrmbookquery * frm = new Tfrmbookquery(Application,con,fstgid);
	frm->ShowModal();
	delete frm;
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdiaobo::N7Click(TObject *Sender)
{
	if (aquery->IsEmpty() ) {
        return;
	}
	AnsiString path;
	AnsiString StgID;
	AnsiString sql;
	StgID = "-1";
	aquery->DisableControls();
	if (DBGrid1->SelectedRows->Count > 0) {
    	for (int i=0; i < DBGrid1->SelectedRows->Count; i++)
		{
			aquery->Bookmark = DBGrid1->SelectedRows->Items[i];
			StgID = StgID + "," + aquery->FieldByName("ID")->AsString;
		}
	}
	else
	{
		StgID = StgID + "," + aquery->FieldByName("ID")->AsString;
	}

	adospcopy->ProcedureName = "CopyData";
	adospcopy->Parameters->Clear();
	adospcopy->Parameters->CreateParameter("@mode",ftInteger,pdInput,sizeof(int),4);
	adospcopy->Parameters->CreateParameter("@ID",ftString,pdInput,StgID.Length(),StgID.c_str());
	adospcopy->Parameters->CreateParameter("@userid",ftInteger,pdInput,sizeof(int),fuserid );
	if (fstgid == outstorage){
		adospcopy->Parameters->CreateParameter("@ininfo",ftInteger,pdInput,sizeof(int),0);
	}
	else
	{
		adospcopy->Parameters->CreateParameter("@ininfo",ftInteger,pdInput,sizeof(int),1);
	}
	adospcopy->ExecProc();

	aquery->EnableControls();
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdiaobo::N8Click(TObject *Sender)
{
	if (ftype != 1){
    	return;
	}
	if (diaobocode->Text == "") {
        return;
	}
	if (fstgid != outstorage)
	{

        ShowMsg(Handle ,"配送出库店不是本店，不能粘贴！",3);
		return;
	}
	AnsiString sql;
	sql = "select state from BS_ZN_DiaoNoteHeader where stgntcodestr = '" + diaobocode->Text+"'";
	aq->Close();
	aq->SQL->Clear();
	aq->SQL->Add(sql);
	aq->Open();
	if (aq->FieldByName("state")->AsInteger > 0 ) {

                 ShowMsg(Handle ,"配送已经确定，不能再粘贴！",3);
		return;
	}
	adospcopy->ProcedureName = "StickData";
	adospcopy->Parameters->Clear();
	adospcopy->Parameters->CreateParameter("@mode",ftInteger,pdInput,sizeof(int),6);
	adospcopy->Parameters->CreateParameter("@HeadId",ftInteger,pdInput,sizeof(int),dsetNtHeader->FieldByName("ID")->AsInteger);
	adospcopy->Parameters->CreateParameter("@userid",ftInteger,pdInput,sizeof(int),fuserid );
        adospcopy->Parameters->CreateParameter("@stgid",ftInteger,pdInput,sizeof(int),fstgid );
	adospcopy->ExecProc();

	QryNtHeader(aqhd->FieldByName("ZNDiaoNtCode")->AsString);
       //	QryNtHeader(diaobocode->Text);
	Screen->Cursor = crDefault ;
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdiaobo::cboutstorageChange(TObject *Sender)
{
	outstorage = int(cboutstorage->Items->Objects[cboutstorage->ItemIndex]);
	ReadinData();
}

//---------------------------------------------------------------------------

void Tfrmdiaobo::ExcelExport(TRzDBGrid* dbg)
{
	AnsiString temptext,path  ;
	int k = dbg->DataSource ->DataSet ->RecordCount ,n=0;

	savedlg->FileName = "配送单"+diaobocode->Text;
	if (savedlg->Execute())
	{
		String DBPath,Name;
		DBPath = Sysutils::ExtractFilePath(savedlg->FileName .c_str()  );
		Name = Sysutils::ExtractFileName(savedlg->FileName .c_str() );
		DBPath = DBPath + Name ;
		path =  DBPath;
	}
	else
	{
	}
	int  iFileHandle;
	int   iFileLength;
	if(FileExists(path))
	   //iFileHandle = FileOpen(path.c_str() ,fmOpenReadWrite);
	   if (DeleteFileA(path))
			iFileHandle = FileCreate(path.c_str());
	   else
			;
	else
		iFileHandle = FileCreate(path.c_str());

	if (ftype ==0) {
		temptext = ",,,配送单";
	}else
	{
	   temptext = ",,,配送申请单";
	}

	iFileLength   =   FileSeek(iFileHandle,0,2);
	FileWrite(iFileHandle,temptext.c_str() ,temptext.Length());

	temptext = "\n";
	temptext = temptext + "单号," + diaobocode->Text + ",操作人," + edopname->Text  ;
	iFileLength   =   FileSeek(iFileHandle,0,2);
	FileWrite(iFileHandle,temptext.c_str() ,temptext.Length());

	temptext = "\n";
	temptext = temptext + "调出店," +cboutstorage->Text+ ",日期," + DateToStr(dtpdata->Date);
	iFileLength   =   FileSeek(iFileHandle,0,2);
	FileWrite(iFileHandle,temptext.c_str() ,temptext.Length());

	temptext = "\n";
	temptext = temptext + "调入店," + cbinstorage->Text + ",调入库位," + cbinbkstack->Text  ;
	iFileLength   =   FileSeek(iFileHandle,0,2);
	FileWrite(iFileHandle,temptext.c_str() ,temptext.Length());

	temptext = "\n";
	temptext = temptext + "备注," + membk->Text ;
	iFileLength   =   FileSeek(iFileHandle,0,2);
	FileWrite(iFileHandle,temptext.c_str() ,temptext.Length());


	int t1= 0;
	temptext = "\n";
	for(int q=0;q<dbg->FieldCount-1 ;++q)
	{
		if (dbg->Columns->Items[q]->Visible == true) {
			t1++;

				temptext = temptext + dbg->Columns ->Items [q]->Title ->Caption + ",";
		}
	}
	FileWrite(iFileHandle,temptext.c_str() ,temptext.Length());

	int t2 = dbg->DataSource ->DataSet ->RecordCount ;

	dbg->DataSource ->DataSet ->First();
	dbg->DataSource ->DataSet->DisableControls();
	for(int   i=2+n;i<=t2+1+n ;i++)
	{
		t1=0;
		temptext = "\n";
		for(int j=1;j<dbg->Columns ->Count  ;j++)
		{
			if (dbg->Columns->Items[j-1]->Visible == true) {
				if (dbg->Columns ->Items [j-1]->FieldName == "ISBN") {
					t1++;
					temptext = temptext + "'" + dbg->DataSource ->DataSet ->FieldByName(dbg->Columns ->Items [j-1]->FieldName )->AsAnsiString + ",";
				}
				else if (dbg->Columns ->Items [j-1]->FieldName == "CatalogName") {
                	AnsiString bookname;
					int len;
					bookname = dbg->DataSource ->DataSet ->FieldByName(dbg->Columns ->Items [j-1]->FieldName )->AsAnsiString;
					bookname = StringReplace(bookname , ",",".",TReplaceFlags()<<rfReplaceAll);
					temptext = temptext + bookname + ",";
				}
				else if (dbg->Columns ->Items [j-1]->FieldName == "id" || dbg->Columns ->Items [j-1]->FieldName == "backdot"){

				}
				else
				{

						temptext = temptext + dbg->DataSource ->DataSet ->FieldByName(dbg->Columns ->Items [j-1]->FieldName )->AsAnsiString + ",";
				}
			}
		}
		FileWrite(iFileHandle,temptext.c_str() ,temptext.Length());
		dbg->DataSource ->DataSet ->Next() ;
	}

    dbg->DataSource ->DataSet->EnableControls();

	AnsiString pxamount,mayang,shiyang;
	temptext = "\n";

	iFileLength   =   FileSeek(iFileHandle,0,2);
	FileWrite(iFileHandle,temptext.c_str() ,temptext.Length());

	FileClose(iFileHandle);


         ShowMsg(Handle ,"导出完毕！",3);
}
//---------------------------------------------------------------------------


void __fastcall Tfrmdiaobo::BtnExportClick(TObject *Sender)
{
   //	if (DBGrid1->Active && DBGrid1->RecordCount >= 1)
   //	{
		ExcelExport(DBGrid1);
  //	}
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdiaobo::cbinbkstackClick(TObject *Sender)
{
	if (aquery->IsEmpty()) {
		return;
	}
	bkchange = 1;
	if (DBGrid1->SelectedRows->Count == 0)
	{
		UpdateNote1();
	}
	else if (DBGrid1->SelectedRows->Count > 0)
	{
		//UpdateNote1();
		for (int i=0; i < DBGrid1->SelectedRows->Count; i++)
		{
			aquery->Bookmark = DBGrid1->SelectedRows->Items[i];
			UpdateNote1();
		}
	}
	else
		return;

	bkchange = 0;
	QryNtHeader();
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdiaobo::BtnFinishClick(TObject *Sender)
{
	if (dsetNtHeader->IsEmpty() ) {
		return;
	}
	Tfrmretailbookup *frm = new Tfrmretailbookup(Application,con,fstgid);
	frm->Diaobo = this;
	frm->modle = 2;
	frm->ShowModal();
	delete frm;
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdiaobo::DBGrid1CellClick(TColumn *Column)
{
	if (aquery->IsEmpty() ) {
    	return;
	}
	cbinbkstack->ItemIndex = cbinbkstack->Items->IndexOfObject((TObject*)aquery->FieldByName("instkid")->AsInteger );
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdiaobo::BtnCancelClick(TObject *Sender)
{
    if (aquery->IsEmpty() ) {
		return;
	}
	try
	{
        cmdshenhe->Parameters->ParamByName("@NtHeaderID")->Value
			= dsetNtHeader->FieldByName("ID")->AsInteger;
		cmdshenhe->Parameters->ParamByName("@Bsmode")->Value = 3;   //反出库
		cmdshenhe->Parameters->ParamByName("@stgid")->Value = fstgid;
		cmdshenhe->Parameters->ParamByName("@userid")->Value = fuserid;
		cmdshenhe->Execute();
		QryNtHeader(dsetNtHeader->FieldByName("ZNDiaoNtCode")->AsString);
	}
	__finally
	{
	}
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdiaobo::BtnCancel1Click(TObject *Sender)
{
    if (aquery->IsEmpty() ) {
		return;
	}
	try
	{
        cmdshenhe->Parameters->ParamByName("@NtHeaderID")->Value
			= dsetNtHeader->FieldByName("ID")->AsInteger;
		cmdshenhe->Parameters->ParamByName("@Bsmode")->Value = 4;   //反入库
		cmdshenhe->Parameters->ParamByName("@stgid")->Value = fstgid;
		cmdshenhe->Parameters->ParamByName("@userid")->Value = fuserid;
		cmdshenhe->Execute();
		QryNtHeader(dsetNtHeader->FieldByName("ZNDiaoNtCode")->AsString);
                dbamountbk->Enabled = true;
	}
	__finally
	{
	}
}
//---------------------------------------------------------------------------


void __fastcall Tfrmdiaobo::BtnOKClick(TObject *Sender)
{
	if (aquery->IsEmpty() ) {
		return;
	}
	try
	{
        cmdshenhe->Parameters->ParamByName("@NtHeaderID")->Value
			= dsetNtHeader->FieldByName("ID")->AsInteger;
		cmdshenhe->Parameters->ParamByName("@Bsmode")->Value = 5;   //申请审核
		cmdshenhe->Parameters->ParamByName("@stgid")->Value = fstgid;
		cmdshenhe->Parameters->ParamByName("@userid")->Value = fuserid;
		cmdshenhe->Execute();
		QryNtHeader(dsetNtHeader->FieldByName("ZNDiaoNtCode")->AsString);
	}
	__finally
	{

	}
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdiaobo::dbamountbkKeyPress(TObject *Sender, wchar_t &Key)
{
	if (Key == '\r') {
    	if (aquery->IsEmpty() ) {
			return;
		}
		try {
			aquery->UpdateBatch(arCurrent);
        } catch (...) {
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdiaobo::BtnBulletsClick(TObject *Sender)
{
	if (dsetNtHeader->IsEmpty() ) {
		return;
	}
	int storage;
	try {
		storage = int(cbinstorage->Items->Objects[cbinstorage->ItemIndex]);
    } catch (...) {
	}

	Tfrmpsinorder *frm = new Tfrmpsinorder(Application,con,storage,fuserid,dsetNtHeader->FieldByName("id")->AsInteger);
	frm->Diaobo = this;
	frm->ShowModal();
	delete frm;
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdiaobo::membkKeyPress(TObject *Sender, wchar_t &Key)
{
	if (Key == '\r') {
		if (dsetNtHeader->IsEmpty() ) {
			return;
		}
		dsetNtHeader->Edit();
		dsetNtHeader->FieldByName("Remarks")->AsAnsiString =membk->Text ;
		dsetNtHeader->UpdateBatch(arCurrent);
	}
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdiaobo::frxdiaoboGetValue(const UnicodeString VarName, Variant &Value)

{
	if (CompareText(VarName,"\"title\"")==0 ) {
		  Value = stogName + "配送单";
	}
	if (CompareText(VarName,"\"user\"")==0 ) {
		  Value = username;
	}
	if (CompareText(VarName,"\"danhao\"")==0 ) {
		  Value = diaobocode->Text;
	}
	if (CompareText(VarName,"\"outstorage\"")==0 ) {
		  Value = cboutstorage->Text;
	}
	if (CompareText(VarName,"\"data\"")==0 ) {
		  Value = DateToStr(dtpdata->Date);
	}
	if (CompareText(VarName,"\"instorage\"")==0 ) {
		  Value = cbinstorage->Text;
	}
	if (CompareText(VarName,"\"totalamount\"")==0 ) {
		  Value = dbtotalamount->Text;
	}
	if (CompareText(VarName,"\"totalfixprice\"")==0 ) {
		  Value = dbtotalmayang->Text;
	}
	if (CompareText(VarName,"\"totaldisprice\"")==0 ) {
		  Value = dntotalshiyang->Text;
	}
	if (CompareText(VarName,"\"bk\"")==0 ) {
		  Value = membk->Text;
	}
	if (CompareText(VarName,"\"state\"")==0 ) {
		  Value = edstate->Text;
	}
	if (CompareText(VarName,"\"inuser\"")==0 ) {
		  Value = edopname->Text;
	}
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdiaobo::SpeedButton1Click(TObject *Sender)
{
	if (GroupBox3->Visible) {
		GroupBox3->Visible = false;
	}
	else
	{
		GroupBox3->Visible = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdiaobo::chfsluruClick(TObject *Sender)
{
	if (chfsluru->Checked ) {
		chfoceset->Checked = true;
	}
	else if (chfsamount->Checked ) {
		chfoceset->Checked = true;
	}
	else if (chfsdiscount->Checked ) {
		chfoceset->Checked = true;
	}
	else
	{
		chfoceset->Checked = false;
	}
}
//---------------------------------------------------------------------------



void __fastcall Tfrmdiaobo::FormClose(TObject *Sender, TCloseAction &Action)
{
    // dsetNtHeader->Active = false;

      dsetNtHeader->Active = false;
      TfrmMDIChild::FormClose(Sender, Action);
}
//---------------------------------------------------------------------------



void __fastcall Tfrmdiaobo::dbnumamountExit(TObject *Sender)
{
  if (dbnumamount->Value==0) {
      dbnumamount->Value=0;
  }
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdiaobo::toolshowmainmenuClick(TObject *Sender)
{
    if (toolshowmainmenu->Caption =="显示\r主菜单")
    {

      HANDLE hWindow = FindWindow("TfrmMain",NULL);
      SendMessage(hWindow ,WM_MYMESSAGE,1,0);
      toolshowmainmenu->Caption ="隐藏\r主菜单";
    }else

    {
    HANDLE hWindow = FindWindow("TfrmMain",NULL);
    SendMessage(hWindow ,WM_MYMESSAGE,0,0);
      toolshowmainmenu->Caption ="显示\r主菜单";

    }
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdiaobo::RzToolButton1Click(TObject *Sender)

{

if (!ispowertozuofei) {
  ShowMsg(Handle ,"无权限，请与管理员联系!",3);
  return;
}

if ((edstate->Text=="待审核")||(edstate->Text=="待出库")) {


  if (ShowMsg(Handle ,"作废后，该单所有的明细将被清空,并且不可恢复,是否继续?",4)==1 ) {


              DBGrid1->DataSource->DataSet->DisableControls();

            for (int i = 1; i <= aquery->RecordCount; i++) {
                    DBGrid1->DataSource->DataSet->RecNo = i;
                    DBGrid1->SelectedRows->CurrentRowSelected = true;
            }
           DBGrid1->DataSource->DataSet->EnableControls();
            if (!dsetNtHeader->IsEmpty() ) {
                    dsetNtHeader->Edit();
                    dsetNtHeader->FieldByName("Remarks")->AsAnsiString ="该单已作废!";
                    dsetNtHeader->UpdateBatch(arCurrent);
            }
            DelNote();

       }



  }else ShowMsg(Handle ,"已确认单据，不能作废!",3);
}
//---------------------------------------------------------------------------

