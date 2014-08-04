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
    content::Message c {};

    if (request().request_method() == "POST") {
        c.info.load(context());

        if (c.info.validate()) {
            session()["name"] = c.info.name.value();
            session()["sex"] = c.info.sex.selected_id();
            session()["state"] = c.info.marital.selected_id();
            session().set("age", c.info.age.value());
            c.info.clear();
        }
    }

    if (session().is_set("name")) {
        c.name = session()["name"];

        if (session()["sex"] == "male") {
            c.who = "Mr";
        }
        else {
            if (session()["state"] == "single") {
                c.who = "Miss";
            }
            else {
                c.who = "Mrs";
            }
        }
        
        c.age = session().get<double>("age");
    }
    else {
        c.name = "Visitor";
        c.age = -1.0;
    }

    render("Message", c);
}

#endif	/* FORMS_H */

