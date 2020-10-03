//---------------------------------------------------------------------------

#include <vcl.h>
#include <Math.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TForm1::clear_graph(){
	Image1->Canvas->FillRect(Rect(0,0,Image1->Width,Image1->Height));
}
//---------------------------------------------------------------------------
void TForm1::axes_coor(){
	int x0, y0;      //?????????? ??????
	int width, height; //?????? ? ?????? ????
	float zoom_level = StrToFloat(Edit6->Text);  //??????? ??????????

	width = Image1->Width;
	height = Image1->Height;

	x0 = width/2;      //??????? ?????
	y0 = height/2;


	if (CheckBox2->Checked) { // ??? Y ? X
		Image1->Canvas->Pen->Color = (TColor) 0xBFBFBF;
        Image1->Canvas->Pen->Width = 1;
		Image1->Canvas->Pen->Style = psDot;
        Image1->Canvas->MoveTo(0, y0);
		Image1->Canvas->LineTo(width, y0);
												////???? ?????????? +
        Image1->Canvas->MoveTo(x0, 0);
		Image1->Canvas->LineTo(x0, height);
	}

    // ????????? ??? ??????? ?????? ?? ????????
		int step = 20 * zoom_level;    //?? 20 ???????

	 // ?????? ????? ?? Y
	 int checkY = step;
	 // ??? ???????? ????????? ???????? ???????
	 int checkYText = 20;
	 while (checkY < height / 2)
	 {
		if (CheckBox2->Checked) { // ?????? ?????
			Image1->Canvas->Pen->Color = (TColor) 0xBFBFBF;
			Image1->Canvas->Pen->Width = 1;
			Image1->Canvas->Pen->Style = psDot;
			Image1->Canvas->MoveTo(0, y0 - checkY);
			Image1->Canvas->LineTo(width, y0 - checkY);
		}
		if (CheckBox3->Checked) { // ?????? ???????
			Image1->Canvas->Pen->Color = clBlack;
			Image1->Canvas->Pen->Width = 1;
			Image1->Canvas->MoveTo(x0 - 3, y0 - checkY);
			Image1->Canvas->LineTo(x0 + 3, y0 - checkY);
			Image1->Canvas->TextOutA(x0 + 8, y0 - checkY - 8, IntToStr(checkYText));
		}

		if (CheckBox2->Checked) { // ?????? ?????
			Image1->Canvas->Pen->Color = (TColor) 0xBFBFBF;
			Image1->Canvas->Pen->Width = 1;
			Image1->Canvas->Pen->Style = psDot;
			Image1->Canvas->MoveTo(0, y0 + checkY);
			Image1->Canvas->LineTo(width, y0 + checkY);
		}
		if (CheckBox3->Checked) { // ?????? ???????
			Image1->Canvas->Pen->Color = clBlack;
			Image1->Canvas->Pen->Width = 1;
			Image1->Canvas->MoveTo(x0 - 3, y0 + checkY);
			Image1->Canvas->LineTo(x0 + 3, y0 + checkY);
			Image1->Canvas->TextOutA(x0 + 8, y0 + checkY - 8, IntToStr(-checkYText));
		}

		checkY += step;
		checkYText += 20;
	 }

	 // ?????? ????? ?? X
	 int checkX = step;
	  // ??? ???????? ????????? ???????? ???????
	 int checkXText = 20;
	 while (checkX < width / 2)
	 {
		if (CheckBox2->Checked) { // ?????? ?????
			Image1->Canvas->Pen->Color = (TColor) 0xBFBFBF;
			Image1->Canvas->Pen->Width = 1;
			Image1->Canvas->Pen->Style = psDot;
			Image1->Canvas->MoveTo(x0 + checkX, 0);
			Image1->Canvas->LineTo(x0 + checkX, height);
		}
		if (CheckBox3->Checked) { // ?????? ???????
			Image1->Canvas->Pen->Color = clBlack;
			Image1->Canvas->Pen->Width = 1;
			Image1->Canvas->MoveTo(x0 + checkX, y0 - 3);
			Image1->Canvas->LineTo(x0 + checkX, y0 + 3);
			Image1->Canvas->TextOutA(x0 + checkX - 8, y0 + 7, IntToStr(checkXText));
		}

		if (CheckBox2->Checked){ // ?????? ???????
			Image1->Canvas->Pen->Color = (TColor) 0xBFBFBF;
			Image1->Canvas->Pen->Width = 1;
			Image1->Canvas->Pen->Style = psDot;
			Image1->Canvas->MoveTo(x0 - checkX, 0);
			Image1->Canvas->LineTo(x0 - checkX, height);
		}
		if (CheckBox3->Checked) { // ?????? ?????
			Image1->Canvas->Pen->Color = clBlack;
			Image1->Canvas->Pen->Width = 1;
			Image1->Canvas->MoveTo(x0 - checkX, y0 - 3);
			Image1->Canvas->LineTo(x0 - checkX, y0 + 3);
			Image1->Canvas->TextOutA(x0 - checkX - 8, y0 + 7, IntToStr(-checkXText));
		}

		checkX += step;
		checkXText += 20;
	 }

	 //?????? ???
	 if (CheckBox1->Checked)
	 {
		Image1->Canvas->Pen->Color = clRed;
		Image1->Canvas->Pen->Width = 1;
		Image1->Canvas->MoveTo(x0, 0);
		Image1->Canvas->LineTo(x0, height);
		Image1->Canvas->MoveTo(0, y0);
		Image1->Canvas->LineTo(width, y0);
		Image1->Canvas->TextOutA(width - 10, y0 - 20, "X");
		Image1->Canvas->TextOutA(x0 - 20, 10, "Y");
	 }
}
//---------------------------------------------------------------------------
void TForm1::graph(){
 Image1->Canvas->Font->Size = 5;
 clear_graph();
 axes_coor();
 print_graph();
}
//---------------------------------------------------------------------------
void TForm1::print_graph(){
	float a,A,lambda,t; //??????????
	float T = 0; //???
	int x0, y0; //??????????
	int width, height; // ?????? ?????? ???? ???????
	float zoom_level = StrToFloat(Edit6->Text);   // ???????  ???????

	//????????? ??????????
	A = StrToFloat(Edit3->Text);
	a = StrToFloat(Edit4->Text);
	lambda = StrToFloat(Edit5->Text);
	t = StrToFloat(Edit1->Text);
	height = Image1->Height;
	width = Image1->Width;

	//??????? ?????
	x0 = width/2;
	y0 = height/2;

	Image1->Canvas->Pen->Color = clBlue;
	Image1->Canvas->Pen->Width = 1;
	Image1->Canvas->Pen->Style = psSolid;

	//?????????? ???????
	bool first = true;
	float step;
	if (Edit7->Text != "")
	{
	step = StrToFloat (Edit7->Text);
	if (step == 0) step = 0.1;
	}
	else step = 0.1;

	while (t >=  0)
	{
		int x = x0 + zoom_level *((A + a) * cos(t) + lambda * a * cos( (A/a + 1 ) * t ))   ; //??? ???? ????????
		int y = y0 + zoom_level * ((A + a) * sin(t) - lambda * a * sin((A/a + 1) * t));
		
		t = t - step;

		if (first)
		{
			first = false;
			Image1->Canvas->MoveTo(x, y);
		}
		else
		{
			Image1->Canvas->LineTo(x, y);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1Change(TObject *Sender)
{
if( Edit1->Text != "")
     graph();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit6Change(TObject *Sender)
{
if( Edit6->Text != "")
		 graph();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit7Change(TObject *Sender)
{
if( Edit7->Text != "")
		 graph();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit3Change(TObject *Sender)
{
if( Edit3->Text != "")
		 graph();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit4Change(TObject *Sender)
{
if( Edit4->Text != "")
		 graph();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit5Change(TObject *Sender)
{
if( Edit5->Text != "")
		 graph();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
graph();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox2Click(TObject *Sender)
{
graph();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox3Click(TObject *Sender)
{
graph();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
Image1->Canvas->Font->Size = 5;
clear_graph();
axes_coor();
print_graph();
}
//---------------------------------------------------------------------------

