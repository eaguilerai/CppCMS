/* 
 * File:   app.h
 * Author: Erasmo
 *
 * Created on 05 de agosto de 2014, 03:34 PM
 */

#ifndef APP_H
#define	APP_H

#include "content.h"

#include <cppcms/application.h>
#include <cppcms/service.h>
#include <cppcms/rpc_json.h>
#include <cppcms/url_dispatcher.h>

#include <string>
#include <iostream>

class App : public cppcms::rpc::json_rpc_server
{
public:
    App(cppcms::service& /* srv */);
    virtual void main(std::string /* url */);
    void load();
};

App::App(cppcms::service& srv) : cppcms::rpc::json_rpc_server(srv)
{
    dispatcher().assign("", &App::load, this);
    mapper().assign("");

    mapper().root("/app");
}

void App::main(std::string url)
{
    dispatcher().dispatch(url);
}

void App::load()
{
    content::Content c {};
    render("Content", c);
}

#endif	/* APP_H */

