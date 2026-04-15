type nativeElement

include NativeElement.Impl({
  type t = nativeElement
})

type props = {
  ref?: ref,
  imageRef?: Image.ref,
  imageStyle?: Style.t,
  children?: React.element,
  ...Image.imageProps,
}

@module("react-native")
external make: React.component<props> = "ImageBackground"
