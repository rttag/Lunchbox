
/* Copyright (c) 2012, Stefan Eilemann <eile@eyescale.ch>
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License version 2.1 as published
 * by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef LUNCHBOX_PLUGIN_COMPRESSORLZF
#define LUNCHBOX_PLUGIN_COMPRESSORLZF

#include "compressor.h"

namespace lunchbox
{
namespace plugin
{

class CompressorLZF : public Compressor
{
public:
    CompressorLZF() : Compressor() {}
    virtual ~CompressorLZF() {}

    virtual void compress( const void* const inData, const eq_uint64_t nPixels,
                           const bool useAlpha );

    static void decompress( const void* const* inData,
                            const eq_uint64_t* const inSizes,
                            const unsigned nInputs, void* const outData,
                            const eq_uint64_t nPixels, const bool useAlpha );

    static void* getNewCompressor( const unsigned name )
        { return new lunchbox::plugin::CompressorLZF; }
    static void* getNewDecompressor( const unsigned name ){ return 0; }
};
}
}
#endif
