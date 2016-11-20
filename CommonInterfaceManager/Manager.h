//
// Created by Rados Jovanovic on 2016-11-19.
// Copyright (c) 2016 into the clouds. All rights reserved.
//

#ifndef COMMONINTERFACEMANAGER_MANAGER_H
#define COMMONINTERFACEMANAGER_MANAGER_H

#include <string>
#include "json.hpp"

namespace visible {

    struct ManagerConfig;

    class Manager {
    public:
        Manager(const ManagerConfig& config);
        ~Manager();

        void foo(const nlohmann::json& jsonObject);

    private:
        class Impl;
        Impl* pimpl;
    };
}

#endif //COMMONINTERFACEMANAGER_MANAGER_H
