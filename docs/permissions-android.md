---
title: PermissionsAndroid
---

[RN doc](https://facebook.github.io/react-native/docs/permissionsandroid.html)

## Example of use

### Requesting single permission.

```reason
  let requestPermissions = () =>
    PermissionsAndroid.request(
      ~permission=PermissionsAndroid.Permission.SEND_SMS,
      ~rationale=
        PermissionsAndroid.rationale(
          ~title="Hello!",
          ~message="Cool app wants to send SMS...",
          (),
        ),
      (),
    )
    |> Js.Promise.then_(permissions => {
         Js.log(permissions);
         Js.Promise.resolve();
       })
    |> ignore;
```

### Requesting multiple permissions.

```reason
  let requestMultiplePermissions = () => {
    PermissionsAndroid.requestMultiple(
      ~permissions=[
        PermissionsAndroid.Permission.SEND_SMS,
        PermissionsAndroid.Permission.READ_EXTERNAL_STORAGE,
        PermissionsAndroid.Permission.WRITE_EXTERNAL_STORAGE,
      ],
    )
    |> Js.Promise.then_(res => {
         Js.log(res);
         Js.Promise.resolve();
       })
    |> ignore;

    ();
  };
```

## Functions

### check

```reason
let check: Permission.t => Js.Promise.t(bool);
```

### request

```reason
let request:
(~permission: Permission.t, ~rationale: rationale=?, unit) =>
Js.Promise.t(result);
```

To create rationale paramters use [`PermissionsAndroid.rationale`](#rationale) function.

```reason
  PermissionsAndroid.rationale(
    ~title="Hello!",
    ~message="Cool app wants to send SMS...",
    (),
  ),
```

### requestMultiple

```reason
let requestMultiple:
  (~permissions: list(Permission.t)) => Js.Promise.t(Js.Dict.t('a));
```

### rationale

To create rationale for showing why you want to get permission.

```reason
let requestMultiple: (~title=string=?, ~message=string=?, unit) => rationale;
```

## Permissions that require prompting the user

All possieble values are avaliable via `PermissionsAndroid.Permission`

```reason
  PermissionsAndroid.Permission.READ_CALENDAR;
  PermissionsAndroid.Permission.WRITE_CALENDAR;
  PermissionsAndroid.Permission.CAMERA;
  PermissionsAndroid.Permission.READ_CONTACTS;
  PermissionsAndroid.Permission.WRITE_CONTACTS;
  PermissionsAndroid.Permission.GET_ACCOUNTS;
  PermissionsAndroid.Permission.ACCESS_FINE_LOCATION;
  PermissionsAndroid.Permission.ACCESS_COARSE_LOCATION;
  PermissionsAndroid.Permission.RECORD_AUDIO;
  PermissionsAndroid.Permission.READ_PHONE_STATE;
  PermissionsAndroid.Permission.CALL_PHONE;
  PermissionsAndroid.Permission.READ_CALL_LOG;
  PermissionsAndroid.Permission.WRITE_CALL_LOG;
  PermissionsAndroid.Permission.ADD_VOICEMAIL;
  PermissionsAndroid.Permission.USE_SIP;
  PermissionsAndroid.Permission.PROCESS_OUTGOING_CALLS;
  PermissionsAndroid.Permission.BODY_SENSORS;
  PermissionsAndroid.Permission.SEND_SMS;
  PermissionsAndroid.Permission.RECEIVE_SMS;
  PermissionsAndroid.Permission.READ_SMS;
  PermissionsAndroid.Permission.RECEIVE_WAP_PUSH;
  PermissionsAndroid.Permission.RECEIVE_MMS;
  PermissionsAndroid.Permission.READ_EXTERNAL_STORAGE;
  PermissionsAndroid.Permission.WRITE_EXTERNAL_STORAGE;
```

## Results for requesting

```reason
  PermissionsAndroid.GRANTED
  PermissionsAndroid.DENIED
  PermissionsAndroid.NEVER_ASK_AGAIN
```
