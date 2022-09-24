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
}
void NameGenerator::create(const HttpRequestPtr &req,
                           std::function<void(const HttpResponsePtr &)> &&callback)
{
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

