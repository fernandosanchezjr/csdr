/*
Copyright (c) 2023 Marat Fayzullin <luarvique@gmail.com>

This file is part of libcsdr.

libcsdr is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

libcsdr is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with libcsdr.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include "module.hpp"

namespace Csdr {

    template <typename T>
    class Afc: public Module<T, T> {
        public:
            Afc(unsigned int sampleRate, unsigned int bandwidth, unsigned int syncWidth);

            bool canProcess() override;
            void process() override;

        private:
            // Configuration
            unsigned int sampleRate; // Sample rate
            unsigned int bandwidth;  // Usable signal bandwidth
            unsigned int syncWidth;  // Center window width
            unsigned int buckets;    // Number of FFT buckets

            // Goertzel coefficients
            double coeffL;           // Left bucket
            double coeffR;           // Right bucket

            // State
            unsigned int deltaF;     // Current frequency correction
    };
}
