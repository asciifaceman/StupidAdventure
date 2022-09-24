#pragma once

#include <drogon/HttpSimpleController.h>

using namespace drogon;

class DangHunk : public drogon::HttpSimpleController<DangHunk>
{
  public:
    void asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    PATH_ADD("/hunk", Get);
    // list path definitions here;
    // PATH_ADD("/path", "filter1", "filter2", HttpMethod1, HttpMethod2...);
    PATH_LIST_END
};
