// TODO FIXME: original source code: wasm-extensions/example/plugin.{h,cc}
#include "proxy_wasm_intrinsics.h"

class PluginRootContext : public RootContext {
 public:
  explicit PluginRootContext(uint32_t id, std::string_view root_id)
      : RootContext(id, root_id) {}

  bool onConfigure(size_t) override;
  bool onStart(size_t) override;
};

class PluginContext : public Context {
 public:
  explicit PluginContext(uint32_t id, RootContext* root) : Context(id, root) {}

  FilterHeadersStatus onResponseHeaders(uint32_t) override;

 private:
  inline PluginRootContext* rootContext() {
    return dynamic_cast<PluginRootContext*>(this->root());
  }
};

// Boilerplate code to register the extension implementation
static RegisterContextFactory register_Example(
    CONTEXT_FACTORY(PluginContext),
    ROOT_FACTORY(PluginRootContext),
    "header_test_filter"
);

bool PluginRootContext::onConfigure(size_t) {
  LOG_ERROR("IRA onConfigure");
  return true;
}

bool PluginRootContext::onStart(size_t) {
  LOG_ERROR("IRA onStart");
  return true;
}

FilterHeadersStatus PluginContext::onResponseHeaders(uint32_t) {
  LOG_ERROR("IRA onResponseHeaders");
  addResponseHeader("X-Wasm-custom", "foo");
  return FilterHeadersStatus::Continue;
}

/* vim: set ts=2 sts=2 sw=2 et tw=112: */
