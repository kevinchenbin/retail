//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unitteacher.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfrmteacher *frmteacher;
//---------------------------------------------------------------------------
__fastcall Tfrmteacher::Tfrmteacher(TComponent* Owner,int id,int atype)
	: TForm(Owner)
{
     ftype=atype;

	 aid=id;

}

void Tfrmteacher::getvalue()
{
   AnsiString sql;
   sql = "select * from dbo.Teacher where id = "+IntToStr(aid);
   adoaq->Close();
   adoaq->SQL->Clear();
   adoaq->SQL->Add(sql);
   adoaq->Open();
   editname->Text=adoaq->FieldByName("Name")->AsAnsiString;
   edittel->Text=adoaq->FieldByName("tel")->AsAnsiString;
   editkemu->Text=adoaq->FieldByName("kemu")->AsAnsiString;
   editmob->Text=adoaq->FieldByName("mob")->AsAnsiString;
   editclass->Text=adoaq->FieldByName("class")->AsAnsiString;
   editaddress->Text=adoaq->FieldByName("address")->AsAnsiString;
   memo->Text=adoaq->FieldByName("bk")->AsAnsiString;
}
void Tfrmteacher::newteacher()
{
   editname->Text="";
   edittel->Text="";
   editkemu->Text="";
   editmob->Text="";
   editclass->Text="";
   editaddress->Text="";
   memo->Text="";
}
void Tfrmteacher::savevalue()
{

	adoaq->Edit();
	adoaq->FieldByName("Name")->AsAnsiString=editname->Text;
	adoaq->FieldByName("tel")->AsAnsiString=edittel->Text;
	adoaq->FieldByName("kemu")->AsAnsiString=editkemu->Text;
	adoaq->FieldByName("mob")->AsAnsiString=editmob->Text;
	adoaq->FieldByName("class")->AsAnsiString=editclass->Text;
	adoaq->FieldByName("address")->AsAnsiString=editaddress->Text;
	adoaq->FieldByName("bk")->AsAnsiString=memo->Text;
	adoaq->Post();

}
void Tfrmteacher::add()
{
   AnsiString sql;
   sql = "select * from dbo.Teacher where id = -1";
   adoaq->Close();
   adoaq->SQL->Clear();
   adoaq->SQL->Add(sql);
   adoaq->Open();

   	adoaq->Append();
	adoaq->FieldByName("Name")->AsAnsiString=editname->Text;
	adoaq->FieldByName("tel")->AsAnsiString=edittel->Text;
	adoaq->FieldByName("kemu")->AsAnsiString=editkemu->Text;
	adoaq->FieldByName("mob")->AsAnsiString=editmob->Text;
	adoaq->FieldByName("class")->AsAnsiString=editclass->Text;
	adoaq->FieldByName("address")->AsAnsiString=editaddress->Text;
	adoaq->FieldByName("bk")->AsAnsiString=memo->Text;
	adoaq->Post();
}
//---------------------------------------------------------------------------
void __fastcall Tfrmteacher::Button1Click(TObject *Sender)
{
  AnsiString msg;

if (ftype==1) { //  �༭

		savevalue();
		msg="�޸ĳɹ�!";
} else if(ftype==2){ //����
	 add();
	 msg="���ӳɹ�!";
}

   //	MessageBoxA(0,msg.c_str(),"��ʾ",MB_ICONASTERISK);

//  Close();
}
//---------------------------------------------------------------------------

void __fastcall Tfrmteacher::FormShow(TObject *Sender)
{
	adoaq->Connection = Acon;
	if(ftype==1) {    //�༭
	   getvalue();
	}else if (ftype==2)   //����
	{
	  newteacher();
	}
}
//---------------------------------------------------------------------------

void __fastcall Tfrmteacher::Button2Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
