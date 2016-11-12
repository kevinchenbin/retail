//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "QryWsaleNoteForm.h"
#include "Notedetail.h"
#include "..\bsadmin\UnitSelectClient.h"
#include "global.h"
#include "Selecttype.h"
#include "bookhistory.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "QryStorageNoteForm"
#pragma link "RzButton"
#pragma link "RzDBCmbo"
#pragma link "RzDBGrid"
#pragma link "RzEdit"
#pragma link "RzLine"
#pragma link "RzPanel"
#pragma link "RzRadChk"
#pragma link "RzTabs"
#pragma link "RzDTP"
#pragma resource "*.dfm"
TfrmQryWsaleNote *frmQryWsaleNote;
//---------------------------------------------------------------------------
__fastcall TfrmQryWsaleNote::TfrmQryWsaleNote(TComponent* Owner)
	: TfrmQryStorageNote(Owner)
{
   dtedtEnd->Date= Now();
   dtedtStart->Date = Now();
   cbinstorage->Caption = "发货";
   //dbgrdByNote->Columns->Items[13]->Title->Caption = "批销商";
   totalchecked = 0.0000;
   totalunchecked = 0.0000;
}
//---------------------------------------------------------------------------
String TfrmQryWsaleNote::QueryDesic()
{
	 TADOQuery * aq;
   aq = new TADOQuery(this);
   aq->Connection = m_con ;
   aq->Close();
   aq->SQL->Clear();
   aq->SQL->Add("select bk from sys_bsset where name ='salexiaoshudian'");
   aq->Open();
   Desic1 = aq->FieldByName("bk")->AsAnsiString ;
   return "￥###,###,##"+ aq->FieldByName("bk")->AsAnsiString ;
   delete aq;

}
//---------------------------------------------------------------------------
void __fastcall TfrmQryWsaleNote::tlbtnQryClick(TObject *Sender)
{
	Query();
	switch (pgcntrlResult->ActivePage->Tag) {
		case 1:
			((TFloatField *)dbgrdByNtHeader->DataSource->DataSet->FieldByName("FixedPrice"))->DisplayFormat = Desic;
			((TFloatField *)dbgrdByNtHeader->DataSource->DataSet->FieldByName("DiscountedPrice"))->DisplayFormat = Desic;
			((TFloatField *)dbgrdByNtHeader->DataSource->DataSet->FieldByName("checked"))->DisplayFormat = Desic;
			((TFloatField *)dbgrdByNtHeader->DataSource->DataSet->FieldByName("nochecked"))->DisplayFormat = Desic;
			((TFloatField *)dbgrdByNtHeader->DataSource->DataSet->FieldByName("profite"))->DisplayFormat = Desic;
			((TFloatField *)dbgrdByNtHeader->DataSource->DataSet->FieldByName("salecbprice"))->DisplayFormat = Desic;
			break;
		case 2:
			((TFloatField *)dbgrdByNote->DataSource->DataSet->FieldByName("FixedPrice"))->DisplayFormat = Desic;
		    	((TFloatField *)dbgrdByNote->DataSource->DataSet->FieldByName("DiscountedPrice"))->DisplayFormat = Desic;
		       //	((TFloatField *)dbgrdByNote->DataSource->DataSet->FieldByName("Discount"))->DisplayFormat = Desic;
			((TFloatField *)dbgrdByNote->DataSource->DataSet->FieldByName("profite"))->DisplayFormat = Desic;
			((TFloatField *)dbgrdByNote->DataSource->DataSet->FieldByName("salecbprice"))->DisplayFormat = Desic;
			break;
		case 3:
			((TFloatField *)dbgrdByCustomer->DataSource->DataSet->FieldByName("FixedPrice"))->DisplayFormat = Desic;
			((TFloatField *)dbgrdByCustomer->DataSource->DataSet->FieldByName("DiscountedPrice"))->DisplayFormat = Desic;
			((TFloatField *)dbgrdByCustomer->DataSource->DataSet->FieldByName("checked"))->DisplayFormat = Desic;
			((TFloatField *)dbgrdByCustomer->DataSource->DataSet->FieldByName("nochecked"))->DisplayFormat = Desic;
			((TFloatField *)dbgrdByCustomer->DataSource->DataSet->FieldByName("profite"))->DisplayFormat = Desic;
			((TFloatField *)dbgrdByCustomer->DataSource->DataSet->FieldByName("salecbprice"))->DisplayFormat = Desic;
			break;
		case 4:
			((TFloatField *)dbgrdByBktype->DataSource->DataSet->FieldByName("FixedPrice"))->DisplayFormat = Desic;
			((TFloatField *)dbgrdByBktype->DataSource->DataSet->FieldByName("DiscountedPrice"))->DisplayFormat = Desic;
			((TFloatField *)dbgrdByBktype->DataSource->DataSet->FieldByName("profite"))->DisplayFormat = Desic;
			((TFloatField *)dbgrdByBktype->DataSource->DataSet->FieldByName("salecbprice"))->DisplayFormat = Desic;
			break;
		case 5:
			((TFloatField *)dbgrdByPress->DataSource->DataSet->FieldByName("FixedPrice"))->DisplayFormat = Desic;
			((TFloatField *)dbgrdByPress->DataSource->DataSet->FieldByName("DiscountedPrice"))->DisplayFormat = Desic;
			((TFloatField *)dbgrdByPress->DataSource->DataSet->FieldByName("profite"))->DisplayFormat = Desic;
			((TFloatField *)dbgrdByPress->DataSource->DataSet->FieldByName("salecbprice"))->DisplayFormat = Desic;
			break;

	default:
		;
	}
}
//---------------------------------------------------------------------------
void TfrmQryWsaleNote::Query()
{
	Desic = QueryDesic();
	long double    TotalMan=0.0000,TotalShi=0.0000,totalprofite = 0.0000;
	int TotalNum=0;
	totalchecked = 0.0000;
	totalunchecked = 0.0000;
	AnsiString isbn;
	if (chckbxISBN->Checked && edtISBN->Text != "") {
		isbn = edtISBN->Text.Trim();
		if (isbn.Length() == 10 || isbn.Length() == 13  ) {
			isbn = isbn.Delete(isbn.Length(),1);
		}
	}
	spQryNote->Active = false;
	for (int i = 0; i < spQryNote->Parameters->Count; i++)
	{
        spQryNote->Parameters->operator [](i)->Value = System::Variant();
	}

	if (chckbxStartTime->Checked ) //开始时间
		spQryNote->Parameters->ParamByName("@Start")->Value = dtedtStart->Date;

	if (chckbxEndTime->Checked ) //结束时间
		spQryNote->Parameters->ParamByName("@End")->Value = dtedtEnd->Date;

    if (chckbxBookName->Checked && edtBookName->Text != "") //书名
		spQryNote->Parameters->ParamByName("@Name")->Value = "%" + edtBookName->Text + "%";

	if (chckbxUserDefNum->Checked && edtUserDefNum->Text != "") //自编码
		spQryNote->Parameters->ParamByName("@UserDefCode")->Value = "%" + edtUserDefNum->Text + "%";

	if (chckbxPress->Checked && dblkpcbbPress->Text != "") //出版社
		spQryNote->Parameters->ParamByName("@PressID")->Value = dsetPress->FieldByName("ID")->AsInteger;

	if (chckbxISBN->Checked && edtISBN->Text != "") //ISBN
          if (isbn.Length()>13) {
               spQryNote->Parameters->ParamByName("@ISBN")->Value = isbn;
         }else
         {
               spQryNote->Parameters->ParamByName("@ISBN")->Value =  isbn ;
         }


	if (chckbxPrice->Checked && numedtMinPrice->Text != "") //定价
		spQryNote->Parameters->ParamByName("@MinPrice")->Value = numedtMinPrice->Value;

	if (chckbxPrice->Checked && numedtMaxPrice->Text != "") //定价
		spQryNote->Parameters->ParamByName("@MaxPrice")->Value = numedtMaxPrice->Value;

	if (chckbxType->Checked && edtyname->Text != "") //书目类型
		spQryNote->Parameters->ParamByName("@BktypeID")->Value = TypeID;

	if (chckbxCustomer->Checked && dblkpcbbCustomer->Text != "") //客户
		spQryNote->Parameters->ParamByName("@CustomerID")->Value = dsetCustomer->FieldByName("ID")->AsInteger;

	if (chckbxAuthor->Checked && edtAuthor->Text != "") //作者
		spQryNote->Parameters->ParamByName("@Author")->Value = "%" + edtAuthor->Text + "%";

	if (chckbxRemarks->Checked && edtRemarks->Text != "") //备注
		spQryNote->Parameters->ParamByName("@Remarks")->Value = "%" + edtRemarks->Text + "%";

	if (chckbxBkstack->Checked) //库位
		spQryNote->Parameters->ParamByName("@BkstackID")->Value = dsetBookstack->FieldByName("ID")->AsInteger;

	if (chckbxAmount->Checked && numedtMinAmount->Text != "") //库存
		spQryNote->Parameters->ParamByName("@MinAmount")->Value = numedtMinAmount->IntValue;

	if (chckbxAmount->Checked && numedtMaxAmount->Text != "") //库存
		spQryNote->Parameters->ParamByName("@MaxAmount")->Value = numedtMaxAmount->IntValue;

	if (chckbxStorage->Checked) //店
		//spQryNote->Parameters->ParamByName("@StgID")->Value = dsetInit->FieldByName("StorageID")->AsInteger;
        spQryNote->Parameters->ParamByName("@StgID")->Value = dsetStorage->FieldByName("ID")->AsInteger;
    if (chdanhao->Checked && eddanhao->Text != "") {
		spQryNote->Parameters->ParamByName("@NoteCode")->Value = eddanhao->Text .Trim();
	}
	if (cbinstorage->Checked && !cboutstorage->Checked ) {
		spQryNote->Parameters->ParamByName("@type")->Value = 1; //正数表示批销
	}

	if (cboutstorage->Checked && !cbinstorage->Checked ) {
        spQryNote->Parameters->ParamByName("@type")->Value = -1; //负数表示退货
	}
	if (chstaff->Checked ) {    //操作员
		try {
			spQryNote->Parameters->ParamByName("@staff")->Value = int(cbstaff->Items->Objects[cbstaff->ItemIndex]);
		} catch (...) {
			ShowMsg(this->Handle,"请选择正确的操作员！",3);
			return;
		}
	}
	if (chdiscount->Checked && edmindiscount->Text != "") {   //最小折扣
		spQryNote->Parameters->ParamByName("@mindiscount")->Value = StrToFloat(edmindiscount->Text);
	}
	if (chdiscount->Checked && edmaxdiscount->Text != "") {   //最大折扣
		spQryNote->Parameters->ParamByName("@maxdiscount")->Value =  StrToFloat(edmaxdiscount->Text);
	}
	if (chnocheck->Checked ) {   //未结
		spQryNote->Parameters->ParamByName("@check")->Value = 1;
		spQryNote->Parameters->ParamByName("@nocheck")->Value = 1;
	}
	if (chcheckpart->Checked ) {   //已结部分
		spQryNote->Parameters->ParamByName("@check")->Value = 1;
		spQryNote->Parameters->ParamByName("@checkpart")->Value = 1;
	}
	if (chchecked->Checked ) {   //已经全部
		spQryNote->Parameters->ParamByName("@check")->Value = 1;
		spQryNote->Parameters->ParamByName("@checked")->Value = 1;
	}
	if (chckbx1->Checked ) {
		spQryNote->Parameters->ParamByName("@SupplierID")->Value = dsetSupplier->FieldByName("ID")->AsInteger;
	}
	if (chjytype->Checked ) {
		spQryNote->Parameters->ParamByName("@BKJYtype")->Value = cbjytype->ItemIndex ;
	}
          // ShowMessage(IntToStr(int(cbqueyueselect->Items->Objects[cbqueyueselect->ItemIndex])));
        if ((cbquyue->Checked)&&(cbqueyueselect->ItemIndex!=-1)) {        //区域选择
               	spQryNote->Parameters->ParamByName("@damage")->Value = (int)(cbqueyueselect->Items->Objects[cbqueyueselect->ItemIndex]);

        }

	if (chrktype->Checked ) {
		if (cbrktype->ItemIndex == 0) {
			spQryNote->Parameters->ParamByName("@outstorage")->Value = 0 ;
		}
		else if (cbrktype->ItemIndex == 1) {
			spQryNote->Parameters->ParamByName("@outstorage")->Value = 2 ;
		}
	}


	if (chsuptype->Checked && cbsuptype->Text != "") {
		spQryNote->Parameters->ParamByName("@instorage")->Value = int(cbsuptype->Items->Objects[cbsuptype->ItemIndex]);
	}
            //chandan->Checked
	if (true) {
		spQryNote->Parameters->ParamByName("@andan")->Value = 1 ;
		if (danhaodisplay) {
		     //	dbgrdByNote->Columns->Items[10]->Visible = true;
		      //	dbgrdByNote->Columns->Items[9]->Visible = false;
		}
		else
		{
		       //	dbgrdByNote->Columns->Items[10]->Visible = false;
		      //	dbgrdByNote->Columns->Items[9]->Visible = true;
		}

                 dbgrdByNote->Columns->Items[10]->Visible = false;
         dbgrdByNote->Columns->Items[9]->Visible = true;
	}
	else
	{
                dbgrdByNote->Columns->Items[8]->Visible = false;
         dbgrdByNote->Columns->Items[11]->Visible = false;
         dbgrdByNote->Columns->Items[10]->Visible = false;
	}

        //金额查询

        if (cbjinge->Checked) {
              	spQryNote->Parameters->ParamByName("@jinge")->Value = nejinge->Text;
        }

	spQryNote->Parameters->ParamByName("@Bsmode")->Value = 2;//批销单查询模式
	spQryNote->Parameters->ParamByName("@SearchMode")->Value = pgcntrlResult->ActivePage->Tag;
       // dbgrdByNote->Columns->Items[13]->Visible = true;
	//初始化汇总

	try
	{
		spQryNote->Active = true;

		switch (pgcntrlResult->ActivePage->Tag)
		{
		case 1:
			dsrcByNtHeader->DataSet = NULL;
			dsetByNtHeader->Recordset = spQryNote->Recordset;
			FormatFloat("#,##0.00",dsetByNtHeader->FieldByName("FixedPrice")->AsFloat);

			dsrcByNtHeader->DataSet = dsetByNtHeader;

			break;
		case 2:
			dsrcByNote->DataSet = NULL;
			dsetByNote->Recordset = spQryNote->Recordset;
			dsrcByNote->DataSet = dsetByNote;
        	break;
		case 3:
			dsrcByCustomer->DataSet = NULL;
			dsetByCustomer->Recordset = spQryNote->Recordset;
			dsrcByCustomer->DataSet = dsetByCustomer;
        	break;
		case 4:
			dsrcByBktype->DataSet = NULL;
			dsetByBktype->Recordset = spQryNote->Recordset;
			dsrcByBktype->DataSet = dsetByBktype;
        	break;
		case 5:
			dsrcByPress->DataSet = NULL;
			dsetByPress->Recordset = spQryNote->Recordset;
			dsrcByPress->DataSet = dsetByPress;
        	break;
		default:
			break;
		}
	}
	catch(...)
	{
        //
    }
}
void __fastcall TfrmQryWsaleNote::edtPressKeyPress(TObject *Sender, wchar_t &Key)
{
	//查询供应商
	if (Key == '\r')
	{
		String sql = "select * from BS_PressInfo where AbbreviatedName like '%";
		sql = sql + edtPress->Text + "%'";
		dsetPress->Active = false;
		dsetPress->CommandText = sql;
		dsetPress->Active = true;
		if (dsetPress->RecordCount >= 1)
		{
			dsetPress->First();
			dblkpcbbPress->KeyValue = dsetPress->FieldByName("ID")->AsInteger ;
		}
	}
}
//---------------------------------------------------------------------------


