Dim fso
Dim CurrentDirectory

Set fso = CreateObject("Scripting.FileSystemObject")
CurrentDirectory = fso.GetAbsolutePathName(".")
fso.CreateTextFile "__esy_elevated_prompt.lock", True

CreateObject("Shell.Application").ShellExecute _
  "cmd", _
  "/c node """ & CurrentDirectory & "\scripts\post_install.js"" -elevated """ & CurrentDirectory & """", _
  "", _
  "runas", _
  1

Do Until NOT fso.FileExists("__esy_elevated_prompt.lock")
  WScript.Sleep 400
Loop
