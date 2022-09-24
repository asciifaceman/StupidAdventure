#include "DangHunk.h"

void DangHunk::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    // write your application logic here
    auto resp = HttpResponse::newHttpResponse();
    resp->setStatusCode(k200OK);
    resp->setContentTypeCode(CT_TEXT_HTML);
    resp->setBody("<p>Good ol denny, what a dang hunk</p>");
    resp->setExpiredTime(0);
    callback(resp);
}
