//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StockInQuery.h"
#include "Orderdetail.h"
#include "pdutil.h"
#include "bookhistory.h"
#include "Addsyslog.h"
#include "global.h"
#include "Selecttype.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIChild"
#pragma link "RzLabel"
#pragma link "RzPanel"
#pragma link "RzButton"
#pragma link "RzRadChk"
#pragma link "RzDBEdit"
#pragma link "RzDBGrid"
#pragma link "RzEdit"
#pragma link "RzDBDTP"
#pragma link "RzDTP"
#pragma link "RzDBCmbo"
#pragma link "DBGridEh"
#pragma link "GridsEh"
#pragma resource "*.dfm"
TfrmStockInQuery *frmStockInQuery;
//---------------------------------------------------------------------------
__fastcall TfrmStockInQuery::TfrmStockInQuery(TComponent* Owner)
	: TfrmMDIChild(Owner)
	,m_sql("")
{
	m_module = MTBsqry;
}
//---------------------------------------------------------------------------
void TfrmStockInQuery::Init(LandInfo* li)
{
	 TfrmMDIChild::Init(li);
	 this->WindowState = wsMaximized ;
	 qry1->Connection = m_con;
	 tblPress->Connection = m_con;
	dsetCatlog->Connection = m_con;
	tblCatalogType->Connection = m_con;
	tbl1supplier->Connection = m_con;
	tbl2supplier->Connection = m_con;
    tblStore ->Connection = m_con;
	aquery->Connection = m_con;
	tbllocal->Connection = m_con;
	aq1supplier->Connection = m_con;
	adospcopy->Connection = m_con;
	aq1supplier->Active = true;
	tbllocal->Active = true;
	aqpress->Connection = m_con ;
	aqpress->Active = true;

	datasetsum->Connection = m_con;
	//-------------------
	tbllocal->Filtered = false;
	tbllocal->Filter = "stgid ="+IntToStr(m_storageID);
    tbllocal->Filtered = true;
	//-------------------
	tblStore->Active = true;
	tblCatalogType->Active = true;
	chckbxShopNum->Checked = true;
	TADOQuery * aq;
	AnsiString sql;
	sql = "select Master from SYS_StorageInfo where id = " + IntToStr(m_storageID);
	aq = new TADOQuery(this);
	aq->Connection = m_con ;
	aq->Close();
	aq->SQL->Clear();
	aq->SQL->Add(sql);
	aq->Open();
	sqlstorage = "[" + IntToStr(m_storageID) + "]";
	if (aq->FieldByName("Master")->AsBoolean) {
		chckbxShopNum->Enabled = true;
		edtstore->Enabled = true;
		sql = "select ID,Name from SYS_StorageInfo where id <> " + IntToStr(m_storageID) ;
		aq->Close();
		aq->SQL->Clear();
		aq->SQL->Add(sql);
		aq->Open();
		while (!aq->Eof )
		{
			sqlstorageadd = sqlstorageadd + ",[" + aq->FieldByName("ID")->AsAnsiString + "]";
                        sqlstoragetotalamount= sqlstoragetotalamount+"isnull(["+ aq->FieldByName("ID")->AsAnsiString + "],0)+";
			aq->Next();
		}
	}
	else
	{
		chckbxShopNum->Enabled = false;
		edtstore->Enabled = false;

		sql = "select * from BS_StoToSto where ystgid = " + IntToStr(m_storageID) + " and stkbook = 1";
        aq->Close();
		aq->SQL->Clear();
		aq->SQL->Add(sql);
		aq->Open();
		if (aq->RecordCount == 0) {

		}
		else
		{
			while (!aq->Eof )
			{
			       	sqlstorageadd = sqlstorageadd + ",[" + aq->FieldByName("mstgid")->AsAnsiString + "]";
                                sqlstoragetotalamount= sqlstoragetotalamount+"isnull(["+ aq->FieldByName("mstgid")->AsAnsiString + "],0)+";
				aq->Next();
			}
		}
	}

	edtstore->KeyValue = m_storageID ;
	delete aq;
	 //Formstrngrid();
	Desic = QueryDesic();
	sbkinfoid = "-1";
	strlist = NULL;
	strlist =new TStringList();
}
void __fastcall TfrmStockInQuery::FormClose(TObject *Sender, TCloseAction &Action)

