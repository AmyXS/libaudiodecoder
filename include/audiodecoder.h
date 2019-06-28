/*
 * libaudiodecoder - Native Portable Audio Decoder Library
 * libaudiodecoder API Header File
 * Latest version available at: http://www.oscillicious.com/libaudiodecoder
 *
 * Copyright (c) 2010-2012 Albert Santoni, Bill Good, RJ Ryan  
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/*
 * The text above constitutes the entire libaudiodecoder license; however, 
 * the Oscillicious community also makes the following non-binding requests:
 *
 * Any person wishing to distribute modifications to the Software is
 * requested to send the modifications to the original developer so that
 * they can be incorporated into the canonical version. It is also 
 * requested that these non-binding requests be included along with the 
 * license above.
 */


#ifndef __AUDIODECODER_H__
#define __AUDIODECODER_H__

#include "audiodecoderbase.h"

#ifdef _WIN32 //Always defined on both Win32 and Win64 - http://msdn.microsoft.com/en-us/library/b0084kay(v=vs.80).aspx
#include "audiodecodermediafoundation.h"

class DllExport AudioDecoder : public AudioDecoderMediaFoundation
{
    public:
        AudioDecoder(const std::string& filename, int output_sample_rate = -1) : AudioDecoderMediaFoundation(filename, output_sample_rate) {};
    private:
        //Disable copy constructor and assignment operator
        AudioDecoder(const AudioDecoder& that);
        AudioDecoder& operator=(AudioDecoder const&);
};

#elif __APPLE__
#include "audiodecodercoreaudio.h"
class AudioDecoder : public AudioDecoderCoreAudio
{
    public:
        //When output_sample_rate is -1, the sample rate of the file will be used as output sample rate
        AudioDecoder(const std::string& filename, int output_sample_rate = -1) : AudioDecoderCoreAudio(filename, output_sample_rate) {};
    private:
        //Disable copy constructor and assignment operator
        AudioDecoder(const AudioDecoder& that);
        AudioDecoder& operator=(AudioDecoder const&);
};
#endif

#endif //__AUDIODECODER_H__
