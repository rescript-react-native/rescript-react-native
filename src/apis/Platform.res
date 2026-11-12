type os = [#ios | #android | #macos | #windows | #web]

/** Do not switch on `Platform.os`, as it will result in code
that prevents the Metro bundler from inlining. Instead, use an if 
or ternary expression. 

```rescript
Platform.os === #ios 
  ? doSomethingInIos() 
  : doSomethingInOtherPlatform()
```
*/
@module("react-native") @scope("Platform")
external os: os = "OS"

@module("react-native") @scope("Platform")
external isPad: bool = "isPad"

@module("react-native") @scope("Platform")
external isTV: bool = "isTV"

@module("react-native") @scope("Platform")
external isVision: bool = "isVision"

@module("react-native") @scope("Platform")
external isTesting: bool = "isTesting"

// a string on iOS (e.g. "18.0"), the API level on Android (e.g. 35)
@unboxed
type version = String(string) | Number(float)

@module("react-native") @scope("Platform")
external version: version = "Version"
