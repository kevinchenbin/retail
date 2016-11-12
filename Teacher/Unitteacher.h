//---------------------------------------------------------------------------

#ifndef UnitteacherH
#define UnitteacherH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class Tfrmteacher : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *Label1;
	TEdit *editname;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TEdit *edittel;
	TEdit *editaddress;
	TEdit *editclass;
	TEdit *editkemu;
	TEdit *editmob;
	TButton *Button1;
	TButton *Button2;
	TLabel *Label7;
	TMemo *memo;
	TADOQuery *adoaq;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations

	void getvalue();
	void savevalue();
	void add();
	void newteacher();
	int ftype;
public:		// User declarations

TADOConnection *Acon;
int aid;
	__fastcall Tfrmteacher(TComponent* Owner,int id,int atype);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfrmteacher *frmteacher;
//---------------------------------------------------------------------------
#endif
