type os = [#ios | #android | #macos | #windows | #web]

@module("react-native") @scope("Platform") external os: os = "OS"
