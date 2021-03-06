//
// Programmer:    Craig Stuart Sapp <craig@ccrma.stanford.edu>
// Creation Date: Fri Jan 18 22:09:03 PST 2002
// Last Modified: Wed Feb 13 13:24:04 PST 2002
// Filename:      SoundFileRead.h
// Based On:      http://sig.sapp.org/include/sigSignal/SoundFileIn.h
// Syntax:        C++ 
//
//

#ifndef _SOUNDFILEREAD_H_INCLUDED
#define _SOUNDFILEREAD_H_INCLUDED

#include "SoundHeader.h"
#include "Array.h"

#ifndef OLDCPP
   #include <iostream>
   #include <fstream>
   using namespace std;
#else
   #include <iostream.h>
   #include <fstream.h>
#endif


class SoundFileRead : public SoundHeader {
   public:
                    SoundFileRead            (const char* aFileName = "",
                                              double start    = -1,
                                              double dur      = -1);
                   ~SoundFileRead            ();

      int           getNextSample16Bit       (int channel = 0);
      int           getCurrentSample16Bit    (int channel = 0);
      int           getNextSample24Bit       (int channel = 0);
      int           getCurrentSample24Bit    (int channel = 0);
      double        getNextSampleDouble      (int channel = 0);
      double        getCurrentSampleDouble   (int channel = 0);
      int           getCurrentSampleIndex    (void);
      void          incrementSample          (void);
      void          setStartAndDuration      (double start, double duration);
      void          reset                    (int sampleIndex = -1);
      void          gotoSample               (int sampleIndex);

      void          setFile                  (const char*  aFileName, 
                                              double start = -1, 
                                              double dur = -1);
      const char*   getFilename              (void);
      void          setLoopOption            (int mode);
      void          setLoopOn                (void);
      void          setLoopOff               (void);

   protected:
      FileIO        sndfile;                 // soundfile input stream
      char         *filename;                // name of the soundfile
      int           endianType;              // how soundfile data is stored
      Array<double> current;                 // output samples, by channel
 
      long          curIndex;                // current sample number
      long          begIndex;                // first sample number
      long          endIndex;                // last sample number (for loop)
      long          sampleCount;             // highest sample index value 
      int           loopingQ;

   private:
      double        (*readSample)            (FileIO&);
      void          determineReadingFunction (void);
      void          fillCurrentArray         (void);
        
};
        


#endif  /* _SOUNDFILEREAD_H_INCLUDED */

