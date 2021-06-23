workspace(name = "istio_ecosystem_wasm_extensions")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Pulls proxy wasm cpp SDK with a specific SHA
#PROXY_WASM_CPP_SDK_SHA = "956f0d500c380cc1656a2d861b7ee12c2515a664"
#PROXY_WASM_CPP_SDK_SHA256 = "b97e3e716b1f38dc601487aa0bde72490bbc82b8f3ad73f1f3e69733984955df"

# https://github.com/istio/istio/issues/26388#issuecomment-686750319
PROXY_WASM_CPP_SDK_SHA = "a96408d4418e0610494cff99478ae10b77eb813b"
PROXY_WASM_CPP_SDK_SHA256 = "d6edcf5258f04e7883909633b957f0220611d5fb0512230d3a7d0c7618f399ce"

http_archive(
    name = "proxy_wasm_cpp_sdk",
    sha256 = PROXY_WASM_CPP_SDK_SHA256,
    strip_prefix = "proxy-wasm-cpp-sdk-" + PROXY_WASM_CPP_SDK_SHA,
    url = "https://github.com/proxy-wasm/proxy-wasm-cpp-sdk/archive/" + PROXY_WASM_CPP_SDK_SHA + ".tar.gz",
)

load("//bazel/dep:deps.bzl", "wasm_dependencies")

wasm_dependencies()

load("//bazel/dep:deps_extra.bzl", "wasm_dependencies_extra")

wasm_dependencies_extra()

### optional imports ###
# To import commonly used libraries from istio proxy, such as base64, json, and flatbuffer.
IO_ISTIO_PROXY_SHA = "a4e4b362e334f4275ac2154fb831ddf3cf45db03"
IO_ISTIO_PROXY_SHA256 = "23296eb7a31e42eb2845488f6869539332dc705c72a3b0ebd196bdaf6d16c23c"

http_archive(
    name = "io_istio_proxy",
    sha256 = IO_ISTIO_PROXY_SHA256,
    strip_prefix = "proxy-" + IO_ISTIO_PROXY_SHA,
    url = "https://github.com/istio/proxy/archive/" + IO_ISTIO_PROXY_SHA + ".tar.gz",
)

load("@istio_ecosystem_wasm_extensions//bazel:wasm.bzl", "wasm_libraries")

wasm_libraries()

# To import proxy wasm cpp host, which will be used in unit testing.
load("@proxy_wasm_cpp_host//bazel:repositories.bzl", "proxy_wasm_cpp_host_repositories")

proxy_wasm_cpp_host_repositories()

load("@proxy_wasm_cpp_host//bazel:dependencies.bzl", "proxy_wasm_cpp_host_dependencies")

proxy_wasm_cpp_host_dependencies()
