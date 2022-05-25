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
