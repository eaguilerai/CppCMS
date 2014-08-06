/* 
 * File:   JSON_RPC.h
 * Author: Erasmo
 *
 * Created on 04 de agosto de 2014, 08:39 PM
 */

#ifndef JSON_RPC_H
#define	JSON_RPC_H

#include "content.h"

#include <cppcms/application.h>
#include <cppcms/service.h>
#include <cppcms/rpc_json.h>
#include <cppcms/url_dispatcher.h>

#include <string>
#include <iostream>

class JSON_service : public cppcms::rpc::json_rpc_server
{
public:
    JSON_service(cppcms::service& /* srv */);
    virtual void main(std::string /* url */);
    void calc();
    void sum(int /* x */, int /* y */);
    void div(int /* x */, int /* y */);
};

JSON_service::JSON_service(cppcms::service& srv) :
cppcms::rpc::json_rpc_server(srv)
{
    dispatcher().assign("", &JSON_service::calc, this);
    mapper().assign("");

    bind("sum", cppcms::rpc::json_method(&JSON_service::sum, this), method_role);
    bind("div", cppcms::rpc::json_method(&JSON_service::div, this), method_role);

    mapper().root("/rpc");
}

void JSON_service::main(std::string url)
{
    std::cout << "URL: " << url << std::endl;
    dispatcher().dispatch(url);
}

void JSON_service::calc()
{
    std::cout << "On calc()." << std::endl;
    std::cout << "Method: " << request().request_method() << std::endl;

    content::None c {};
    render("Client", c);
}

void JSON_service::sum(int x, int y)
{
    return_result(x + y);
}

void JSON_service::div(int x, int y)
{
    std::cout << "On div()" << std::endl;
    if (y == 0) {
        return_error("Division by zero.");
    }
    else {
        return_result(x / y);
    }
}

#endif	/* JSON_RPC_H */

