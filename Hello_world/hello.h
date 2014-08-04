/* 
 * File:   hello.h
 * Author: Erasmo
 *
 * Created on 29 de julio de 2014, 11:38 AM
 */

#ifndef HELLO_H
#define	HELLO_H

#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/service.h>
#include <cppcms/http_response.h>
#include <cppcms/url_dispatcher.h>
#include <iostream>
#include <cstdlib>

#include "content.h"

class Hello : public cppcms::application
{
public:

    Hello(cppcms::service& /* srv */);
//    virtual void main(std::string /* url */);
    void number(std::string /* num */);
    void smile();
    void welcome();
};

Hello::Hello(cppcms::service& srv) :
cppcms::application(srv)
{
    dispatcher().assign("/number/(\\d+)", &Hello::number, this, 1);
    mapper().assign("number", "/number/{1}");

    dispatcher().assign("/smile", &Hello::smile, this);
    mapper().assign("smile", "/smile");

    dispatcher().assign("", &Hello::welcome, this);
    mapper().assign("");

    mapper().root("/hello");
}

//void Hello::main(std::string /* url */)
//{
//    content::message c;
//    c.text = ">>>Hello<<<";
//    render("message", c);
//}

void Hello::number(std::string num)
{
    int no = atoi(num.c_str());
    response().out() << "The number is " << no << "<br />";
    response().out() << "<a href='" << url("/") << "'>Go back</a>";
}

void Hello::smile()
{
    response().out() << ":-) <br />\n";
    response().out() << "<a href='" << url("/") << "'>Go back</a>";
}

void Hello::welcome()
{
    response().out() <<
            "<h1>Welcome to page with links</h1>\n"
            "<a href='" << url("/number", 1) << "'>1</a><br />\n"
            "<a href='" << url("/number", 15) << "'>15</a><br />\n"
            "<a href='" << url("/smile") << "'>:-)</a><br />\n";

}
#endif	/* HELLO_H */
