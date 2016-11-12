//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "diaoboset.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RzCmboBx"
#pragma link "RzButton"
#pragma resource "*.dfm"
Tfrmdiaoboset *frmdiaoboset;
//---------------------------------------------------------------------------
__fastcall Tfrmdiaoboset::Tfrmdiaoboset(TComponent* Owner,TADOConnection* con)
	: TForm(Owner)
{
   aquery->Connection = con;
   qryretairange->Connection = con;
}
//---------------------------------------------------------------------------
void __fastcall Tfrmdiaoboset::FormShow(TObject *Sender)
{
	Readydata();
}
//---------------------------------------------------------------------------
void Tfrmdiaoboset::Readydata()
{
  String sql= "select * from sys_bsset";
  aquery->Close();
  aquery->SQL->Clear();
  aquery->SQL->Add(sql);
  aquery->Open();
  while (!aquery->Eof)
  {
	if (aquery->FieldByName("name")->AsAnsiString == "diaoboadddiscount")
	{
		edadddiscount->Text  = aquery->FieldByName("bk")->AsString ;
	}
	if (aquery->FieldByName("name")->AsAnsiString == "diaodefaultdiscount")
	{
		eddefaultdiscount->Text = aquery->FieldByName("bk")->AsString ;
	}
	if (aquery->FieldByName("name")->AsAnsiString == "diaodiscounttype" ) {
		RadioGroup1->ItemIndex = aquery->FieldByName("bk")->AsInteger ;
	}
	//�ظ�¼����ʾ
	if (aquery->FieldByName("name")->AsAnsiString == "peisongsametishi" ) {
		chpeisongsametishi->Checked = aquery->FieldByName("value")->AsBoolean ;
	}
	aquery->Next();
  }
}
//---------------------------------------------------------------------------


void __fastcall Tfrmdiaoboset::FormClose(TObject *Sender, TCloseAction &Action)
{
	Action = caFree;
}
//---------------------------------------------------------------------------


void __fastcall Tfrmdiaoboset::edadddiscountKeyPress(TObject *Sender, wchar_t &Key)

{
	if ((Key < '0' || Key > '9') && (Key != '\b') && (Key != '.') && (Key != '\r') ) {
		Key = NULL;
	}
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdiaoboset::RzButton1Click(TObject *Sender)
{
	AnsiString sql,bk;
   float adddiscount,defaultdiscount;
   //Ĭ�ϵ����ۿ�
   try {
		defaultdiscount = StrToFloat(eddefaultdiscount->Text);
   } catch (...) {

                   ShowMsg(Handle ,"��������ȷ��Ĭ�ϵ����ۿۣ�",0);
		return;
   }
   if (defaultdiscount > 100) {

                 ShowMsg(Handle ,"Ĭ�ϵ����ۿ۲��ܴ���100��",0);
		return;
   }
   if (defaultdiscount < 0) {

                ShowMsg(Handle ,"Ĭ�ϵ����ۿ۲���С��0��",0);
		return;
   }
   //�ӿ��ۿ�
   try {
		adddiscount = StrToFloat(edadddiscount->Text);
   } catch (...) {

                ShowMsg(Handle ,"��������ȷ�ļӿ��ۿۣ�",0);
		return;
   }
   if (adddiscount > 100) {

                ShowMsg(Handle ,"�ӿ��ۿ۲��ܴ���100��",0);
		return;
   }
   if (adddiscount < 0) {

                ShowMsg(Handle ,"�ӿ��ۿ۲���С��0��",0);
		return;
   }
   //Ĭ�ϵ����ۿ�
   sql = "update sys_bsset set bk = '" + eddefaultdiscount->Text + "' where name = 'diaodefaultdiscount'";
   aquery->Close();
   aquery->SQL->Clear();
   aquery->SQL->Add(sql);
   aquery->ExecSQL();
   //�ӿ��ۿ�
   sql = "update sys_bsset set bk = '" + edadddiscount->Text + "' where name = 'diaoboadddiscount'";
   aquery->Close();
   aquery->SQL->Clear();
   aquery->SQL->Add(sql);
   aquery->ExecSQL();
   //�����ۿ۷�ʽ
   sql = "update sys_bsset set bk = '" + IntToStr(RadioGroup1->ItemIndex) + "' where name = 'diaodiscounttype'";
   aquery->Close();
   aquery->SQL->Clear();
   aquery->SQL->Add(sql);
   aquery->ExecSQL();
   //�ظ�¼����ʾ
   if (chpeisongsametishi->Checked ) {
	   sql = "update sys_bsset set value = 1 where name = 'peisongsametishi'";
   }
   else
   {
		sql = "update sys_bsset set value = 0 where name = 'peisongsametishi'";
   }
   aquery->Close();
   aquery->SQL->Clear();
   aquery->SQL->Add(sql);
   aquery->ExecSQL();
   ShowMsg(Handle ,"ҵ�����óɹ���",3);
   Close();
}
//---------------------------------------------------------------------------


void __fastcall Tfrmdiaoboset::RzButton2Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
