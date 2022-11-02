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
@module("react-native")
@scope("Platform")
external os: os = "OS"
