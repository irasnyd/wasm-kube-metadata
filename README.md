# Scaffold extension

This extension provides a starting point for a new extension.

## Instructions

Lots of Bazel code copy/pasted from the repository:
* https://github.com/proxy-wasm/proxy-wasm-cpp-sdk
* https://github.com/istio-ecosystem/wasm-extensions/blob/master/doc/write-a-wasm-extension-with-cpp.md

This makes it possible to compile a plugin using the newest versions of the
WASM toolchain, but using older versions of the SDK.

YAML based upon:
* https://github.com/istio/istio/issues/26388

### plugin.cc

Initial attempt to get WASM working, based upon:
* https://github.com/istio-ecosystem/wasm-extensions/tree/master/extensions/scaffold

```
$ bazel build :plugin.wasm
$ kubectl delete envoyfilter header-test-filter
$ kubectl --namespace=isnyder delete cm header-test-filter
$ kubectl --namespace=isnyder create cm header-test-filter --from-file=filter.wasm=bazel-bin/plugin.wasm
$ kubectly apply -f ./yaml
```

### filter1.cc

Based upon the example in the README.md of this repository:
* https://github.com/proxy-wasm/proxy-wasm-cpp-sdk/tree/a96408d4418e0610494cff99478ae10b77eb813b

```
$ bazel build :filter1.wasm
$ kubectl delete envoyfilter header-test-filter
$ kubectl --namespace=isnyder delete cm header-test-filter
$ kubectl --namespace=isnyder create cm header-test-filter --from-file=filter.wasm=bazel-bin/filter1.wasm
$ kubectly apply -f ./yaml
```

### filter2.cc

Based upon the example here:
* https://github.com/istio-ecosystem/wasm-extensions/blob/master/doc/write-a-wasm-extension-with-cpp.md
* https://github.com/istio-ecosystem/wasm-extensions/blob/master/example/plugin.cc

```
$ bazel build :filter2.wasm
$ kubectl delete envoyfilter header-test-filter
$ kubectl --namespace=isnyder delete cm header-test-filter
$ kubectl --namespace=isnyder create cm header-test-filter --from-file=filter.wasm=bazel-bin/filter2.wasm
$ kubectly apply -f ./yaml
```
