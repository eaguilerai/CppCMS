/* 
 * File:   content.h
 * Author: Erasmo
 *
 * Created on 04 de agosto de 2014, 04:32 PM
 */

#ifndef CONTENT_H
#define	CONTENT_H

#include <cppcms/view.h>
#include <cppcms/form.h>
#include <string>

namespace content {

    struct Input_form : public cppcms::form
    {
        cppcms::widgets::numeric<int> arg {};
        cppcms::widgets::submit submit {};
        
        Input_form() {
            arg.message("Argument:");
            submit.value("Calculate");
            
            add(arg);
            add(submit);
            
            arg.non_empty();
        }
    };
    
    struct Message : public cppcms::base_content
    {
        long long int fact {};
        int arg {};
        Input_form info {};
    };
}
#endif	/* CONTENT_H */

