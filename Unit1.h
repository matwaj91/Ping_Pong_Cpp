//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *background;
        TImage *ball;
        TTimer *timerBall;
        TImage *leftRacket;
        TImage *rightRacket;
        TTimer *leftRacketUp;
        TTimer *leftRacketDown;
        TTimer *rightRacketUp;
        TTimer *rightRacketDown;
        void __fastcall rightRacketUpTimerTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall rightRacketDownTimerTimer(TObject *Sender);
        void __fastcall leftRacketUpTimerTimer(TObject *Sender);
        void __fastcall leftRacketDownTimerTimer(TObject *Sender);
        void __fastcall timerBallTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