void __fastcall TfrmQryWsaleNote::tlbtnExportClick(TObject *Sender)
{
		//Excel导出
	switch (pgcntrlResult->ActivePage->Tag)
	{
	case 1:
		if (dsetByNtHeader->Active && dsetByNtHeader->RecordCount > 0) {
				DbgridToExcel(dbgrdByNtHeader);
			}
		break;
	case 2:
		if (dsetByNote->Active && dsetByNote->RecordCount > 0) {
				DbgridToExcel(dbgrdByNote);
			}
		break;
	case 3:
		if (dsetByCustomer->Active && dsetByCustomer->RecordCount > 0) {
				DbgridToExcel(dbgrdByCustomer);
			}
		break;
	case 4:
		if (dsetByBktype->Active && dsetByBktype->RecordCount > 0) {
				DbgridToExcel(dbgrdByBktype);
			}
		break;
	case 5:
		if (dsetByPress->Active && dsetByPress->RecordCount > 0) {
				DbgridToExcel(dbgrdByPress);
			}
		break;
	default:
		break;
	}
}
//---------------------------------------------------------------------------
bool __fastcall TfrmQryWsaleNote::DbgridToExcel(TDBGridEh* dbg)
{
	AnsiString temptext,path;
        TDateTime t=   Date();
	savedlg->FileName = "发货查询"+t.DateString();
	if (savedlg->Execute())
	{
		String DBPath,Name;
		DBPath = ExtractFilePath(savedlg->FileName .c_str()  );
		Name = ExtractFileName(savedlg->FileName .c_str() );
		DBPath = DBPath + Name + ".csv";
		path =  DBPath;
	}
	else
	{
    	return false;
	}
	int  iFileHandle;
	int   iFileLength;

	if(FileExists(path))
	   if (DeleteFileA(path))
			iFileHandle = FileCreate(path.c_str());
	   else
			return false;
	else
		iFileHandle = FileCreate(path.c_str());

	int k = dbg->DataSource ->DataSet ->RecordCount ,n=0;

	int t1= 0;
	for(int q=0;q<dbg->FieldCount ;++q)
	{
		if (dbg->Columns->Items[q]->Visible == true) {
			/*t1++;
			temptext = "'"+ dbg->Columns ->Items [q]->Title ->Caption;
			v.OlePropertyGet("Cells",1+n,(t1)).OlePropertySet("Value",temptext .c_str() );
			v.OlePropertyGet("Cells",1+n,t1).OleFunction("BorderAround",1,2,1); */
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
		for(int j=1;j<dbg->Columns ->Count+1  ;j++)
		{
			if (dbg->Columns->Items[j-1]->Visible == true) {
				if (dbg->Columns ->Items [j-1]->FieldName == "BookName" || dbg->Columns ->Items [j-1]->FieldName == "Remarks") {
					AnsiString bookname;
					bookname = dbg->DataSource ->DataSet ->FieldByName(dbg->Columns ->Items [j-1]->FieldName )->AsAnsiString;
					bookname = StringReplace(bookname , ",",".",TReplaceFlags()<<rfReplaceAll);
					bookname = StringReplace(bookname , '\n',"",TReplaceFlags()<<rfReplaceAll);
					bookname = StringReplace(bookname , '\r',"",TReplaceFlags()<<rfReplaceAll);
					temptext = temptext + bookname + ",";
				}
				else if (dbg->Columns ->Items [j-1]->FieldName == "FixedPrice" || dbg->Columns ->Items [j-1]->FieldName == "DiscountedPrice" || dbg->Columns ->Items [j-1]->FieldName == "checked" || dbg->Columns ->Items [j-1]->FieldName == "nochecked" || dbg->Columns ->Items [j-1]->FieldName == "salecbprice" || dbg->Columns ->Items [j-1]->FieldName == "profite") {
					temptext = temptext + FormatFloat(Desic1,dbg->DataSource ->DataSet ->FieldByName(dbg->Columns ->Items [j-1]->FieldName )->AsFloat) + ",";
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

	temptext = "\n合计,";
	AnsiString text;
	for(int q=1;q<dbg->FieldCount ;++q)
	{
		if (dbg->Columns->Items[q]->Visible == true) {
			text = dbg->GetFooterValue(q,dbg->Columns->Items [q]);
			text = StringReplace(text , ",","",TReplaceFlags()<<rfReplaceAll);
			text = StringReplace(text , "-","'-",TReplaceFlags()<<rfReplaceAll);
			temptext = temptext + text + ",";
		}
	}

	FileWrite(iFileHandle,temptext.c_str() ,temptext.Length());
	FileClose(iFileHandle);
	ShowMsg(this->Handle,"导出完毕！",3);
	return false;
}
//---------------------------------------------------------------------------


void __fastcall TfrmQryWsaleNote::dblkpcbbSupplierIDClick(TObject *Sender)
{
	if (dblkpcbbSupplierID->Text != "") {
		chckbx1->Checked = true;
	}
}
//---------------------------------------------------------------------------
void TfrmQryWsaleNote::View()
{
	//单号显示
	if (danhaodisplay) {
		dbgrdByNtHeader->Columns->Items[1]->Visible = false;
		dbgrdByNtHeader->Columns->Items[2]->Visible = true;
		dbgrdByNote->Columns->Items[14]->Visible = false;
		dbgrdByNote->Columns->Items[15]->Visible = true;
	}
	else
	{
		dbgrdByNtHeader->Columns->Items[1]->Visible = true;
		dbgrdByNtHeader->Columns->Items[2]->Visible = false;
		dbgrdByNote->Columns->Items[14]->Visible = true;
		dbgrdByNote->Columns->Items[15]->Visible = false;
	}
	if (!prf) {
		dbgrdByNtHeader->Columns->Items[8]->Visible = false;
		dbgrdByNote->Columns->Items[8]->Visible = false;
		dbgrdByCustomer->Columns->Items[5]->Visible = false;
		dbgrdByBktype->Columns->Items[5]->Visible = false;
		dbgrdByPress->Columns->Items[5]->Visible = false;
	}
	if (!cbpr) {
		dbgrdByNtHeader->Columns->Items[7]->Visible = false;
		dbgrdByNote->Columns->Items[7]->Visible = false;
		dbgrdByCustomer->Columns->Items[4]->Visible = false;
		dbgrdByBktype->Columns->Items[4]->Visible = false;
		dbgrdByPress->Columns->Items[4]->Visible = false;
	}
	if (!discountqry) {
	       //	dbgrdByNtHeader->Columns->Items[6]->Visible = false;
		dbgrdByNote->Columns->Items[6]->Visible = false;
		dbgrdByNote->Columns->Items[17]->Visible = false;
		dbgrdByCustomer->Columns->Items[3]->Visible = false;
		dbgrdByBktype->Columns->Items[3]->Visible = false;
		dbgrdByPress->Columns->Items[3]->Visible = false;
	}
	if (!finca) {
		dbgrdByNtHeader->Columns->Items[10]->Visible = false;
		dbgrdByNtHeader->Columns->Items[11]->Visible = false;
		dbgrdByCustomer->Columns->Items[7]->Visible = false;
		dbgrdByCustomer->Columns->Items[8]->Visible = false;
		dbgrdByCustomer->Columns->Items[9]->Visible = false;
	}
}

//---------------------------------------------------------------------------

void __fastcall TfrmQryWsaleNote::edsuplierKeyPress(TObject *Sender, wchar_t &Key)

{
	if (Key == '\r') {
		AnsiString sql;

                if(qfsupplier)
                {
                  sql = "select ID,Name from CUST_CustomerInfo where type = 1 and customerstate=1 and stgid="+IntToStr(m_storageID)+" and Name like '%" +  edsuplier->Text + "%'";
                }else sql = "select ID,Name from CUST_CustomerInfo where type = 1 and customerstate=1  and Name like '%" +  edsuplier->Text + "%'";




		dsetSupplier->Active = false;
		dsetSupplier->CommandText = sql;
		dsetSupplier->Active = true;
		dsetSupplier->First();
		dblkpcbbSupplierID->KeyValue = dsetSupplier->FieldByName("ID")->AsInteger;
	}
}
//---------------------------------------------------------------------------


void __fastcall TfrmQryWsaleNote::BtnAlignBottomClick(TObject *Sender)
{
	WindowState = wsMinimized ;
}
//---------------------------------------------------------------------------

void TfrmQryWsaleNote::Init(LandInfo* li)
{
	TfrmMDIChild::Init(li);
	//
	fcon = m_con;
	spQryNote->Connection = m_con;
	dsetPress->Connection = m_con;
	dsetPress->Active = true;
	dsetBookType->Connection = m_con;
	dsetBookType->Active = true;
	dsetStorage->Connection = m_con;
	dsetStorage->Active = true;

          qfclient=li->qfclient;
         qfsupplier=li->qfsupply;



	dsetCustomer->Connection = m_con;
        dsetCustomer->Active = false;
        if (qfclient) {
          dsetCustomer->CommandText="select ID,Name from CUST_CustomerInfo where type in(2,3) and customerstate=1 and stgid="+IntToStr(m_storageID)+" and Name like '%" +  edtCustomer->Text.Trim()  + "%'";
        }else dsetCustomer->CommandText="select ID,Name from CUST_CustomerInfo where type in(2,3) and customerstate=1 and Name like '%" +  edtCustomer->Text.Trim()  + "%'";



        dsetCustomer->Active = true;

	dsetBookstack->Connection = m_con;
	dsetBookstack->Active = true;
	qryItems->Connection = m_con;
        dsetSupplier->Connection = m_con;
        if (qfsupplier) {
         dsetSupplier->CommandText = "select ID, Name from CUST_CustomerInfo where  Type =1  and customerstate=1 and stgid="+IntToStr(m_storageID)+" order by name";
        }else dsetSupplier->CommandText = "select ID, Name from CUST_CustomerInfo where  Type =1  and customerstate=1  order by name";




	dsetSupplier->Active = true;

	numedtMinPrice->Text = "";
	numedtMaxPrice->Text = "";
	numedtMinAmount->Text = "";
	numedtMaxAmount->Text = "";
	//dsetInit->Edit();
	//dsetInit->FieldByName("StorageID")->AsInteger = m_storageID ;
	//dsetInit->Post();
	dblkpcbbStorage->KeyValue = m_storageID ;
	chckbxStorage->Checked = true;
    TADOQuery * aq;
    aq = new TADOQuery(this);
	aq->Connection = m_con ;
	AnsiString sql;


        sql = "select id,local from Sys_Local ";
	aq->Close();
	aq->SQL->Clear();
	aq->SQL->Add(sql);
	aq->Open();
        while (!aq->Eof )
	{
		cbqueyueselect->AddItem(aq->FieldByName("local")->AsString ,(TObject*)aq->FieldByName("id")->AsInteger );
		aq->Next();
	}



	/*sql = "select id,Name from SYS_StaffInfo where stgID = " + IntToStr(m_storageID) + " and Career = 2" ;
	aq->Close();
	aq->SQL->Clear();
	aq->SQL->Add(sql);
	aq->Open();
	while (!aq->Eof )
	{
		cbyewuyuan->AddItem(aq->FieldByName("Name")->AsString ,(TObject*)aq->FieldByName("ID")->AsInteger );
		aq->Next();
	}

	sql = "select id,Name from CUST_CustomerInfo where type in (2,3)";
	aq->Close();
	aq->SQL->Clear();
	aq->SQL->Add(sql);
	aq->Open();
	while (!aq->Eof )
	{
		cbclient->AddItem(aq->FieldByName("Name")->AsString ,(TObject*)aq->FieldByName("ID")->AsInteger );
		aq->Next();
	}  */

	sql = "select * from SYS_BSSET where name = 'changeDanHaoDisplay'";
	aq->Close();
	aq->SQL->Clear();
	aq->SQL->Add(sql);
	aq->Open();
	danhaodisplay = aq->FieldByName("value")->AsBoolean ;
	sql = "select Master from SYS_StorageInfo where id = " + IntToStr(m_storageID);
    aq->Close();
	aq->SQL->Clear();
	aq->SQL->Add(sql);
	aq->Open();
        master = aq->FieldByName("Master")->AsBoolean;
	if (aq->FieldByName("Master")->AsBoolean) {
		chckbxStorage->Enabled = true;
		dblkpcbbStorage->Enabled = true;
	}
	else
	{
		chckbxStorage->Enabled = false;
		sql = "select * from BS_StoToSto where ystgid = " + IntToStr(m_storageID) + " and wsale = 1";
        aq->Close();
		aq->SQL->Clear();
		aq->SQL->Add(sql);
		aq->Open();
		if (aq->RecordCount == 0) {
			dblkpcbbStorage->Enabled = false;
		}
		else
		{
			AnsiString ss ;
			ss = "ID = " + IntToStr(m_storageID);
			while (!aq->Eof )
			{
				ss = ss + " or ID = " + aq->FieldByName("mstgid")->AsString ;
				aq->Next();
			}
			dsetStorage->Filtered = false;
			dsetStorage->Filter = ss;
			dsetStorage->Filtered = true;
		}
	}

        if(!master)
        {
        sql = "select id,Name,stgid from SYS_User where stgid = "+IntToStr(m_storageID);
        }else
        sql= "select id,Name,stgid from SYS_User ";

	aq->Close();
	aq->SQL->Clear();
	aq->SQL->Add(sql);
	aq->Open();
	while (!aq->Eof )
	{
		cbstaff->AddItem(aq->FieldByName("stgid")->AsString + "店" + aq->FieldByName("Name")->AsString ,(TObject*)aq->FieldByName("ID")->AsInteger );
		aq->Next();
	}



	sql = "select ReadPurview from SYS_GroupAction left join SYS_UserGroup on SYS_GroupAction.GroupID = SYS_UserGroup.GroupID "
			" left join sys_action A1 on SYS_GroupAction.actionid = A1.Code "
			" left join sys_action A2 ON A2.CODE = A1.parent "
			" where A1.ActionName = '成本查询' "
			" and A2.ActionName = '发货查询' "
			" and SYS_UserGroup.Userid = " + IntToStr(m_userID);
	aq->Close();
	aq->SQL->Clear();
	aq->SQL->Add(sql);
	aq->Open();
	cbpr = aq->FieldByName("ReadPurview")->AsBoolean ;

	sql = "select ReadPurview from SYS_GroupAction left join SYS_UserGroup on SYS_GroupAction.GroupID = SYS_UserGroup.GroupID "
			" left join sys_action A1 on SYS_GroupAction.actionid = A1.Code "
			" left join sys_action A2 ON A2.CODE = A1.parent "
			" where A1.ActionName = '毛利查询' "
			" and A2.ActionName = '发货查询' "
			" and SYS_UserGroup.Userid = " + IntToStr(m_userID);
	aq->Close();
	aq->SQL->Clear();
	aq->SQL->Add(sql);
	aq->Open();
	prf = aq->FieldByName("ReadPurview")->AsBoolean ;

	sql = "select ReadPurview from SYS_GroupAction left join SYS_UserGroup on SYS_GroupAction.GroupID = SYS_UserGroup.GroupID "
			" left join sys_action A1 on SYS_GroupAction.actionid = A1.Code "
			" left join sys_action A2 ON A2.CODE = A1.parent "
			" where A1.ActionName = '折扣查询' "
			" and A2.ActionName = '发货查询' "
			" and SYS_UserGroup.Userid = " + IntToStr(m_userID);
	aq->Close();
	aq->SQL->Clear();
	aq->SQL->Add(sql);
	aq->Open();
	discountqry = aq->FieldByName("ReadPurview")->AsBoolean ;

	sql = "select ReadPurview from SYS_GroupAction left join SYS_UserGroup on SYS_GroupAction.GroupID = SYS_UserGroup.GroupID "
			" left join sys_action A1 on SYS_GroupAction.actionid = A1.Code "
			" left join sys_action A2 ON A2.CODE = A1.parent "
			" where A1.ActionName = '结款情况' "
			" and A2.ActionName = '发货查询' "
			" and SYS_UserGroup.Userid = " + IntToStr(m_userID);
	aq->Close();
	aq->SQL->Clear();
	aq->SQL->Add(sql);
	aq->Open();
	finca = aq->FieldByName("ReadPurview")->AsBoolean ;

	sql = "select *from CUST_Customertype where type = 2";
    aq->Close();
	aq->SQL->Clear();
	aq->SQL->Add(sql);
	aq->Open();
	while (!aq->Eof )
	{
	    cbsuptype->AddItem(aq->FieldByName("Name")->AsAnsiString,(TObject*)aq->FieldByName("ID")->AsInteger );
		aq->Next();
	}

  	delete aq;
	Desic = QueryDesic();
	View();
}

//---------------------------------------------------------------------------


void __fastcall TfrmQryWsaleNote::dbgrdByNtHeader1DblClick(TObject *Sender)
{
	if (dsetByNtHeader->IsEmpty() ) {
		return;
	}
	if (dsetByNtHeader->RecordCount > 0) {
		TfrmNotedetail *frm = new TfrmNotedetail(Application,dsetByNtHeader->FieldByName("Code")->AsString,2,fcon,0);
		frm->ShowModal();
		delete frm;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmQryWsaleNote::dbgrdByNtHeaderDblClick(TObject *Sender)
{
	if (dsetByNtHeader->IsEmpty() ) {
		return;
	}
	if (dsetByNtHeader->RecordCount > 0) {
		TfrmNotedetail *frm = new TfrmNotedetail(Application,dsetByNtHeader->FieldByName("Code")->AsString,2,fcon,0);
		frm->ShowModal();
		delete frm;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmQryWsaleNote::dbgrdByPressTitleClick(TColumnEh *Column)
{
	if (dsetByPress->IsEmpty() ) {
		return;
	}
	AnsiString qusort;
	qusort =  Column->FieldName + " ASC";
	if (dsetByPress->Sort == "") {
		dsetByPress->Sort =  Column->FieldName + " ASC";
	}
	else if (dsetByPress->Sort == qusort) {
		dsetByPress->Sort =  Column->FieldName + " DESC";
	}
	else
	{
		dsetByPress->Sort =  Column->FieldName + " ASC";
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmQryWsaleNote::dbgrdByBktypeTitleClick(TColumnEh *Column)
{
	if (dsetByBktype->IsEmpty() ) {
		return;
	}
	AnsiString qusort;
	qusort =  Column->FieldName + " ASC";
	if (dsetByBktype->Sort == "") {
		dsetByBktype->Sort =  Column->FieldName + " ASC";
	}
	else if (dsetByBktype->Sort == qusort) {
		dsetByBktype->Sort =  Column->FieldName + " DESC";
	}
	else
	{
		dsetByBktype->Sort =  Column->FieldName + " ASC";
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmQryWsaleNote::dbgrdByCustomerTitleClick(TColumnEh *Column)
{
	if (dsetByCustomer->IsEmpty() ) {
		return;
	}
	AnsiString qusort;
	qusort =  Column->FieldName + " ASC";
	if (dsetByCustomer->Sort == "") {
		dsetByCustomer->Sort =  Column->FieldName + " ASC";
	}
	else if (dsetByCustomer->Sort == qusort) {
		dsetByCustomer->Sort =  Column->FieldName + " DESC";
	}
	else
	{
		dsetByCustomer->Sort =  Column->FieldName + " ASC";
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmQryWsaleNote::dbgrdByNoteTitleClick(TColumnEh *Column)
{
	if (dsetByNote->IsEmpty() ) {
		return;
	}
	AnsiString qusort;
	qusort =  Column->FieldName + " ASC";
	if (dsetByNote->Sort == "") {
		dsetByNote->Sort =  Column->FieldName + " ASC";
	}
	else if (dsetByNote->Sort == qusort) {
		dsetByNote->Sort =  Column->FieldName + " DESC";
	}
	else
	{
		dsetByNote->Sort =  Column->FieldName + " ASC";
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmQryWsaleNote::dbgrdByNtHeaderTitleClick(TColumnEh *Column)
{
	if (dsetByNtHeader->IsEmpty() ) {
		return;
	}
	AnsiString qusort;
	qusort =  Column->FieldName + " ASC";
	if (dsetByNtHeader->Sort == "") {
		dsetByNtHeader->Sort =  Column->FieldName + " ASC";
	}
	else if (dsetByNtHeader->Sort == qusort) {
		dsetByNtHeader->Sort =  Column->FieldName + " DESC";
	}
	else
	{
		dsetByNtHeader->Sort =  Column->FieldName + " ASC";
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmQryWsaleNote::pgcntrlResultChange(TObject *Sender)
{
	switch (pgcntrlResult->ActivePage->Tag) {
		case 1:
			//chandan->Visible = false;
			break;
		case 2:
		      //	chandan->Visible = true;
		       //	chandan->Caption = "明细按单";
			break;
		case 3:
        	chandan->Visible = false;
			//chandan->Visible = true;
			//chandan->Caption = "客户分级";
			break;
		case 4:
		     //	chandan->Visible = false;
			break;
		case 5:
		      //	chandan->Visible = false;
			break;
	default:
		;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmQryWsaleNote::edtCustomerKeyPress(TObject *Sender, wchar_t &Key)

{
	if (Key == '\r') {
    	AnsiString sql;
        if(qfclient)
        {
         sql = "select ID,Name from CUST_CustomerInfo where type in(2,3) and customerstate=1 and stgid="+IntToStr(m_storageID)+" and Name like '%" +  edtCustomer->Text.Trim()  + "%'";
        }else sql = "select ID,Name from CUST_CustomerInfo where type in(2,3) and customerstate=1  and Name like '%" +  edtCustomer->Text.Trim()  + "%'";


		dsetCustomer->Active = false;
		dsetCustomer->CommandText = sql;
		dsetCustomer->Active = true;
		dsetCustomer->First();
		dblkpcbbCustomer->KeyValue  = dsetCustomer->FieldByName("ID")->AsInteger;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmQryWsaleNote::dblkpcbbCustomerClick(TObject *Sender)
{
	if (dblkpcbbCustomer->Text != "") {
		chckbxCustomer->Checked = true;
	}
}
//---------------------------------------------------------------------------



void __fastcall TfrmQryWsaleNote::SpeedButton1Click(TObject *Sender)
{
	Tfrmselecttype * frm = new Tfrmselecttype(Application,fcon,"");
	if (mrOk == frm->ShowModal())
	{
		TypeID = frm->GetSelectID();
		edtyname->Text = frm->GetSelect();
		chckbxType->Checked = true;
	}
	delete frm;
}
//---------------------------------------------------------------------------

void __fastcall TfrmQryWsaleNote::edpyqueryKeyPress(TObject *Sender, wchar_t &Key)

{
	if (Key == '\r') {
		Tfrmselecttype * frm = new Tfrmselecttype(Application,fcon,edpyquery->Text);
		if (mrOk == frm->ShowModal())
		{
			TypeID = frm->GetSelectID();
			edtyname->Text = frm->GetSelect();
			chckbxType->Checked = true;
		}
		delete frm;
	}
}
//---------------------------------------------------------------------------


void __fastcall TfrmQryWsaleNote::cbrktypeClick(TObject *Sender)
{
	if (cbrktype->Text != "") {
        chrktype->Checked = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmQryWsaleNote::cbsuptypeClick(TObject *Sender)
{
	if (cbsuptype->Text != "") {
        chsuptype->Checked = true;
	}
}
//---------------------------------------------------------------------------



void __fastcall TfrmQryWsaleNote::N1Click(TObject *Sender)
{
	if (dsetByNote->IsEmpty() ) {
		return;
	}
       
	int fstgid;
	if (chckbxStorage->Checked ) {
		fstgid = dsetStorage->FieldByName("ID")->AsInteger ;
	}
	else
	{
		fstgid = -1;
	}
	Tfrmbookhistory *frm = new Tfrmbookhistory(Application,m_con,fstgid,dsetByNote->FieldByName("bookcatalogid")->AsInteger );
	frm->ShowModal();
	delete frm;
}
//---------------------------------------------------------------------------



void __fastcall TfrmQryWsaleNote::cbqueyueselectChange(TObject *Sender)
{
     cbquyue->Checked = true;
}
//---------------------------------------------------------------------------

