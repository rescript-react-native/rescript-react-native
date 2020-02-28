---
id: apis/PermissionsAndroid
title: PermissionsAndroid
officialDoc: https://reactnative.dev/docs/permissionsandroid
---

Only for projects supporting Native Code. Requires the project to have been
created using `react-native init` or ejected afterwards if created using
`expo init` or `create-react-native-app`.

`PermissionsAndroid` provides access to the permissions model avaiable since
`Android M`. While certain permissions are granted by default as long as they
are listed in `AndroidManifest.xml`, _dangerous_ permissions require a dialog.
This API will allow you to manage such permissions.

## Types

### `Permission.t`

Type for permissions that may be granted to the app. Available permissions are:

```reason
Permission.readCalendar
Permission.writeCalendar
Permission.camera
Permission.readContacts
Permission.writeContacts
Permission.getAccounts
Permission.accessFineLocation
Permission.accessCoarseLocation
Permission.recordAudio
Permission.readPhoneState
Permission.callPhone
Permission.readCallLog
Permission.writeCallLog
Permission.addVoicemail
Permission.useSip
Permission.processOutgoingCalls
Permission.bodySensors
Permission.sendSms
Permission.receiveSms
Permission.readSms
Permission.receiveWapPush
Permission.receiveMms
Permission.readExternalStorage
Permission.writeExternalStorage
```

### `Result.t`

Type for the result of a request for some permission. Possible results are:

```reason
Result.granted
Result.denied
Result.neverAskAgain
```

### `rationale`

To be used with the [`requestWithRationale`](#requestwithrationale) method. May
be created by the constructor of the same name.

```reason
rationale:
  (
    ~title: string,
    ~message: string,
    ~buttonPositive: string,
    ~buttonNegative: string=?,
    ~buttonNeutral: string=?,
    unit
  ) =>
  rationale
```

where

- `title` is the title of the dialog,
- `message` is the message of the dialog,
- `buttonPositive` is the text of the positive button,
- `buttonNegative` is the text of the negative button (optional), and
- `buttonNeutral` is the text of the neutral button (optional).

### `dict`

An extension of the `Js.Dict.t` type to allow keys of type `Permission.t`.
Values of keys may be accessed by the [`get`](#get) method.

## Methods

### `check`

Method to check whether the specified permission has been granted to the app,
returns a `bool` wrapped in a promise.

```reason
check: Permission.t => Js.Promise.t(bool)
```

### `request`

Method to request the specified permission, returns `Result.t` wrapped in a
promise.

```reason
request: Permission.t => Js.Promise.t(Result.t)
```

### `requestWithRationale`

Method to request the specified permission with a rationale, returns `Result.t`
wrapped in a promise. It is advised to provide a rationale if users have
previously turned off the permission. Rationale will be presented to the user
only when necessary. For further information, please refer to the
[official Android documentation](https://developer.android.com/training/permissions/requesting.html#explain).

```reason
requestWithRationale: (Permission.t, rationale) => Js.Promise.t(Result.t)
```

### `requestMultiple`

Method to request multiple permissions within the same dialog prompted to the
user, returns [`dict`](#dict) wrapped in a promise.

```reason
requestMultiple: array(Permission.t) => Js.Promise.t(dict)
```

### `get`

Getter method to access value of the specified permission in the [`dict`](#dict)
object returned by the `requestMultiple` method.

```reason
get: (dict, Permission.t) => option(Result.t)
```
