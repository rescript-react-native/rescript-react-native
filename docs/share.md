---
title: Share
---

## Example of use

```reason
Share.share(
  ~content=URL("https://callstack.com", Some("Callstack Home Page")),
  (),
);
```

```reason
Share.share(
  ~content=Message("Sharing something", Some("The title for my message")),
  (),
);
```

## Function parameters

### content

```reason
content: content
```

_reference:_

```reason
type content =
  | Message(message, option(title))
  | URL(url, option(title));
```

### subject

```reason
subject: string=?
```

### tintColor

```reason
tintColor: string=?
```

### excludedActivityTypes

```reason
excludedActivityTypes: array(string)=?
```

### dialogTitle

```reason
dialogTitle: string=?
```

### non-labeled argument

```reason
unit
```
