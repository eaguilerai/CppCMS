/* 
 * File:   content.h
 * Author: Erasmo
 *
 * Created on 03 de agosto de 2014, 11:24 PM
 */

#ifndef CONTENT_H
#define	CONTENT_H

#include <cppcms/view.h>
#include <cppcms/form.h>

namespace content {

    struct Info_form : public cppcms::form
    {
        cppcms::widgets::text name {};
        cppcms::widgets::radio sex {};
        cppcms::widgets::select marital {};
        cppcms::widgets::numeric<double> age {};
        cppcms::widgets::submit submit {};

        Info_form()
        {
            name.message("Your name");
            sex.message("Your sex");
            marital.message("Marital status");
            age.message("Your age");
            submit.value("Send");

            add(name);
            add(sex);
            add(marital);
            add(age);
            add(submit);

            sex.add("Male", "male");
            sex.add("Female", "female");
            marital.add("Single", "single");
            marital.add("Married", "married");
            marital.add("Divorced", "divorced");

            name.non_empty();
            age.range(0, 120);
        }

        virtual bool validate()
        {
            if (!cppcms::form::validate()) {
                return false;
            }
            else if (marital.selected_id() != "single"
                    && age.value() < 18) {
                marital.valid(false);
                return false;
            }

            return true;
        }
    };

    struct message : public cppcms::base_content
    {
        std::string name {};
        std::string state {};
        std::string sex {};
        double age {};
        Info_form info {};
    };

    //    Info_form::Info_form()
    //    {
    //        name.message("Your name");
    //        sex.message("Your sex");
    //        marital.message("Marital status");
    //        age.message("Your age");
    //        submit.value("Send");
    //
    //        add(name);
    //        add(sex);
    //        add(marital);
    //        add(age);
    //        add(submit);
    //
    //        sex.add("Male", "male");
    //        sex.add("Female", "female");
    //        marital.add("Single", "single");
    //        marital.add("Married", "married");
    //        marital.add("Divorced", "divorced");
    //
    //        name.non_empty();
    //        age.range(0, 120);
    //    }

    //    bool Info_form::validate()
    //    {
    //        if (!cppcms::form::validate()) {
    //            return false;
    //        }
    //        else if (marital.selected_id() != "single"
    //                && age.value() < 18) {
    //            marital.valid(false);
    //            return false;
    //        }
    //        
    //        return true;
    //    }
}

#endif	/* CONTENT_H */