{
	Action = caFree;
}
//---------------------------------------------------------------------------
void __fastcall TfrmStockInQuery::btnExit4Click(TObject *Sender)
{
	Close();
}
//------------------------------------------------
 String TfrmStockInQuery::QueryDesic()
 {
	TADOQuery * aq;
	aq = new TADOQuery(this);
	aq->Connection = m_con ;
	aq->Close();
	aq->SQL->Clear();
	aq->SQL->Add("select bk from sys_bsset where name ='xiaoshudian'");
	aq->Open();
	return "￥###,###,##" + aq->FieldByName("bk")->AsAnsiString ;
	delete aq;
 }

//---------------------------------
void __fastcall TfrmStockInQuery::btnExit1Click(TObject *Sender)
{
	//Query();
	AnsiString sql,sqlgroup,sqlhaving,sqlgroup1,isbn,sqlss,sqltotalamount;
	if (chckbxISBN->Checked && edtISBN->Text != "") {
		isbn = edtISBN->Text.Trim();
        if (isbn.Length()==10 || isbn.Length()==13 ) {
			isbn = isbn.Delete(isbn.Length(),1);
		}
	}
	if (chother->Checked) {
		sqlss = sqlstorage + sqlstorageadd;
                sqltotalamount=sqlstoragetotalamount+"isnull("+sqlstorage+",0)";
               // sqltotalamount=sqltotalamount.Delete(sqlstoragetotalamount.Length(),1);
	}
	else
	{
		sqlss =   sqlstorage;
                sqltotalamount="sum(D.amount) ";
	}
	sqlgroup = "group by A.id ,A.Barcode,A.isbn,A.name ,A.userdefcode,A.price,A.author,A.presscount,A.pressdate,A.huojiangstate,A.BookWords, "
				" B.AbbreviatedName,C.Name,A.Disprice ," + sqlss;
	sqlgroup1 = "group by A.id ,A.Barcode,A.isbn,A.name ,A.userdefcode,A.price,A.author,A.presscount,A.pressdate,A.huojiangstate,A.BookWords, "
				" B.AbbreviatedName,D.Cbprice,C.Name,A.Disprice,E.name,F.name," + sqlss;
	if (chmutisupplier->Checked) {
		sql = "select rank() over(order by A.id) as xuhao,A.id as bkcatalogid,A.Barcode,A.ISBN,A.price,A.name as bookname,A.userdefcode,A.author,A.presscount,convert(varchar(10),A.pressdate,120) as pressdate,A.huojiangstate,A.BookWords,"
			" B.AbbreviatedName,C.Name as typename,0 AS ID,"+sqltotalamount+" as amount,D.Cbprice,sum(D.amount*A.price) as mayang,sum(D.Cbprice*D.amount) as shiyang,sum(D.bkharmnum) as bkharmnum,sum(D.bkdamnum) as bkdamnum, "
			" E.name as stackname,F.name as suppliername," + sqlss +
			" from BS_BookCatalog A left join BS_PressInfo B on A.pressid = B.id "
			" left join BS_BookType C on A.smallBookTypeID = C.id "
			" left join STK_BookInfo D on A.id = D.BkcatalogID "
			" left join STK_BookstackInfo E on D.BkstackID = E.id "
			" left join CUST_CustomerInfo F on D.Supplierid = F.id "
			" left join SYS_StorageInfo G on D.stgid = G.id "
			" left join (select bkcatalogid ,supplierid," + sqlss +
			" from (select bkcatalogid,supplierid,amount,stgid from stk_bookinfo ) as SourceTable "
			" pivot(sum(amount) for stgid in(" + sqlss + ")) as PivotTable) J on D.BkcatalogID = J.bkcatalogid and D.supplierid = J.supplierid ";
	}
	else
	{
		sql = "select rank() over(order by A.id) as xuhao,A.Barcode,A.id as bkcatalogid,A.ISBN,A.name as bookname,A.price,A.userdefcode,A.author,A.presscount,convert(varchar(10),A.pressdate,120) as pressdate,A.huojiangstate,A.BookWords, "
			" B.AbbreviatedName,C.Name as typename,0 AS ID,"+sqltotalamount+" as amount,A.Disprice as Cbprice ,sum(D.amount*A.price) as mayang,sum(A.Disprice*D.amount) as shiyang,sum(D.bkharmnum) as bkharmnum,sum(D.bkdamnum) as bkdamnum, "
			" '' as stackname,'' as suppliername, " + sqlss +
			" from BS_BookCatalog A left join BS_PressInfo B on A.pressid = B.id "
			" left join BS_BookType C on A.smallBookTypeID = C.id "
			" left join STK_BookInfo D on A.id = D.BkcatalogID "
			" left join STK_BookstackInfo E on D.BkstackID = E.id "
			" left join CUST_CustomerInfo F on D.Supplierid = F.id "
			" left join SYS_StorageInfo G on D.stgid = G.id "
			" left join (select bkcatalogid ," + sqlss +
			" from (select bkcatalogid,amount,stgid from stk_bookinfo ) as SourceTable "
			" pivot(sum(amount) for stgid in(" + sqlss + ")) as PivotTable) J on D.BkcatalogID = J.bkcatalogid ";
	}
       //	if (chlocal->Checked ) {
       //		sql = sql + " join Order_lock on A.id = Order_lock.bkcatalogid and Order_lock.stgid = G.id ";
       //	}
	sql = sql + " where A.Unavailable = 1 and F.type =1 ";

	if (chckbxBookName->Checked && edtBookName->Text != "")
	{
		sql = sql + " AND A.name like '%" + edtBookName->Text.Trim() + "%'";
	}
	if (chckbxISBN->Checked && edtISBN->Text != "")
	{
		sql = sql + " AND (A.ISBN like '%" + isbn + "%' or A.barcode like '%" + isbn + "%') ";
	}
	if (chckbxSupplier->Checked && edtSupplier->Text != "" )
	{
		sql = sql + " and F.name = '" + edtSupplier->Text.Trim() + "'";
	}
	if (chckbxUserDefNum->Checked && edtUserDefNum->Text != "")
	{
		sql = sql + " and A.userdefcode like '%" + edtUserDefNum->Text.Trim() + "%'";
	}
	if (chckbxPrice->Checked && edtPrice->Text != "")
	{
		try {
			StrToFloat(edtPrice->Text);
		} catch (...) {
			MessageBox(0,"请输入正确的定价！","提示" ,MB_OK);
			return;
		}
		sql = sql + " and A.price = " + edtPrice->Text;
	}
	if (chckbxAuthor->Checked && edtAuthor->Text != "")
	{
		sql = sql + " and A.author like '%" + edtAuthor->Text.Trim() + "%'";
	}
	if (chckbxAmount->Checked )
	{
		if (edtAmountLow->Text != "") {
			try {
				StrToInt(edtAmountLow->Text);
			} catch (...) {
				MessageBox(0,"请输入正确的数量！","提示" ,MB_OK);
				return;
			}
			/*if (chmutisupplier->Checked) {
				sql = sql + " and D.amount >= " + edtAmountLow->Text;
			}
			else
			{
				sqlhaving = " having sum(D.amount) >= " + edtAmountLow->Text;
			} */
			sqlhaving = " having sum(D.amount) >= " + edtAmountLow->Text;
		}
		if (edtAmountHigh->Text != "") {
			try {
				StrToInt(edtAmountHigh->Text);
			} catch (...) {
				MessageBox(0,"请输入正确的数量！","提示" ,MB_OK);
				return;
			}
			if (sqlhaving == "") {
				sqlhaving = " having sum(D.amount) <= " + edtAmountHigh->Text;
			}
			else
			{
				sqlhaving = sqlhaving + " and sum(D.amount) <= " + edtAmountHigh->Text;
			}
		}
	}
	if (chckbxPressCount->Checked && edtPressCount->Text != "")
	{
		sql = sql + " and B.AbbreviatedName = '" + edtPressCount->Text.Trim() + "'";
	}
	if (chckbxType->Checked )
	{
		sql = sql + " and C.id = '" + IntToStr(TypeID) + "'";
	}

	if (chckbxShopNum->Checked && edtstore->Text != "")
	{
		if (chother->Checked ) {
			sql = sql + " and D.StgID in(select mstgid from BS_StoToSto where ystgid = " + IntToStr(m_storageID) + " and stkbook = 1 union select " + IntToStr(m_storageID) + ") ";
		}
		else
		{
			sql = sql + " and G.name = '" + edtstore->Text.Trim() + "'";
		}
	}
	if (rzlocal->Checked && edtlocal->Text != "" ) {
		sql = sql + " and E.name = '" + edtlocal->Text.Trim() + "'";
	}

	if (chharm->Checked ) {
		sql = sql + " and D.bkharmnum > 0";
	}
	if (chdam->Checked ) {
		sql = sql + " and D.bkdamnum > 0";
	}
	if (chzero->Checked ) {
		if (sqlhaving == "") {
			sqlhaving = " having sum(D.amount) <> 0";
		}
		else
		{
			sqlhaving = sqlhaving + " and sum(D.amount) <> 0";
		}
	}
	if (!chmutisupplier->Checked) {
		sql = sql + sqlgroup + sqlhaving;
		DBGridEh1->Columns->Items[1]->Visible = false;
		DBGridEh1->Columns->Items[31]->Visible = false;
	}
	else
	{
		sql = sql + sqlgroup1 + sqlhaving;
		DBGridEh1->Columns->Items[1]->Visible = true;
		DBGridEh1->Columns->Items[31]->Visible = true;
	}

      String sql1 = sql;
	qry1->Close();
	qry1->SQL->Clear();
	qry1->SQL->Add(sql);
	qry1->Prepared = true;
	Screen->Cursor = crHourGlass ;
	qry1->Open();
	Screen->Cursor = crDefault ;
  //	ds1->DataSet= qry1;

	datasetsum->Parameters->ParamByName("@sql")->Value =sql1;
	datasetsum->Parameters->ParamByName("@mode")->Value = 1;

	 if (!datasetsum->Active) {
		 datasetsum->Active = true;
	 }else
	 {
		 datasetsum->Active = false;
		 datasetsum->Active = true;
	 }
           // DBGridEh1->Columns->Items[7]->Visible = true;
	 DBGridEh1->Columns->Items[7]->Footer->Value =  datasetsum->FieldByName("amount")->AsAnsiString;  //库存数量
	 DBGridEh1->Columns->Items[26]->Footer->Value = FormatFloat("####0.00",datasetsum->FieldByName("mayang")->AsFloat);  //库存码洋  mayang
	 DBGridEh1->Columns->Items[27]->Footer->Value = FormatFloat("0.00",datasetsum->FieldByName("shiyang")->AsFloat);  //库存实洋  shiyang
	 DBGridEh1->Columns->Items[28]->Footer->Value = datasetsum->FieldByName("bkharmnum")->AsAnsiString;    //损量   bkharmnum
	 DBGridEh1->Columns->Items[29]->Footer->Value = datasetsum->FieldByName("bkdamnum")->AsAnsiString;   //缺量    bkdamnum

	 if (datasetsum->Active) {
         datasetsum->Active = false;
	 }


    if (sqlstorage != "" && chother->Checked ) {
        TADOQuery *aq = new TADOQuery(this);
		aq->Connection = m_con;
		sql = "select ID,Name from SYS_StorageInfo "   ;
		aq->Close();
		aq->SQL->Clear();
		aq->SQL->Add(sql);
		aq->Open();
		AnsiString ss = IntToStr(m_storageID);
		int i = 0;

		while (!aq->Eof)
		{
			ss = aq->FieldByName("ID")->AsAnsiString ;
			try {
				DBGridEh1->Columns->Items[8+i]->Field = qry1->FieldByName(ss);
			       	DBGridEh1->Columns->Items[8+i]->Visible = true;
				DBGridEh1->Columns->Items[8+i]->Title->Caption = aq->FieldByName("Name")->AsString ;
				aq->Next();
				i++;
			} catch (...) {
				aq->Next();
				i++;
			}
		}
		delete aq;

	}
	else
	{
	      //	DBGridEh1->Columns->Items[7]->Visible = false;
		DBGridEh1->Columns->Items[8]->Visible = false;
		DBGridEh1->Columns->Items[9]->Visible = false;
		DBGridEh1->Columns->Items[10]->Visible = false;
		DBGridEh1->Columns->Items[11]->Visible = false;
		DBGridEh1->Columns->Items[12]->Visible = false;
		DBGridEh1->Columns->Items[13]->Visible = false;
		DBGridEh1->Columns->Items[14]->Visible = false;
		DBGridEh1->Columns->Items[15]->Visible = false;
		DBGridEh1->Columns->Items[16]->Visible = false;
		DBGridEh1->Columns->Items[17]->Visible = false;
	}
}
//---------------------------------------------------------------------------


