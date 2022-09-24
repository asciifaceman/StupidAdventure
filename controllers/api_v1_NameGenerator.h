/**
 *
 *  api_v1_NameGenerator.h
 *  This file is generated by drogon_ctl
 *
 */

#pragma once

#include <drogon/HttpController.h>
using namespace drogon;
namespace api 
{
namespace v1 
{
/**
 * @brief this class is created by the drogon_ctl command (drogon_ctl create controller -r api::v1::NameGenerator).
 * this class is a restful API controller.
 */
class NameGenerator: public drogon::HttpController<NameGenerator>
{
private:
    std::vector<std::string> _firstNames;
    std::vector<std::string> _lastNames;

  public:

    METHOD_LIST_BEGIN
    // use METHOD_ADD to add your custom processing function here;
    METHOD_ADD(NameGenerator::getOne,"/{1}",Get,Options);
    METHOD_ADD(NameGenerator::get,"",Get,Options);
    METHOD_ADD(NameGenerator::create,"/{1}/{2}",Post,Options);
    METHOD_ADD(NameGenerator::updateOne,"/{1}",Put,Options);
    //METHOD_ADD(NameGenerator::update,"",Put,Options);
    METHOD_ADD(NameGenerator::deleteOne,"/{1}",Delete,Options);
    METHOD_ADD(NameGenerator::health, "/health", Get, Options);
    METHOD_LIST_END

    void getOne(const HttpRequestPtr &req,
                std::function<void(const HttpResponsePtr &)> &&callback,
                std::string &&id);
    void updateOne(const HttpRequestPtr &req,
                std::function<void(const HttpResponsePtr &)> &&callback,
                std::string &&id);
    void deleteOne(const HttpRequestPtr &req,
                   std::function<void(const HttpResponsePtr &)> &&callback,
                   std::string &&id);
    void health(const HttpRequestPtr &req,
             std::function<void(const HttpResponsePtr &)> &&callback);
    void get(const HttpRequestPtr &req,
             std::function<void(const HttpResponsePtr &)> &&callback);
    void create(const HttpRequestPtr &req,
                std::function<void(const HttpResponsePtr &)> &&callback,
                std::string &&nameType,
                std::string &&name);

    std::string AssembleName();
    void AddFirstName(std::string name);
    void AddLastName(std::string name);
//    void update(const HttpRequestPtr &req,
//                std::function<void(const HttpResponsePtr &)> &&callback);

};

class NameStore {
private:
    std::vector<std::string> _firstNames;
    std::vector<std::string> _lastNames;
public:

    std::string AssembleName();
    void AddFirstName(std::string name);
    void AddLastName(std::string name);
};
}
}
