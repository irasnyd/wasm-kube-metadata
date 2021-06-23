/*
 * Originally based upon:
 * https://github.com/proxy-wasm/proxy-wasm-cpp-sdk/tree/a96408d4418e0610494cff99478ae10b77eb813b
 * See README.md in the above repository
 */

#include <string>
#include <unordered_map>

#include "proxy_wasm_intrinsics.h"

class ExampleContext : public Context {
public:
  explicit ExampleContext(uint32_t id, RootContext* root) : Context(id, root) {
    LOG_ERROR("ExampleContext::constructor IRA");
  }

  //FilterHeadersStatus onRequestHeaders(uint32_t headers, bool end_of_stream) override;
  FilterHeadersStatus onRequestHeaders(uint32_t headers) override;
  FilterHeadersStatus onResponseHeaders(uint32_t) override;
  void onDone() override;
};
static RegisterContextFactory register_ExampleContext(CONTEXT_FACTORY(ExampleContext));

//FilterHeadersStatus ExampleContext::onRequestHeaders(uint32_t headers, bool end_of_stream) {
FilterHeadersStatus ExampleContext::onRequestHeaders(uint32_t headers)
{
  LOG_ERROR("IRA onRequestHeaders");
  addRequestHeader("x-isnyder-test-req", "example-context is here!!!");
  /*
  logInfo(std::string("onRequestHeaders ") + std::to_string(id()));
  auto path = getRequestHeader(":path");
  logInfo(std::string("header path ") + std::string(path->view()));
  */
  return FilterHeadersStatus::Continue;
}

FilterHeadersStatus ExampleContext::onResponseHeaders(uint32_t headers)
{
  LOG_ERROR("IRA onResponseHeaders");
  addResponseHeader("x-isnyder-test-resp", "example-context is here!!!");
  return FilterHeadersStatus::Continue;
}

void ExampleContext::onDone()
{
  LOG_ERROR("IRA onDone");
  //logInfo("onDone " + std::to_string(id()));
}

/* vim: set ts=2 sts=2 sw=2 et tw=112: */