void TfrmStockInQuery::OnHotKeyPress(DWORD vkCode)
{
	if(vkCode == 81)
	btnExit1Click(NULL);
	if(vkCode == VK_ESCAPE)
	btnExit4Click(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TfrmStockInQuery::edtISBNKeyPress(TObject *Sender, wchar_t &Key)
{
	if(Key == VK_RETURN)
	{
		if(chckbxISBN->Checked )
		{
		    //	if(edtISBN->Text .Length() != 13 )
		       //	{
		       //		ShowMessage("位数不正确！");
		       //		return;
		      //	}
			for(int i=1;i<edtISBN->Text .Length();i++ )
			if(edtISBN->Text .SubString(i,1)>='0'&&edtISBN->Text .SubString(i,1)<='9'  )
			continue;
			else
			{
				ShowMessage("请输入数字！");
				return;
			}
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmStockInQuery::edtAmountHighKeyPress(TObject *Sender, wchar_t &Key)

{
	if(Key==VK_RETURN)
	if(chckbxAmount->Checked )
	if(StrToInt(edtAmountHigh->Text )<StrToInt(edtAmountLow->Text ))
	{
		ShowMessage("上限小于下限");
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmStockInQuery::btnExit2Click(TObject *Sender)
{
		//Excel导出
	if (qry1->Active  && qry1->RecordCount >= 1)
	{
		DbgridToExcel(DBGridEh1);
	}
}
//---------------------------------------------------------------------------
//Excel导出函数
bool __fastcall TfrmStockInQuery::DbgridToExcel(TDBGridEh* dbg)
{
	AnsiString temptext,path;
	int k = dbg->DataSource ->DataSet ->RecordCount ,n=0;

        TDateTime t=   Date();
	savedlg->FileName = "库存查询"+t.DateString();
	if (savedlg->Execute())
	{
		String DBPath,Name;
		DBPath = ExtractFilePath(savedlg->FileName .c_str());
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
    /*
    Variant vExcelApp, vSheet;
    try
    {
        vExcelApp = Variant::CreateObject("Excel.Application");
    }
    catch(...)
    {
        MessageBox(0, "启动 Excel 出错, 可能是没有安装Excel.",
                "Excel导出", MB_OK | MB_ICONERROR);
        return false;
    }


      vExcelApp.OlePropertySet("Visible", false);
    // 新建一个工作表
    vExcelApp.OlePropertyGet("Workbooks").OleFunction("Add", 1); // 工作表
    // 操作这个工作表
    vSheet = vExcelApp.OlePropertyGet("ActiveWorkbook")
            .OlePropertyGet("Sheets", 1);

       for(int j=0; j<dbg->Columns->Count; j++)
    {
         	if (dbg->Columns->Items[j]->Visible == true)
                {
                  vSheet.OlePropertyGet("Cells", 1, j + 1).OlePropertySet("Value",
                  dbg->Columns->Items[j]->Title->Caption);
                }
    }

   int nRowCount ;
   nRowCount=dbg->SelectedRows->Count;
     dbg->DataSource->DataSet->First();
    for(int i=0; i<nRowCount; i++)
    {

        dbg->DataSource->DataSet->Bookmark = dbg->SelectedRows->Items[i];
        for(int j=0; j<dbg->Columns->Count; j++)
        {
        if (dbg->Columns->Items[j]->Visible == true)
        {
            vSheet.OlePropertyGet("Cells", i + 2, j + 1)
                .OlePropertySet("Value",
                dbg->DataSource->DataSet->FieldByName(
                dbg->Columns->Items[j]->FieldName)->AsString.c_str());
        }
        }
       // dbg->DataSource->DataSet->Next();
    }
    // 保存Excel文档并退出
    vExcelApp.OlePropertyGet("ActiveWorkbook")
            .OleFunction("SaveAs", path.c_str());
    vExcelApp.OleFunction("Quit");
    vSheet = Unassigned;
    vExcelApp = Unassigned;
    // 工作结束
    MessageBox(0, "导出结束!",
            "Excel导出", MB_OK | MB_ICONINFORMATION);

         */


	for(int q=0;q<dbg->FieldCount ;++q)
	{
		if (dbg->Columns->Items[q]->Visible == true) {
			temptext = temptext + dbg->Columns ->Items [q]->Title ->Caption + ",";
		}
	}

	iFileLength   =   FileSeek(iFileHandle,0,2);
	FileWrite(iFileHandle,temptext.c_str() ,temptext.Length());



	int t2 = dbg->DataSource ->DataSet ->RecordCount ;

	dbg->DataSource ->DataSet ->First();
	dbg->DataSource ->DataSet->DisableControls();
	for(int i=2+n;i<=t2+1+n;i++)
	{
		temptext = "\n";
		for(int j=1;j<dbg->Columns ->Count+1  ;j++)
		{
			if (dbg->Columns->Items[j-1]->Visible == true) {
				AnsiString bookname;
				int len;
			    	bookname = dbg->DataSource ->DataSet ->FieldByName(dbg->Columns ->Items [j-1]->FieldName )->AsAnsiString;
				bookname = StringReplace(bookname , '\n',"",TReplaceFlags()<<rfReplaceAll);
				bookname = StringReplace(bookname , ",",".",TReplaceFlags()<<rfReplaceAll);
				temptext = temptext + bookname + ",";
			}
		}
		FileWrite(iFileHandle,temptext.c_str() ,temptext.Length());
		dbg->DataSource ->DataSet ->Next() ;
	}
	dbg->DataSource ->DataSet->EnableControls();

	temptext = "\n";
	for(int q=0;q<dbg->FieldCount ;++q)
	{
		if (dbg->Columns->Items[q]->Visible == true) {
			AnsiString footvalue;
			footvalue =dbg->GetFooterValue(0,dbg->Columns ->Items[q]);// dbg->Columns->Items[q]->Footer->Value ;
			footvalue = StringReplace(footvalue , ",","",TReplaceFlags()<<rfReplaceAll);
			temptext = temptext + footvalue + ",";
		}
	}
	FileWrite(iFileHandle,temptext.c_str() ,temptext.Length());

	FileClose(iFileHandle);
	ShowMsg(this->Handle,"导出完毕！",3);
	return false;
}
//---------------------------------------------------------------------------

void __fastcall TfrmStockInQuery::edtBookNameChange(TObject *Sender)
{
	if (edtBookName->Text != "") {
        chckbxBookName->Checked = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmStockInQuery::edtPriceChange(TObject *Sender)
{
	if (edtPrice->Text != "") {
        chckbxPrice->Checked = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmStockInQuery::edtPressCountClick(TObject *Sender)
{
	if (edtPressCount->Text != "") {
        chckbxPressCount->Checked = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmStockInQuery::edtstoreClick(TObject *Sender)
{
	if (edtstore->Text != "") {
		chckbxShopNum->Checked = true;
		int storage = tblStore->FieldByName("ID")->AsInteger ;
		tbllocal->Active = false;
		tbllocal->Filtered = true;
		tbllocal->Filter = "StgID = " + IntToStr(storage);
		tbllocal->Active = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmStockInQuery::edtISBNChange(TObject *Sender)
{
	if (edtISBN->Text != "") {
        chckbxISBN->Checked = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmStockInQuery::edtAuthorChange(TObject *Sender)
{
	if (edtAuthor->Text != "") {
        chckbxAuthor->Checked = true;
	}
}
//---------------------------------------------------------------------------


void __fastcall TfrmStockInQuery::edtAmountHighChange(TObject *Sender)
{
	if (edtAmountHigh->Text != "") {
        chckbxAmount->Checked = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmStockInQuery::edtlocalClick(TObject *Sender)
{
	if (edtlocal->Text != "") {
        rzlocal->Checked = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmStockInQuery::edtSupplierClick(TObject *Sender)
{
	if (edtSupplier->Text != "") {
        chckbxSupplier->Checked = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmStockInQuery::edtUserDefNumChange(TObject *Sender)
{
	if (edtUserDefNum->Text != "") {
        chckbxUserDefNum->Checked = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmStockInQuery::DBGridEh1TitleClick(TColumnEh *Column)
{
	if (qry1->IsEmpty() ) {
		return;
	}
	AnsiString qusort;
	qusort =  Column->FieldName + " ASC";
	if (qry1->Sort == "") {
		qry1->Sort =  Column->FieldName + " ASC";
	}
	else if (qry1->Sort == qusort) {
		qry1->Sort =  Column->FieldName + " DESC";
	}
	else
	{
		qry1->Sort =  Column->FieldName + " ASC";
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmStockInQuery::BtnAlignBottomClick(TObject *Sender)
{
	WindowState = wsMinimized ;
}
//---------------------------------------------------------------------------

void __fastcall TfrmStockInQuery::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if (Key == VK_F6) {      //导出
		btnExit2->Click();
	}
	if (Shift.Contains(ssAlt)&& Key == 70 ) {    //查询
		btnExit1->Click();
	}
	if (Shift.Contains(ssAlt)&& Key == 78 ) {    //最小化
		BtnAlignBottom->Click();
	}
	if (Shift.Contains(ssAlt)&& Key == 81 ) {    //退出
		btnExit4->Click();
	}
	if (Shift.Contains(ssAlt)&& Key ==90) {   //恢复窗口
		WindowState = wsNormal  ;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmStockInQuery::edtSupplier1KeyPress(TObject *Sender, wchar_t &Key)

{
	if (Key == VK_RETURN) {
		String sql = "select ID,Name from CUST_CustomerInfo where type = 1 and customerstate=1 and Name like '%" + edtSupplier1->Text + "%'";
		aq1supplier->Close();
		aq1supplier->SQL->Clear();
		aq1supplier->SQL->Add(sql);
		aq1supplier->Open();
		aq1supplier->First();
		edtSupplier->KeyValue = aq1supplier->FieldByName("ID")->AsInteger ;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmStockInQuery::edtPressCount1KeyPress(TObject *Sender, wchar_t &Key)

{
	if (Key == VK_RETURN) {
		String sql = "select ID,PresentNum,AbbreviatedName from BS_PressInfo where AbbreviatedName like '%" + edtPressCount1->Text + "%'";
		aqpress->Close();
		aqpress->SQL->Clear();
		aqpress->SQL->Add(sql);
		aqpress->Open();
		aqpress->First();
		edtPressCount->KeyValue = aqpress->FieldByName("ID")->AsInteger ;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmStockInQuery::N1Click(TObject *Sender)
{
	/*AnsiString path;
  	AnsiString sql;

	adospcopy->ProcedureName = "CopyData";
	adospcopy->Parameters->Clear();
	adospcopy->Parameters->CreateParameter("@mode",ftInteger,pdInput,sizeof(int),3);
	adospcopy->Parameters->CreateParameter("@ID",ftString,pdInput,sbkinfoid.Length(),sbkinfoid.c_str());
	adospcopy->Parameters->CreateParameter("@userid",ftInteger,pdInput,sizeof(int),m_userID );
	adospcopy->ExecProc();   */
}

//---------------------------------------------------------------------------

bool TfrmStockInQuery::GetID(String str)
{
	int i ;
	i = strlist->IndexOf(str);
	if (i == -1) {
		return false;
	}
	else return true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmStockInQuery::edtAmountLowChange(TObject *Sender)
{
	if (edtAmountLow->Text != "") {
        chckbxAmount->Checked = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmStockInQuery::N2Click(TObject *Sender)
{
	/*if (qry1->IsEmpty() ) {
		return;
	}
	if (!DBGridEh1->Columns->Items[2]->Visible) {
		return;
	}
	qry1->First();
	int idx;
	qry1->DisableControls();
	while (!qry1->Eof)
	{
    	if (strlist == NULL) {
			strlist->Add(qry1->FieldByName("id")->AsAnsiString);
			//strlist->AddObject(qry1->FieldByName("BookInfoID")->AsAnsiString,(TObject*)qry1->FieldByName("BookInfoID")->AsInteger);
			sbkinfoid = sbkinfoid + "," +  qry1->FieldByName("id")->AsAnsiString;
		}
		else
		{
			idx=strlist->IndexOf(qry1->FieldByName("id")->AsAnsiString);
			if (idx == -1) {
				strlist->Add(qry1->FieldByName("id")->AsAnsiString);
				//strlist->AddObject(qry1->FieldByName("BookInfoID")->AsAnsiString,(TObject*)qry1->FieldByName("BookInfoID")->AsInteger);
				sbkinfoid = sbkinfoid + "," +  qry1->FieldByName("id")->AsAnsiString;
			}
		}
		qry1->Next();
	}
	qry1->EnableControls();  */
}

//---------------------------------------------------------------------------

void __fastcall TfrmStockInQuery::N5Click(TObject *Sender)
{
	if (qry1->IsEmpty() ) {
		return;
	}
	if (!DBGridEh1->Columns->Items[1]->Visible) {
		return;
	}
	AnsiString sql;
	if (qry1->FieldByName("amount")->AsInteger != 0 ) {
		ShowMsg(this->Handle,"该库存不为0，直接删除会造成该书总库存不准，请调整库存后再删除！",3);
		return;
	}
	TADOQuery *aq = new TADOQuery(this);
	aq->Connection = m_con;
	sql = "select * from bs_storagenote where bkinfoid = " + qry1->FieldByName("ID")->AsAnsiString ;
    aq->Close();
	aq->SQL->Clear();
	aq->SQL->Add(sql);
	aq->Open();
	if (aq->RecordCount > 1) {
		if (ShowMsg(this->Handle,"该库存有入库记录，确认删除？",1) != 1) {
			return;
		}
	}

	sql = "delete from stk_bookinfo where id = " + qry1->FieldByName("ID")->AsAnsiString ;
	aq->Close();
	aq->SQL->Clear();
	aq->SQL->Add(sql);
	try {
		aq->ExecSQL();
		qry1->Active = false;
		qry1->Active = true;
	} catch (...) {
		ShowMsg(this->Handle,"该数据有关联，不能删除！",3);
	}
	delete aq;
	logmessage = "删除" + qry1->FieldByName("suppliername")->AsAnsiString +"的" + qry1->FieldByName("bookname")->AsAnsiString + "库存记录";
	AddEvent(1,"库存查询",m_userID,m_storageID,logmessage,m_con);
}
//---------------------------------------------------------------------------

void __fastcall TfrmStockInQuery::DBGridEh1DblClick(TObject *Sender)
{
	if (qry1->IsEmpty() ) {
		return;
	}
	TfrmOrderdetail *frm = new TfrmOrderdetail(Application,m_con,qry1->FieldByName("bkcatalogid")->AsInteger ,m_storageID );
	frm->ShowModal();
	delete frm;
}
//---------------------------------------------------------------------------

void __fastcall TfrmStockInQuery::N3Click(TObject *Sender)
{
	if (qry1->IsEmpty() ) {
		return;
	}
	int fstgid;
	if (chckbxShopNum->Checked ) {
		fstgid = tblStore->FieldByName("ID")->AsInteger ;
	}
	else
	{
		fstgid = -1;
	}
	Tfrmbookhistory *frm = new Tfrmbookhistory(Application,m_con,fstgid,qry1->FieldByName("BkcatalogID")->AsInteger );
	frm->ShowModal();
	delete frm;
}
//---------------------------------------------------------------------------

void __fastcall TfrmStockInQuery::SpeedButton1Click(TObject *Sender)
{
	Tfrmselecttype * frm = new Tfrmselecttype(Application,m_con,"");
	if (mrOk == frm->ShowModal())
	{
		TypeID = frm->GetSelectID();
		edtyname->Text = frm->GetSelect();
		chckbxType->Checked = true;
	}
	delete frm;
}
//---------------------------------------------------------------------------

void __fastcall TfrmStockInQuery::edpyqueryKeyPress(TObject *Sender, wchar_t &Key)

{
	if (Key == '\r') {
		Tfrmselecttype * frm = new Tfrmselecttype(Application,m_con,edpyquery->Text);
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


