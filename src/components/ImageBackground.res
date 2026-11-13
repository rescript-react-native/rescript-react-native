type nativeElement

include NativeElement.Impl({type t = nativeElement})

type props = {
  ref?: ref,
  imageRef?: Image.ref,
  imageStyle?: Style.t,
  children?: React.element,
  ...Image.imageProps,
}

@deprecated(
  "ImageBackground is deprecated and will be removed in a future release, use a View with an absolutely positioned Image instead."
)
@module("react-native")
external make: React.component<props> = "ImageBackground"
