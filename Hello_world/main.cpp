/* 
 * File:   main.cpp
 * Author: Erasmo
 *
 * Created on 29 de julio de 2014, 11:11 AM
 */

#include "hello.h"

#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/service.h>
#include <cppcms/http_response.h>
#include <cppcms/json.h>
#include <iostream>

/*
 * 
 */
int main(int argc, char** argv) {
    try {
        std::cout << "Program started.\n";
        cppcms::service srv(argc, argv);
        srv.applications_pool().mount(
                cppcms::applications_factory<Hello>()
                );
        srv.run();
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
