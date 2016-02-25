/**********************************************************************

   Audacity: A Digital Audio Editor
   Paulstretch.h

   Nasca Octavian Paul (Paul Nasca)

 **********************************************************************/

#ifndef __AUDACITY_EFFECT_PAULSTRETCH__
#define __AUDACITY_EFFECT_PAULSTRETCH__

#include <wx/string.h>

#include "Effect.h"

class ShuttleGui;

#define PAULSTRETCH_PLUGIN_SYMBOL XO("Paulstretch")

class EffectPaulstretch final : public Effect
{
public:
   EffectPaulstretch();
   virtual ~EffectPaulstretch();

   // IdentInterface implementation

   virtual wxString GetSymbol();
   virtual wxString GetDescription();

   // EffectIdentInterface implementation

   virtual EffectType GetType();

   // EffectClientInterface implementation

   virtual bool GetAutomationParameters(EffectAutomationParameters & parms);
   virtual bool SetAutomationParameters(EffectAutomationParameters & parms);

   // Effect implementation

   virtual double CalcPreviewInputLength(double previewLength);
   virtual bool Process();
   virtual void PopulateOrExchange(ShuttleGui & S);
   virtual bool TransferDataToWindow();
   virtual bool TransferDataFromWindow();

private:
   // EffectPaulstretch implementation
   
   void OnText(wxCommandEvent & evt);
   int GetBufferSize(double rate);

   bool ProcessOne(WaveTrack *track, double t0, double t1, int count);

private:
   float mAmount;
   float mTime_resolution;  //seconds
   double m_t1;

   DECLARE_EVENT_TABLE();
};

#endif

