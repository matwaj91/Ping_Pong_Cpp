//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

  int ballHorizontalOffset = -8;
  int ballVerticalOffset = 8;
  
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rightRacketUpTimerTimer(TObject *Sender)
{
   if(rightRacket->Top > 10)
   {
        rightRacket->Top -= 10;
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if(Key == VK_UP) rightRacketUp->Enabled = true;
   if(Key == VK_DOWN) rightRacketDown->Enabled = true;
   if(Key == 87) leftRacketUp->Enabled = true;
   if(Key == 83) leftRacketDown->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if(Key == VK_UP) rightRacketUp->Enabled = false;
   if(Key == VK_DOWN) rightRacketDown->Enabled = false;
   if(Key == 87) leftRacketUp->Enabled = false;
   if(Key == 83) leftRacketDown->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::rightRacketDownTimerTimer(TObject *Sender)
{
   if(rightRacket->Top+rightRacket->Height < background->Height-10)
   {
     rightRacket->Top += 10;
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::leftRacketUpTimerTimer(TObject *Sender)
{
   if(leftRacket->Top > 10)
   {
     leftRacket->Top -= 10;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::leftRacketDownTimerTimer(TObject *Sender)
{
   if(leftRacket->Top+leftRacket->Height < background->Height-10)
   {
     leftRacket->Top += 10;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::timerBallTimer(TObject *Sender)
{
   ball->Left += ballHorizontalOffset;
   ball->Top += ballVerticalOffset;

   if(ball->Top-5 <= background->Top)
   {
      ballVerticalOffset = -ballVerticalOffset;
   }
   if(ball->Top + ball->Height >= background->Height)
   {
      ballVerticalOffset = -ballVerticalOffset;
   }
   if(ball->Left <= leftRacket->Left + leftRacket->Width)
   {
      timerBall->Enabled = false;
      ball->Visible = false;
   }
   else if (ball->Top > leftRacket->Top - ball->Height/2 &&
            ball->Top < leftRacket->Top + leftRacket->Height &&
            ball->Left >= leftRacket->Left + leftRacket->Width)
   {
      if(ballHorizontalOffset > 0) ballHorizontalOffset = -ballHorizontalOffset;
   } ///

}
//---------------------------------------------------------------------------


