include NativeElement

type props = {
  ref?: ref,
  imageRef?: Image.ref,
  imageStyle?: Style.t,
  ...Image.imageProps,
}

@module("react-native")
external make: React.component<props> = "ImageBackground"
