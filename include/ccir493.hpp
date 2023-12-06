/*
Copyright (c) 2023 Marat Fayzullin <luarvique@gmail.com>
Copyright (c) 2023 Jakob Ketterl <jakob.ketterl@gmx.de>

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

    const unsigned char CCIR493_LETTERS[] = {
    };

    class Ccir493Decoder: public Module<unsigned short, unsigned char> {
        public:
            Ccir493Decoder(bool fec = true, unsigned int errorsAllowed = 16)
            : useFec(fec), errorsAllowed(errorsAllowed) {}

            bool canProcess() override;
            void process() override;

        private:
            unsigned int errorsAllowed;
            unsigned int errors = 0;
            int mode = 0;
            bool useFec;

            unsigned char fec(unsigned short code);
            unsigned char ascii(unsigned short code);
            bool isValid(unsigned short code);
    };
}