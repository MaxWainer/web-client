// MIT License
//
// Copyright (c) 2022 Max_Wainer
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

//
// Created by HYPERPC on 5/25/2022.
//

#include "request_type.hpp"

#include <sstream>

namespace web_cli {

    std::ostream &operator<<(std::stringstream &ostream, const web_cli::MediaType &obj) {
        ostream << obj.p_type;
        ostream << std::string("/");
        ostream << obj.p_subtype;

        if (obj.p_rawCharset != "NOT SET") {
            ostream << std::string("; charset=");
            ostream << obj.p_rawCharset;
        }

        return ostream;
    }

    std::string MediaType::asString() {
        std::stringstream ostream;

        ostream << this;

        return ostream.str();
    }

    std::ostream &operator<<(std::stringstream &ostream, const RequestBody &obj) {
        ostream << obj.p_rawBody;
        return ostream;
    }

    std::string RequestBody::asString() {
        std::stringstream ostream;

        ostream << this;

        return ostream.str();
    }
} // namespace web_cli