/**
 *
 *  api_v1_NameGenerator.cc
 *  This file is generated by drogon_ctl
 *
 */

#include "api_v1_NameGenerator.h"
#include <string>
#include <trantor/utils/Date.h>
#include <trantor/utils/Logger.h>
#include <chrono>

using namespace api::v1;

void NameGenerator::getOne(const HttpRequestPtr &req,
                           std::function<void(const HttpResponsePtr &)> &&callback,
                           std::string &&id)
{
}

void NameGenerator::get(const HttpRequestPtr &req,
                        std::function<void(const HttpResponsePtr &)> &&callback)
{
    Json::Value ret;
    ret["message"] = AssembleName();
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    resp->setStatusCode(k200OK);
    resp->setContentTypeCode(CT_APPLICATION_JSON);
    callback(resp);

}
void NameGenerator::create(const HttpRequestPtr& req,
    std::function<void(const HttpResponsePtr &)> &&callback,
    std::string &&nameType,
    std::string &&name)
{
    Json::Value ret;
    bool failed = false;

    if (nameType == "first") {
        AddFirstName(name);
        ret["message"] = "Added First Name: " + name;
    }
    else if (nameType == "last") {
        AddLastName(name);
        ret["message"] = "Added Last Name: " + name;
    }
    else {
        ret["message"] = std::format("Name type {} doesn't exist", nameType);
        failed = true;
    }
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    resp->setStatusCode(k200OK);
    if (failed) {
        resp->setStatusCode(k501NotImplemented);
    }
    resp->setContentTypeCode(CT_APPLICATION_JSON);

    callback(resp);
}
void NameGenerator::updateOne(const HttpRequestPtr &req,
                              std::function<void(const HttpResponsePtr &)> &&callback,
                              std::string &&id)
{
}

void NameGenerator::health(const drogon::HttpRequestPtr &req,
    std::function<void(const drogon::HttpResponsePtr &)> &&callback)
{
 
    Json::Value ret;
    ret["status"] = "ok";
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    resp->setStatusCode(k200OK);
    resp->setContentTypeCode(CT_APPLICATION_JSON);

    callback(resp);
}

/*
void NameGenerator::update(const HttpRequestPtr &req,
                           std::function<void(const HttpResponsePtr &)> &&callback)
{

}*/

void NameGenerator::deleteOne(const HttpRequestPtr &req,
                              std::function<void(const HttpResponsePtr &)> &&callback,
                              std::string &&id)
{
}

std::string NameGenerator::AssembleName()
{
    LOG_INFO << "Starting name generation...";
    std::string firstName = "";
    std::string lastName = "";
    std::string assembledName = "";
    int indexFirstName = rand() % _firstNames.size();
    int indexLastName = rand() % _lastNames.size();

    LOG_INFO << "Acquired sizes...";
    if (_firstNames.size() > 0) {
        firstName.append(_firstNames[indexFirstName]);
    }
    if (_lastNames.size() > 0) {
        lastName.append(_lastNames[indexLastName]);
    }
    LOG_INFO << "appending";
    assembledName.append(firstName);
    assembledName.append(" ");
    assembledName.append(lastName);
    return assembledName;

}

void NameGenerator::AddFirstName(std::string name)
{
    _firstNames.push_back(name);
}

void NameGenerator::AddLastName(std::string name)
{
    _lastNames.push_back(name);
}