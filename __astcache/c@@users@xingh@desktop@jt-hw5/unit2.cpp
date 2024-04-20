//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
	reCLL->Text = "";
	reDLL->Text = "";
	reLS->Text = "";
	reLQ->Text = "";
}
//---------------------------------------------------------------------------

// Function to convert UnicodeString (or TCaption) to std::string
std::string UnicodeToString(const System::UnicodeString& unicodeStr) {
	AnsiString ansiStr = unicodeStr; // Convert from UnicodeString to AnsiString
	return std::string(ansiStr.c_str()); // Convert from AnsiString to std::string and return
}

// Function to convert std::string to UnicodeString (or TCaption)
System::UnicodeString StringToUnicode(const std::string& stdStr) {
	return System::UnicodeString(stdStr.c_str());
}

CircularLinkedList<int> cll;
DoublyLinkedList<int> dll;
LinkedStack<int> ls;
LinkedQueue<int> lq;

const int CLL = 1;
const int DLL = 2;
const int LS = 3;
const int LQ = 4;

int currentOutputPage = CLL;

int CLLrange = 100;
int DLLrange = 100;
int LSrange = 100;
int LQrange = 100;

void __fastcall TForm2::tsDLLOutputShow(TObject *Sender)
{
	currentOutputPage = DLL;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::tsLQUOutputShow(TObject *Sender)
{
	currentOutputPage = LQ;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::tsLSOuputShow(TObject *Sender)
{
    currentOutputPage = LS;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::tsCLLOuputShow(TObject *Sender)
{
	currentOutputPage = CLL;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btnClearClick(TObject *Sender)
{
	switch(currentOutputPage) {
		case CLL:
			reCLL->Clear();
			break;
		case DLL:
			reDLL->Clear();
			break;
		case LS:
			reLS->Clear();
			break;
		case LQ:
			reLQ->Clear();
			break;
		default:
			break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btnPrintClick(TObject *Sender)
{
	switch(currentOutputPage) {
		case CLL:
			reCLL->Lines->Add(StringToUnicode(cll.visualize()));
			break;
		case DLL:
			reDLL->Lines->Add(StringToUnicode(dll.visualize()));
			break;
		case LS:
			reLS->Lines->Add(StringToUnicode(ls.visualize()));
			break;
		case LQ:
			reLQ->Lines->Add(StringToUnicode(lq.visualize()));
			break;
		default:
			break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btnCLLClearClick(TObject *Sender)
{
	bool result = cll.clear();
	reCLL->Lines->Add(StringToUnicode(cll.visualize()));
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btnCLLReverseClick(TObject *Sender)
{
	bool result = cll.reverse();
	reCLL->Lines->Add(StringToUnicode(cll.visualize()));
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btnDLLClearClick(TObject *Sender)
{
	bool result = dll.clear();
	reDLL->Lines->Add(StringToUnicode(dll.visualize()));
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btnDLLReverseClick(TObject *Sender)
{
	bool result = dll.reverse();
	reDLL->Lines->Add(StringToUnicode(dll.visualize()));
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btnLSClearClick(TObject *Sender)
{
	bool result = ls.clear();
	reLS->Lines->Add(StringToUnicode(ls.visualize()));
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btnLSReverseClick(TObject *Sender)
{
	bool result = reverseLinkedStack(ls);
	reLS->Lines->Add(StringToUnicode(ls.visualize()));
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btnLQClearClick(TObject *Sender)
{
	bool result = lq.clear();
    reLQ->Lines->Add(StringToUnicode(lq.visualize()));
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btnLQReverseClick(TObject *Sender)
{
	bool result = reverseLinkedQueue(lq);
	reLQ->Lines->Add(StringToUnicode(lq.visualize()));
}
//---------------------------------------------------------------------------
void __fastcall TForm2::editLSRangeChange(TObject *Sender)
{
	if(editLSRange->Text == ""){
		editLSRange->Text = "0";
	}
	tbLSRange->Max = StrToInt(editLSRange->Text);
	LSrange = StrToInt(editLSRange->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::editDLLRangeChange(TObject *Sender)
{
	if(editDLLRange->Text == ""){
		editDLLRange->Text = "0";
	}
	tbDLLRange->Max = StrToInt(editDLLRange->Text);
	DLLrange = StrToInt(editDLLRange->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::editCLLRangeChange(TObject *Sender)
{
	if(editCLLRange->Text == ""){
		editCLLRange->Text = "0";
	}
	tbCLLRange->Max = StrToInt(editCLLRange->Text);
	CLLrange = StrToInt(editCLLRange->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::editLQRangeChange(TObject *Sender)
{
	if(editLQRange->Text == ""){
		editLQRange->Text = "0";
	}
	tbLQRange->Max = StrToInt(editLQRange->Text);
	LQrange = StrToInt(editLQRange->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::tbCLLRangeChange(TObject *Sender)
{
	CLLrange = tbCLLRange->Position;
	tbCLLRange->Hint = IntToStr(LSrange);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::tbDLLRangeChange(TObject *Sender)
{
	DLLrange = tbDLLRange->Position;
	tbDLLRange->Hint = IntToStr(DLLrange);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::tbLSRangeChange(TObject *Sender)
{
	LSrange = tbLSRange->Position;
	tbLSRange->Hint = IntToStr(CLLrange);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::tbLQRangeChange(TObject *Sender)
{
	LQrange = tbLQRange->Position;
	tbLQRange->Hint = IntToStr(LQrange);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btnCLLRandomClick(TObject *Sender)
{
	bool result = cll.randomInsert(StrToInt(editCLLCount->Text), 0, CLLrange);
	reCLL->Lines->Add(StringToUnicode(cll.visualize()));
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btnDLLRandomClick(TObject *Sender)
{
	bool result = dll.randomInsert(StrToInt(editDLLCount->Text), 0, DLLrange);
	reDLL->Lines->Add(StringToUnicode(dll.visualize()));
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btnLSRandomClick(TObject *Sender)
{
	bool result = ls.randomInsert(StrToInt(editLSCount->Text), 0, LSrange);
	reLS->Lines->Add(StringToUnicode(ls.visualize()));
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btnLQRandomClick(TObject *Sender)
{
	bool result = lq.randomInsert(StrToInt(editLQCount->Text), 0, LQrange);
	reLQ->Lines->Add(StringToUnicode(lq.visualize()));
}
//---------------------------------------------------------------------------
void __fastcall TForm2::editLQCountChange(TObject *Sender)
{
	if(editLQCount->Text == ""){
		editLQCount->Text = "0";
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::editLSCountChange(TObject *Sender)
{
	if(editLSCount->Text == ""){
		editLSCount->Text = "0";
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::editDLLCountChange(TObject *Sender)
{
	if(editDLLCount->Text == ""){
		editDLLCount->Text = "0";
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::editCLLCountChange(TObject *Sender)
{
	if(editCLLCount->Text == ""){
		editCLLCount->Text = "0";
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::editCLLElementChange(TObject *Sender)
{
	if(editCLLElement->Text == ""){
		editCLLElement->Text = "0";
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::editCLLTargetChange(TObject *Sender)
{
	if(editCLLTarget->Text == ""){
		editCLLTarget->Text = "0";
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::editDLLElementChange(TObject *Sender)
{
	if(editDLLElement->Text == ""){
		editDLLElement->Text = "0";
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::editDLLTargetChange(TObject *Sender)
{
	if(editDLLTarget->Text == ""){
		editDLLTarget->Text = "0";
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::editLSElementChange(TObject *Sender)
{
	if(editLSElement->Text == ""){
		editLSElement->Text = "0";
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::editLQElementChange(TObject *Sender)
{
	if(editLQElement->Text == ""){
		editLQElement->Text = "0";
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btnPushClick(TObject *Sender)
{
	bool result = ls.push(StrToInt(editLSElement->Text));
    reLS->Lines->Add(StringToUnicode(ls.visualize()));
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btnPopClick(TObject *Sender)
{
	try {
		int result = ls.pop();
		editLSPopResult->Text = IntToStr(result);
		reLS->Lines->Add(StringToUnicode(ls.visualize()));
	} catch (...) {
		reLS->Lines->Add(StringToUnicode(ls.visualize()));
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btnEnqueueClick(TObject *Sender)
{
	bool result = lq.enqueue(StrToInt(editLQElement->Text));
	reLQ->Lines->Add(StringToUnicode(lq.visualize()));
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btnDequeueClick(TObject *Sender)
{
	try {
		int result = lq.dequeue();
		editLQDequeued->Text = IntToStr(result);
		reLQ->Lines->Add(StringToUnicode(lq.visualize()));
	} catch (...) {
		reLQ->Lines->Add(StringToUnicode(lq.visualize()));
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btnCLLInsertFirstClick(TObject *Sender)
{
	bool result = cll.insertFirst(StrToInt(editCLLElement->Text));
	reCLL->Lines->Add(StringToUnicode(cll.visualize()));
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btnCLLInsertLastClick(TObject *Sender)
{
	bool result = cll.insertLast(StrToInt(editCLLElement->Text));
	reCLL->Lines->Add(StringToUnicode(cll.visualize()));
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btnDLLInsertFirstClick(TObject *Sender)
{
	bool result = dll.insertFront(StrToInt(editDLLElement->Text));
	reDLL->Lines->Add(StringToUnicode(dll.visualize()));
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btnDLLInsertLastClick(TObject *Sender)
{
	bool result = dll.insertLast(StrToInt(editDLLElement->Text));
	reDLL->Lines->Add(StringToUnicode(dll.visualize()));
}
//---------------------------------------------------------------------------
void __fastcall TForm2::tsCLLShow(TObject *Sender)
{
	pcOutput->ActivePageIndex = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::tsDLLShow(TObject *Sender)
{
	pcOutput->ActivePageIndex = 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::tsLSShow(TObject *Sender)
{
	pcOutput->ActivePageIndex = 2;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::tsLQShow(TObject *Sender)
{
	pcOutput->ActivePageIndex = 3;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::btnCLLSearchClick(TObject *Sender)
{
	int result = cll.find(StrToInt(editCLLTarget->Text));
	String msg = "Target not found";
	if(result != -1) {
		msg = "Target located at index " + IntToStr(result);
	}
	reCLL->Lines->Add(msg);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::btnCLLDeleteClick(TObject *Sender)
{
	bool result = cll.deleteNode(StrToInt(editCLLTarget->Text));
    String msg = "Target not found";
	if (result) {
		msg = StringToUnicode(cll.visualize());
	}
	reCLL->Lines->Add(msg);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::btnCLLInsertAfterClick(TObject *Sender)
{
	bool result = cll.findAndInsertAfter(StrToInt(editCLLTarget->Text), StrToInt(editCLLElement->Text));
    String msg = "Target not found";
	if (result) {
		msg = StringToUnicode(cll.visualize());
	}
	reCLL->Lines->Add(msg);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::btnCLLInsertBeforeClick(TObject *Sender)
{
	bool result = cll.findAndInsertBefore(StrToInt(editCLLTarget->Text), StrToInt(editCLLElement->Text));
	String msg = "Target not found";
	if (result) {
		msg = StringToUnicode(cll.visualize());
	}
	reCLL->Lines->Add(msg);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::btnDLLSearchClick(TObject *Sender)
{
	int result = dll.find(StrToInt(editDLLTarget->Text));
	String msg = "Target not found";
	if(result != -1) {
		msg = "Target located at index " + IntToStr(result);
	}
	reDLL->Lines->Add(msg);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::btnDLLDeleteClick(TObject *Sender)
{
	bool result = dll.deleteNode(StrToInt(editDLLTarget->Text));
	String msg = "Target not found";
	if (result) {
		msg = StringToUnicode(dll.visualize());
	}
	reDLL->Lines->Add(msg);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::btnDLLInsertAfterClick(TObject *Sender)
{
	bool result = dll.findAndInsertAfter(StrToInt(editDLLTarget->Text), StrToInt(editDLLElement->Text));
	String msg = "Target not found";
	if (result) {
		msg = StringToUnicode(dll.visualize());
	}
	reDLL->Lines->Add(msg);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::btnDLLInsertBeforeClick(TObject *Sender)
{
	bool result = dll.findAndInsertBefore(StrToInt(editDLLTarget->Text), StrToInt(editDLLElement->Text));
    String msg = "Target not found";
	if (result) {
		msg = StringToUnicode(dll.visualize());
	}
	reDLL->Lines->Add(msg);
}
//---------------------------------------------------------------------------

