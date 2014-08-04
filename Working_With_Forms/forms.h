/* 
 * File:   forms.h
 * Author: Erasmo
 *
 * Created on 04 de agosto de 2014, 12:05 AM
 */

#ifndef FORMS_H
#define	FORMS_H

#include "content.h"

#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/service.h>
#include <cppcms/http_response.h>
#include <iostream>

class Forms : public cppcms::application
{
public:
    Forms(cppcms::service& srv);
    virtual void main(std::string /* url */);
};

Forms::Forms(cppcms::service& srv) : cppcms::application(srv)
{
}

void Forms::main(std::string /* url */)
{
//    response().out() <<
//            "<html>"
//            "   <body>"
//            "       <h1>Hello world!</h1>"
//            "   </body>"
//            "</html>";
    content::message c {};
    
    if (request().request_method() == "POST") {
        c.info.load(context());
        
        if (c.info.validate()) {
            c.name = c.info.name.value();
            c.sex = c.info.sex.selected_id();
            c.state = c.info.marital.selected_id();
            c.age = c.info.age.value();
            
            c.info.clear();
        }
    }
    
    render("message", c);
}

#endif	/* FORMS_H */

