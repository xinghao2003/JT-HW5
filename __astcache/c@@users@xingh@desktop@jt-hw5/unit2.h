﻿//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "lib\CircularLinkedList.h"
#include "lib\DoublyLinkedList.h"
#include "lib\LinkedQueue.h"
#include "lib\LinkedStack.h"
#include "lib\Reverse.h"
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TPageControl *pcOperations;
	TTabSheet *tsCLL;
	TTabSheet *tsDLL;
	TTabSheet *tsLS;
	TTabSheet *tsLQ;
	TPageControl *pcOutput;
	TTabSheet *tsCLLOuput;
	TTabSheet *tsDLLOutput;
	TTabSheet *tsLSOuput;
	TTabSheet *tsLQUOutput;
	TGroupBox *gbCLLInsert;
	TGroupBox *gbCLLSearch;
	TGroupBox *gbCLLRandom;
	TRichEdit *reLQ;
	TRichEdit *reLS;
	TRichEdit *reDLL;
	TRichEdit *reCLL;
	TEdit *editCLLElement;
	TEdit *editCLLTarget;
	TEdit *editCLLCount;
	TEdit *editCLLRange;
	TGroupBox *gbPushPop;
	TGroupBox *gbLSOperations;
	TGroupBox *gbLSRandom;
	TEdit *editLSElement;
	TButton *btnPush;
	TButton *btnCLLInsertFirst;
	TButton *btnCLLInsertLast;
	TButton *btnCLLSearch;
	TButton *btnLSClear;
	TButton *btnLSReverse;
	TGroupBox *gbCLLOperations;
	TButton *btnCLLClear;
	TButton *btnCLLReverse;
	TButton *btnClear;
	TButton *btnPrint;
	TButton *btnCLLDelete;
	TButton *btnCLLInsertAfter;
	TButton *btnCLLInsertBefore;
	TButton *btnCLLRandom;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TGroupBox *gbDLLOperations;
	TButton *btnDLLClear;
	TButton *btnDLLReverse;
	TGroupBox *gbDLLInsert;
	TLabel *Label5;
	TEdit *editDLLElement;
	TButton *btnDLLInsertFirst;
	TButton *btnDLLInsertLast;
	TGroupBox *gbDLLSearch;
	TLabel *Label6;
	TEdit *editDLLTarget;
	TButton *btnDLLSearch;
	TButton *btnDLLDelete;
	TButton *btnDLLInsertAfter;
	TButton *btnDLLInsertBefore;
	TGroupBox *gbDLLRandom;
	TLabel *Label7;
	TLabel *Label8;
	TEdit *editDLLCount;
	TEdit *editDLLRange;
	TButton *btnDLLRandom;
	TTrackBar *tbCLLRange;
	TButton *btnPop;
	TTrackBar *tbDLLRange;
	TLabel *Label12;
	TLabel *Label13;
	TEdit *editLSCount;
	TLabel *Label9;
	TLabel *Label11;
	TEdit *editLSRange;
	TTrackBar *tbLSRange;
	TButton *btnLSRandom;
	TEdit *editLSPopResult;
	TGroupBox *gbLQRandom;
	TLabel *Label10;
	TLabel *Label14;
	TEdit *editLQCount;
	TEdit *editLQRange;
	TTrackBar *tbLQRange;
	TButton *btnLQRandom;
	TGroupBox *gbLQOperations;
	TButton *btnLQClear;
	TButton *btnLQReverse;
	TGroupBox *gbLQEnqueueDequeue;
	TLabel *Label15;
	TLabel *Label16;
	TEdit *editLQElement;
	TButton *btnEnqueue;
	TButton *btnDequeue;
	TEdit *editLQDequeued;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall tsDLLOutputShow(TObject *Sender);
	void __fastcall tsLQUOutputShow(TObject *Sender);
	void __fastcall tsLSOuputShow(TObject *Sender);
	void __fastcall tsCLLOuputShow(TObject *Sender);
	void __fastcall btnClearClick(TObject *Sender);
	void __fastcall btnPrintClick(TObject *Sender);
	void __fastcall editLQRangeChange(TObject *Sender);
	void __fastcall btnCLLClearClick(TObject *Sender);
	void __fastcall btnCLLReverseClick(TObject *Sender);
	void __fastcall btnDLLClearClick(TObject *Sender);
	void __fastcall btnDLLReverseClick(TObject *Sender);
	void __fastcall btnLSClearClick(TObject *Sender);
	void __fastcall btnLSReverseClick(TObject *Sender);
	void __fastcall btnLQClearClick(TObject *Sender);
	void __fastcall btnLQReverseClick(TObject *Sender);
	void __fastcall editLSRangeChange(TObject *Sender);
	void __fastcall editDLLRangeChange(TObject *Sender);
	void __fastcall editCLLRangeChange(TObject *Sender);
	void __fastcall tbCLLRangeChange(TObject *Sender);
	void __fastcall tbDLLRangeChange(TObject *Sender);
	void __fastcall tbLSRangeChange(TObject *Sender);
	void __fastcall tbLQRangeChange(TObject *Sender);
	void __fastcall btnLQRandomClick(TObject *Sender);
	void __fastcall btnCLLRandomClick(TObject *Sender);
	void __fastcall btnDLLRandomClick(TObject *Sender);
	void __fastcall btnLSRandomClick(TObject *Sender);
	void __fastcall editLQCountChange(TObject *Sender);
	void __fastcall editLSCountChange(TObject *Sender);
	void __fastcall editDLLCountChange(TObject *Sender);
	void __fastcall editCLLCountChange(TObject *Sender);
	void __fastcall editCLLElementChange(TObject *Sender);
	void __fastcall editCLLTargetChange(TObject *Sender);
	void __fastcall editDLLElementChange(TObject *Sender);
	void __fastcall editDLLTargetChange(TObject *Sender);
	void __fastcall editLSElementChange(TObject *Sender);
	void __fastcall editLQElementChange(TObject *Sender);
	void __fastcall btnPushClick(TObject *Sender);
	void __fastcall btnPopClick(TObject *Sender);
	void __fastcall btnEnqueueClick(TObject *Sender);
	void __fastcall btnDequeueClick(TObject *Sender);
	void __fastcall btnCLLInsertFirstClick(TObject *Sender);
	void __fastcall btnCLLInsertLastClick(TObject *Sender);
	void __fastcall btnDLLInsertFirstClick(TObject *Sender);
	void __fastcall btnDLLInsertLastClick(TObject *Sender);
	void __fastcall tsDLLShow(TObject *Sender);
	void __fastcall tsCLLShow(TObject *Sender);
	void __fastcall tsLSShow(TObject *Sender);
	void __fastcall tsLQShow(TObject *Sender);
	void __fastcall btnCLLSearchClick(TObject *Sender);
	void __fastcall btnCLLDeleteClick(TObject *Sender);
	void __fastcall btnCLLInsertAfterClick(TObject *Sender);
	void __fastcall btnCLLInsertBeforeClick(TObject *Sender);
	void __fastcall btnDLLSearchClick(TObject *Sender);
	void __fastcall btnDLLDeleteClick(TObject *Sender);
	void __fastcall btnDLLInsertAfterClick(TObject *Sender);
	void __fastcall btnDLLInsertBeforeClick(TObject *Sender);



private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
