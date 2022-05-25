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

#ifndef WEB_CLIENT_REQUEST_TYPE_HPP
#define WEB_CLIENT_REQUEST_TYPE_HPP

#include <string>
#include "../commons/commons.hpp"

namespace web_cli {

    struct RequestBody : public commons::IToString {
    private:
        const std::string &p_rawBody;
    public:
        explicit RequestBody(const std::string &rawBody) : p_rawBody(rawBody) {}

        friend std::ostream &operator<<(std::stringstream &, const RequestBody &);

        std::string asString() override;
    };

    struct MediaType : public commons::IToString {
    private:
        const std::string &p_type;
        const std::string &p_subtype;
        const std::string &p_rawCharset;
    public:
        MediaType(const std::string &type,
                  const std::string &subtype,
                  const std::string &rawCharset = "NOT SET") : p_type(type), p_subtype(subtype),
                                                               p_rawCharset(rawCharset) {}

        friend std::ostream &operator<<(std::stringstream &, const MediaType &);

        std::string asString() override;
    };

    namespace request_type {
        class IType {
        public:
            virtual std::string rawName() = 0;
        };

        struct GetType : public IType {
        private:
            static GetType *p_instance;

            // keep constructors private
            GetType() = default;

            GetType(const GetType &) = default;

            GetType &operator=(GetType &) = default;

        public:
            std::string rawName() override {
                return "GET";
            }

            static GetType *instance() {
                if (!p_instance)
                    p_instance = new GetType();

                return p_instance;
            }
        };

        class PostType : public IType {
        private:
            const RequestBody &p_requestBody;
        public:
            explicit PostType(const RequestBody &body) : p_requestBody(body) {};

            std::string rawName() override {
                return "POST";
            }
        };
    }; // namespace request_type

} // namespace web_cli

#endif //WEB_CLIENT_REQUEST_TYPE_HPP
