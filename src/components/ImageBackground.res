type nativeElement

include NativeElement.Impl({
  type t = nativeElement
})

external asImageBackgroundElement: DOMAPI.anyElement => element = "%identity"

type props = {
  ref?: ref,
  imageRef?: Image.ref,
  imageStyle?: Style.t,
  ...Image.imageProps,
}

@module("react-native")
external make: React.component<props> = "ImageBackground"
