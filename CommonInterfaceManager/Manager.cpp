//
// Created by Rados Jovanovic on 2016-11-19.
// Copyright (c) 2016 into the clouds. All rights reserved.
//

#include "Manager.h"
#include "ManagerConfig.h"
#include "inputTokens.h"
#include "X.h"
#include "Y.h"

//////////////////////////////////////////////////////////////////////
//  IMPLEMENTATION CLASS
//////////////////////////////////////////////////////////////////////

class visible::Manager::Impl {
public:
    Impl(const ManagerConfig& config):config(config) {}
    visible::ManagerConfig config;

    invisible::X x;
    invisible::Y y;
};

//////////////////////////////////////////////////////////////////////
//  PUBLIC METHODS
//////////////////////////////////////////////////////////////////////

visible::Manager::Manager(const ManagerConfig& config) {
    pimpl = new visible::Manager::Impl(config);
}

visible::Manager::~Manager() {
    delete pimpl;
}

void visible::Manager::foo(const nlohmann::json& json) {
    // do we satisfy the requirements needed to call X
    if (pimpl->config.shouldX) {
        assert( json.contains( token::USERNAME ) ); // check the input
        pimpl->x.foo( json[token::USERNAME] );
    }

    // do we satisfy the requirements needed to call Y
    if (pimpl->config.shouldY) {
        assert( json.contains(token::USERNAME) && json.contains(token::CODENAME) ); // check the input
        pimpl->y.foo( json[token::CODENAME], json[token::USERNAME] );
    }
}


