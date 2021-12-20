//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "mmsystem.h"

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

  int ballHorizontalOffset = 8;
  int ballVerticalOffset = 8;
  int leftPlayerPoints = 0;
  int rightPlayerPoints = 0;
  int numberBallBounces = 0;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rightRacketUpTimerTimer(TObject *Sender)
{
   if(rightRacket->Top > 10) rightRacket->Top -= 10;
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
     rightRacket->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::leftRacketUpTimerTimer(TObject *Sender)
{
   if(leftRacket->Top > 10) leftRacket->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::leftRacketDownTimerTimer(TObject *Sender)
{
   if(leftRacket->Top+leftRacket->Height < background->Height-10)
     leftRacket->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::timerBallTimer(TObject *Sender)
{
   ball->Left += ballHorizontalOffset;
   ball->Top += ballVerticalOffset;

   if(ball->Top-5 <= background->Top)
      ballVerticalOffset = -ballVerticalOffset;

   if(ball->Top + ball->Height >= background->Height)
      ballVerticalOffset = -ballVerticalOffset;
      
   if((ball->Left < leftRacket->Left) || (ball->Left > rightRacket->Left))
   {
      if(ball->Left < leftRacket->Left)
         rightPlayerPoints++;
      else if(ball->Left > rightRacket->Left)
         leftPlayerPoints++;

      timerBall->Enabled = false;
      ball->Visible = false;
      sndPlaySound("snd/start.wav",SND_SYNC);
      leftRacket->Visible = false;
      rightRacket->Visible = false;
      header->Transparent = false;
      header->Caption = "Current score " + IntToStr(leftPlayerPoints) + ":" +
      IntToStr(rightPlayerPoints) + "  ";
      header->Visible = true;
      ballBounces-> Caption = "Number of ball bounces: " +
      IntToStr(numberBallBounces) + "  ";
      numberBallBounces = 0;
      ballBounces->Visible = true;
      nextRound->Visible = true;
      startOver->Visible = true;
   }
   else if (((ball->Top > leftRacket->Top - ball->Height) &&
           (ball->Top < leftRacket->Top + leftRacket->Height + ball->Height) &&
           (ball->Left <= leftRacket->Left + leftRacket->Width)) ||
           ((ball->Top > rightRacket->Top - ball->Height) &&
           (ball->Top < rightRacket->Top + rightRacket->Height + ball->Height) &&
           (ball->Left + ball->Width >= rightRacket->Left)))
   {
       ballHorizontalOffset = -ballHorizontalOffset;
       numberBallBounces++;

       if(timerBall->Interval != 2)
           timerBall->Interval -= 2;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::newGameClick(TObject *Sender)
{
   ball->Picture->LoadFromFile("img/ball.bmp");
   leftRacket->Picture->LoadFromFile("img/racket.bmp");
   rightRacket->Picture->LoadFromFile("img/racket.bmp");
   header->Visible = false;
   newGame->Visible = false;
   timerBall->Enabled = true;
   leftRacket->Visible = true;
   rightRacket->Visible = true;
   ball->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::startOverClick(TObject *Sender)
{
   if(Application->MessageBox(
   "Are you sure you want to start over?", "Confirm",
   MB_YESNO | MB_ICONQUESTION) == IDYES)
   {
      ballHorizontalOffset = 8;
      ballVerticalOffset = 8;
      ball->Left = 448;
      ball->Top = 288;
      leftRacket->Left = 16;
      leftRacket->Top = 152;
      rightRacket->Left = 904;
      rightRacket->Top = 152;
      leftPlayerPoints = 0;
      rightPlayerPoints = 0;
      timerBall->Interval = 30;
      header->Visible = false;
      ballBounces->Visible = false;
      nextRound->Visible = false;
      startOver->Visible = false;
      timerBall->Enabled = true;
      leftRacket->Visible = true;
      rightRacket->Visible = true;
      ball->Visible = true;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::nextRoundClick(TObject *Sender)
{
     ballHorizontalOffset = 8;
     ballVerticalOffset = 8;
     ball->Left = 448;
     ball->Top = 288;
     leftRacket->Left = 16;
     leftRacket->Top = 152;
     rightRacket->Left = 904;
     rightRacket->Top = 152;
     timerBall->Interval = 30;
     header->Visible = false;
     ballBounces->Visible = false;
     nextRound->Visible = false;
     startOver->Visible = false;
     leftRacket->Visible = true;
     rightRacket->Visible = true;
     timerBall->Enabled = true;
     ball->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::informationClick(TObject *Sender)
{
    AnsiString welcome = "Welcome to PingPong Game!";
    AnsiString leftplayer = "Left player moves the paddle by using W and S buttons.";
    AnsiString rightPlayer = "Right player moves the paddle by using Up Arrow and Down Arrow. ";
    AnsiString ballBounce = "The longer you bounce, the faster moves the ball. ";
    AnsiString goodLuck = "Good Luck!";

    ShowMessage(welcome + '\n' + '\n' + leftplayer + '\n' + rightPlayer + '\n' +
                ballBounce + '\n' + '\n'+ goodLuck);
}
//---------------------------------------------------------------------------


