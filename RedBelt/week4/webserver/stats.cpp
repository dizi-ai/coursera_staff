#include "stats.h"


void Stats::AddMethod(string_view method) {
    if (this->method_.find(method)!=method_.end())
        this->method_[method]++;
    else
        this->method_["UNKNOWN"]++;
}
void Stats::AddUri(string_view uri) {
    if (this->uri_.find(uri)!=uri_.end())
        this->uri_[uri]++;
    else
        this->uri_["unknown"]++;
}
const map<string_view, int> & Stats::GetMethodStats() const {
    return this->method_;
}
const map<string_view, int> & Stats::GetUriStats() const {
    return this->uri_;
}
HttpRequest ParseRequest(string_view line) {
    HttpRequest hq;
    size_t pos=line.find_first_not_of(' ',0);
    line.remove_prefix(pos);

    size_t slash=line.find(' ',0);
    hq.method=line.substr(0,slash);
    line.remove_prefix(++slash);

    slash=line.find(' ',0);
    hq.uri=line.substr(0,slash);
    line.remove_prefix(++slash);
    hq.protocol=line;
    return hq;
}