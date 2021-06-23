#include "plugin.h"

static RegisterContextFactory register_Scaffold(
    CONTEXT_FACTORY(PluginContext), ROOT_FACTORY(PluginRootContext));

bool PluginRootContext::onConfigure(size_t)
{
    LOG_DEBUG("IRA WAS HERE onConfigure");
    return true;
}

/* vim: set ts=4 sts=4 sw=4 et: */
