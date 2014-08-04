/* 
 * File:   content.h
 * Author: Erasmo
 *
 * Created on 31 de julio de 2014, 05:47 PM
 */

#ifndef CONTENT_H
#define	CONTENT_H

#include <cppcms/view.h>
#include <string>

namespace content {

    struct message : cppcms::base_content {
        std::string text;
    };
}

#endif	/* CONTENT_H */

