/* 
 * File:   cache.h
 * Author: Erasmo
 *
 * Created on 04 de agosto de 2014, 04:44 PM
 */

#ifndef CACHE_H
#define	CACHE_H

#include <cppcms/application.h>
#include <cppcms/service.h>
#include <cppcms/cache_interface.h>

#include "content.h"

class Caching : public cppcms::application
{
public:
    Caching(cppcms::service& srv);
    virtual void main(std::string /* url */);
};

Caching::Caching(cppcms::service& srv) : cppcms::application(srv)
{
}

void Caching::main(std::string /* url */)
{
    content::Message c {};
    c.arg = 0;
    c.fact = 1;
    
    if (request().request_method() == "POST") {
        c.info.load(context());
        
        if (c.info.validate()) {
            c.arg = c.info.arg.value();
            c.info.clear();
        }
    }
    else {
        render("Message", c);
        return;
    }
    
    std::ostringstream key;
    key << "factorial_" << c.arg;
    
    if (cache().fetch_page(key.str())) {
        return;
    }
    else {
        long long int f = 1;
        
        for (int i = 1; i <= c.arg; i++) {
            f *= i;
        }
        
        c.fact = f;
        render("Message", c);
        cache().store_page(key.str(), 3600);
    }
}

#endif	/* CACHE_H */

