//
//  main.cpp
//  CommonInterfaceManager
//
//  Created by Rados Jovanovic on 2016-11-19.
//  Copyright (c) 2016 into the clouds. All rights reserved.
//

#include <iostream>
#include "json.hpp"
#include "Manager.h"
#include "ManagerConfig.h"

#include "InputTokens.h"

// forward decl
nlohmann::json CreateExampleJson();


int main(int argc, const char * argv[]) {

    std::cout << "Hello, World!\n";

    // setup the manager
    visible::ManagerConfig config;
    config.shouldX = true;
    config.shouldY = true;

    visible::Manager manager(config);

    // create parameters for a function and call it
    const nlohmann::json jsonObject = CreateExampleJson();
    manager.foo(jsonObject);

    return 0;
}

// a helper object can assist with creation of the json string.
// We could have inputJson.SetUsername(name) instead of raw json creation.
nlohmann::json CreateExampleJson()
{
    nlohmann::json j = {
            {token::USERNAME, "Bond"}, // needed for X.foo and Y.foo
            {token::CODENAME, "007"},  // needed for Y.foo
    };
    return j;
}